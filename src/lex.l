%{
#include "y.tab.h"
#include "symbol_table.h"
int yywrap(void);

%}

%%

[ \t]+                { /* Ignorar espacios en blanco. */ }
\n                    { return NEWLINE; }
[0-9]+                  { yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return IDENTIFIER; }
"+"                   { return PLUS; }
"-"                   { return MINUS; }
"*"                   { return TIMES; }
"/"                   { return DIVIDE; }
"="                   { return EQUAL; }
";"                   { return SEMICOLON; }
"("                   { return LPAREN; }
")"                   { return RPAREN; }
"{"                   { return LBRACE; }
"}"                   { return RBRACE; }

%%
int yywrap(void) {
    return 1;
}