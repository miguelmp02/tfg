%{
#include "y.tab.h"
#include "symbol_table.h"
#include "node.h"

int yywrap(void);
%}
%option yylineno
%%

"main"  { /*printf("MAIN ");*/ return MAIN; }
"function"  {/*printf("FUNCTION ");*/ return FUNCTION; }
"return"  { /*printf("RETURN ");*/ return RETURN; }
"if"    {  /* printf("IF ");*/ return IF; }
"else"  {  /*printf("ELSE ");*/ return ELSE; }
"for"   {  /*printf("FOR ");*/ return FOR; }
"while" {  /*printf("WHILE ");*/ return WHILE; }
"int"   {  /*printf("INT ");*/ return TOK_INT; }
"boolean" { /*printf("BOOLEAN ");*/ return TOK_BOOLEAN; }
"true"  {  /*printf("TRUE ");*/ return TOK_TRUE; }
"false" {  /*printf("FALSE ");*/ return TOK_FALSE; }
"array" {  /*printf("ARRAY ");*/ return ARRAY; }
"scanf" {  /*printf("SCANF ");*/ return SCANF; }
"printf" { /*printf("PRINTF ");*/ return PRINTF; }
"free"  {  /*printf("FREE ");*/ return FREE; }
[ \t]+  { /* Ignorar espacios en blanco. */ }
\n      { /*printf("NEWLINE\n");*/ return NEWLINE; }
[0-9]+  {
    yylval.ival = atoi(yytext);
    /*printf("NUMBER(%s) ", yytext);*/
    return NUMBER;
}
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = strdup(yytext);
    /*printf("IDENTIFIER(%s) ", yytext);*/
    return IDENTIFIER;
}
"+"     { /*printf("PLUS ");*/ return PLUS; }
"-"     {  /*printf("MINUS ");*/ return MINUS; }
"*"     {  /*printf("TIMES ");*/ return TIMES; }
"/"     {  /*printf("DIVIDE ");*/ return DIVIDE; }
"="     { /*printf("EQUAL ");*/ return EQUAL; }
";"     { /*printf("SEMICOLON ");*/ return SEMICOLON; }
"&"     {  /*printf("AMPERSAND ");*/ return AMPERSAND; }
","     {  /*printf("COMMA ");*/ return COMMA; }
"("     {  /*printf("LPAREN ");*/ return LPAREN; }
")"     { /*printf("RPAREN ");*/ return RPAREN; }
"{"     { /*printf("LBRACE ");*/ return LBRACE; }
"}"     { /*printf("RBRACE ");*/ return RBRACE; }
"["     {  /*printf("LBRACKET ");*/ return LBRACKET; }
"]"     {  /*printf("RBRACKET ");*/ return RBRACKET; }
"&&"    {  /*printf("AND ");*/ return AND; }
"||"    {  /*printf("OR ");*/ return OR; }
"!"     {  /*printf("NOT ");*/ return NOT; }
"=="    {  /*printf("EQ ");*/ return EQ; }
"!="    {  /*printf("NE ");*/ return NE; }
"<"     {  /*printf("LT ");*/ return LT; }
"<="    {  /*printf("LE ");*/ return LE; }
">"     {  /*printf("GT ");*/ return GT; }
">="    { /*printf("GE ");*/ return GE; }
.|\n    { printf("Error token: '%s' no reconocido en la linea %d\n", yytext, yylineno); return ERROR_TOKEN; }

"//"[^"\n"]*    { /* Ignorar comentario de una línea */ }


%%
int yywrap(void) {
    return 1;
}
