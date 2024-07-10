%{
#include "y.tab.h"
#include "symbol_table.h"
#include "node.h"
int yywrap(void);

%}

%%

[ \t]+                { /* Ignorar espacios en blanco. */ }
\n                    { printf("NEWLINE\n"); return NEWLINE; }
[0-9]+ {
    printf("NUMBER(%s) ", yytext);
    yylval.ival = atoi(yytext);
    return NUMBER;
}
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("IDENTIFIER(%s) ", yytext);
    yylval.node = create_identifier_node(yytext);
    return IDENTIFIER;
}
"+"                   { printf("PLUS "); return PLUS; }
"-"                   { printf("MINUS "); return MINUS; }
"*"                   { printf("TIMES "); return TIMES; }
"/"                   { printf("DIVIDE "); return DIVIDE; }
"="                   { printf("EQUAL "); return EQUAL; }
";"                   { printf("SEMICOLON "); return SEMICOLON; }
"("                   { printf("LPAREN "); return LPAREN; }
")"                   { printf("RPAREN "); return RPAREN; }
"{"                   { printf("LBRACE "); return LBRACE; }
"}"                   { printf("RBRACE "); return RBRACE; }

%%
int yywrap(void) {
    return 1;
}