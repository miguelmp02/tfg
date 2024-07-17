%{
#include "node.h"  // Asume que este archivo define las estructuras del AST
#include <string.h> 
#include <stdio.h>
void yyerror(const char *s);
int yylex(void);
%}
%union {
    int ival;                
    char* sval;              
    struct ASTNode* node;    
    struct Declaration* declaration;
    struct IfExpr* ifExpr;
    struct WhileExpr* whileExpr;
    struct ForLoop* forLoop;
    struct FunctionCall* functionCall;
    char* identifier;    
}

%token TOK_INT TOK_BOOLEAN TOK_TRUE TOK_FALSE
%token ARRAY SCANF PRINTF
%token PLUS MINUS TIMES DIVIDE EQUAL SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA AMPERSAND
%token AND OR NOT EQ NE LT LE GT GE IF ELSE FOR WHILE
%token NEWLINE
%token ERROR_TOKEN
%token LBRACKET RBRACKET
%token <ival> NUMBER
%token <sval> IDENTIFIER 
%type <node> declaration_statement control_statement assignment_statement if_statement while_statement for_statement function_call printf_statement
%type <node> expression statement program
%type <sval> type

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%left PLUS MINUS
%left TIMES DIVIDE
%left AND OR
%left EQ NE LT LE GT GE
%nonassoc '(' ')'

%%
program:
    /* Vacío */
    { $$ = NULL; }
    | program statement
    ;

statement:
    assignment_statement
    | declaration_statement
    | control_statement
    | function_call
    | printf_statement
    ;

assignment_statement:
    IDENTIFIER EQUAL expression SEMICOLON {
        $$ = create_assignment_node($1, $3);
    }
    ;

declaration_statement:
    type IDENTIFIER SEMICOLON {
        $$ = create_declaration_node($1, $2);
    }
    ;

type:
    TOK_INT { $$ = strdup("int"); }
    | TOK_BOOLEAN { $$ = strdup("boolean"); }
    ;

control_statement:
    if_statement
    | while_statement
    | for_statement
    ;

if_statement:
    IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
        $$ = create_if_node($3, $5, NULL);
    }
    | IF '(' expression ')' statement ELSE statement {
        $$ = create_if_node($3, $5, $7);
    }
    ;

while_statement:
    WHILE '(' expression ')' statement {
        $$ = create_while_node($3, $5);
    }
    ;

for_statement:
    FOR '(' expression ';' expression ';' expression ')' statement {
        $$ = create_for_node($3, $5, $7, $9);
    }
    ;

function_call:
    IDENTIFIER '(' ')' SEMICOLON {
        $$ = create_function_call_node($1);
    }
    ;

printf_statement:
    PRINTF IDENTIFIER SEMICOLON {
        $$ = create_printf_node($2);
    }
    ;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression TIMES expression
    | expression DIVIDE expression
    | NUMBER {
        $$ = create_constant_node($1);
    }
    | IDENTIFIER {
        $$ = create_identifier_node($1);
    }
    | '(' expression ')' {
        $$ = $2;
    }
    ;
%%

