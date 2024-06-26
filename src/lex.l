%{
#include "y.tab.h"
#include "symbol_table.h"
%}

%%

[ \t]+                { /* Ignorar espacios en blanco. */ }
\n                    { return NEWLINE; }
[0-9]+                { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval = strdup(yytext); return IDENTIFIER; }
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
