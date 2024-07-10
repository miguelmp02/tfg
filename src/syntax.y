%{
#include "node.h"
#include <stdlib.h>
void yyerror(const char *s);
int yylex(void);
%}

%union {
    struct ASTNode* node;  
    int ival;       
    char *sval;      
}
%token <ival> NUMBER
%token <sval> IDENTIFIER
%token EQUAL SEMICOLON PLUS MINUS TIMES DIVIDE
%token NEWLINE LPAREN RPAREN LBRACE RBRACE
%type <node> expression statement program

%left PLUS MINUS
%left TIMES DIVIDE
%right EQUAL

%%
program:
    /* Vacío */
    { $$ = NULL; }
    | program statement
    { $$ = ($1 == NULL) ? $2 : create_program_node($1, $2); }
    ;

statement:
    IDENTIFIER EQUAL expression SEMICOLON {
        $$ = create_assignment_node($1, $3);
    }
    | expression SEMICOLON {
        $$ = $1;
    }
    ;

expression:
    expression PLUS expression
    { $$ = create_binary_op_node("+", $1, $3); }
    | expression MINUS expression
    { $$ = create_binary_op_node("-", $1, $3); }
    | expression TIMES expression
    { $$ = create_binary_op_node("*", $1, $3); }
    | expression DIVIDE expression
    { $$ = create_binary_op_node("/", $1, $3); }
    | NUMBER
    { $$ = create_constant_node($1); }
    | IDENTIFIER {
        $$ = create_identifier_node($1); // Aquí $1 es una cadena (char*), no un ASTNode*
    }
    ;
%%
