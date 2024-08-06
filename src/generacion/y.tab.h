/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_GENERACION_Y_TAB_H_INCLUDED
# define YY_YY_SRC_GENERACION_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAIN = 258,                    /* MAIN  */
    FUNCTION = 259,                /* FUNCTION  */
    RETURN = 260,                  /* RETURN  */
    FREE = 261,                    /* FREE  */
    MALLOC = 262,                  /* MALLOC  */
    TOK_INT = 263,                 /* TOK_INT  */
    TOK_BOOLEAN = 264,             /* TOK_BOOLEAN  */
    TOK_CHAR = 265,                /* TOK_CHAR  */
    TOK_FLOAT = 266,               /* TOK_FLOAT  */
    TOK_STRING = 267,              /* TOK_STRING  */
    TOK_TRUE = 268,                /* TOK_TRUE  */
    TOK_FALSE = 269,               /* TOK_FALSE  */
    ERROR_TOKEN = 270,             /* ERROR_TOKEN  */
    PLUS = 271,                    /* PLUS  */
    MINUS = 272,                   /* MINUS  */
    TIMES = 273,                   /* TIMES  */
    DIVIDE = 274,                  /* DIVIDE  */
    EQUAL = 275,                   /* EQUAL  */
    SEMICOLON = 276,               /* SEMICOLON  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    COMMA = 281,                   /* COMMA  */
    AMPERSAND = 282,               /* AMPERSAND  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    NOT = 285,                     /* NOT  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    LT = 288,                      /* LT  */
    LE = 289,                      /* LE  */
    GT = 290,                      /* GT  */
    GE = 291,                      /* GE  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    FOR = 294,                     /* FOR  */
    WHILE = 295,                   /* WHILE  */
    LBRACKET = 296,                /* LBRACKET  */
    RBRACKET = 297,                /* RBRACKET  */
    ARRAY = 298,                   /* ARRAY  */
    SCANF = 299,                   /* SCANF  */
    PRINTF = 300,                  /* PRINTF  */
    NEWLINE = 301,                 /* NEWLINE  */
    NUMBER = 302,                  /* NUMBER  */
    IDENTIFIER = 303,              /* IDENTIFIER  */
    LOWER_THAN_ELSE = 304          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define MAIN 258
#define FUNCTION 259
#define RETURN 260
#define FREE 261
#define MALLOC 262
#define TOK_INT 263
#define TOK_BOOLEAN 264
#define TOK_CHAR 265
#define TOK_FLOAT 266
#define TOK_STRING 267
#define TOK_TRUE 268
#define TOK_FALSE 269
#define ERROR_TOKEN 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define EQUAL 275
#define SEMICOLON 276
#define LPAREN 277
#define RPAREN 278
#define LBRACE 279
#define RBRACE 280
#define COMMA 281
#define AMPERSAND 282
#define AND 283
#define OR 284
#define NOT 285
#define EQ 286
#define NE 287
#define LT 288
#define LE 289
#define GT 290
#define GE 291
#define IF 292
#define ELSE 293
#define FOR 294
#define WHILE 295
#define LBRACKET 296
#define RBRACKET 297
#define ARRAY 298
#define SCANF 299
#define PRINTF 300
#define NEWLINE 301
#define NUMBER 302
#define IDENTIFIER 303
#define LOWER_THAN_ELSE 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "src/syntax.y"

    int ival;                
    char* sval; 
    char* identifier;                 
    struct ASTNode* node;    
    struct Declaration* declaration;
    struct IfExpr* ifExpr;
    struct WhileExpr* whileExpr;
    struct ForLoop* forLoop;
    struct FunctionCall* functionCall;
    struct {
        struct ASTNode* left;
        struct ASTNode* right;
        char* op;
    } binary;

#line 182 "src/generacion/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_GENERACION_Y_TAB_H_INCLUDED  */
