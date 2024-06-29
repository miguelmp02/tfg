%{
#include <stdio.h>
#include "y.tab.h"
#include "symbol_table.h"
#include "semantic.h"
#include "codegen.h"

extern int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "%s\n", s); }
%}

%union {
    int ival;
    char* sval;
}

%token <sval> IDENTIFIER  // Sólo necesitas esto para los tokens
%token <ival> NUMBER
%token NEWLINE PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE

%type <ival> expression  // %type para los no terminales que necesitan un tipo

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
    NUMBER                                  { $$ = $1; }
    | IDENTIFIER                            { $$ = find_symbol($1)->value; }  // Asegúrate de que esta línea maneje adecuadamente el tipo y los datos
    | expression PLUS expression            { $$ = $1 + $3; }
    | expression MINUS expression           { $$ = $1 - $3; }
    | expression TIMES expression           { $$ = $1 * $3; }
    | expression DIVIDE expression          { $$ = $1 / $3; }
    | LPAREN expression RPAREN              { $$ = $2; }
    ;
%%
