%{
#include "node.h"
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"

extern int yylineno;
void yyerror(const char *s);
void yysemanticerror(const char *s);
int yylex(void);
%}

%token MAIN
%token FUNCTION RETURN FREE 
%token TOK_INT TOK_BOOLEAN TOK_TRUE TOK_FALSE ERROR_TOKEN
%token PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA AMPERSAND AND OR NOT EQ NE LT LE GT GE IF ELSE FOR WHILE LBRACKET RBRACKET ARRAY SCANF PRINTF
%token NEWLINE
%token <ival> NUMBER 
%token <sval> IDENTIFIER

%type <node> declaration_statement assignment_statement if_statement while_statement for_statement function_call printf_statement scanf_statement expression statement program
%type <sval> type
%type <node> program_body function_body if_body while_body for_body pointer_type pointer_assignment_statement free_statement array_access
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
        printf("Programa main procesado correctamente en la linea %d.\n", yylineno);
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

optional_classes:
    | optional_classes IDENTIFIER optional_newlines LBRACE program_body RBRACE optional_newlines
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
        printf("Asignando a '%s' el resultado de la expresion en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node($1, $3);
    }
    | IDENTIFIER EQUAL function_call SEMICOLON {
        printf("Asignando a '%s' el resultado de la llamada a funcion en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node($1, $3);
    }
    | IDENTIFIER EQUAL array_access SEMICOLON {
        printf("Asignando a '%s' el resultado de la llamada a array en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node($1, $3);
    }
    | array_access EQUAL expression SEMICOLON {
        printf("Asignando al array el resultado en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node_array($1, $3);
    }
    | array_access EQUAL array_access SEMICOLON {
        printf("Asignando al array el resultado en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node_array($1, $3);
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
        printf("Error: falta ';' despues del array en la linea %d.\n", $1, yylineno);
        yyerror("Falta ';' despues del array");
        yyerrok;
        $$ = NULL;
    }
    | array_access EQUAL expression {
        printf("Error: falta ';' despues de la asignacion en la linea %d.\n", $1, yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        $$ = NULL;
    }
    | IDENTIFIER EQUAL AMPERSAND IDENTIFIER SEMICOLON {
        printf("Asignando a '%s' la dirección de '%s' en la linea %d.\n", $1, $4, yylineno);
        $$ = create_assignment_node_ampersand($1, $4);
    }
    ;

pointer_type:
      TIMES { $$ = create_pointer_node(1); }  
    | pointer_type TIMES {
        $$ = increase_pointer_level($1); 
        printf("Annadiendo un nivel de puntero, total ahora es %d.\n", $$->data.pointer_level);
    }
    ;

pointer_assignment_statement:
    TIMES IDENTIFIER EQUAL expression SEMICOLON {
        printf("Asignacion de puntero para '%s' en linea %d.\n", $2, yylineno);
        $$ = create_pointer_assignment_node($2, $4);
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
            insert_symbol($2, convert_data_type($1));
            printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $2, $1, yylineno);
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
            insert_symbol($3, convert_data_type($1));
            printf("Declarando puntero '%s' de tipo '%s' con %d niveles de puntero en la linea %d.\n", $3, $1, $2->data.pointer_level, yylineno);
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
            insert_symbol($3, convert_data_type($1));
            printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $3, $1, yylineno);
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
    ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER SEMICOLON{
        $$ = create_array_node($2, $4, $6);
        printf("Declaración de array de tipo '%s' con identificador '%s' en la linea %d.\n", $2, $6, yylineno);
    }
    ;
    | ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER{
        printf("Error: falta ';' al final de la array de '%s' en la linea %d.\n", $2, yylineno);
        yyerror("Falta ';' al final de la array");
        yyerrok;
        $$ = NULL;
    }
    ;

array_access:
    IDENTIFIER LBRACKET expression_list RBRACKET{
        $$ = create_array_access_node($1, $3);
        printf("Acceso a array '%s' en la linea %d.\n", $1, yylineno);
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
        printf("Llamando a 'printf' con '%s' en la linea %d.\n", $2, yylineno);
        $$ = create_printf_node($2);
    }
    | PRINTF IDENTIFIER {
        printf("Error: falta ';' despues de un printf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un printf");
        yyerrok;
        $$ = NULL;
    }
    | PRINTF pointer_type IDENTIFIER SEMICOLON {
        printf("Llamando a 'printf' con '%s' en la linea %d.\n", $3, yylineno);
        $$ = create_printf_node($3);
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
        printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
        $$ = create_scanf_node($2);
    }
    | SCANF array_access SEMICOLON {
        printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
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
        printf("Llamando a 'free' con '%s' en la linea %d.\n", $2, yylineno);
        $$ = create_free_node($2);
    }
    | FREE IDENTIFIER {
        printf("Error: falta ';' despues de un free en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un free");
        yyerrok;
        $$ = NULL;
    }
    ;

return_statement:
    RETURN expression SEMICOLON {
        printf("Declaracion de retorno en la linea %d.\n", yylineno);
        $$ = create_return_node($2);
    }
    | RETURN expression {
        printf("Error: falta ';' despues de un return en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un return");
        yyerrok;
        $$ = NULL;
    }
    ;

function_definition:
    FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE function_body RBRACE{
        $$ = create_function_node($2, $3, $5, $9);
        printf("Definicion de funcion '%s' con tipo '%s' y retorno asegurado en la linea %d.\n", $3, $2, yylineno);
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
    |type IDENTIFIER {
        $$ = create_parameter_node($1, $2);
    }
    ;

function_body:
    { $$ = NULL; }
    | function_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | function_body NEWLINE
    ;
    
function_call:
    IDENTIFIER LPAREN argument_list RPAREN {
        printf("Llamada a la funcion '%s' con argumentos en la linea %d.\n", $1, yylineno);
        $$ = create_function_call_node($1, $3);
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
        printf("Tipo detectado: int en la linea %d.\n", yylineno);
    }
    | TOK_BOOLEAN {
        $$ = strdup("boolean");
        printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
    ;

if_statement:
    IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines ELSE optional_newlines LBRACE if_body RBRACE {
        printf("Entrando a la sentencia 'if-else' en linea %d.\n", yylineno);
        $$ = create_if_node($3, $7, $13);
    }
    | IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines LBRACE if_body RBRACE {
        printf("Error: falta ELSE para definir parametros de la funcion en la linea %d.\n", yylineno);
        yyerror("Falta ELSE para definir parametros de la funcion");
        yyerrok;
        $$ = NULL;
    }
    ;

if_body:
    { $$ = NULL; }
    | if_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | if_body NEWLINE
    ;

while_statement:
    WHILE LPAREN argument_while_list RPAREN optional_newlines LBRACE while_body RBRACE {
        printf("Procesando una sentencia 'while' en la linea %d.\n", yylineno);
        $$ = create_while_node($3, $7);
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
        printf("Procesando una sentencia 'for' en la linea %d.\n", yylineno);
        $$ = create_for_node($3, $7);
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
        } else {
            printf("Operacion PLUS en linea %d.\n", yylineno);
            $$ = create_binary_op_node("+", $1, $3);
        }
    }
    | expression MINUS expression {
        printf("Operacion MINUS en linea %d.\n", yylineno);
        $$ = create_binary_op_node("-", $1, $3);
    }
    | expression TIMES expression {
        printf("Operacion TIMES en linea %d.\n", yylineno);
        $$ = create_binary_op_node("*", $1, $3);
    }
    | expression TIMES function_call {
        printf("Operacion TIMES en linea %d.\n", yylineno);
        $$ = create_binary_op_node("*", $1, $3);
    }
    | expression DIVIDE expression {
        printf("Operacion DIVIDE en linea %d.\n", yylineno);
        $$ = create_binary_op_node("/", $1, $3);
    }
    | expression EQUAL expression {
        printf("Comparacion '=' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("=", $1, $3);
    }
    | expression EQ expression {
        printf("Comparacion '==' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("==", $1, $3);
    }
    | expression NE expression {
        printf("Comparacion '!=' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("!=", $1, $3);
    }
    | expression LT expression {
        printf("Comparacion '<' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("<", $1, $3);
    }
    | array_access LT expression{
        printf("Comparacion '<' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("<", $1, $3);
    }
    | expression LE expression {
        printf("Comparacion '=<' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("=<", $1, $3);
    }
    | expression GT expression {
        printf("Comparacion '>' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node(">", $1, $3);
    }
    | expression GE expression {
        printf("Comparacion '>=' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node(">=", $1, $3);
    }
    | expression AND expression {
        printf("Comparacion '&&' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("&&", $1, $3);
    }
    | expression OR expression {
        printf("Comparacion '||' entre expresiones en la linea %d.\n", yylineno);
        $$ = create_binary_op_node("||", $1, $3);
    }
    | NUMBER {
        printf("Numero detectado: %d en la linea %d.\n", $1, yylineno);
        $$ = create_constant_node($1);
    }
    | IDENTIFIER {
        printf("Identificador detectado: %s en la linea %d.\n", $1, yylineno);
        $$ = create_identifier_node($1);
    }
    | TOK_TRUE {
        $$ = create_constant_node(1);
        printf("Valor booleano 'true' detectado en la linea %d.\n", yylineno);
    }
    | TOK_FALSE {
        $$ = create_constant_node(0);
        printf("Valor booleano 'false' detectado en la linea %d.\n", yylineno);
    }
    | LPAREN expression RPAREN {
        printf("Evaluando expresion entre parentesis en la linea %d.\n", yylineno);
        $$ = $2;
    }
    | TIMES expression{
        printf("Evaluando expresion con punteros en la linea %d.\n", yylineno);
        $$ = $2;
    }
    | error {
        yyerror("Error en la expresion");
    }
    ;
    
%%
