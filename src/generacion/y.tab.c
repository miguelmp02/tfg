/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/syntax.y"

#include "node.h"
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"
#include "codegen.h"

extern int yylineno;
DataType current_function_type;
DataType data_type;
void yyerror(const char *s);
void yysemanticerror(const char *s);
int yylex(void);

#line 86 "src/generacion/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_FUNCTION = 4,                   /* FUNCTION  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_FREE = 6,                       /* FREE  */
  YYSYMBOL_MALLOC = 7,                     /* MALLOC  */
  YYSYMBOL_TOK_INT = 8,                    /* TOK_INT  */
  YYSYMBOL_TOK_BOOLEAN = 9,                /* TOK_BOOLEAN  */
  YYSYMBOL_TOK_CHAR = 10,                  /* TOK_CHAR  */
  YYSYMBOL_TOK_FLOAT = 11,                 /* TOK_FLOAT  */
  YYSYMBOL_TOK_STRING = 12,                /* TOK_STRING  */
  YYSYMBOL_TOK_TRUE = 13,                  /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 14,                 /* TOK_FALSE  */
  YYSYMBOL_ERROR_TOKEN = 15,               /* ERROR_TOKEN  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 19,                    /* DIVIDE  */
  YYSYMBOL_EQUAL = 20,                     /* EQUAL  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_AMPERSAND = 27,                 /* AMPERSAND  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_LBRACKET = 41,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 42,                  /* RBRACKET  */
  YYSYMBOL_ARRAY = 43,                     /* ARRAY  */
  YYSYMBOL_SCANF = 44,                     /* SCANF  */
  YYSYMBOL_PRINTF = 45,                    /* PRINTF  */
  YYSYMBOL_NEWLINE = 46,                   /* NEWLINE  */
  YYSYMBOL_NUMBER = 47,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 48,                /* IDENTIFIER  */
  YYSYMBOL_LOWER_THAN_ELSE = 49,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_optional_newlines = 58,         /* optional_newlines  */
  YYSYMBOL_class_definition = 59,          /* class_definition  */
  YYSYMBOL_optional_classes = 60,          /* optional_classes  */
  YYSYMBOL_program_body = 61,              /* program_body  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_assignment_statement = 63,      /* assignment_statement  */
  YYSYMBOL_pointer_type = 64,              /* pointer_type  */
  YYSYMBOL_pointer_assignment_statement = 65, /* pointer_assignment_statement  */
  YYSYMBOL_declaration_statement = 66,     /* declaration_statement  */
  YYSYMBOL_array_declaration = 67,         /* array_declaration  */
  YYSYMBOL_array_access = 68,              /* array_access  */
  YYSYMBOL_expression_list = 69,           /* expression_list  */
  YYSYMBOL_dimension_list = 70,            /* dimension_list  */
  YYSYMBOL_printf_statement = 71,          /* printf_statement  */
  YYSYMBOL_scanf_statement = 72,           /* scanf_statement  */
  YYSYMBOL_free_statement = 73,            /* free_statement  */
  YYSYMBOL_return_statement = 74,          /* return_statement  */
  YYSYMBOL_function_definition = 75,       /* function_definition  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_parameter_list = 77,            /* parameter_list  */
  YYSYMBOL_parameter = 78,                 /* parameter  */
  YYSYMBOL_function_body = 79,             /* function_body  */
  YYSYMBOL_function_call = 80,             /* function_call  */
  YYSYMBOL_argument_list = 81,             /* argument_list  */
  YYSYMBOL_type = 82,                      /* type  */
  YYSYMBOL_if_statement = 83,              /* if_statement  */
  YYSYMBOL_if_body = 84,                   /* if_body  */
  YYSYMBOL_else_body = 85,                 /* else_body  */
  YYSYMBOL_while_statement = 86,           /* while_statement  */
  YYSYMBOL_argument_while_list = 87,       /* argument_while_list  */
  YYSYMBOL_while_body = 88,                /* while_body  */
  YYSYMBOL_for_statement = 89,             /* for_statement  */
  YYSYMBOL_argument_for_list = 90,         /* argument_for_list  */
  YYSYMBOL_for_body = 91,                  /* for_body  */
  YYSYMBOL_expression = 92                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   633

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,    54,    52,     2,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    60,    66,    73,    74,    78,    88,    89,
      92,    93,    94,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   115,   137,   164,
     175,   180,   185,   194,   200,   206,   212,   218,   233,   234,
     241,   252,   261,   271,   277,   287,   293,   303,   312,   322,
     331,   344,   345,   351,   354,   360,   369,   375,   384,   393,
     402,   406,   412,   421,   430,   439,   453,   459,   473,   483,
     493,   506,   506,   518,   524,   530,   539,   540,   546,   547,
     559,   560,   561,   565,   585,   586,   587,   593,   597,   601,
     605,   609,   616,   628,   637,   638,   639,   643,   644,   645,
     649,   662,   663,   664,   669,   670,   671,   675,   693,   694,
     695,   701,   702,   703,   707,   722,   737,   752,   767,   782,
     797,   812,   827,   842,   857,   872,   887,   902,   917,   922,
     934,   939,   944,   948,   952
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "FUNCTION",
  "RETURN", "FREE", "MALLOC", "TOK_INT", "TOK_BOOLEAN", "TOK_CHAR",
  "TOK_FLOAT", "TOK_STRING", "TOK_TRUE", "TOK_FALSE", "ERROR_TOKEN",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "EQUAL", "SEMICOLON", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "COMMA", "AMPERSAND", "AND", "OR", "NOT",
  "EQ", "NE", "LT", "LE", "GT", "GE", "IF", "ELSE", "FOR", "WHILE",
  "LBRACKET", "RBRACKET", "ARRAY", "SCANF", "PRINTF", "NEWLINE", "NUMBER",
  "IDENTIFIER", "LOWER_THAN_ELSE", "'('", "')'", "'+'", "'-'", "'*'",
  "'/'", "$accept", "program", "optional_newlines", "class_definition",
  "optional_classes", "program_body", "statement", "assignment_statement",
  "pointer_type", "pointer_assignment_statement", "declaration_statement",
  "array_declaration", "array_access", "expression_list", "dimension_list",
  "printf_statement", "scanf_statement", "free_statement",
  "return_statement", "function_definition", "$@1", "parameter_list",
  "parameter", "function_body", "function_call", "argument_list", "type",
  "if_statement", "if_body", "else_body", "while_statement",
  "argument_while_list", "while_body", "for_statement",
  "argument_for_list", "for_body", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-109)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -160,    14,     0,  -160,  -160,  -160,    -3,  -160,   219,    60,
      15,   -43,  -160,  -160,  -160,  -160,  -160,    29,  -160,    59,
      92,   118,   182,   106,   -17,  -160,   127,   114,  -160,  -160,
    -160,  -160,   163,  -160,  -160,  -160,  -160,  -160,  -160,     5,
    -160,  -160,  -160,   181,    34,   175,   187,   169,   190,   197,
     200,   202,   180,    89,    12,    26,   192,    88,   220,  -160,
     221,   -10,   103,   105,    89,  -160,    89,   199,   224,    27,
     182,   182,   269,  -160,  -160,   218,   226,  -160,  -160,  -160,
      89,   203,  -160,  -160,  -160,    89,    89,  -160,   209,   227,
     153,   157,   597,   174,   597,    89,  -160,  -160,  -160,  -160,
     231,   232,   206,   104,    -9,   236,   513,   151,   597,    38,
     597,   146,   534,   240,  -160,   245,   178,  -160,   223,   179,
     182,   211,   262,   555,  -160,  -160,   265,   576,    89,    89,
      89,    89,    89,    89,  -160,    89,    89,    89,    89,    89,
      89,    89,    89,    89,  -160,    89,  -160,   133,   597,  -160,
    -160,   263,  -160,  -160,  -160,  -160,    89,    89,  -160,  -160,
    -160,  -160,  -160,   182,  -160,  -160,  -160,   215,  -160,  -160,
    -160,    33,  -160,   265,   265,   265,   265,   265,   265,    37,
     265,   265,   265,   265,   265,   265,   265,   265,   597,    54,
     597,   109,    89,   238,  -160,   597,   597,  -160,   110,   111,
    -160,   115,  -160,  -160,  -160,  -160,   597,   266,  -160,  -160,
     117,  -160,   264,   288,   312,   336,  -160,   360,   384,  -160,
     408,  -160,  -160,  -160,   242,  -160,  -160,   244,  -160,  -160,
     249,  -160,  -160,   256,  -160,  -160,  -160,   180,   100,  -160,
    -160,  -160,  -160,   432,  -160,  -160,  -160,   456,   119,  -160,
    -160,   259,  -160,  -160,   480,  -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     5,     6,     4,    10,     3,     0,
       0,     0,    87,    88,    90,    89,    91,     0,     5,     0,
       0,     0,     0,     0,     0,    12,     0,     0,    20,    21,
      14,    25,    26,    15,    16,    24,    23,    13,    22,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,    66,
      64,     0,     8,     0,     0,     0,     0,    61,    62,    38,
      56,     0,     0,     0,     0,    11,     0,     0,    43,     0,
      78,    78,    78,    69,    70,     0,     0,    68,    65,    63,
       0,     2,   134,   130,   131,     0,     0,   128,   129,     0,
       0,     0,   109,     0,   102,     0,    59,    60,    55,    39,
      58,     0,     0,   129,    35,    34,    33,     0,    85,     0,
      51,     0,    36,    47,    42,    45,     0,    76,     0,     0,
      78,     0,     0,    41,     5,     9,   133,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     5,     0,    53,    57,
      32,     0,    29,    28,    27,    83,     0,     0,    50,    31,
      30,    46,    44,    78,     5,    79,     5,     0,     5,    67,
      40,     0,   132,   122,   114,   115,   116,   117,   118,     0,
     126,   127,   119,   120,   121,   123,   124,   125,   110,     0,
     103,     0,     0,     0,    37,    86,    52,    77,     0,     0,
       5,     0,    10,    94,   111,   104,    54,    49,    80,    80,
       0,    80,     0,     0,     0,     0,    48,     0,     0,    71,
       0,     5,     5,    96,     0,   107,   113,     0,   100,   106,
       0,    73,    82,     0,    74,    80,    75,     7,     0,    95,
     112,   105,    81,     0,    97,     5,    72,     0,     0,    93,
      99,     0,    97,    98,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,    -2,  -160,  -160,   112,     1,  -160,   272,  -160,
    -160,  -160,    -8,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,   -65,   152,  -159,    58,  -160,    -5,  -160,  -160,    67,
    -160,  -160,  -160,  -160,  -160,  -160,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   125,    81,     8,   233,    28,    61,    29,
      30,    31,    89,   109,   147,    33,    34,    35,    36,    37,
     235,   116,   117,   217,    38,   107,    39,    40,   213,   247,
      41,    93,   215,    42,    91,   214,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    59,     6,     4,    44,    50,   119,   121,    99,    27,
      92,    94,   152,    82,     3,    58,    52,    56,   106,   108,
     110,     7,   112,    59,   128,    83,    84,    82,    45,    46,
      85,    60,    67,  -108,    86,  -108,   123,    47,   100,    83,
      84,   126,   127,     5,    85,    99,     5,  -101,    86,  -101,
     218,   148,   220,    68,   104,   167,    71,   202,   111,    87,
      88,   203,    48,    49,   157,   118,   118,   118,    12,    13,
      14,    15,    16,    87,    88,   115,   243,    51,   204,     5,
     158,    53,    72,     5,   173,   174,   175,   176,   177,   178,
      82,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       5,   190,    83,    84,    82,    76,    82,    85,    43,    96,
     101,    86,   195,   196,    54,   118,    83,    84,    83,    84,
     105,    85,   171,    85,   244,    86,    63,    86,   -84,    64,
     102,   -84,   179,   205,   208,   209,    87,    88,   245,   211,
      55,   219,   189,   252,   191,    64,     5,    62,   206,    63,
      87,   103,    87,    88,    57,     5,     5,     5,   118,   192,
      65,     5,   198,     5,   199,     5,   201,   159,    64,   129,
     130,   131,   132,   133,   155,   193,   134,   156,   143,   128,
     144,   135,   136,    66,   137,   138,   139,   140,   141,   142,
      12,    13,    14,    15,    16,   145,    73,   146,   210,   163,
     163,   164,   166,    70,    32,    32,    32,    32,    74,    32,
      32,    77,    32,    27,   224,   227,   230,    75,    78,   237,
     238,    79,    80,     9,    10,    11,     5,    12,    13,    14,
      15,    16,   163,    95,   168,    32,   163,    17,   200,    32,
      63,    97,    98,   248,    18,   114,    32,   113,   251,   122,
      64,   124,   149,   150,   151,   251,    19,   153,    20,    21,
     128,   161,    22,    23,    24,    25,   162,    26,     9,    10,
      11,   165,    12,    13,    14,    15,    16,    12,    13,    14,
      15,    16,    17,   169,   194,   133,   207,   216,   239,   221,
     240,   120,     9,    10,    11,   241,    12,    13,    14,    15,
      16,    19,   242,    20,    21,   253,    17,    22,    23,    24,
      25,    69,    26,   222,   212,   197,     9,    10,    11,   254,
      12,    13,    14,    15,    16,    19,     0,    20,    21,     0,
      17,    22,    23,    24,   223,     0,    26,   225,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    19,
       0,    20,    21,     0,    17,    22,    23,    24,   226,     0,
      26,   228,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    19,     0,    20,    21,     0,    17,    22,
      23,    24,   229,     0,    26,   231,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    19,     0,    20,
      21,     0,    17,    22,    23,    24,   232,     0,    26,   234,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    19,     0,    20,    21,     0,    17,    22,    23,    24,
     232,     0,    26,   236,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    19,     0,    20,    21,     0,
      17,    22,    23,    24,   232,     0,    26,   246,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    19,
       0,    20,    21,     0,    17,    22,    23,    24,   232,     0,
      26,   249,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    19,     0,    20,    21,     0,    17,    22,
      23,    24,   250,     0,    26,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    20,
      21,     0,     0,    22,    23,    24,   250,     0,    26,   129,
     130,   131,   132,   133,   154,     0,     0,     0,     0,     0,
       0,   135,   136,     0,   137,   138,   139,   140,   141,   142,
     129,   130,   131,   132,   133,   160,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,   138,   139,   140,   141,
     142,   129,   130,   131,   132,   133,   170,     0,     0,     0,
       0,     0,     0,   135,   136,     0,   137,   138,   139,   140,
     141,   142,   129,   130,   131,   132,   133,     0,     0,   172,
       0,     0,     0,     0,   135,   136,     0,   137,   138,   139,
     140,   141,   142,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,   135,   136,     0,   137,   138,
     139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       8,    18,     4,     3,     9,    48,    71,    72,    18,     8,
      54,    55,    21,     1,     0,    23,    18,    22,    62,    63,
      64,    24,    66,    18,    33,    13,    14,     1,    13,    14,
      18,    48,    27,    21,    22,    23,    80,    22,    48,    13,
      14,    85,    86,    46,    18,    18,    46,    21,    22,    23,
     209,    95,   211,    48,    62,   120,    22,    24,    66,    47,
      48,    24,    47,    48,    26,    70,    71,    72,     8,     9,
      10,    11,    12,    47,    48,    48,   235,    48,    24,    46,
      42,    22,    48,    46,   128,   129,   130,   131,   132,   133,
       1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      46,   145,    13,    14,     1,    47,     1,    18,    48,    21,
       7,    22,   156,   157,    22,   120,    13,    14,    13,    14,
      62,    18,   124,    18,    24,    22,    22,    22,    23,    41,
      27,    26,   134,    24,    24,    24,    47,    48,    38,    24,
      22,    24,   144,    24,   146,    41,    46,    20,   192,    22,
      47,    48,    47,    48,    48,    46,    46,    46,   163,    26,
      46,    46,   164,    46,   166,    46,   168,    21,    41,    16,
      17,    18,    19,    20,    23,    42,    23,    26,    21,    33,
      23,    28,    29,    20,    31,    32,    33,    34,    35,    36,
       8,     9,    10,    11,    12,    21,    21,    23,   200,    21,
      21,    23,    23,    22,   212,   213,   214,   215,    21,   217,
     218,    21,   220,   212,   213,   214,   215,    48,    21,   221,
     222,    21,    20,     4,     5,     6,    46,     8,     9,    10,
      11,    12,    21,    41,    23,   243,    21,    18,    23,   247,
      22,    21,    21,   245,    25,    21,   254,    48,   247,    23,
      41,    48,    21,    21,    48,   254,    37,    21,    39,    40,
      33,    21,    43,    44,    45,    46,    21,    48,     4,     5,
       6,    48,     8,     9,    10,    11,    12,     8,     9,    10,
      11,    12,    18,    21,    21,    20,    48,    21,    46,    25,
      46,    22,     4,     5,     6,    46,     8,     9,    10,    11,
      12,    37,    46,    39,    40,    46,    18,    43,    44,    45,
      46,    39,    48,    25,   202,   163,     4,     5,     6,   252,
       8,     9,    10,    11,    12,    37,    -1,    39,    40,    -1,
      18,    43,    44,    45,    46,    -1,    48,    25,    -1,    -1,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    37,
      -1,    39,    40,    -1,    18,    43,    44,    45,    46,    -1,
      48,    25,    -1,    -1,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    37,    -1,    39,    40,    -1,    18,    43,
      44,    45,    46,    -1,    48,    25,    -1,    -1,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    37,    -1,    39,
      40,    -1,    18,    43,    44,    45,    46,    -1,    48,    25,
      -1,    -1,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    37,    -1,    39,    40,    -1,    18,    43,    44,    45,
      46,    -1,    48,    25,    -1,    -1,     4,     5,     6,    -1,
       8,     9,    10,    11,    12,    37,    -1,    39,    40,    -1,
      18,    43,    44,    45,    46,    -1,    48,    25,    -1,    -1,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    37,
      -1,    39,    40,    -1,    18,    43,    44,    45,    46,    -1,
      48,    25,    -1,    -1,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    37,    -1,    39,    40,    -1,    18,    43,
      44,    45,    46,    -1,    48,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      40,    -1,    -1,    43,    44,    45,    46,    -1,    48,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    16,    17,    18,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    57,    58,     0,     3,    46,    58,    24,    61,     4,
       5,     6,     8,     9,    10,    11,    12,    18,    25,    37,
      39,    40,    43,    44,    45,    46,    48,    62,    63,    65,
      66,    67,    68,    71,    72,    73,    74,    75,    80,    82,
      83,    86,    89,    48,    82,    13,    14,    22,    47,    48,
      48,    48,    58,    22,    22,    22,    82,    48,    68,    18,
      48,    64,    20,    22,    41,    46,    20,    27,    48,    64,
      22,    22,    48,    21,    21,    48,    80,    21,    21,    21,
      20,    60,     1,    13,    14,    18,    22,    47,    48,    68,
      92,    90,    92,    87,    92,    41,    21,    21,    21,    18,
      48,     7,    27,    48,    68,    80,    92,    81,    92,    69,
      92,    68,    92,    48,    21,    48,    77,    78,    82,    77,
      22,    77,    23,    92,    48,    59,    92,    92,    33,    16,
      17,    18,    19,    20,    23,    28,    29,    31,    32,    33,
      34,    35,    36,    21,    23,    21,    23,    70,    92,    21,
      21,    48,    21,    21,    21,    23,    26,    26,    42,    21,
      21,    21,    21,    21,    23,    48,    23,    77,    23,    21,
      21,    58,    23,    92,    92,    92,    92,    92,    92,    58,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    58,
      92,    58,    26,    42,    21,    92,    92,    78,    58,    58,
      23,    58,    24,    24,    24,    24,    92,    48,    24,    24,
      58,    24,    61,    84,    91,    88,    21,    79,    79,    24,
      79,    25,    25,    46,    62,    25,    46,    62,    25,    46,
      62,    25,    46,    62,    25,    76,    25,    58,    58,    46,
      46,    46,    46,    79,    24,    38,    25,    85,    58,    25,
      46,    62,    24,    46,    85,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    76,    75,    75,    75,    75,    77,    77,    78,    78,
      79,    79,    79,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    87,    87,    87,    88,    88,    88,    89,    90,    90,
      90,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     5,     3,     0,     2,     6,     0,     2,
       0,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     5,     1,     2,
       5,     4,     3,     2,     4,     3,     4,     3,     7,     6,
       4,     1,     3,     1,     3,     3,     2,     4,     3,     3,
       3,     2,     2,     3,     2,     3,     2,     5,     3,     3,
       3,     0,    11,     9,     9,     9,     1,     3,     0,     2,
       0,     3,     2,     4,     0,     1,     3,     1,     1,     1,
       1,     1,    14,    12,     0,     3,     2,     0,     3,     2,
       8,     0,     1,     3,     0,     3,     2,     8,     0,     1,
       3,     0,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: optional_newlines MAIN optional_newlines LBRACE program_body RBRACE optional_newlines optional_classes  */
#line 56 "src/syntax.y"
                                                                                                          {
        //printf("Programa main procesado correctamente en la linea %d.\n", yylineno);
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1421 "src/generacion/y.tab.c"
    break;

  case 3: /* program: optional_newlines MAIN optional_newlines LBRACE program_body  */
#line 60 "src/syntax.y"
                                                                   {
        printf("Error: falta RBRACE para cerrar el main en la linea %d.\n", yylineno);
        yyerror("Falta RBRACE para cerrar el main");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1432 "src/generacion/y.tab.c"
    break;

  case 4: /* program: optional_newlines MAIN optional_newlines  */
#line 66 "src/syntax.y"
                                               {
        printf("Error: falta LBRACE para abrir el main en la linea %d.\n", yylineno);
        yyerror("Falta LBRACE abrir el main");
        (yyval.node) = NULL;
    }
#line 1442 "src/generacion/y.tab.c"
    break;

  case 7: /* class_definition: IDENTIFIER optional_newlines LBRACE program_body RBRACE optional_newlines  */
#line 79 "src/syntax.y"
    {
        if (find_symbol((yyvsp[-5].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador de clase previamente declarado");
        } else {
            insert_symbol((yyvsp[-5].sval),0,0);
            //printf("Definiendo clase '%s' en la línea %d.\n", $1, yylineno);
        }
    }
#line 1455 "src/generacion/y.tab.c"
    break;

  case 10: /* program_body: %empty  */
#line 92 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 1461 "src/generacion/y.tab.c"
    break;

  case 11: /* program_body: program_body statement NEWLINE  */
#line 93 "src/syntax.y"
                                     { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1467 "src/generacion/y.tab.c"
    break;

  case 12: /* program_body: program_body NEWLINE  */
#line 94 "src/syntax.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1473 "src/generacion/y.tab.c"
    break;

  case 27: /* assignment_statement: IDENTIFIER EQUAL expression SEMICOLON  */
#line 115 "src/syntax.y"
                                          {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else if ((yyvsp[-1].node) == NULL) {
            yysemanticerror("Error semantico: Expresion no definida");
            printf("Error semantico en la linea %d: Expresion no definida para la asignacion a '%s'.\n", yylineno, (yyvsp[-3].sval));
            (yyval.node) = NULL;
        } else {
          //  printf("Debug: Tipo del simbolo '%s': %d, Tipo de la expresion: %d\n", $1, symbol->type, $3->data_type);
            if (symbol->type != (yyvsp[-1].node)->data_type) {
                yysemanticerror("Error semantico: Tipo de identificador incompatible en la asignacion.");
                printf("Error semantico en la linea %d: Tipo de identificador incompatible en la asignacion. Tipo de '%s': %d, Tipo de expresion: %d\n", yylineno, (yyvsp[-3].sval), symbol->type, (yyvsp[-1].node)->data_type);
                (yyval.node) = NULL;
            } else {
               // printf("Asignando a '%s' el resultado de la expresion en la linea %d.\n", $1, yylineno);
                (yyval.node) = create_assignment_node((yyvsp[-3].sval), (yyvsp[-1].node));
                generate_quad(OP_ASSIGN, extract_identifier((yyvsp[-1].node)), "", (yyvsp[-3].sval));
            }
        }
    }
#line 1500 "src/generacion/y.tab.c"
    break;

  case 28: /* assignment_statement: IDENTIFIER EQUAL function_call SEMICOLON  */
#line 137 "src/syntax.y"
                                               {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        Symbol *func_symbol = find_symbol((yyvsp[-1].node)->data.functionCall.functionName);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico en la linea %d: Identificador \"%s\" no declarado previamente.\n", yylineno, (yyvsp[-3].sval));
        } else if (func_symbol == NULL) {
            yysemanticerror("Error semantico: Funcion no declarada previamente");
            printf("Error semantico en la linea %d: Funcion \"%s\" no declarada previamente.\n", yylineno, (yyvsp[-1].node)->data.functionCall.functionName);
        } else if ((yyvsp[-1].node) == NULL) {
            yysemanticerror("Error semantico: Expresion no definida");
            printf("Error semantico en la linea %d: Expresion no definida para la asignacion a '%s'.\n", yylineno, (yyvsp[-3].sval));
            (yyval.node) = NULL;
        } else if ((yyvsp[-1].node)->data_type == -1) {
            yysemanticerror("Error semantico: Tipo de expresion no definido");
            printf("Error semantico en la linea %d: Tipo de expresion no definido para la asignacion a '%s'.\n", yylineno, (yyvsp[-3].sval));
            (yyval.node) = NULL;
        } else if (symbol->type != func_symbol->type) {
            yysemanticerror("Error semantico: Tipo de identificador incompatible en la asignacion.");
            printf("Error semantico en la linea %d: Tipo de identificador incompatible en la asignacion. Tipo de '%s': %d, Tipo de funcion: %d\n", yylineno, (yyvsp[-3].sval), symbol->type, func_symbol->type);
            (yyval.node) = NULL;
        } else {
           // printf("Asignando a '%s' el resultado de la llamada a funcion en la linea %d.\n", $1, yylineno);
            (yyval.node) = create_assignment_node((yyvsp[-3].sval), (yyvsp[-1].node));
            generate_quad(OP_ASSIGN, (yyvsp[-1].node)->data.functionCall.functionName, "", (yyvsp[-3].sval));
        }
    }
#line 1532 "src/generacion/y.tab.c"
    break;

  case 29: /* assignment_statement: IDENTIFIER EQUAL array_access SEMICOLON  */
#line 164 "src/syntax.y"
                                              {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else {
           // printf("Asignando a '%s' el resultado de la llamada a array en la linea %d.\n", $1, yylineno);
            (yyval.node) = create_assignment_node((yyvsp[-3].sval), (yyvsp[-1].node));
            generate_quad(OP_ASSIGN, extract_identifier((yyvsp[-1].node)), "", (yyvsp[-3].sval));
        }
    }
#line 1548 "src/generacion/y.tab.c"
    break;

  case 30: /* assignment_statement: array_access EQUAL expression SEMICOLON  */
#line 175 "src/syntax.y"
                                              {
        //printf("Asignando al array el resultado en la linea %d.\n", yylineno);
        (yyval.node) = create_assignment_node_array((yyvsp[-3].node), (yyvsp[-1].node));
        generate_quad(OP_ASSIGN, extract_identifier((yyvsp[-1].node)), "", extract_identifier((yyvsp[-3].node)));
    }
#line 1558 "src/generacion/y.tab.c"
    break;

  case 31: /* assignment_statement: array_access EQUAL array_access SEMICOLON  */
#line 180 "src/syntax.y"
                                                {
       // printf("Asignando al array el resultado en la linea %d.\n", yylineno);
        (yyval.node) = create_assignment_node_array((yyvsp[-3].node), (yyvsp[-1].node));
        generate_quad(OP_ASSIGN, extract_identifier((yyvsp[-1].node)), "", extract_identifier((yyvsp[-3].node)));
    }
#line 1568 "src/generacion/y.tab.c"
    break;

  case 32: /* assignment_statement: IDENTIFIER EQUAL MALLOC SEMICOLON  */
#line 185 "src/syntax.y"
                                        {
        if (find_symbol((yyvsp[-3].sval)) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else {
            //printf("Asignando al identifier malloc en la linea %d.\n", $1, yylineno);
            (yyval.node) = create_assignment_node((yyvsp[-3].sval), 0);
        }   
    }
#line 1582 "src/generacion/y.tab.c"
    break;

  case 33: /* assignment_statement: IDENTIFIER EQUAL expression  */
#line 194 "src/syntax.y"
                                  {
        printf("Error: falta ';' despues de la asignacion de '%s' en la linea %d.\n", (yyvsp[-2].sval), yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1593 "src/generacion/y.tab.c"
    break;

  case 34: /* assignment_statement: IDENTIFIER EQUAL function_call  */
#line 200 "src/syntax.y"
                                     {
        printf("Error: falta ';' despues de la llamada a funcion asignada a '%s' en la linea %d.\n", (yyvsp[-2].sval), yylineno);
        yyerror("Falta ';' despues de la llamada a funcion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1604 "src/generacion/y.tab.c"
    break;

  case 35: /* assignment_statement: IDENTIFIER EQUAL array_access  */
#line 206 "src/syntax.y"
                                    {
        printf("Error: falta ';' despues del array en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues del array");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1615 "src/generacion/y.tab.c"
    break;

  case 36: /* assignment_statement: array_access EQUAL expression  */
#line 212 "src/syntax.y"
                                    {
        printf("Error: falta ';' despues de la asignacion en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1626 "src/generacion/y.tab.c"
    break;

  case 37: /* assignment_statement: IDENTIFIER EQUAL AMPERSAND IDENTIFIER SEMICOLON  */
#line 218 "src/syntax.y"
                                                      {
        Symbol *symbol1 = find_symbol((yyvsp[-4].sval));
        Symbol *symbol2 = find_symbol((yyvsp[-1].sval));
        if (symbol1 == NULL || symbol2 == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" o \"%s\" no declarado previamente.\n", (yyvsp[-4].sval), (yyvsp[-1].sval));
        } else {
            printf("Asignando a '%s' la dirección de '%s' en la linea %d.\n", (yyvsp[-4].sval), (yyvsp[-1].sval), yylineno);
            (yyval.node) = create_assignment_node_ampersand((yyvsp[-4].sval), (yyvsp[-1].sval));
            generate_quad(OP_ASSIGN, (yyvsp[-1].sval), "", (yyvsp[-4].sval));
        }
    }
#line 1643 "src/generacion/y.tab.c"
    break;

  case 38: /* pointer_type: TIMES  */
#line 233 "src/syntax.y"
            { (yyval.node) = create_pointer_node(1); }
#line 1649 "src/generacion/y.tab.c"
    break;

  case 39: /* pointer_type: pointer_type TIMES  */
#line 234 "src/syntax.y"
                         {
        (yyval.node) = increase_pointer_level((yyvsp[-1].node)); 
       // printf("Annadiendo un nivel de puntero, total ahora es %d.\n", $$->data.pointer_level);
    }
#line 1658 "src/generacion/y.tab.c"
    break;

  case 40: /* pointer_assignment_statement: TIMES IDENTIFIER EQUAL expression SEMICOLON  */
#line 241 "src/syntax.y"
                                                {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else {
            //printf("Asignacion de puntero para '%s' en linea %d.\n", $2, yylineno);
            (yyval.node) = create_pointer_assignment_node((yyvsp[-3].sval), (yyvsp[-1].node));
            generate_quad(OP_ASSIGN, extract_identifier((yyvsp[-1].node)), "", (yyvsp[-3].sval));
        }
    }
#line 1674 "src/generacion/y.tab.c"
    break;

  case 41: /* pointer_assignment_statement: TIMES IDENTIFIER EQUAL expression  */
#line 252 "src/syntax.y"
                                        {
        printf("Error: falta ';' despues de la asignacion de '%s' en la linea %d.\n", (yyvsp[-2].sval), yylineno);
        yyerror("Falta ';' despues de la asignacion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1685 "src/generacion/y.tab.c"
    break;

  case 42: /* declaration_statement: type IDENTIFIER SEMICOLON  */
#line 261 "src/syntax.y"
                              {
        if (find_symbol((yyvsp[-1].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            insert_symbol((yyvsp[-1].sval), convert_data_type((yyvsp[-2].sval)),0);
            //printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $2, $1, yylineno);
            (yyval.node) = create_declaration_node((yyvsp[-2].sval), (yyvsp[-1].sval), 0);
        }
    }
#line 1700 "src/generacion/y.tab.c"
    break;

  case 43: /* declaration_statement: type IDENTIFIER  */
#line 271 "src/syntax.y"
                      {
        printf("Error: falta ';' despues de la declaracion de '%s' en la linea %d.\n", (yyvsp[0].sval), yylineno);
        yyerror("Falta ';' despues de la declaracion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1711 "src/generacion/y.tab.c"
    break;

  case 44: /* declaration_statement: type pointer_type IDENTIFIER SEMICOLON  */
#line 277 "src/syntax.y"
                                             {
        if (find_symbol((yyvsp[-1].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            insert_symbol((yyvsp[-1].sval), convert_data_type((yyvsp[-3].sval)),0);
           // printf("Declarando puntero '%s' de tipo '%s' con %d niveles de puntero en la linea %d.\n", $3, $1, $2->data.pointer_level, yylineno);
            (yyval.node) = create_declaration_node((yyvsp[-3].sval), (yyvsp[-1].sval), (yyvsp[-2].node)->data.pointer_level);
        }
    }
#line 1726 "src/generacion/y.tab.c"
    break;

  case 45: /* declaration_statement: type pointer_type IDENTIFIER  */
#line 287 "src/syntax.y"
                                   {
        printf("Error: falta ';' despues de la declaracion del puntero de '%s' en la linea %d.\n", (yyvsp[0].sval), yylineno);
        yyerror("Falta ';' despues de la declaracion del puntero");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1737 "src/generacion/y.tab.c"
    break;

  case 46: /* declaration_statement: type AMPERSAND IDENTIFIER SEMICOLON  */
#line 293 "src/syntax.y"
                                          {
        if (find_symbol((yyvsp[-1].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            insert_symbol((yyvsp[-1].sval), convert_data_type((yyvsp[-3].sval)),0);
            //printf("Declarando variable '%s' de tipo '%s' en la linea %d.\n", $3, $1, yylineno);
            (yyval.node) = create_declaration_node((yyvsp[-3].sval), (yyvsp[-1].sval), 0);
        }
    }
#line 1752 "src/generacion/y.tab.c"
    break;

  case 47: /* declaration_statement: type AMPERSAND IDENTIFIER  */
#line 303 "src/syntax.y"
                                {
        printf("Error: falta ';' despues de la declaracion de '%s' en la linea %d.\n", (yyvsp[0].sval), yylineno);
        yyerror("Falta ';' despues de la declaracion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1763 "src/generacion/y.tab.c"
    break;

  case 48: /* array_declaration: ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER SEMICOLON  */
#line 312 "src/syntax.y"
                                                                      {
        if (find_symbol((yyvsp[-1].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            insert_symbol((yyvsp[-1].sval), convert_data_type((yyvsp[-5].sval)), 0);
            (yyval.node) = create_array_node((yyvsp[-5].sval), (yyvsp[-3].node), (yyvsp[-1].sval));
           // printf("Declaración de array de tipo '%s' con identificador '%s' en la linea %d.\n", $2, $6, yylineno);
        }
    }
#line 1778 "src/generacion/y.tab.c"
    break;

  case 49: /* array_declaration: ARRAY type LBRACKET dimension_list RBRACKET IDENTIFIER  */
#line 322 "src/syntax.y"
                                                            {
        printf("Error: falta ';' al final de la array de '%s' en la linea %d.\n", (yyvsp[-4].sval), yylineno);
        yyerror("Falta ';' al final de la array");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1789 "src/generacion/y.tab.c"
    break;

  case 50: /* array_access: IDENTIFIER LBRACKET expression_list RBRACKET  */
#line 331 "src/syntax.y"
                                                 {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else {
            (yyval.node) = create_array_access_node((yyvsp[-3].sval), (yyvsp[-1].node));
             (yyval.node)->data_type = symbol->type;
            //printf("Acceso a array '%s' de tipo '%d' en la linea %d.\n", $1, symbol->type, yylineno);
        }
    }
#line 1805 "src/generacion/y.tab.c"
    break;

  case 52: /* expression_list: expression_list COMMA expression  */
#line 345 "src/syntax.y"
                                       {
        (yyval.node) = combine_expressions((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1813 "src/generacion/y.tab.c"
    break;

  case 53: /* dimension_list: expression  */
#line 351 "src/syntax.y"
               {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1821 "src/generacion/y.tab.c"
    break;

  case 54: /* dimension_list: dimension_list COMMA expression  */
#line 354 "src/syntax.y"
                                      {
        (yyval.node) = create_dimension_list((yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 1829 "src/generacion/y.tab.c"
    break;

  case 55: /* printf_statement: PRINTF IDENTIFIER SEMICOLON  */
#line 360 "src/syntax.y"
                                {
        if (find_symbol((yyvsp[-1].sval)) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            //printf("Llamando a 'printf' con '%s' en la linea %d.\n", $2, yylineno);
            (yyval.node) = create_printf_node((yyvsp[-1].sval));
        }
    }
#line 1843 "src/generacion/y.tab.c"
    break;

  case 56: /* printf_statement: PRINTF IDENTIFIER  */
#line 369 "src/syntax.y"
                        {
        printf("Error: falta ';' despues de un printf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un printf");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1854 "src/generacion/y.tab.c"
    break;

  case 57: /* printf_statement: PRINTF pointer_type IDENTIFIER SEMICOLON  */
#line 375 "src/syntax.y"
                                               {
        if (find_symbol((yyvsp[-1].sval)) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-1].sval));
        } else {
           // printf("Llamando a 'printf' con '%s' en la linea %d.\n", $3, yylineno);
            (yyval.node) = create_printf_node((yyvsp[-1].sval));
        }
    }
#line 1868 "src/generacion/y.tab.c"
    break;

  case 58: /* printf_statement: PRINTF pointer_type IDENTIFIER  */
#line 384 "src/syntax.y"
                                     {
        printf("Error: falta ';' despues de un printf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un printf");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1879 "src/generacion/y.tab.c"
    break;

  case 59: /* scanf_statement: SCANF IDENTIFIER SEMICOLON  */
#line 393 "src/syntax.y"
                               {
        if (find_symbol((yyvsp[-1].sval)) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-1].sval));
        } else {
            //printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
            (yyval.node) = create_scanf_node((yyvsp[-1].sval));
        }
    }
#line 1893 "src/generacion/y.tab.c"
    break;

  case 60: /* scanf_statement: SCANF array_access SEMICOLON  */
#line 402 "src/syntax.y"
                                   {
        //printf("Llamando a 'scanf' con '%s' en la linea %d.\n", $2, yylineno);
        (yyval.node) = create_scanf_node_array((yyvsp[-1].node));
    }
#line 1902 "src/generacion/y.tab.c"
    break;

  case 61: /* scanf_statement: SCANF IDENTIFIER  */
#line 406 "src/syntax.y"
                       {
        printf("Error: falta ';' despues de un f scanf la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un scanf");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1913 "src/generacion/y.tab.c"
    break;

  case 62: /* scanf_statement: SCANF array_access  */
#line 412 "src/syntax.y"
                         {
        printf("Error: falta ';' despues de un scanf en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un scanf");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1924 "src/generacion/y.tab.c"
    break;

  case 63: /* free_statement: FREE IDENTIFIER SEMICOLON  */
#line 421 "src/syntax.y"
                              {
        if (find_symbol((yyvsp[-1].sval)) == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Error identificador \"%s\" no declarado previamente.\n", (yyvsp[-1].sval));
        } else {
           // printf("Llamando a 'free' con '%s' en la linea %d.\n", $2, yylineno);
            (yyval.node) = create_free_node((yyvsp[-1].sval));
        }
    }
#line 1938 "src/generacion/y.tab.c"
    break;

  case 64: /* free_statement: FREE IDENTIFIER  */
#line 430 "src/syntax.y"
                      {
        printf("Error: falta ';' despues de un free en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un free");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1949 "src/generacion/y.tab.c"
    break;

  case 65: /* return_statement: RETURN IDENTIFIER SEMICOLON  */
#line 439 "src/syntax.y"
                                {
        Symbol *symbol = find_symbol((yyvsp[-1].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Identificador \"%s\" no declarado previamente.\n", (yyvsp[-1].sval));
        } else if (symbol->type != current_function_type) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de '%s': %d, Tipo esperado: %d\n", (yyvsp[-1].sval), symbol->type, current_function_type);
            (yyval.node) = NULL;           
        } else {
           // printf("Declaracion de retorno en la linea %d. Tipo de '%s': %d\n", yylineno, $2, symbol->type);
            (yyval.node) = create_return_node((yyvsp[-1].sval), NULL);
        }
    }
#line 1968 "src/generacion/y.tab.c"
    break;

  case 66: /* return_statement: RETURN IDENTIFIER  */
#line 453 "src/syntax.y"
                        {
        printf("Error: falta ';' despues de un return en la linea %d.\n", yylineno);
        yyerror("Falta ';' despues de un return");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1979 "src/generacion/y.tab.c"
    break;

  case 67: /* return_statement: RETURN LPAREN function_call RPAREN SEMICOLON  */
#line 459 "src/syntax.y"
                                                   {
        Symbol *symbol = find_symbol((yyvsp[-2].node)->data.functionCall.functionName);
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador de funcion no declarado previamente");
            (yyval.node) = NULL;
        } else if (symbol->type != current_function_type) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de funcion '%s': %d, Tipo esperado: %d\n", (yyvsp[-2].node)->data.functionCall.functionName, symbol->type, current_function_type);
            (yyval.node) = NULL;
        } else {
           // printf("Declaracion de retorno en la linea %d.\n", yylineno);
            (yyval.node) = create_return_node(NULL, (yyvsp[-2].node));
        }
    }
#line 1998 "src/generacion/y.tab.c"
    break;

  case 68: /* return_statement: RETURN NUMBER SEMICOLON  */
#line 473 "src/syntax.y"
                              {
        if (current_function_type != TYPE_INT) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: int, Tipo esperado: %d\n", current_function_type);
            (yyval.node) = NULL;
        } else {
            //printf("Declaracion de retorno en la linea %d.\n", yylineno);
            (yyval.node) = create_constant_node((yyvsp[-1].ival));
        }
    }
#line 2013 "src/generacion/y.tab.c"
    break;

  case 69: /* return_statement: RETURN TOK_TRUE SEMICOLON  */
#line 483 "src/syntax.y"
                                {
        if (current_function_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: boolean, Tipo esperado: %d\n", current_function_type);
            (yyval.node) = NULL;
        } else {
            (yyval.node) = create_constant_node(1);
            //printf("Valor booleano 'true' detectado en la linea %d.\n", yylineno);
        }
    }
#line 2028 "src/generacion/y.tab.c"
    break;

  case 70: /* return_statement: RETURN TOK_FALSE SEMICOLON  */
#line 493 "src/syntax.y"
                                 {
        if (current_function_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Tipo de retorno incompatible.");
            printf("Error semantico: Tipo de retorno incompatible. Tipo de retorno: boolean, Tipo esperado: %d\n", current_function_type);
            (yyval.node) = NULL;
        } else {
            (yyval.node) = create_constant_node(0);
          //  printf("Valor booleano 'false' detectado en la linea %d.\n", yylineno);
        }
    }
#line 2043 "src/generacion/y.tab.c"
    break;

  case 71: /* $@1: %empty  */
#line 506 "src/syntax.y"
                                                                                   {
        if (find_symbol((yyvsp[-5].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador de funcion previamente declarado");
        } else {
            int num_parameters = count_parameters((yyvsp[-3].node));
            current_function_type = convert_data_type((yyvsp[-6].sval));
            insert_symbol((yyvsp[-5].sval), convert_data_type((yyvsp[-6].sval)), num_parameters);
           // printf("Declaracion de funcion '%s' con tipo '%s' en la linea %d.\n", $3, $2, yylineno);
        }
    }
#line 2058 "src/generacion/y.tab.c"
    break;

  case 72: /* function_definition: FUNCTION type IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE $@1 function_body RBRACE  */
#line 515 "src/syntax.y"
                           {
        //printf("Definicion de funcion '%s' con tipo '%s' y retorno asegurado en la linea %d.\n", $3, $2, yylineno);
    }
#line 2066 "src/generacion/y.tab.c"
    break;

  case 73: /* function_definition: FUNCTION IDENTIFIER LPAREN parameter_list RPAREN optional_newlines LBRACE function_body RBRACE  */
#line 518 "src/syntax.y"
                                                                                                    {
        printf("Error: falta definir el tipo de funcion en la linea %d.\n", yylineno);
        yyerror("Falta definir el tipo de funcion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2077 "src/generacion/y.tab.c"
    break;

  case 74: /* function_definition: FUNCTION type LPAREN parameter_list RPAREN optional_newlines LBRACE function_body RBRACE  */
#line 524 "src/syntax.y"
                                                                                              {
        printf("Error: falta definir el identificador de funcion en la linea %d.\n", yylineno);
        yyerror("Falta definir el identificador de function");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2088 "src/generacion/y.tab.c"
    break;

  case 75: /* function_definition: FUNCTION type IDENTIFIER parameter_list RPAREN optional_newlines LBRACE function_body RBRACE  */
#line 530 "src/syntax.y"
                                                                                                  {
        printf("Error: falta LPAREN para definir parametros de la funcion en la linea %d.\n", yylineno);
        yyerror("Falta LPAREN para definir parametros de la funcion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2099 "src/generacion/y.tab.c"
    break;

  case 77: /* parameter_list: parameter_list SEMICOLON parameter  */
#line 540 "src/syntax.y"
                                         {
        (yyval.node) = combine_parameter_nodes((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2107 "src/generacion/y.tab.c"
    break;

  case 78: /* parameter: %empty  */
#line 546 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2113 "src/generacion/y.tab.c"
    break;

  case 79: /* parameter: type IDENTIFIER  */
#line 547 "src/syntax.y"
                      {
        if (find_symbol((yyvsp[0].sval)) != NULL) {
            yysemanticerror("Error semantico: Identificador previamente declarado");
            printf("Error semantico: Error identificador \"%s\" ya declarado previamente.\n", (yyvsp[0].sval));
        } else {
            insert_symbol((yyvsp[0].sval), convert_data_type((yyvsp[-1].sval)),0);
            (yyval.node) = create_parameter_node((yyvsp[-1].sval), (yyvsp[0].sval));
        }
    }
#line 2127 "src/generacion/y.tab.c"
    break;

  case 80: /* function_body: %empty  */
#line 559 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2133 "src/generacion/y.tab.c"
    break;

  case 81: /* function_body: function_body statement NEWLINE  */
#line 560 "src/syntax.y"
                                      { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2139 "src/generacion/y.tab.c"
    break;

  case 83: /* function_call: IDENTIFIER LPAREN argument_list RPAREN  */
#line 565 "src/syntax.y"
                                           {
        Symbol *symbol = find_symbol((yyvsp[-3].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico: Identificador \"%s\" no declarado previamente.\n", (yyvsp[-3].sval));
        } else {
            int num_arguments = count_arguments((yyvsp[-1].node));
            if (num_arguments != symbol->num_parameters) {
                yysemanticerror("Error semantico: Numero incorrecto de argumentos en la llamada a la funcion");
                printf("Error semantico: Numero incorrecto de argumentos en la llamada a la funcion '%s'. Esperados %d, encontrados %d en la linea %d.\n", (yyvsp[-3].sval), symbol->num_parameters, num_arguments, yylineno);
            } else {
              //  printf("Llamada a la funcion '%s' con argumentos en la linea %d.\n", $1, yylineno);
                (yyval.node) = create_function_call_node((yyvsp[-3].sval), (yyvsp[-1].node));
            }
        }
    }
#line 2160 "src/generacion/y.tab.c"
    break;

  case 84: /* argument_list: %empty  */
#line 585 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2166 "src/generacion/y.tab.c"
    break;

  case 86: /* argument_list: argument_list COMMA expression  */
#line 587 "src/syntax.y"
                                     {
        (yyval.node) = combine_argument_nodes((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2174 "src/generacion/y.tab.c"
    break;

  case 87: /* type: TOK_INT  */
#line 593 "src/syntax.y"
            {
        (yyval.sval) = strdup("int");
       // printf("Tipo detectado: int en la linea %d.\n", yylineno);
    }
#line 2183 "src/generacion/y.tab.c"
    break;

  case 88: /* type: TOK_BOOLEAN  */
#line 597 "src/syntax.y"
                  {
        (yyval.sval) = strdup("boolean");
        //printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
#line 2192 "src/generacion/y.tab.c"
    break;

  case 89: /* type: TOK_FLOAT  */
#line 601 "src/syntax.y"
                {
        (yyval.sval) = strdup("float");
       // printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
#line 2201 "src/generacion/y.tab.c"
    break;

  case 90: /* type: TOK_CHAR  */
#line 605 "src/syntax.y"
               {
        (yyval.sval) = strdup("char");
        //printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
#line 2210 "src/generacion/y.tab.c"
    break;

  case 91: /* type: TOK_STRING  */
#line 609 "src/syntax.y"
                 {
        (yyval.sval) = strdup("string");
       // printf("Tipo detectado: boolean en la linea %d.\n", yylineno);
    }
#line 2219 "src/generacion/y.tab.c"
    break;

  case 92: /* if_statement: IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines ELSE optional_newlines LBRACE else_body RBRACE  */
#line 616 "src/syntax.y"
                                                                                                                                         {
       // printf("Entrando a la sentencia 'if-else' en linea %d.\n", yylineno);
        char label_else[20], label_end[20];
        sprintf(label_else, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier((yyvsp[-11].node)), "", label_else);
        (yyval.node) = (yyvsp[-7].node);
        generate_quad(OP_JUMP, "", "", label_end);
        generate_quad(OP_LABEL, label_else, "", "");
        (yyval.node) = (yyvsp[-1].node);
        generate_quad(OP_LABEL, label_end, "", "");
    }
#line 2236 "src/generacion/y.tab.c"
    break;

  case 93: /* if_statement: IF LPAREN expression RPAREN optional_newlines LBRACE if_body RBRACE optional_newlines LBRACE else_body RBRACE  */
#line 628 "src/syntax.y"
                                                                                                                    {
        printf("Error: falta ELSE para definir parametros de la funcion en la linea %d.\n", yylineno);
        yyerror("Falta ELSE para definir parametros de la funcion");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2247 "src/generacion/y.tab.c"
    break;

  case 94: /* if_body: %empty  */
#line 637 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2253 "src/generacion/y.tab.c"
    break;

  case 95: /* if_body: if_body statement NEWLINE  */
#line 638 "src/syntax.y"
                                { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2259 "src/generacion/y.tab.c"
    break;

  case 96: /* if_body: if_body NEWLINE  */
#line 639 "src/syntax.y"
                      { (yyval.node) = (yyvsp[-1].node); }
#line 2265 "src/generacion/y.tab.c"
    break;

  case 97: /* else_body: %empty  */
#line 643 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2271 "src/generacion/y.tab.c"
    break;

  case 98: /* else_body: else_body statement NEWLINE  */
#line 644 "src/syntax.y"
                                  { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2277 "src/generacion/y.tab.c"
    break;

  case 99: /* else_body: else_body NEWLINE  */
#line 645 "src/syntax.y"
                        { (yyval.node) = (yyvsp[-1].node); }
#line 2283 "src/generacion/y.tab.c"
    break;

  case 100: /* while_statement: WHILE LPAREN argument_while_list RPAREN optional_newlines LBRACE while_body RBRACE  */
#line 649 "src/syntax.y"
                                                                                       {
        //printf("Procesando una sentencia 'while' en la linea %d.\n", yylineno);
        char label_start[20], label_end[20];
        sprintf(label_start, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        generate_quad(OP_LABEL, label_start, "", "");
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier((yyvsp[-5].node)), "", label_end);
        (yyval.node) = (yyvsp[-1].node);
        generate_quad(OP_JUMP, "", "", label_start);
        generate_quad(OP_LABEL, label_end, "", "");
    }
#line 2299 "src/generacion/y.tab.c"
    break;

  case 101: /* argument_while_list: %empty  */
#line 662 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2305 "src/generacion/y.tab.c"
    break;

  case 103: /* argument_while_list: argument_while_list SEMICOLON expression  */
#line 664 "src/syntax.y"
                                               {
        (yyval.node) = combine_argument_nodes((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2313 "src/generacion/y.tab.c"
    break;

  case 104: /* while_body: %empty  */
#line 669 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2319 "src/generacion/y.tab.c"
    break;

  case 105: /* while_body: while_body statement NEWLINE  */
#line 670 "src/syntax.y"
                                   { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2325 "src/generacion/y.tab.c"
    break;

  case 107: /* for_statement: FOR LPAREN argument_for_list RPAREN optional_newlines LBRACE for_body RBRACE  */
#line 675 "src/syntax.y"
                                                                                 {
       // printf("Procesando una sentencia 'for' en la linea %d.\n", yylineno);
        char label_start[20], label_end[20], label_increment[20];
        sprintf(label_start, "L%d", new_label());
        sprintf(label_end, "L%d", new_label());
        sprintf(label_increment, "L%d", new_label());
        (yyval.node) = (yyvsp[-5].node);
        generate_quad(OP_LABEL, label_start, "", "");
        generate_quad(OP_JUMP_IF_FALSE, extract_identifier((yyvsp[-5].node)), "", label_end);
        (yyval.node) = (yyvsp[-1].node);
        generate_quad(OP_LABEL, label_increment, "", "");
        (yyval.node) = (yyvsp[-5].node);
        generate_quad(OP_JUMP, "", "", label_start);
        generate_quad(OP_LABEL, label_end, "", "");
    }
#line 2345 "src/generacion/y.tab.c"
    break;

  case 108: /* argument_for_list: %empty  */
#line 693 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2351 "src/generacion/y.tab.c"
    break;

  case 110: /* argument_for_list: argument_for_list SEMICOLON expression  */
#line 695 "src/syntax.y"
                                             {
        (yyval.node) = combine_argument_nodes((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2359 "src/generacion/y.tab.c"
    break;

  case 111: /* for_body: %empty  */
#line 701 "src/syntax.y"
    { (yyval.node) = NULL; }
#line 2365 "src/generacion/y.tab.c"
    break;

  case 112: /* for_body: for_body statement NEWLINE  */
#line 702 "src/syntax.y"
                                 { (yyval.node) = combine_nodes((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2371 "src/generacion/y.tab.c"
    break;

  case 114: /* expression: expression PLUS expression  */
#line 707 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion PLUS solo permitida entre enteros.");
            printf("Error semantico: Operacion PLUS solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Operacion PLUS en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("+", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_INT;
            generate_quad(OP_ADD, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2391 "src/generacion/y.tab.c"
    break;

  case 115: /* expression: expression MINUS expression  */
#line 722 "src/syntax.y"
                                  {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion MINUS solo permitida entre enteros.");
            printf("Error semantico: Operacion MINUS solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
          //  printf("Operacion MINUS en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("-", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_INT;
            generate_quad(OP_SUB, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2411 "src/generacion/y.tab.c"
    break;

  case 116: /* expression: expression TIMES expression  */
#line 737 "src/syntax.y"
                                  {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion TIMES solo permitida entre enteros.");
            printf("Error semantico: Operacion TIMES solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Operacion TIMES en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("*", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_INT;
            generate_quad(OP_MUL, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2431 "src/generacion/y.tab.c"
    break;

  case 117: /* expression: expression DIVIDE expression  */
#line 752 "src/syntax.y"
                                   {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Operacion DIVIDE solo permitida entre enteros.");
            printf("Error semantico: Operacion DIVIDE solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Operacion DIVIDE en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("/", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_INT;
            generate_quad(OP_DIV, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node))); 
        }
    }
#line 2451 "src/generacion/y.tab.c"
    break;

  case 118: /* expression: expression EQUAL expression  */
#line 767 "src/syntax.y"
                                  {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != (yyvsp[0].node)->data_type) {
            yysemanticerror("Error semantico: Comparacion '=' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '=' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Comparacion '=' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("=", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_EQ, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2471 "src/generacion/y.tab.c"
    break;

  case 119: /* expression: expression EQ expression  */
#line 782 "src/syntax.y"
                                {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != (yyvsp[0].node)->data_type) {
            yysemanticerror("Error semantico: Comparacion '==' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '==' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Comparacion '==' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("==", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_EQ, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2491 "src/generacion/y.tab.c"
    break;

  case 120: /* expression: expression NE expression  */
#line 797 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != (yyvsp[0].node)->data_type) {
            yysemanticerror("Error semantico: Comparacion '!=' solo permitida entre operandos del mismo tipo.");
            printf("Error semantico: Comparacion '!=' solo permitida entre operandos del mismo tipo. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Comparacion '!=' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("!=", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_NE, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2511 "src/generacion/y.tab.c"
    break;

  case 121: /* expression: expression LT expression  */
#line 812 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Comparacion '<' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("<", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LT, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2531 "src/generacion/y.tab.c"
    break;

  case 122: /* expression: array_access LT expression  */
#line 827 "src/syntax.y"
                                 {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Comparacion '<' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("<", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LT, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2551 "src/generacion/y.tab.c"
    break;

  case 123: /* expression: expression LE expression  */
#line 842 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '<=' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '<=' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Comparacion '<=' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("<=", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_LE, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2571 "src/generacion/y.tab.c"
    break;

  case 124: /* expression: expression GT expression  */
#line 857 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '>' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '>' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Comparacion '>' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node(">", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_GT, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2591 "src/generacion/y.tab.c"
    break;

  case 125: /* expression: expression GE expression  */
#line 872 "src/syntax.y"
                                {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Comparacion inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_INT || (yyvsp[0].node)->data_type != TYPE_INT) {
            yysemanticerror("Error semantico: Comparacion '>=' solo permitida entre enteros.");
            printf("Error semantico: Comparacion '>=' solo permitida entre enteros. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
           // printf("Comparacion '>=' en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node(">=", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_GE, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2611 "src/generacion/y.tab.c"
    break;

  case 126: /* expression: expression AND expression  */
#line 887 "src/syntax.y"
                                {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion lógica inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_BOOLEAN || (yyvsp[0].node)->data_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Operacion AND solo permitida entre booleanos.");
            printf("Error semantico: Operacion AND solo permitida entre booleanos. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
          //  printf("Operacion AND en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("&&", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_AND, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node)));  
        }
    }
#line 2631 "src/generacion/y.tab.c"
    break;

  case 127: /* expression: expression OR expression  */
#line 902 "src/syntax.y"
                               {
        if ((yyvsp[-2].node) == NULL || (yyvsp[0].node) == NULL) {
            yyerror("Operacion lógica inválida debido a operandos no definidos.");
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node)->data_type != TYPE_BOOLEAN || (yyvsp[0].node)->data_type != TYPE_BOOLEAN) {
            yysemanticerror("Error semantico: Operacion OR solo permitida entre booleanos.");
            printf("Error semantico: Operacion OR solo permitida entre booleanos. Tipo de operando 1: %d, Tipo de operando 2: %d\n", (yyvsp[-2].node)->data_type, (yyvsp[0].node)->data_type);
            (yyval.node) = NULL;
        } else {
            //printf("Operacion OR en linea %d.\n", yylineno);
            (yyval.node) = create_binary_op_node("||", (yyvsp[-2].node), (yyvsp[0].node));
            (yyval.node)->data_type = TYPE_BOOLEAN;
            generate_quad(OP_OR, extract_identifier((yyvsp[-2].node)), extract_identifier((yyvsp[0].node)), extract_identifier((yyval.node))); 
        }
    }
#line 2651 "src/generacion/y.tab.c"
    break;

  case 128: /* expression: NUMBER  */
#line 917 "src/syntax.y"
             {
        //printf("Numero detectado: %d en la linea %d.\n", $1, yylineno);
        (yyval.node) = create_constant_node((yyvsp[0].ival));
        (yyval.node)->data_type = TYPE_INT;
    }
#line 2661 "src/generacion/y.tab.c"
    break;

  case 129: /* expression: IDENTIFIER  */
#line 922 "src/syntax.y"
                 {
        Symbol *symbol = find_symbol((yyvsp[0].sval));
        if (symbol == NULL) {
            yysemanticerror("Error semantico: Identificador no declarado previamente");
            printf("Error semantico en la linea %d: Identificador \"%s\" no declarado previamente.\n", yylineno, (yyvsp[0].sval));
            (yyval.node) = NULL;
        } else {
            //printf("Identificador detectado: %s en la linea %d. Tipo: %d\n", $1, yylineno, symbol->type);
            (yyval.node) = create_identifier_node((yyvsp[0].sval));
            (yyval.node)->data_type = symbol->type; // Asegurar que el tipo se establece correctamente
        }
    }
#line 2678 "src/generacion/y.tab.c"
    break;

  case 130: /* expression: TOK_TRUE  */
#line 934 "src/syntax.y"
               {
        (yyval.node) = create_constant_node(1);
        (yyval.node)->data_type = TYPE_BOOLEAN;
       // printf("Valor booleano 'true' detectado en la linea %d.\n", yylineno);
    }
#line 2688 "src/generacion/y.tab.c"
    break;

  case 131: /* expression: TOK_FALSE  */
#line 939 "src/syntax.y"
                {
        (yyval.node) = create_constant_node(0);
        (yyval.node)->data_type = TYPE_BOOLEAN;
        //printf("Valor booleano 'false' detectado en la linea %d.\n", yylineno);
    }
#line 2698 "src/generacion/y.tab.c"
    break;

  case 132: /* expression: LPAREN expression RPAREN  */
#line 944 "src/syntax.y"
                               {
       // printf("Evaluando expresion entre parentesis en la linea %d.\n", yylineno);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2707 "src/generacion/y.tab.c"
    break;

  case 133: /* expression: TIMES expression  */
#line 948 "src/syntax.y"
                       {
       // printf("Evaluando expresion con punteros en la linea %d.\n", yylineno);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2716 "src/generacion/y.tab.c"
    break;

  case 134: /* expression: error  */
#line 952 "src/syntax.y"
            {
        yyerror("Error en la expresion");
    }
#line 2724 "src/generacion/y.tab.c"
    break;


#line 2728 "src/generacion/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 957 "src/syntax.y"

