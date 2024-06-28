%{
#include <stdio.h>
#include "symbol_table.h"
#include "semantic.h"
#include "codegen.h"

extern int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "%s\n", s); }
%}

%token NEWLINE NUMBER IDENTIFIER PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE

// Definiendo la precedencia y la asociatividad de los operadores
%right EQUAL
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc LPAREN RPAREN

%%
program:
    | program statement
    ;

statement:
    IDENTIFIER EQUAL expression SEMICOLON   { process_assignment($1, $3); }
    | expression SEMICOLON                  { eval_expression($1); }
    ;

expression:
    NUMBER
    | IDENTIFIER
    | expression PLUS expression           { $$ = $1 + $3; }
    | expression MINUS expression          { $$ = $1 - $3; }
    | expression TIMES expression          { $$ = $1 * $3; }
    | expression DIVIDE expression         { $$ = $1 / $3; }
    | LPAREN expression RPAREN             { $$ = $2; }
    ;

%%
