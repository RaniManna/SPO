/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "bison.y"


  #include <stdio.h>
  #include <stdlib.h>
  #include <getopt.h>

  extern FILE* yyin;
  extern FILE* yyout;

  extern int yylex(void);
  void yyerror( char const* s );

  int is_verbose = 0;
  static struct ast_node* root = NULL; // pointer to the root of AST
  static struct ast_node* tmp = NULL;

#line 88 "bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_CHR = 5,                        /* CHR  */
  YYSYMBOL_HEX = 6,                        /* HEX  */
  YYSYMBOL_BITS = 7,                       /* BITS  */
  YYSYMBOL_DEC = 8,                        /* DEC  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_BIN_PLUS = 13,                  /* BIN_PLUS  */
  YYSYMBOL_BIN_MUL = 14,                   /* BIN_MUL  */
  YYSYMBOL_BIN_DIV = 15,                   /* BIN_DIV  */
  YYSYMBOL_BIN_LESS = 16,                  /* BIN_LESS  */
  YYSYMBOL_BIN_GREATER = 17,               /* BIN_GREATER  */
  YYSYMBOL_BIN_EQUALS = 18,                /* BIN_EQUALS  */
  YYSYMBOL_OP = 19,                        /* OP  */
  YYSYMBOL_CP = 20,                        /* CP  */
  YYSYMBOL_SBO = 21,                       /* SBO  */
  YYSYMBOL_SBC = 22,                       /* SBC  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_REPEAT = 24,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 25,                     /* UNTIL  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_EOEXPR = 28,                    /* EOEXPR  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_COLON = 30,                     /* COLON  */
  YYSYMBOL_VAR = 31,                       /* VAR  */
  YYSYMBOL_BEGINNING = 32,                 /* BEGINNING  */
  YYSYMBOL_END = 33,                       /* END  */
  YYSYMBOL_METHOD = 34,                    /* METHOD  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_BOOLEAN = 36,                   /* BOOLEAN  */
  YYSYMBOL_BYTE = 37,                      /* BYTE  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_UINT = 39,                      /* UINT  */
  YYSYMBOL_LONG = 40,                      /* LONG  */
  YYSYMBOL_ULONG = 41,                     /* ULONG  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_STRING = 43,                    /* STRING  */
  YYSYMBOL_ARRAY = 44,                     /* ARRAY  */
  YYSYMBOL_OF = 45,                        /* OF  */
  YYSYMBOL_THEN = 46,                      /* THEN  */
  YYSYMBOL_ELSE = 47,                      /* ELSE  */
  YYSYMBOL_ERROR = 48,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_typeRef = 51,                   /* typeRef  */
  YYSYMBOL_array = 52,                     /* array  */
  YYSYMBOL_array_elements = 53,            /* array_elements  */
  YYSYMBOL_funcDef = 54,                   /* funcDef  */
  YYSYMBOL_funcSignature = 55,             /* funcSignature  */
  YYSYMBOL_argDef = 56,                    /* argDef  */
  YYSYMBOL_argDef_list = 57,               /* argDef_list  */
  YYSYMBOL_body = 58,                      /* body  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_statement_block = 60,           /* statement_block  */
  YYSYMBOL_statement_list = 61,            /* statement_list  */
  YYSYMBOL_literal = 62,                   /* literal  */
  YYSYMBOL_list = 63,                      /* list  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_expr_list = 65                  /* expr_list  */
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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   103,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   120,   123,   124,   125,   126,   129,
     130,   133,   134,   138,   139,   142,   143,   144,   147,   148,
     151,   152,   153,   154,   155,   156,   157,   158,   161,   162,
     165,   166,   169,   170,   171,   172,   173,   174,   175,   178,
     179,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   207,   208,   209
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "BOOL", "CHR",
  "HEX", "BITS", "DEC", "STR", "ASSIGN", "NOT", "MINUS", "BIN_PLUS",
  "BIN_MUL", "BIN_DIV", "BIN_LESS", "BIN_GREATER", "BIN_EQUALS", "OP",
  "CP", "SBO", "SBC", "WHILE", "REPEAT", "UNTIL", "DO", "BREAK", "EOEXPR",
  "COMMA", "COLON", "VAR", "BEGINNING", "END", "METHOD", "IF", "BOOLEAN",
  "BYTE", "INT", "UINT", "LONG", "ULONG", "CHAR", "STRING", "ARRAY", "OF",
  "THEN", "ELSE", "ERROR", "$accept", "program", "typeRef", "array",
  "array_elements", "funcDef", "funcSignature", "argDef", "argDef_list",
  "body", "statement", "statement_block", "statement_list", "literal",
  "list", "expr", "expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     8,    39,   -22,    42,   -18,   -71,   -71,    61,   -71,
      61,    89,   -71,   -71,    35,    37,    47,    40,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,    98,    98,    98,   122,    54,
     -71,    98,   122,   -71,    50,   -71,   -71,    60,     4,    61,
      55,    52,   251,    34,   229,   198,     2,   -71,     5,   -71,
     -71,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,    66,   -71,   -71,   -71,     4,   -71,   -71,    71,   -71,
     122,    98,    98,   122,   241,   260,   217,    36,    36,    36,
      36,    36,   146,    79,    88,   131,   -71,   221,    91,   -71,
     164,   181,    67,    98,   -71,   -71,    86,    96,    90,    34,
     -71,   -71,   -71,   122,   -71,   131,    75,   131,   -71,   -71,
       4,   -71,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     0,     0,     1,     2,    27,    20,
      27,     0,    19,    29,    24,    26,     0,     0,    63,    43,
      45,    47,    46,    48,    44,     0,     0,     0,     0,     0,
      39,     0,    41,    32,     0,    62,    42,     0,     0,    27,
      22,     0,    59,    62,     0,     0,     0,    36,     0,    40,
      38,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      67,    37,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    23,    13,    25,     0,    28,    50,     0,    64,
       0,     0,     0,     0,    58,    51,    52,    53,    54,    55,
      56,    57,    66,     0,     0,     0,    21,     0,     0,    33,
       0,     0,    30,    67,    60,    61,    18,     0,    17,     0,
      49,    34,    35,     0,    65,     0,     0,     0,    31,    15,
       0,    16,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   120,   -70,   -71,   -55,   -71,   -71,   -71,    -1,   -71,
     -27,    11,   100,   -26,    64,   -23,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    72,    73,   107,     3,     5,    15,    16,    12,
      32,    33,    34,    35,    36,    37,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    46,    42,    44,    45,    96,    94,    62,    48,    17,
       9,     4,     1,    10,    11,    51,    13,    52,    53,    54,
      55,    56,    57,    58,    59,    81,    60,    82,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    92,    74,     6,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   114,
     122,    83,    76,    99,    77,    59,   102,    60,   100,   101,
     119,     8,   121,    78,    14,    38,    39,    40,    41,   108,
      51,   109,    52,    53,    54,    55,    56,    57,    58,    59,
      92,    60,    47,    50,    11,    75,   118,    95,    61,   108,
      97,   108,    18,    19,    20,    21,    22,    23,    24,   104,
      25,    18,    19,    20,    21,    22,    23,    24,    26,    25,
     105,   110,    27,    28,   113,   115,    29,    26,   116,   117,
     120,    11,    30,     7,    31,    18,    19,    20,    21,    22,
      23,    24,    49,    25,   106,    19,    20,    21,    22,    23,
      24,    26,    98,     0,     0,    27,    28,     0,     0,    29,
      97,     0,     0,     0,    11,     0,    51,    31,    52,    53,
      54,    55,    56,    57,    58,    59,     0,    60,     0,     0,
       0,     0,     0,     0,    51,   103,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,     0,     0,     0,     0,
       0,    51,   111,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,     0,     0,     0,     0,     0,    51,   112,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
       0,     0,     0,     0,    80,    19,    20,    21,    22,    23,
      24,    54,    55,    56,    57,    58,    59,     0,    60,    51,
      97,    52,    53,    54,    55,    56,    57,    58,    59,    79,
      60,    51,     0,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,    53,    54,    55,    56,    57,    58,    59,
       0,    60
};

static const yytype_int8 yycheck[] =
{
      26,    28,    25,    26,    27,    75,    60,     3,    31,    10,
      28,     3,    34,    31,    32,    10,     5,    12,    13,    14,
      15,    16,    17,    18,    19,    23,    21,    25,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    39,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   103,
     120,    46,    41,    80,    20,    19,    83,    21,    81,    82,
     115,    19,   117,    29,     3,    30,    29,    20,    28,    95,
      10,    97,    12,    13,    14,    15,    16,    17,    18,    19,
     103,    21,    28,    33,    32,    30,   113,    21,    28,   115,
      19,   117,     3,     4,     5,     6,     7,     8,     9,    20,
      11,     3,     4,     5,     6,     7,     8,     9,    19,    11,
      22,    20,    23,    24,    47,    29,    27,    19,    22,    29,
      45,    32,    33,     3,    35,     3,     4,     5,     6,     7,
       8,     9,    32,    11,     3,     4,     5,     6,     7,     8,
       9,    19,    78,    -1,    -1,    23,    24,    -1,    -1,    27,
      19,    -1,    -1,    -1,    32,    -1,    10,    35,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    29,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    10,    28,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    10,    28,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    -1,    26,     4,     5,     6,     7,     8,
       9,    14,    15,    16,    17,    18,    19,    -1,    21,    10,
      19,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    13,    14,    15,    16,    17,    18,    19,
      -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    50,    54,     3,    55,     0,    50,    19,    28,
      31,    32,    58,    60,     3,    56,    57,    57,     3,     4,
       5,     6,     7,     8,     9,    11,    19,    23,    24,    27,
      33,    35,    59,    60,    61,    62,    63,    64,    30,    29,
      20,    28,    64,    62,    64,    64,    59,    28,    64,    61,
      33,    10,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    28,     3,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    51,    52,    57,    30,    60,    20,    29,    20,
      26,    23,    25,    46,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    21,    51,    19,    63,    59,
      64,    64,    59,    29,    20,    22,     3,    53,    62,    62,
      20,    28,    28,    47,    65,    29,    22,    29,    59,    53,
      45,    53,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     3,     3,     1,     1,     3,
       3,     6,     4,     3,     1,     3,     1,     0,     4,     1,
       4,     6,     1,     4,     5,     5,     2,     2,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     4,     1,     1,     3,     3,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: funcDef program  */
#line 102 "bison.y"
                        { (yyval.node) = root = insert_def_list(make_program((yyvsp[-1].node)), (yyvsp[0].node));}
#line 1348 "bison.tab.c"
    break;

  case 3: /* program: funcDef  */
#line 103 "bison.y"
                 { (yyval.node) = root = insert_def_list(make_program( (yyvsp[0].node) ), NULL); }
#line 1354 "bison.tab.c"
    break;

  case 4: /* typeRef: IDENT  */
#line 108 "bison.y"
                   { (yyval.node) = make_typeref_ident(make_ident((yyvsp[0].value), make_typeref(TR_NONE))); }
#line 1360 "bison.tab.c"
    break;

  case 5: /* typeRef: BOOLEAN  */
#line 109 "bison.y"
                   { (yyval.node) = make_typeref(TR_BOOL); }
#line 1366 "bison.tab.c"
    break;

  case 6: /* typeRef: BYTE  */
#line 110 "bison.y"
                   { (yyval.node) = make_typeref(TR_BYTE); }
#line 1372 "bison.tab.c"
    break;

  case 7: /* typeRef: INT  */
#line 111 "bison.y"
                   { (yyval.node) = make_typeref(TR_INT); }
#line 1378 "bison.tab.c"
    break;

  case 8: /* typeRef: UINT  */
#line 112 "bison.y"
                   { (yyval.node) = make_typeref(TR_UINT); }
#line 1384 "bison.tab.c"
    break;

  case 9: /* typeRef: LONG  */
#line 113 "bison.y"
                   { (yyval.node) = make_typeref(TR_LONG); }
#line 1390 "bison.tab.c"
    break;

  case 10: /* typeRef: ULONG  */
#line 114 "bison.y"
                   { (yyval.node) = make_typeref(TR_ULONG); }
#line 1396 "bison.tab.c"
    break;

  case 11: /* typeRef: CHAR  */
#line 115 "bison.y"
                   { (yyval.node) = make_typeref(TR_CHAR); }
#line 1402 "bison.tab.c"
    break;

  case 12: /* typeRef: STRING  */
#line 116 "bison.y"
                   { (yyval.node) = make_typeref(TR_STR); }
#line 1408 "bison.tab.c"
    break;

  case 13: /* typeRef: array  */
#line 117 "bison.y"
                   { (yyval.node) = make_typeref_array((yyvsp[0].node)); }
#line 1414 "bison.tab.c"
    break;

  case 14: /* array: ARRAY SBO array_elements SBC OF typeRef  */
#line 120 "bison.y"
                                                { (yyval.node) = set_type_array((yyvsp[-3].node), (yyvsp[0].node)); }
#line 1420 "bison.tab.c"
    break;

  case 15: /* array_elements: IDENT COMMA array_elements  */
#line 123 "bison.y"
                                                { (yyval.node) = insert_array (&(yyvsp[0].node), make_ident((yyvsp[-2].value), make_typeref(TR_NONE))); }
#line 1426 "bison.tab.c"
    break;

  case 16: /* array_elements: literal COMMA array_elements  */
#line 124 "bison.y"
                                                { (yyval.node) = insert_array (&(yyvsp[0].node), (yyvsp[-2].node)); }
#line 1432 "bison.tab.c"
    break;

  case 17: /* array_elements: literal  */
#line 125 "bison.y"
                                                { (yyval.node) = make_array((yyvsp[0].node), NULL); }
#line 1438 "bison.tab.c"
    break;

  case 18: /* array_elements: IDENT  */
#line 126 "bison.y"
                                                { (yyval.node) = make_array(make_ident((yyvsp[0].value),  make_typeref(TR_NONE)), NULL); }
#line 1444 "bison.tab.c"
    break;

  case 19: /* funcDef: METHOD funcSignature body  */
#line 129 "bison.y"
                                     { (yyval.node) = make_func ((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1450 "bison.tab.c"
    break;

  case 20: /* funcDef: METHOD funcSignature EOEXPR  */
#line 130 "bison.y"
                                     { (yyval.node) = make_func ((yyvsp[-1].node), NULL); }
#line 1456 "bison.tab.c"
    break;

  case 21: /* funcSignature: IDENT OP argDef_list CP COLON typeRef  */
#line 133 "bison.y"
                                                     {  (yyval.node) = make_func_sign (make_ident ((yyvsp[-5].value), (yyvsp[0].node)) , (yyvsp[-3].node)); }
#line 1462 "bison.tab.c"
    break;

  case 22: /* funcSignature: IDENT OP argDef_list CP  */
#line 134 "bison.y"
                                        { (yyval.node) = make_func_sign (make_ident ((yyvsp[-3].value), make_typeref(TR_NONE)), (yyvsp[-1].node)); }
#line 1468 "bison.tab.c"
    break;

  case 23: /* argDef: IDENT COLON typeRef  */
#line 138 "bison.y"
                            { (yyval.node) = make_ident ((yyvsp[-2].value), (yyvsp[0].node)); }
#line 1474 "bison.tab.c"
    break;

  case 24: /* argDef: IDENT  */
#line 139 "bison.y"
                            { (yyval.node) = make_ident ((yyvsp[0].value), make_typeref(TR_NONE)); }
#line 1480 "bison.tab.c"
    break;

  case 25: /* argDef_list: argDef COMMA argDef_list  */
#line 142 "bison.y"
                                      { (yyval.node) = insert_argdef_list(&(yyvsp[0].node), (yyvsp[-2].node)); }
#line 1486 "bison.tab.c"
    break;

  case 26: /* argDef_list: argDef  */
#line 143 "bison.y"
                                      { (yyval.node) = make_argdef_list((yyvsp[0].node), NULL);}
#line 1492 "bison.tab.c"
    break;

  case 27: /* argDef_list: %empty  */
#line 144 "bison.y"
             {(yyval.node) = make_argdef_list(NULL, NULL);}
#line 1498 "bison.tab.c"
    break;

  case 28: /* body: VAR argDef_list EOEXPR statement_block  */
#line 147 "bison.y"
                                              { (yyval.node) = make_body((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1504 "bison.tab.c"
    break;

  case 29: /* body: statement_block  */
#line 148 "bison.y"
                                              { (yyval.node) = make_body(NULL, (yyvsp[0].node)); }
#line 1510 "bison.tab.c"
    break;

  case 30: /* statement: IF expr THEN statement  */
#line 151 "bison.y"
                                                 { (yyval.node) = make_statement(make_branch((yyvsp[-2].node), (yyvsp[0].node), NULL )); }
#line 1516 "bison.tab.c"
    break;

  case 31: /* statement: IF expr THEN statement ELSE statement  */
#line 152 "bison.y"
                                                  { (yyval.node) = make_statement(make_branch((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node) )); }
#line 1522 "bison.tab.c"
    break;

  case 32: /* statement: statement_block  */
#line 153 "bison.y"
                                                  { (yyval.node) = make_statement((yyvsp[0].node));}
#line 1528 "bison.tab.c"
    break;

  case 33: /* statement: WHILE expr DO statement  */
#line 154 "bison.y"
                                                  { (yyval.node) = make_statement(make_while((yyvsp[-2].node), (yyvsp[0].node))); }
#line 1534 "bison.tab.c"
    break;

  case 34: /* statement: REPEAT statement WHILE expr EOEXPR  */
#line 155 "bison.y"
                                                  { (yyval.node) = make_statement(make_repeat((yyvsp[-3].node), (yyvsp[-1].node))); }
#line 1540 "bison.tab.c"
    break;

  case 35: /* statement: REPEAT statement UNTIL expr EOEXPR  */
#line 156 "bison.y"
                                                  { (yyval.node) = make_statement(make_repeat((yyvsp[-3].node), (yyvsp[-1].node))); }
#line 1546 "bison.tab.c"
    break;

  case 36: /* statement: BREAK EOEXPR  */
#line 157 "bison.y"
                                                  { (yyval.node) = make_statement(make_break());}
#line 1552 "bison.tab.c"
    break;

  case 37: /* statement: expr EOEXPR  */
#line 158 "bison.y"
                                                  { (yyval.node) = make_statement((yyvsp[-1].node)); }
#line 1558 "bison.tab.c"
    break;

  case 38: /* statement_block: BEGINNING statement_list END  */
#line 161 "bison.y"
                                              { (yyval.node) = (yyvsp[-1].node); }
#line 1564 "bison.tab.c"
    break;

  case 39: /* statement_block: BEGINNING END  */
#line 162 "bison.y"
                                              {(yyval.node) = NULL;}
#line 1570 "bison.tab.c"
    break;

  case 40: /* statement_list: statement statement_list  */
#line 165 "bison.y"
                                         {insert_stat_list(&(yyvsp[0].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[0].node);}
#line 1576 "bison.tab.c"
    break;

  case 41: /* statement_list: statement  */
#line 166 "bison.y"
                                         {(yyval.node) = make_stat_list((yyvsp[0].node), NULL); }
#line 1582 "bison.tab.c"
    break;

  case 42: /* literal: list  */
#line 169 "bison.y"
               {(yyval.node)=  (yyvsp[0].node); }
#line 1588 "bison.tab.c"
    break;

  case 43: /* literal: BOOL  */
#line 170 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_BOOL)); }
#line 1594 "bison.tab.c"
    break;

  case 44: /* literal: STR  */
#line 171 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_STR)); }
#line 1600 "bison.tab.c"
    break;

  case 45: /* literal: CHR  */
#line 172 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_CHAR)); }
#line 1606 "bison.tab.c"
    break;

  case 46: /* literal: BITS  */
#line 173 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_BITS)); }
#line 1612 "bison.tab.c"
    break;

  case 47: /* literal: HEX  */
#line 174 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_HEX)); }
#line 1618 "bison.tab.c"
    break;

  case 48: /* literal: DEC  */
#line 175 "bison.y"
               {(yyval.node)=  make_literal((yyvsp[0].value), make_typeref_lt(LT_DEC)); }
#line 1624 "bison.tab.c"
    break;

  case 49: /* list: OP literal COMMA list CP  */
#line 178 "bison.y"
                                 { (yyval.node) = insert_literal_list(&(yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1630 "bison.tab.c"
    break;

  case 50: /* list: OP literal CP  */
#line 179 "bison.y"
                                 { (yyval.node) = make_literal_list((yyvsp[-1].node), NULL); }
#line 1636 "bison.tab.c"
    break;

  case 51: /* expr: expr MINUS expr  */
#line 191 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_MINUS     , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1642 "bison.tab.c"
    break;

  case 52: /* expr: expr BIN_PLUS expr  */
#line 192 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_PLUS  , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1648 "bison.tab.c"
    break;

  case 53: /* expr: expr BIN_MUL expr  */
#line 193 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_MUL   , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1654 "bison.tab.c"
    break;

  case 54: /* expr: expr BIN_DIV expr  */
#line 194 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_DIV   , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1660 "bison.tab.c"
    break;

  case 55: /* expr: expr BIN_LESS expr  */
#line 195 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_LESS  , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1666 "bison.tab.c"
    break;

  case 56: /* expr: expr BIN_GREATER expr  */
#line 196 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_GREATER,(yyvsp[-2].node), (yyvsp[0].node));}
#line 1672 "bison.tab.c"
    break;

  case 57: /* expr: expr BIN_EQUALS expr  */
#line 197 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_BIN_EQUALS, (yyvsp[-2].node),(yyvsp[0].node));}
#line 1678 "bison.tab.c"
    break;

  case 58: /* expr: expr ASSIGN expr  */
#line 198 "bison.y"
                                     { (yyval.node) = make_binexpr( OT_ASSIGN    , (yyvsp[-2].node),(yyvsp[0].node));}
#line 1684 "bison.tab.c"
    break;

  case 59: /* expr: NOT expr  */
#line 199 "bison.y"
                               { (yyval.node) = make_unexpr( OT_UN_NOT, (yyvsp[0].node) ); }
#line 1690 "bison.tab.c"
    break;

  case 60: /* expr: expr OP expr_list CP  */
#line 200 "bison.y"
                               { (yyval.node) = make_expr_call((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1696 "bison.tab.c"
    break;

  case 61: /* expr: expr SBO expr_list SBC  */
#line 201 "bison.y"
                               { (yyval.node) = make_expr_indexer((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1702 "bison.tab.c"
    break;

  case 62: /* expr: literal  */
#line 202 "bison.y"
                               { (yyval.node) = make_expr((yyvsp[0].node)); }
#line 1708 "bison.tab.c"
    break;

  case 63: /* expr: IDENT  */
#line 203 "bison.y"
                               { (yyval.node) = make_expr(make_ident ((yyvsp[0].value), make_typeref(TR_NONE))); }
#line 1714 "bison.tab.c"
    break;

  case 64: /* expr: OP expr CP  */
#line 204 "bison.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1720 "bison.tab.c"
    break;

  case 65: /* expr_list: expr COMMA expr_list  */
#line 207 "bison.y"
                                  {(yyval.node) = insert_expr_list(&(yyvsp[0].node), (yyvsp[-2].node)); }
#line 1726 "bison.tab.c"
    break;

  case 66: /* expr_list: expr  */
#line 208 "bison.y"
                                  {(yyval.node) = make_expr_list((yyvsp[0].node), NULL); }
#line 1732 "bison.tab.c"
    break;

  case 67: /* expr_list: %empty  */
#line 209 "bison.y"
                                  {(yyval.node) = NULL; }
#line 1738 "bison.tab.c"
    break;


#line 1742 "bison.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 225 "bison.y"


void
yyerror(const char *s)
{
 // fprintf(stderr,"error: %s on line %d\n", s, yylineno);
}

int main( int argc, char** argv ) {
  int optidx = 0;
  int is_input = 0;
  struct option options[] = {
    { "file",    required_argument, NULL, 'f' },
    { "help",    no_argument,       NULL, 'h' },
    { 0, 0, 0, 0 }
  };

  char brief_option;
  while ( -1 != (brief_option = getopt_long( argc, argv, "vhf:o:", options, &optidx )) )
    switch ( brief_option ) {
      case 'h':
        fprintf( stdout,
          "SYNOPSYS"
          "\n\tspc [-v] [-f <input file>]"
          "\nDESCRIPTION"
          "\n\t-h, --help"
          "\n\t\tshows this help message and exits"
          "\n\t-f, --file"
          "\n\t\tspecifies the input file path, default: stdin"
        );
        return 0;
      case 'f':
        yyin = fopen( optarg, "r" ); is_input = 1; break;
      default: {
      printf("can't open file");
      exit(-1);
        }
    }

  bool parse_result = yyparse( );
  if ( is_input )
    fclose( yyin );

  // traverse AST for generating TAC
  if ( root == NULL ) printf("node is null\n");

   //is_verbose && fprintf( stdout, "can't find root\n" );
  else {
   //print_ast( root );
   print_cfg(root);
  }                                                                                      
  //                                                                                       
  free_ast( root );                                                                      
  return parse_result;                                                                   
}                                                                                        

