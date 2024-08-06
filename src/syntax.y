%{
#include "node.h"
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"
#include "codegen.h"

extern int yylineno;
DataType current_function_type;
DataType data_type;
void yyerror(const char *s);
void yysemanticerror(const char *s);
int yylex(void);
%}

%token MAIN
%token FUNCTION RETURN FREE MALLOC
%token TOK_INT TOK_BOOLEAN TOK_CHAR TOK_FLOAT TOK_STRING TOK_TRUE TOK_FALSE ERROR_TOKEN
%token PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA AMPERSAND AND OR NOT EQ NE LT LE GT GE IF ELSE FOR WHILE LBRACKET RBRACKET ARRAY SCANF PRINTF
%token NEWLINE
%token <ival> NUMBER 
%token <sval> IDENTIFIER

%type <node> declaration_statement assignment_statement if_statement while_statement for_statement function_call printf_statement scanf_statement expression statement program
%type <sval> type
%type <node> program_body function_body if_body else_body while_body for_body pointer_type pointer_assignment_statement free_statement array_access
%type <node> function_definition parameter_list parameter argument_list argument_for_list argument_while_list return_statement array_declaration dimension_list expression_list
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%nonassoc '(' ')'


%left PLUS MINUS TIMES DIVIDE AND OR EQ NE LT LE GT GE '+' '-' '*' '/'

%right EQUAL

%union {
    int ival;                
    char* sval; 
    char* identifier;                 
    struct ASTNode* node;    
    struct Declaration* declaration;
    struct IfExpr* ifExpr;
    struct WhileExpr* whileExpr;
    struct ForLoop* forLoop;
    struct FunctionCall* functionCall;
    struct {
        struct ASTNode* left;
        struct ASTNode* right;
        char* op;
    } binary;
}

%%
program:
    optional_newlines MAIN optional_newlines LBRACE program_body RBRACE optional_newlines optional_classes{
        //printf("Programa main procesado correctamente en la linea %d.\n", yylineno);
        $$ = $5;
    }
    | optional_newlines MAIN optional_newlines LBRACE program_body {
        printf("Error: falta RBRACE para cerrar el main en la linea %d.\n", yylineno);
        yyerror("Falta RBRACE para cerrar el main");
        yyerrok;
        $$ = NULL;
    }
    | optional_newlines MAIN optional_newlines {
        printf("Error: falta LBRACE para abrir el main en la linea %d.\n", yylineno);
        yyerror("Falta LBRACE abrir el main");
        $$ = NULL;
    }
    ;

optional_newlines:
    | optional_newlines NEWLINE
    ;

class_definition:
    IDENTIFIER optional_newlines LBRACE program_body RBRACE optional_newlines
    {
        if (find_symbol($1) != NULL) {
            yysemanticerror("Error semantico: Identificador de clase previamente declarado");
        } else {
            insert_symbol($1,0,0);
            //printf("Definiendo clase '%s' en la línea %d.\n", $1, yylineno);
        }
    }
    ;
optional_classes:
    | optional_classes class_definition
    ;
program_body:
    { $$ = NULL; }
    | program_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | program_body NEWLINE { $$ = $1; }
    ;
    
statement:
    function_definition
    | declaration_statement
    | printf_statement
    | scanf_statement
    | if_statement
    | while_statement
    | for_statement
    | assignment_statement
    | pointer_assignment_statement
    | function_call
    | return_statement
    | free_statement
    | array_declaration
    | array_access
    ;

assignment_statement:
    IDENTIFIER EQUAL expression SEMICOLON {
        Symbol *symbol = find_symbol($1);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $1);
        } else if ($3 == NULL) {
            yysemanticerror("Error semantico: Expresion no definida");
            printf("Error semantico en la linea %d: Expresion no definida para la asignacion a '%s'.\n", yylineno, $1);
            $$ = NULL;
        } else {
          //  printf("Debug: Tipo del simbolo '%s': %d, Tipo de la expresion: %d\n", $1, symbol->type, $3->data_type);
            if (symbol->type != $3->data_type) {
                yysemanticerror("Error semantico: Tipo de identificador incompatible en la asignacion.");
                printf("Error semantico en la linea %d: Tipo de identificador incompatible en la asignacion. Tipo de '%s': %d, Tipo de expresion: %d\n", yylineno, $1, symbol->type, $3->data_type);
                $$ = NULL;
            } else {
               // printf("Asignando a '%s' el resultado de la expresion en la linea %d.\n", $1, yylineno);
                $$ = create_assignment_node($1, $3);
                generate_quad(OP_ASSIGN, extract_identifier($3), "", $1);
            }
        }
    }
    | IDENTIFIER EQUAL function_call SEMICOLON {
        Symbol *symbol = find_symbol($1);
        Symbol *func_symbol = find_symbol($3->data.functionCall.functionName);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico en la linea %d: Identificador \"%s\" no declarado previamente.\n", yylineno, $1);
        } else if (func_symbol == NULL) {
            yysemanticerror("Error semantico: Funcion no declarada previamente");
            printf("Error semantico en la linea %d: Funcion \"%s\" no declarada previamente.\n", yylineno, $3->data.functionCall.functionName);
        } else if ($3 == NULL) {
            yysemanticerror("Error semantico: Expresion no definida");
            printf("Error semantico en la linea %d: Expresion no definida para la asignacion a '%s'.\n", yylineno, $1);
            $$ = NULL;
        } else if ($3->data_type == -1) {
            yysemanticerror("Error semantico: Tipo de expresion no definido");
            printf("Error semantico en la linea %d: Tipo de expresion no definido para la asignacion a '%s'.\n", yylineno, $1);
            $$ = NULL;
        } else if (symbol->type != func_symbol->type) {
            yysemanticerror("Error semantico: Tipo de identificador incompatible en la asignacion.");
            printf("Error semantico en la linea %d: Tipo de identificador incompatible en la asignacion. Tipo de '%s': %d, Tipo de funcion: %d\n", yylineno, $1, symbol->type, func_symbol->type);
            $$ = NULL;
        } else {
           // printf("Asignando a '%s' el resultado de la llamada a funcion en la linea %d.\n", $1, yylineno);
            $$ = create_assignment_node($1, $3);
            generate_quad(OP_ASSIGN, $3->data.functionCall.functionName, "", $1);
        }
    }
    | IDENTIFIER EQUAL array_access SEMICOLON {
        Symbol *symbol = find_symbol($1);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $1);
        } else {
           // printf("Asignando a '%s' el resultado de la llamada a array en la linea %d.\n", $1, yylineno);
            $$ = create_assignment_node($1, $3);
            generate_quad(OP_ASSIGN, extract_identifier($3), "", $1);
        }
    }
    | array_access EQUAL expression SEMICOLON {
        //printf("Asignando al array el resultado en la linea %d.\n", yylineno);
        $$ = create_assignment_node_array($1, $3);
        generate_quad(OP_ASSIGN, extract_identifier($3), "", extract_identifier($1));
    }
    | array_access EQUAL array_access SEMICOLON {
       // printf("Asignando al array el resultado en la linea %d.\n", yylineno);
        $$ = create_assignment_node_array($1, $3);
        generate_quad(OP_ASSIGN, extract_identifier($3), "", extract_identifier($1));
    }
    | IDENTIFIER EQUAL MALLOC SEMICOLON {
        if (find_symbol($1) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $1);
        } else {
            //printf("Asignando al identifier malloc en la linea %d.\n", $1, yylineno);
            $$ = create_assignment_node($1, 0);
        }   
    }
    | IDENTIFIER EQUAL expression {
        printf("Error: falta ';' despues de la asignacion de '%s' en la linea %d.\n", $1, yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        $$ = NULL;
    }
    | IDENTIFIER EQUAL function_call {
        printf("Error: falta ';' despues de la llamada a funcion asignada a '%s' en la linea %d.\n", $1, yylineno);
        yyerror("Falta ';' despues de la llamada a funcion");
        yyerrok;
        $$ = NULL;
    }
    | IDENTIFIER EQUAL array_access {
        printf("Error: falta ';' despues del array en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues del array");
        yyerrok;
        $$ = NULL;
    }
    | array_access EQUAL expression {
        printf("Error: falta ';' despues de la asignacion en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        $$ = NULL;
    }
    | IDENTIFIER EQUAL AMPERSAND IDENTIFIER SEMICOLON {
        Symbol *symbol1 = find_symbol($1);
        Symbol *symbol2 = find_symbol($4);
        if (symbol1 == NULL || symbol2 == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" o \"%s\" no declarado previamente.\n", $1, $4);
        } else {
            printf("Asignando a '%s' la dirección de '%s' en la linea %d.\n", $1, $4, yylineno);
            $$ = create_assignment_node_ampersand($1, $4);
            generate_quad(OP_ASSIGN, $4, "", $1);
        }
    }
    ;

pointer_type:
      TIMES { $$ = create_pointer_node(1); }  
    | pointer_type TIMES {
        $$ = increase_pointer_level($1); 
       // printf("Annadiendo un nivel de puntero, total ahora es %d.\n", $$->data.pointer_level);
    }
    ;

pointer_assignment_statement:
    TIMES IDENTIFIER EQUAL expression SEMICOLON {
        Symbol *symbol = find_symbol($2);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $2);
        } else {
            //printf("Asignacion de puntero para '%s' en linea %d.\n", $2, yylineno);
            $$ = create_pointer_assignment_node($2, $4);
            generate_quad(OP_ASSIGN, extract_identifier($4), "", $2);
        }
    }
    | TIMES IDENTIFIER EQUAL expression {
        printf("Error: falta ';' despues de la asignacion de '%s' en la linea %d.\n", $2, yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        $$ = NULL;
    }
    ;

declaration_statement:
    type IDENTIFIER SEMICOLON {
        if (find_symbol($2) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", $2);
        } else {
            insert_symbol($2, convert_data_type($1),0);
            //printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $2, $1, yylineno);
            $$ = create_declaration_node($1, $2, 0);
        }
    }
    | type IDENTIFIER {
        printf("Error: falta ';' despues de la declaracion de '%s' en la linea %d.\n", $2, yylineno);
        yyerror("Falta ';' despues de la declaracion");
        yyerrok;
        $$ = NULL;
    }
    | type pointer_type IDENTIFIER SEMICOLON {
        if (find_symbol($3) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", $3);
        } else {
            insert_symbol($3, convert_data_type($1),0);
           // printf("Declarando puntero '%s' de tipo '%s' con %d niveles de puntero en la linea %d.\n", $3, $1, $2->data.pointer_level, yylineno);
            $$ = create_declaration_node($1, $3, $2->data.pointer_level);
        }
    }
    | type pointer_type IDENTIFIER {
        printf("Error: falta ';' despues de la declaracion del puntero de '%s' en la linea %d.\n", $3, yylineno);
        yyerror("Falta ';' despues de la declaracion del puntero");
        yyerrok;
        $$ = NULL;
    }
    | type AMPERSAND IDENTIFIER SEMICOLON {
        if (find_symbol($3) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", $3);
        } else {
            insert_symbol($3, convert_data_type($1),0);
            //printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $3, $1, yylineno);
            $$ = create_declaration_node($1, $3, 0);
        }
    }
    | type AMPERSAND IDENTIFIER {
        printf("Error: falta ';' despues de la declaracion de '%s' en la linea %d.\n", $3, yylineno);
        yyerror("Falta ';' despues de la declaracion");
        yyerrok;
        $$ = NULL;
    }   
    ;

array_declaration:
     ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER SEMICOLON {
        if (find_symbol($6) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", $6);
        } else {
            insert_symbol($6, convert_data_type($2), 0);
            $$ = create_array_node($2, $4, $6);
           // printf("Declaración de array de tipo '%s' con identificador '%s' en la linea %d.\n", $2, $6, yylineno);
        }
    }
    | ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER{
        printf("Error: falta ';' al final de la array de '%s' en la linea %d.\n", $2, yylineno);
        yyerror("Falta ';' al final de la array");
        yyerrok;
        $$ = NULL;
    }
    ;

array_access:
    IDENTIFIER LBRACKET expression_list RBRACKET {
        Symbol *symbol = find_symbol($1);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $1);
        } else {
            $$ = create_array_access_node($1, $3);
             $$->data_type = symbol->type;
            //printf("Acceso a array '%s' de tipo '%d' en la linea %d.\n", $1, symbol->type, yylineno);
        }
    }
    ;
expression_list:
    expression
    | expression_list COMMA expression {
        $$ = combine_expressions($1, $3);
    }
    ;

dimension_list:
    expression {
        $$ = $1; 
    }
    | dimension_list COMMA expression {
        $$ = create_dimension_list($1, $3); 
    }
    ;
    
printf_statement:
    PRINTF IDENTIFIER SEMICOLON {
        if (find_symbol($2) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $2);
        } else {
            //printf("Llamando a 'printf' con '%s' en la linea %d.\n", $2, yylineno);
            $$ = create_printf_node($2);
        }
    }
    | PRINTF IDENTIFIER {
        printf("Error: falta ';' despues de un printf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un printf");
        yyerrok;
        $$ = NULL;
    }
    | PRINTF pointer_type IDENTIFIER SEMICOLON {
        if (find_symbol($3) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $3);
        } else {
           // printf("Llamando a 'printf' con '%s' en la linea %d.\n", $3, yylineno);
            $$ = create_printf_node($3);
        }
    }
    | PRINTF pointer_type IDENTIFIER {
        printf("Error: falta ';' despues de un printf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un printf");
        yyerrok;
        $$ = NULL;
    }
    ;

scanf_statement:
    SCANF IDENTIFIER SEMICOLON {
        if (find_symbol($2) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $2);
        } else {
            //printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
            $$ = create_scanf_node($2);
        }
    }
    | SCANF array_access SEMICOLON {
        //printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
        $$ = create_scanf_node_array($2);
    }
    | SCANF IDENTIFIER {
        printf("Error: falta ';' despues de un f scanf la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un scanf");
        yyerrok;
        $$ = NULL;
    }
    | SCANF array_access {
        printf("Error: falta ';' despues de un scanf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un scanf");
        yyerrok;
        $$ = NULL;
    }
    ;

free_statement:
    FREE IDENTIFIER SEMICOLON {
        if (find_symbol($2) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", $2);
        } else {
           // printf("Llamando a 'free' con '%s' en la linea %d.\n", $2, yylineno);
            $$ = create_free_node($2);
        }
    }
    | FREE IDENTIFIER {
        printf("Error: falta ';' despues de un free en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un free");
        yyerrok;
        $$ = NULL;
    }
    ;

return_statement:
    RETURN IDENTIFIER SEMICOLON {
        Symbol *symbol = find_symbol($2);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Identificador \"%s\" no declarado previamente.\n", $2);
        } else if (symbol->type != current_function_type) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de '%s': %d, Tipo esperado: %d\n", $2, symbol->type, current_function_type);
            $$ = NULL;           
        } else {
           // printf("Declaracion de retorno en la linea %d. Tipo de '%s': %d\n", yylineno, $2, symbol->type);
            $$ = create_return_node($2, NULL);
        }
    }
    | RETURN IDENTIFIER {
        printf("Error: falta ';' despues de un return en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un return");
        yyerrok;
        $$ = NULL;
    }
    | RETURN LPAREN function_call RPAREN SEMICOLON {
        Symbol *symbol = find_symbol($3->data.functionCall.functionName);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador de funcion no declarado previamente");
            $$ = NULL;
        } else if (symbol->type != current_function_type) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de funcion '%s': %d, Tipo esperado: %d\n", $3->data.functionCall.functionName, symbol->type, current_function_type);
            $$ = NULL;
        } else {
           // printf("Declaracion de retorno en la linea %d.\n", yylineno);
            $$ = create_return_node(NULL, $3);
        }
    }
    | RETURN NUMBER SEMICOLON {
        if (current_function_type != TYPE_INT) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: int, Tipo esperado: %d\n", current_function_type);
            $$ = NULL;
        } else {
            //printf("Declaracion de retorno en la linea %d.\n", yylineno);
            $$ = create_constant_node($2);
        }
    }
    | RETURN TOK_TRUE SEMICOLON {
        if (current_function_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: boolean, Tipo esperado: %d\n", current_function_type);
            $$ = NULL;
        } else {
            $$ = create_constant_node(1);
            //printf("Valor booleano 'true' detectado en la linea %d.\n", yylineno);
        }
    }
    | RETURN TOK_FALSE SEMICOLON {
        if (current_function_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: boolean, Tipo esperado: %d\n", current_function_type);
            $$ = NULL;
        } else {
            $$ = create_constant_node(0);
          //  printf("Valor booleano 'false' detectado en la linea %d.\n", yylineno);
        }
    }
    ;

function_definition:
    FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE {
        if (find_symbol($3) != NULL) {
            yysemanticerror("Error semantico: Identificador de funcion previamente declarado");
        } else {
            int num_parameters = count_parameters($5);
            current_function_type = convert_data_type($2);
            insert_symbol($3, convert_data_type($2), num_parameters);
           // printf("Declaracion de funcion '%s' con tipo '%s' en la linea %d.\n", $3, $2, yylineno);
        }
    } function_body RBRACE {
        //printf("Definicion de funcion '%s' con tipo '%s' y retorno asegurado en la linea %d.\n", $3, $2, yylineno);
    }
    | FUNCTION IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE function_body RBRACE{
        printf("Error: falta definir el tipo de funcion en la linea %d.\n", yylineno);
        yyerror("Falta definir el tipo de funcion");
        yyerrok;
        $$ = NULL;
    }
    | FUNCTION type LPAREN parameter_list RPAREN optional_newlines LBRACE function_body RBRACE{
        printf("Error: falta definir el identificador de funcion en la linea %d.\n", yylineno);
        yyerror("Falta definir el identificador de function");
        yyerrok;
        $$ = NULL;
    }
    | FUNCTION type IDENTIFIER parameter_list RPAREN optional_newlines LBRACE function_body RBRACE{
        printf("Error: falta LPAREN para definir parametros de la funcion en la linea %d.\n", yylineno);
        yyerror("Falta LPAREN para definir parametros de la funcion");
        yyerrok;
        $$ = NULL;
    }
    ;

parameter_list:
    parameter
    | parameter_list SEMICOLON parameter {
        $$ = combine_parameter_nodes($1, $3);
    }
    ;

parameter:
    { $$ = NULL; }
    | type IDENTIFIER {
        if (find_symbol($2) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", $2);
        } else {
            insert_symbol($2, convert_data_type($1),0);
            $$ = create_parameter_node($1, $2);
        }
    }
    ;

function_body:
    { $$ = NULL; }
    | function_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | function_body NEWLINE
    ;
    
function_call:
    IDENTIFIER LPAREN argument_list RPAREN {
        Symbol *symbol = find_symbol($1);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Identificador \"%s\" no declarado previamente.\n", $1);
        } else {
            int num_arguments = count_arguments($3);
            if (num_arguments != symbol->num_parameters) {
                yysemanticerror("Error semantico: Numero incorrecto de argumentos en la llamada a la funcion");
                printf("Error semantico: Numero incorrecto de argumentos en la llamada a la funcion '%s'. Esperados %d, encontrados %d en la linea %d.\n", $1, symbol->num_parameters, num_arguments, yylineno);
            } else {
              //  printf("Llamada a la funcion '%s' con argumentos en la linea %d.\n", $1, yylineno);
                $$ = create_function_call_node($1, $3);
            }
        }
    }
    ;


argument_list:
    { $$ = NULL; }
    | expression
    | argument_list COMMA expression {
        $$ = combine_argument_nodes($1, $3);
    }
    ;

type:
    TOK_INT {
        $$ = strdup("int");
       // printf("Tipo detectado: int en la linea %d.\n", yylineno);
    }
    | TOK_BOOLEAN {
        $$ = strdup("boolean");
        //printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
    | TOK_FLOAT {
        $$ = strdup("float");
       // printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
    | TOK_CHAR {
        $$ = strdup("char");
        //printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
    | TOK_STRING {
        $$ = strdup("string");
       // printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
    ;

if_statement:
    IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines ELSE optional_newlines LBRACE else_body RBRACE {
       // printf("Entrando a la sentencia 'if-else' en linea %d.\n", yylineno);
        char label_else[20], label_end[20];
        sprintf(label_else, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier($3), "", label_else);
        $$ = $7;
        generate_quad(OP_JUMP, "", "", label_end);
        generate_quad(OP_LABEL, label_else, "", "");
        $$ = $13;
        generate_quad(OP_LABEL, label_end, "", "");
    }
    | IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines LBRACE else_body RBRACE {
        printf("Error: falta ELSE para definir parametros de la funcion en la linea %d.\n", yylineno);
        yyerror("Falta ELSE para definir parametros de la funcion");
        yyerrok;
        $$ = NULL;
    }
    ;

if_body:
    { $$ = NULL; }
    | if_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | if_body NEWLINE { $$ = $1; }
    ;

else_body:
    { $$ = NULL; }
    | else_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | else_body NEWLINE { $$ = $1; }
    ;

while_statement:
    WHILE LPAREN argument_while_list RPAREN optional_newlines LBRACE while_body RBRACE {
        //printf("Procesando una sentencia 'while' en la linea %d.\n", yylineno);
        char label_start[20], label_end[20];
        sprintf(label_start, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        generate_quad(OP_LABEL, label_start, "", "");
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier($3), "", label_end);
        $$ = $7;
        generate_quad(OP_JUMP, "", "", label_start);
        generate_quad(OP_LABEL, label_end, "", "");
    }
    ;
argument_while_list:
    { $$ = NULL; }
    | expression
    | argument_while_list SEMICOLON expression {
        $$ = combine_argument_nodes($1, $3);
    }
    ;
while_body:
    { $$ = NULL; }
    | while_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | while_body NEWLINE
    ;

for_statement:
    FOR LPAREN argument_for_list RPAREN optional_newlines LBRACE for_body RBRACE {
       // printf("Procesando una sentencia 'for' en la linea %d.\n", yylineno);
        char label_start[20], label_end[20], label_increment[20];
        sprintf(label_start, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        sprintf(label_increment, "L%d", new_label());
        $$ = $3;
        generate_quad(OP_LABEL, label_start, "", "");
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier($3), "", label_end);
        $$ = $7;
        generate_quad(OP_LABEL, label_increment, "", "");
        $$ = $3;
        generate_quad(OP_JUMP, "", "", label_start);
        generate_quad(OP_LABEL, label_end, "", "");
    }
    ;

argument_for_list:
    { $$ = NULL; }
    | expression
    | argument_for_list SEMICOLON expression {
        $$ = combine_argument_nodes($1, $3);
    }
    ;

for_body:
    { $$ = NULL; }
    | for_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | for_body NEWLINE
    ;

expression:
    expression PLUS expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion PLUS solo permitida entre enteros.");
            printf("Error semantico: Operacion PLUS solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Operacion PLUS en linea %d.\n", yylineno);
            $$ = create_binary_op_node("+", $1, $3);
            $$->data_type = TYPE_INT;
            generate_quad(OP_ADD, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression MINUS expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion MINUS solo permitida entre enteros.");
            printf("Error semantico: Operacion MINUS solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
          //  printf("Operacion MINUS en linea %d.\n", yylineno);
            $$ = create_binary_op_node("-", $1, $3);
            $$->data_type = TYPE_INT;
            generate_quad(OP_SUB, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression TIMES expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion TIMES solo permitida entre enteros.");
            printf("Error semantico: Operacion TIMES solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Operacion TIMES en linea %d.\n", yylineno);
            $$ = create_binary_op_node("*", $1, $3);
            $$->data_type = TYPE_INT;
            generate_quad(OP_MUL, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression DIVIDE expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion DIVIDE solo permitida entre enteros.");
            printf("Error semantico: Operacion DIVIDE solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Operacion DIVIDE en linea %d.\n", yylineno);
            $$ = create_binary_op_node("/", $1, $3);
            $$->data_type = TYPE_INT;
            generate_quad(OP_DIV, extract_identifier($1), extract_identifier($3), extract_identifier($$)); 
        }
    }
    | expression EQUAL expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != $3->data_type) {
            yysemanticerror("Error semantico: Comparacion '=' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '=' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Comparacion '=' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("=", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_EQ, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
     | expression EQ expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != $3->data_type) {
            yysemanticerror("Error semantico: Comparacion '==' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '==' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Comparacion '==' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("==", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_EQ, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression NE expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != $3->data_type) {
            yysemanticerror("Error semantico: Comparacion '!=' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '!=' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Comparacion '!=' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("!=", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_NE, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression LT expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Comparacion '<' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("<", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LT, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | array_access LT expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Comparacion '<' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("<", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LT, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression LE expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<=' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<=' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Comparacion '<=' en linea %d.\n", yylineno);
            $$ = create_binary_op_node("<=", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LE, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression GT expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '>' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '>' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Comparacion '>' en linea %d.\n", yylineno);
            $$ = create_binary_op_node(">", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_GT, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
     | expression GE expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_INT || $3->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '>=' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '>=' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
           // printf("Comparacion '>=' en linea %d.\n", yylineno);
            $$ = create_binary_op_node(">=", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_GE, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression AND expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion lógica inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_BOOLEAN || $3->data_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Operacion AND solo permitida entre booleanos.");
            printf("Error semantico: Operacion AND solo permitida entre booleanos. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
          //  printf("Operacion AND en linea %d.\n", yylineno);
            $$ = create_binary_op_node("&&", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_AND, extract_identifier($1), extract_identifier($3), extract_identifier($$));  
        }
    }
    | expression OR expression {
        if ($1 == NULL || $3 == NULL) {
            yyerror("Operacion lógica inválida debido a operandos no definidos.");
            $$ = NULL;
        } else if ($1->data_type != TYPE_BOOLEAN || $3->data_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Operacion OR solo permitida entre booleanos.");
            printf("Error semantico: Operacion OR solo permitida entre booleanos. Tipo de operando 1: %d, Tipo de operando 2: %d\n", $1->data_type, $3->data_type);
            $$ = NULL;
        } else {
            //printf("Operacion OR en linea %d.\n", yylineno);
            $$ = create_binary_op_node("||", $1, $3);
            $$->data_type = TYPE_BOOLEAN;
            generate_quad(OP_OR, extract_identifier($1), extract_identifier($3), extract_identifier($$)); 
        }
    }
    | NUMBER {
        //printf("Numero detectado: %d en la linea %d.\n", $1, yylineno);
        $$ = create_constant_node($1);
        $$->data_type = TYPE_INT;
    }
    | IDENTIFIER {
        Symbol *symbol = find_symbol($1);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico en la linea %d: Identificador \"%s\" no declarado previamente.\n", yylineno, $1);
            $$ = NULL;
        } else {
            //printf("Identificador detectado: %s en la linea %d. Tipo: %d\n", $1, yylineno, symbol->type);
            $$ = create_identifier_node($1);
            $$->data_type = symbol->type; // Asegurar que el tipo se establece correctamente
        }
    }
    | TOK_TRUE {
        $$ = create_constant_node(1);
        $$->data_type = TYPE_BOOLEAN;
       // printf("Valor booleano 'true' detectado en la linea %d.\n", yylineno);
    }
    | TOK_FALSE {
        $$ = create_constant_node(0);
        $$->data_type = TYPE_BOOLEAN;
        //printf("Valor booleano 'false' detectado en la linea %d.\n", yylineno);
    }
    | LPAREN expression RPAREN {
       // printf("Evaluando expresion entre parentesis en la linea %d.\n", yylineno);
        $$ = $2;
    }
    | TIMES expression {
       // printf("Evaluando expresion con punteros en la linea %d.\n", yylineno);
        $$ = $2;
    }
    | error {
        yyerror("Error en la expresion");
    }
    ;
    
%%
