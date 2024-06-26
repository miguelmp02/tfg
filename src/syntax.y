%{
#include <stdio.h>
#include "symbol_table.h"
#include "semantic.h"
#include "codegen.h"

extern int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "%s\n", s); }
%}

%token NEWLINE NUMBER IDENTIFIER PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE

%%
program:
    | program statement
    ;

statement:
    | IDENTIFIER EQUAL expression SEMICOLON   { process_assignment($1, $3); }
    | expression SEMICOLON                    { eval_expression($1); }
    ;

expression:
    NUMBER
    | IDENTIFIER
    | expression PLUS expression
    | expression MINUS expression
    | expression TIMES expression
    | expression DIVIDE expression
    | LPAREN expression RPAREN
    ;

%%
