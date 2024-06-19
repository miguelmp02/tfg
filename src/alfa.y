%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
void yyerror(char *s);
int yylex(void);
SymbolTable *symbolTable;

extern int yylex();
extern void yyerror(char *s);
%}

%token <string> IDENTIFICADOR NUMERO
%token IGUAL MAS MENOS MUL DIV
%token PARIZQ PARDER PUNTOYCOMA

%%
programa: /* definiciones de la gramática */
%%
int main(int argc, char **argv) {
    symbolTable = create_symbol_table(100);
    yyparse();
    free_symbol_table(symbolTable);
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
