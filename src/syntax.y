%{
#include "node.h"
#include <string.h>
#include <stdio.h>

extern int yylineno;
void yyerror(const char *s);
int yylex(void);
%}

%token MAIN
%token TOK_INT TOK_BOOLEAN TOK_TRUE TOK_FALSE ERROR_TOKEN
%token PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA AMPERSAND AND OR NOT EQ NE LT LE GT GE IF ELSE FOR WHILE LBRACKET RBRACKET ARRAY SCANF PRINTF
%token NEWLINE
%token <ival> NUMBER
%token <sval> IDENTIFIER

%type <node> declaration_statement control_statement assignment_statement if_statement while_statement for_statement function_call printf_statement expression statement program
%type <sval> type
%type <node> program_body

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%nonassoc '(' ')'

%left PLUS MINUS TIMES DIVIDE AND OR EQ NE LT LE GT GE

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
    MAIN optional_newlines LBRACE program_body RBRACE {
        printf("Programa main procesado correctamente en la linea %d.\n", yylineno);
        $$ = $4;
    }
    ;

optional_newlines:
    | NEWLINE optional_newlines
    ;

program_body:
    { $$ = NULL; }
    | program_body statement NEWLINE { $$ = combine_nodes($1, $2); }
    | program_body NEWLINE { $$ = $1; }
    ;
    
statement:
    assignment_statement
    | declaration_statement
    | control_statement
    | function_call
    | printf_statement
    ;

assignment_statement:
    IDENTIFIER EQUAL expression SEMICOLON {
        printf("Asignando a '%s' el resultado de la expresion en la linea %d.\n", $1, yylineno);
        $$ = create_assignment_node($1, $3);
    }
    ;

declaration_statement:
    type IDENTIFIER SEMICOLON {
        printf("Declarando variable '%s' de tipo '%s' en la línea %d.\n", $2, $1, yylineno);
        $$ = create_declaration_node($1, $2);
    }
    | type IDENTIFIER {
        printf("Error: falta ';' después de la declaración de '%s' en la línea %d.\n", $2, yylineno);
        yyerror("Falta ';' después de la declaración");
        yyerrok;
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

function_call:
    IDENTIFIER '(' ')' SEMICOLON {
        printf("Llamada a función '%s' sin argumentos en la linea %d.\n", $1, yylineno);
        struct ASTNode* args[1] = {NULL}; 
        $$ = create_function_call_node($1, args, 0);
    }
    ;

printf_statement:
    PRINTF IDENTIFIER SEMICOLON {
        printf("Llamando a 'printf' con '%s' en la linea %d.\n", $2, yylineno);
        $$ = create_printf_node($2);
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
