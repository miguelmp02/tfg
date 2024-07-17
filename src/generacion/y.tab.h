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
    TOK_INT = 258,                 /* TOK_INT  */
    TOK_BOOLEAN = 259,             /* TOK_BOOLEAN  */
    TOK_TRUE = 260,                /* TOK_TRUE  */
    TOK_FALSE = 261,               /* TOK_FALSE  */
    ARRAY = 262,                   /* ARRAY  */
    SCANF = 263,                   /* SCANF  */
    PRINTF = 264,                  /* PRINTF  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    TIMES = 267,                   /* TIMES  */
    DIVIDE = 268,                  /* DIVIDE  */
    EQUAL = 269,                   /* EQUAL  */
    SEMICOLON = 270,               /* SEMICOLON  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    COMMA = 275,                   /* COMMA  */
    AMPERSAND = 276,               /* AMPERSAND  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    EQ = 280,                      /* EQ  */
    NE = 281,                      /* NE  */
    LT = 282,                      /* LT  */
    LE = 283,                      /* LE  */
    GT = 284,                      /* GT  */
    GE = 285,                      /* GE  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    FOR = 288,                     /* FOR  */
    WHILE = 289,                   /* WHILE  */
    NEWLINE = 290,                 /* NEWLINE  */
    ERROR_TOKEN = 291,             /* ERROR_TOKEN  */
    LBRACKET = 292,                /* LBRACKET  */
    RBRACKET = 293,                /* RBRACKET  */
    NUMBER = 294,                  /* NUMBER  */
    IDENTIFIER = 295,              /* IDENTIFIER  */
    LOWER_THAN_ELSE = 296          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TOK_INT 258
#define TOK_BOOLEAN 259
#define TOK_TRUE 260
#define TOK_FALSE 261
#define ARRAY 262
#define SCANF 263
#define PRINTF 264
#define PLUS 265
#define MINUS 266
#define TIMES 267
#define DIVIDE 268
#define EQUAL 269
#define SEMICOLON 270
#define LPAREN 271
#define RPAREN 272
#define LBRACE 273
#define RBRACE 274
#define COMMA 275
#define AMPERSAND 276
#define AND 277
#define OR 278
#define NOT 279
#define EQ 280
#define NE 281
#define LT 282
#define LE 283
#define GT 284
#define GE 285
#define IF 286
#define ELSE 287
#define FOR 288
#define WHILE 289
#define NEWLINE 290
#define ERROR_TOKEN 291
#define LBRACKET 292
#define RBRACKET 293
#define NUMBER 294
#define IDENTIFIER 295
#define LOWER_THAN_ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "src/syntax.y"

    int ival;                
    char* sval;              
    struct ASTNode* node;    
    struct Declaration* declaration;
    struct IfExpr* ifExpr;
    struct WhileExpr* whileExpr;
    struct ForLoop* forLoop;
    struct FunctionCall* functionCall;
    char* identifier;    

#line 161 "src/generacion/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_GENERACION_Y_TAB_H_INCLUDED  */
