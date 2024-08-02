%{
#include "node.h"
#include <string.h>
#include <stdio.h>

extern int yylineno;
void yyerror(const char *s);
int yylex(void);
%}

%token MAIN
%token FUNCTION RETURN
%token TOK_INT TOK_BOOLEAN TOK_TRUE TOK_FALSE ERROR_TOKEN
%token PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA AMPERSAND AND OR NOT EQ NE LT LE GT GE IF ELSE FOR WHILE LBRACKET RBRACKET ARRAY SCANF PRINTF
%token NEWLINE
%token <ival> NUMBER
%token <sval> IDENTIFIER

%type <node> declaration_statement control_statement assignment_statement if_statement while_statement for_statement function_call printf_statement expression statement program
%type <sval> type
%type <node> program_body function_body
%type <node> function_definition parameter_list parameter argument_list return_statement

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%nonassoc '(' ')'

%left PLUS MINUS TIMES DIVIDE AND OR EQ NE LT LE GT GE '+' '-' '*' '/'

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
    MAIN optional_newlines LBRACE program_body RBRACE optional_newlines{
        printf("Programa main procesado correctamente en la linea %d.\n", yylineno);
        $$ = $4;
    }
    | MAIN optional_newlines LBRACE program_body {
        printf("Error: falta RBRACE para cerrar el main en la linea %d.\n", yylineno);
        yyerror("Falta RBRACE para cerrar el main");
        yyerrok;
        $$ = NULL;
    }
    | MAIN optional_newlines {
        printf("Error: falta LBRACE para abrir el main en la linea %d.\n", yylineno);
        yyerror("Falta LBRACE abrir el main");
        $$ = NULL;
    }
    ;

optional_newlines:
    | optional_newlines NEWLINE
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
    | control_statement
    | assignment_statement
    | function_call
    | return_statement
    ;

assignment_statement:
    IDENTIFIER EQUAL expression SEMICOLON {
        printf("Asignando a '%s' el resultado de la expresion en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node($1, $3);
    }
    | IDENTIFIER EQUAL expression {
        printf("Error: falta ';' despues de la asignacion de '%s' en la linea %d.\n", $1, yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        $$ = NULL;
    }

    ;

declaration_statement:
    type IDENTIFIER SEMICOLON {
        printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $2, $1, yylineno);
        $$ = create_declaration_node($1, $2);
    }
    | type IDENTIFIER {
        printf("Error: falta ';' despues de la declaracion de '%s' en la linea %d.\n", $2, yylineno);
        yyerror("Falta ';' despues de la declaracion");
        yyerrok;
        $$ = NULL;
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
        yyerror("Falta definir el tipo de function");
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
    | FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN optional_newlines function_body RBRACE{
        printf("Error: falta LBRACE para abrir la funcion en la linea %d.\n", yylineno);
        yyerror("Falta LBRACE para abrir la funcion");
        yyerrok;
        $$ = NULL;
    }
    | FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE function_body{
        printf("Error: falta RBRACE para abrir la funcion en la linea %d.\n", yylineno);
        yyerror("Falta RBRACE para abrir la funcion");
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
    type IDENTIFIER {
        $$ = create_parameter_node($1, $2);
    }
    ;

function_body:
    { $$ = NULL; }
    | function_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    //| function_body NEWLINE { $$ = $1; }
    ;
    
function_call:
    IDENTIFIER LPAREN argument_list RPAREN SEMICOLON {
        printf("Llamada a la funcion '%s' con argumentos en la linea %d.\n", $1, yylineno);
        $$ = create_function_call_node($1, $3);
    }
    ;

argument_list:
    expression
    | argument_list COMMA expression {
        $$ = combine_argument_nodes($1, $3);
    }
    ;

type:
    TOK_INT {
        printf("Tipo detectado: int en la linea %d.\n", yylineno);
        $$ = strdup("int");
    }
    | TOK_BOOLEAN {
        printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
        $$ = strdup("boolean");
    }
    ;

control_statement:
    if_statement
    | while_statement
    | for_statement
    ;

if_statement:
    IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
        printf("Entrando a la sentencia if en linea %d.\n", yylineno);
        $$ = create_if_node($3, $5, NULL);
    }
    | IF '(' expression ')' statement ELSE statement {
        printf("Entrando a la sentencia 'if-else' en linea %d.\n", yylineno);
        $$ = create_if_node($3, $5, $7);
    }
    ;

while_statement:
    WHILE '(' expression ')' statement {
        printf("Procesando una sentencia 'while' en la linea %d.\n", yylineno);
        $$ = create_while_node($3, $5);
    }
    ;

for_statement:
    FOR '(' expression ';' expression ';' expression ')' statement {
        printf("Procesando una sentencia 'for' en la linea %d.\n", yylineno);
        $$ = create_for_node($3, $5, $7, $9);
    }
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
    | expression DIVIDE expression {
        printf("Operacion DIVIDE en linea %d.\n", yylineno);
        $$ = create_binary_op_node("/", $1, $3);
    }
    | NUMBER {
        printf("Numero detectado: %d en la linea %d.\n", $1, yylineno);
        $$ = create_constant_node($1);
    }
    | IDENTIFIER {
        printf("Identificador detectado: %s en la linea %d.\n", $1, yylineno);
        $$ = create_identifier_node($1);
    }
    | '(' expression ')' {
        printf("Evaluando expresion entre paréntesis en la linea %d.\n", yylineno);
        $$ = $2;
    }
    | error {
        yyerror("Error en la expresion");
    }
    ;
    
%%
