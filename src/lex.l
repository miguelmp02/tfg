%{
#include "y.tab.h"
#include "symbol_table.h"
#include "node.h"

int yywrap(void);
%}
%option yylineno
%%

"if"    { insert_symbol(yytext, IF); /*printf("IF ");*/ return IF; }
"else"  { insert_symbol(yytext, ELSE); /*printf("ELSE ");*/ return ELSE; }
"for"   { insert_symbol(yytext, FOR); /*printf("FOR ");*/ return FOR; }
"while" { insert_symbol(yytext, WHILE); /*printf("WHILE ");*/ return WHILE; }
"int"   { insert_symbol(yytext, TOK_INT); /*printf("INT ");*/ return TOK_INT; }
"boolean" { insert_symbol(yytext, TOK_BOOLEAN); /*printf("BOOLEAN ");*/ return TOK_BOOLEAN; }
"true"  { insert_symbol(yytext, TOK_TRUE); /*printf("TRUE ");*/ return TOK_TRUE; }
"false" { insert_symbol(yytext, TOK_FALSE); /*printf("FALSE ");*/ return TOK_FALSE; }
"array" { insert_symbol(yytext, ARRAY); /*printf("ARRAY ");*/ return ARRAY; }
"scanf" { insert_symbol(yytext, SCANF); /*printf("SCANF ");*/ return SCANF; }
"printf" { insert_symbol(yytext, PRINTF); /*printf("PRINTF ");*/ return PRINTF; }

[ \t]+  { /* Ignorar espacios en blanco. */ }

\n      { insert_symbol("NEWLINE", NEWLINE); /*printf("NEWLINE\n");*/ return NEWLINE; }

[0-9]+  {
    yylval.ival = atoi(yytext);
    insert_symbol(yytext, NUMBER);
    /*printf("NUMBER(%s) ", yytext);*/
    return NUMBER;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = strdup(yytext);
    insert_symbol(yytext, IDENTIFIER);
    /*printf("IDENTIFIER(%s) ", yytext);*/
    return IDENTIFIER;
}

"+"     { insert_symbol(yytext, PLUS); /*printf("PLUS ");*/ return PLUS; }
"-"     { insert_symbol(yytext, MINUS); /*printf("MINUS ");*/ return MINUS; }
"*"     { insert_symbol(yytext, TIMES); /*printf("TIMES ");*/ return TIMES; }
"/"     { insert_symbol(yytext, DIVIDE); /*printf("DIVIDE ");*/ return DIVIDE; }
"="     { insert_symbol(yytext, EQUAL); /*printf("EQUAL ");*/ return EQUAL; }
";"     { insert_symbol(yytext, SEMICOLON); /*printf("SEMICOLON ");*/ return SEMICOLON; }
"&"     { insert_symbol(yytext, AMPERSAND); /*printf("AMPERSAND ");*/ return AMPERSAND; }
","     { insert_symbol(yytext, COMMA); /*printf("COMMA ");*/ return COMMA; }
"("     { insert_symbol(yytext, LPAREN); /*printf("LPAREN ");*/ return LPAREN; }
")"     { insert_symbol(yytext, RPAREN); /*printf("RPAREN ");*/ return RPAREN; }
"{"     { insert_symbol(yytext, LBRACE); /*printf("LBRACE ");*/ return LBRACE; }
"}"     { insert_symbol(yytext, RBRACE); /*printf("RBRACE ");*/ return RBRACE; }
"["     { insert_symbol(yytext, LBRACKET); /*printf("LBRACKET ");*/ return LBRACKET; }
"]"     { insert_symbol(yytext, RBRACKET); /*printf("RBRACKET ");*/ return RBRACKET; }
"&&"    { insert_symbol(yytext, AND); /*printf("AND ");*/ return AND; }
"||"    { insert_symbol(yytext, OR); /*printf("OR ");*/ return OR; }
"!"     { insert_symbol(yytext, NOT); /*printf("NOT ");*/ return NOT; }
"=="    { insert_symbol(yytext, EQ); /*printf("EQ ");*/ return EQ; }
"!="    { insert_symbol(yytext, NE); /*printf("NE ");*/ return NE; }
"<"     { insert_symbol(yytext, LT); /*printf("LT ");*/ return LT; }
"<="    { insert_symbol(yytext, LE); /*printf("LE ");*/ return LE; }
">"     { insert_symbol(yytext, GT); /*printf("GT ");*/ return GT; }
">="    { insert_symbol(yytext, GE); /*printf("GE ");*/ return GE; }
.|\n    { printf("Error token: '%s' no reconocido en la linea %d\n", yytext, yylineno); return ERROR_TOKEN; }

%%
int yywrap(void) {
    return 1;
}
