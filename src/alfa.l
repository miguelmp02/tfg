%{
#include "alfa.tab.h" // Asegúrate de incluir el header correcto para los tokens
%}

%%
[ \t]+             { /* Ignorar espacios y tabs */ }
\n                 { /* Ignorar nuevas líneas */ }
"="                { return IGUAL; }
"+"                { return MAS; }
"-"                { return MENOS; }
"*"                { return MUL; }
"/"                { return DIV; }
"("                { return PARIZQ; }
")"                { return PARDER; }
";"                { return PUNTOYCOMA; }
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.string = strdup(yytext);
    return IDENTIFICADOR;
}
[0-9]+             {
    yylval.entero = atoi(yytext);
    return NUMERO;
}
"//".*             { /* Ignorar comentarios de una línea */ }
"/*"               { BEGIN(COMENTARIO); }
<COMENTARIO>"*/"   { BEGIN(INITIAL); }
<COMENTARIO>.|\n   { /* Ignorar contenido dentro de comentarios multilínea */ }

%%

int yywrap() {
    return 1;
}
