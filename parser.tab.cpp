/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */

#include "production.h"
#include "output.hpp"
#include <iostream>
#include <stdlib.h>
#include "utils.h"
#include "bp.hpp"


extern int yylineno;

using namespace std;
using namespace output;
extern int yylex();
//was original char * message...
void yyerror(char const * message);

void insertFunction(sp retType , sp id, sp formals, TablesPtr tables, OffsetsPtr offsets);
void openFuncScope(sp formals, TablesPtr tables, OffsetsPtr offsets);
void closeScope();

int curr_ret_type;
int while_counter;
int switch_case_counter;

DefaultsPtr defaults;
TablesPtr tables;
OffsetsPtr offsets;


#line 97 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    BYTE = 260,
    B = 261,
    BOOL = 262,
    TRUE = 263,
    FALSE = 264,
    RETURN = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    SWITCH = 269,
    CASE = 270,
    BREAK = 271,
    DEFAULT = 272,
    COLON = 273,
    SC = 274,
    COMMA = 275,
    LPAREN = 276,
    RPAREN = 277,
    LBRACE = 278,
    RBRACE = 279,
    ID = 280,
    NUM = 281,
    STRING = 282,
    ASSIGN = 283,
    OR = 284,
    AND = 285,
    RELOP = 286,
    PLUS_MINUS = 287,
    MUL_DIV = 288,
    NOT = 289,
    LEFT = 290,
    NO_ELSE = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    60,    50,    63,    76,    94,   105,   114,
     115,   119,   119,   119,   119,   124,   125,   128,   129,   132,
     133,   136,   139,   140,   144,   148,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   156,   156,   157,   157,   158,
     158,   158,   160,   163,   159,   170,   173,   177,   178,   181,
     181,   182,   185,   186,   187,   190,   191,   194,   195,   198,
     199,   200,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   219,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "SWITCH", "CASE",
  "BREAK", "DEFAULT", "COLON", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ID", "NUM", "STRING", "ASSIGN", "OR", "AND", "RELOP",
  "PLUS_MINUS", "MUL_DIV", "NOT", "LEFT", "NO_ELSE", "$accept", "Program",
  "$@1", "@2", "_global_scope_open", "_global_scope_close", "_scope_open",
  "_scope_close", "Funcs", "FuncDecl", "$@3", "$@4", "@5", "RetType",
  "Formals", "FormalsList", "FormalDecl", "Statements", "marker",
  "Statement", "@6", "$@7", "@8", "@9", "$@10", "@11", "@12", "@13",
  "_switch_open", "_while_open", "CaseList", "CaseStatement", "@14",
  "CaseDec", "Call", "ExpList", "Type", "Exp", "M_BOOLEAN", "N_BOOLEAN", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-52)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,    24,   -99,   -99,    64,   -99,   -99,   -99,   -99,   -99,
      64,    22,   -99,   -99,   -99,    29,   -99,   154,    30,   -99,
      37,    39,   -99,   154,   -99,   -99,   -99,    43,   105,    17,
     -99,   -99,   -99,    55,   -99,    13,    56,    62,   -99,    73,
      69,   -99,   -99,   -99,    77,    86,   108,   -99,    77,   -99,
      58,    96,   -99,   -99,   -99,    99,   -99,   105,    74,    77,
     -99,   105,   -99,   -99,    21,   115,   -99,   -99,   -99,   -99,
     -99,    77,    77,    77,    77,   110,    77,   119,   -99,   138,
     109,    94,   -99,   -99,   105,   -99,    77,   -99,    77,    77,
     131,   135,   -99,   120,    77,   120,   -99,   -99,    77,   -99,
     -99,   157,   103,   124,   134,   120,   148,   -99,   -99,   -99,
     -99,   -99,   149,   150,   -99,   -99,   -99,   -99,    -5,   -99,
     -99,   105,   146,   156,    -4,   -99,    15,   -99,   -99,     1,
     -99,   158,   -99,   105,   105,   -99,   160,   -99,   -99,    38,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,     9,    16,    59,    60,    61,     3,
       9,     0,    15,     6,    10,     0,     4,    17,     0,    18,
      19,     0,    11,     0,    21,    12,    20,     0,     0,     0,
       7,     7,     7,     0,     7,     0,    76,     0,    22,     0,
       0,    70,    71,    31,     0,    65,    67,    69,     0,    66,
       0,     0,    46,    76,    45,     0,    33,     0,     0,     0,
      13,     0,    76,    30,     0,     0,    68,    72,    32,    76,
      76,     0,     0,     0,     0,     0,     0,    76,    56,     0,
      57,     0,     8,    23,     0,    27,     0,    62,     0,     0,
      75,    64,    63,    24,     0,    34,    25,    55,     0,    29,
      14,    76,     0,    74,    73,    39,     0,     8,    58,    77,
      37,    28,     0,     0,    26,     8,     8,    76,     0,    76,
      38,     0,     0,     0,     0,    48,    49,     7,    40,     0,
      54,     0,    47,     0,     0,     8,     0,    52,    35,    76,
      42,    41,    53,     8,    43,    36,     8,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   -99,   -30,   -98,   165,   -99,
     -99,   -99,   -99,   -99,   -99,   153,   -99,   -54,   -99,   -56,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,    57,   -99,   -99,   -28,    81,     4,   -13,   -47,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,    13,     2,    16,    51,   100,     9,    10,
      25,    27,    82,    11,    18,    19,    20,    36,    37,    38,
     107,   106,   143,   116,   112,   135,   144,   146,    55,    53,
     124,   125,   133,   126,    49,    79,    40,    80,    61,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    52,    54,    77,    57,    83,    75,   136,    12,   114,
     122,   122,   123,   123,    12,    84,    50,   119,   120,   137,
     131,    21,    88,    89,     3,    41,    42,    21,   101,    39,
     -51,    65,   -51,    39,    58,    67,    43,   141,    44,   -51,
      85,    59,    45,    46,    47,   145,    81,    15,   147,    86,
      17,    48,    22,   -50,   110,   -50,    39,    23,    90,    91,
      92,    93,   -50,    95,    24,   128,    28,     5,     6,     7,
     121,     8,   127,   102,    56,   103,   104,    68,   140,   139,
      60,   105,    41,    42,    62,    41,    42,    69,    70,    71,
      72,    73,    63,    39,    64,    44,    78,   134,    44,    45,
      46,    47,    45,    46,    47,    39,    39,    58,    48,     6,
       7,    48,     8,    99,    66,    29,    30,    74,    31,    32,
      76,    33,   111,    69,    70,    71,    72,    73,    34,    98,
      35,    94,    69,    70,    71,    72,    73,    87,    69,    70,
      71,    72,    73,    96,    69,    70,    71,    72,    73,    69,
      70,    71,    72,    73,    70,    71,    72,    73,     6,     7,
      97,     8,   -52,    72,    73,    71,    72,    73,    73,   109,
     113,   117,   129,   118,   130,    14,    26,   138,   142,   108,
       0,   132
};

static const yytype_int16 yycheck[] =
{
      28,    31,    32,    57,    34,    61,    53,     6,     4,   107,
      15,    15,    17,    17,    10,    62,    29,   115,   116,    18,
      24,    17,    69,    70,     0,     8,     9,    23,    84,    57,
      15,    44,    17,    61,    21,    48,    19,   135,    21,    24,
      19,    28,    25,    26,    27,   143,    59,    25,   146,    28,
      21,    34,    22,    15,   101,    17,    84,    20,    71,    72,
      73,    74,    24,    76,    25,   121,    23,     3,     4,     5,
     117,     7,   119,    86,    19,    88,    89,    19,   134,   133,
      24,    94,     8,     9,    22,     8,     9,    29,    30,    31,
      32,    33,    19,   121,    25,    21,    22,   127,    21,    25,
      26,    27,    25,    26,    27,   133,   134,    21,    34,     4,
       5,    34,     7,    19,     6,    10,    11,    21,    13,    14,
      21,    16,    19,    29,    30,    31,    32,    33,    23,    20,
      25,    21,    29,    30,    31,    32,    33,    22,    29,    30,
      31,    32,    33,    24,    29,    30,    31,    32,    33,    29,
      30,    31,    32,    33,    30,    31,    32,    33,     4,     5,
      22,     7,    31,    32,    33,    31,    32,    33,    33,    12,
      22,    22,    26,    23,    18,    10,    23,    19,    18,    98,
      -1,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    41,     0,    39,     3,     4,     5,     7,    45,
      46,    50,    73,    40,    45,    25,    42,    21,    51,    52,
      53,    73,    22,    20,    25,    47,    52,    48,    23,    10,
      11,    13,    14,    16,    23,    25,    54,    55,    56,    71,
      73,     8,     9,    19,    21,    25,    26,    27,    34,    71,
      74,    43,    43,    66,    43,    65,    19,    43,    21,    28,
      24,    75,    22,    19,    25,    74,     6,    74,    19,    29,
      30,    31,    32,    33,    21,    75,    21,    54,    22,    72,
      74,    74,    49,    56,    75,    19,    28,    22,    75,    75,
      74,    74,    74,    74,    21,    74,    24,    22,    20,    19,
      44,    56,    74,    74,    74,    74,    58,    57,    72,    12,
      75,    19,    61,    22,    44,    76,    60,    22,    23,    44,
      44,    75,    15,    17,    67,    68,    70,    75,    56,    26,
      18,    24,    68,    69,    43,    62,     6,    18,    19,    54,
      56,    44,    18,    59,    63,    44,    64,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    40,    38,    41,    42,    43,    44,    45,
      45,    47,    48,    49,    46,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    57,    56,    56,    56,    56,
      56,    56,    56,    56,    58,    59,    56,    60,    56,    61,
      62,    56,    63,    64,    56,    65,    66,    67,    67,    69,
      68,    68,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     5,     0,     0,     0,     0,     0,
       2,     0,     0,     0,    12,     1,     1,     0,     1,     1,
       3,     2,     1,     3,     4,     0,     6,     3,     5,     4,
       2,     2,     3,     2,     0,     0,    12,     0,     7,     0,
       0,    11,     0,     0,    13,     1,     1,     2,     1,     0,
       3,     1,     3,     4,     2,     4,     3,     1,     3,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     4,     3,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 50 "parser.ypp" /* yacc.c:1646  */
    {
						vector<int> StringArgs;
						StringArgs.push_back(STRING);
						vector<int> IntArgs;
						IntArgs.push_back(INT);
						SymbolType printType(StringArgs, VOID);
						SymbolType printiType(IntArgs, VOID);
						INSERT_FUNC("print", printType);
						INSERT_FUNC("printi", printiType);
						}
#line 1380 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p1((yyvsp[-2]), tables, offsets);}
#line 1386 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "parser.ypp" /* yacc.c:1646  */
    {
		#ifdef DEBUG
		cout <<"GLOBAL SCOPE OPEN"<<endl;
		#endif
		SymTable t=SymTable();
		while_counter = 0;
		switch_case_counter = 0;
		PUSH_T(t);
		PUSH_O(0);
		RegisterPoolManager::instance().push();
	}
#line 1402 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "parser.ypp" /* yacc.c:1646  */
    {
			try{
				SymbolType symbolType = TOP_T.getType("main");
				if(!symbolType.isFunction || !symbolType.argTypes.empty() || symbolType.type!= VOID)
				{
					throw ErrorMainMissing();
				}
				
			}catch(SymTable::SymbolDoesNotExist & e){
				throw ErrorMainMissing();
			}
			#ifdef DEBUG
			cout <<"GLOBAL SCOPE CLOSE"<<endl;
			#endif
			closeScope();

			
}
#line 1425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {
	#ifdef DEBUG
	cout <<"Scope Open"<<endl;
	#endif
	SymTable t=SymTable::createWithParent(TOP_T);	

	PUSH_T(t);
	PUSH_O(TOP_O);
	RegisterPoolManager::instance().push();
	}
#line 1440 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "parser.ypp" /* yacc.c:1646  */
    {
	#ifdef DEBUG
	cout <<"Scope Closed"<<endl;
	#endif
	closeScope();
	}
#line 1451 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p3e(tables,offsets);}
#line 1457 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p3((yyvsp[-1]),(yyvsp[0]), tables, offsets); }
#line 1463 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "parser.ypp" /* yacc.c:1646  */
    {insertFunction((yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1]), tables, offsets);}
#line 1469 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "parser.ypp" /* yacc.c:1646  */
    {openFuncScope((yyvsp[-2]),tables,offsets);}
#line 1475 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval)=p4((yyvsp[-9]), (yyvsp[-8]), (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables, offsets);
	}
#line 1483 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 124 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p5((yyvsp[0]), tables, offsets); }
#line 1489 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p6((yyvsp[0]), tables, offsets); }
#line 1495 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p8e(tables,offsets);}
#line 1501 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p8((yyvsp[0]), tables, offsets); }
#line 1507 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p9((yyvsp[0]), tables, offsets);}
#line 1513 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p10((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables, offsets);}
#line 1519 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p11((yyvsp[-1]), (yyvsp[0]),tables, offsets);}
#line 1525 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p12((yyvsp[0]), tables, offsets);}
#line 1531 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p13((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ,tables, offsets);}
#line 1537 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p21e((yyvsp[0]));}
#line 1543 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p14((yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]) ,tables, offsets);}
#line 1549 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 149 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p15((yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables, offsets);}
#line 1555 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p16((yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables, offsets);}
#line 1561 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 151 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p17((yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables, offsets);}
#line 1567 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 152 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p18((yyvsp[-1]),(yyvsp[0]), tables, offsets);}
#line 1573 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 153 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p19((yyvsp[-1]),(yyvsp[0]),tables, offsets, curr_ret_type);}
#line 1579 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p20((yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables, offsets, curr_ret_type);}
#line 1585 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p25((yyvsp[-1]),(yyvsp[0]),tables, offsets, while_counter, switch_case_counter);}
#line 1591 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {p26e((yyvsp[0]));}
#line 1597 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 156 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p26((yyvsp[-9]),(yyvsp[-7]),(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables, offsets);POP_D;}
#line 1603 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p21((yyvsp[-4]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));}
#line 1609 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {p21e((yyvsp[-1]));}
#line 1615 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "parser.ypp" /* yacc.c:1646  */
    { (yyval)=p23((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]), (yyvsp[0]), tables, offsets);}
#line 1621 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {while_counter-=1;}
#line 1627 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 160 "parser.ypp" /* yacc.c:1646  */
    { 
														(yyval)=p24((yyvsp[-9]), (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
													}
#line 1635 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 163 "parser.ypp" /* yacc.c:1646  */
    { 
					(yyval)=p22(); /*9 should be inner statement*/
				}
#line 1643 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "parser.ypp" /* yacc.c:1646  */
    {PUSH_D(0);}
#line 1649 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "parser.ypp" /* yacc.c:1646  */
    {while_counter+=1;}
#line 1655 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 177 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p27((yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1661 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 178 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p28((yyvsp[0]), tables,offsets);}
#line 1667 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {switch_case_counter+=1; }
#line 1673 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p29((yyvsp[-1]), (yyvsp[0]), tables,offsets); switch_case_counter-=1;}
#line 1679 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 182 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p30((yyvsp[0]), tables,offsets);}
#line 1685 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 185 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p31((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1691 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 186 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p32((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1697 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 187 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p33((yyvsp[-1]), (yyvsp[0]), tables,offsets, defaults);}
#line 1703 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 190 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p34((yyvsp[-3]), (yyvsp[-2]),(yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1709 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 191 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p35((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]),  tables,offsets) ;}
#line 1715 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 194 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p36((yyvsp[0]), tables,offsets);}
#line 1721 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 195 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p37((yyvsp[-2]),(yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1727 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 198 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p38((yyvsp[0]), tables,offsets);}
#line 1733 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p39((yyvsp[0]), tables,offsets);}
#line 1739 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 200 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p40((yyvsp[0]), tables,offsets);}
#line 1745 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p41((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1751 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p42((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1757 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p42((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1763 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 206 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p43((yyvsp[0]), tables,offsets);}
#line 1769 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 207 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p44((yyvsp[0]), tables,offsets);}
#line 1775 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 208 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p45((yyvsp[0]), tables,offsets);}
#line 1781 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 209 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p46((yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1787 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 210 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p47((yyvsp[0]), tables,offsets);}
#line 1793 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p48((yyvsp[0]), tables,offsets);}
#line 1799 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 212 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p49((yyvsp[0]), tables,offsets);}
#line 1805 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p50((yyvsp[-1]), (yyvsp[0]), tables,offsets);}
#line 1811 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p51((yyvsp[-3]), (yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1817 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 215 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p52((yyvsp[-3]), (yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1823 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 216 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p53((yyvsp[-2]), (yyvsp[-1]),(yyvsp[0]), tables,offsets);}
#line 1829 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p54();}
#line 1835 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 222 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=p55();}
#line 1841 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1845 "parser.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 226 "parser.ypp" /* yacc.c:1906  */

int main()
{
	tables = shared_ptr<Tables>(new Tables());
	offsets =shared_ptr<Offsets>( new Offsets());
	defaults = shared_ptr <Defaults> ( new Defaults());

	try {
		EMIT_DATA("err_msg1:   .asciiz \"Error division by zero\\n\"");
		EMIT("div_by_zero:");
		EMIT("li $v0, 4");
		EMIT("la $a0, err_msg1");
		EMIT("syscall");
		EMIT("li $v0, 10");
		EMIT("syscall");
		int result = yyparse();
		#ifdef DEBUG
		cout << result <<endl;
		#endif
		//HW5:
		EMIT("li $v0, 10");
		EMIT("syscall");
		CodeBuffer::instance().printDataBuffer();
		CodeBuffer::instance().printCodeBuffer();
		return result;
	}
	catch (Error & er)
	{
		er.print(yylineno);
		exit(0);
	}
}
void yyerror(char const * message)
{
	throw ErrorSyn();
}


//FuncDecl -> RetType ID  Formals
void insertFunction(sp retType , sp id, sp formals, TablesPtr tables, OffsetsPtr offsets)	{
	#ifdef DEBUG
	cout << "insertFunction" <<endl;
	#endif DEBUG
	try {
			SymbolType symType(getArgumentTypes(formals->arguments), retType->returnType);
			INSERT_FUNC(id->lexeme,symType);
		}
		catch(SymTable::SymbolAlreadyExists & e){
			throw ErrorDef(id->lexeme);
		}
	curr_ret_type = retType->returnType;
}
//TODO: We need to insert arguments onto scope (with -1...-2 etc) taken from 'formals'
void openFuncScope(sp formals, TablesPtr tables, OffsetsPtr offsets)
{
#ifdef DEBUG
cout << "openFuncScope" <<endl;
#endif DEBUG
		SymTable t=SymTable::createWithParent(TOP_T);
		PUSH_T(t);
		PUSH_O(TOP_O);
		RegisterPoolManager::instance().push();

		//TODO:get argument names...
		#ifdef DEBUG
		cout<<"Inserting func args"<<endl;
		#endif DEBUG
		vector<ar> args = formals->arguments;
		try{
			INSERT_FUNC_ARGS(args);
		}
		catch(SymTable::SymbolAlreadyExists &e){
			throw ErrorDef(e.s);
		}
		//update argument place/address (needs to be in AddressDesc)
		//We assume args are just above the $fp (loaded by caller)
		for (int i = 0; i< args.size(); i++) 
		{
			args[i]->place = 	ToString<int>(i*-4) + "($fp)";
		}
		
		
}
void closeScope() {
		//endScope();
		//TOP_T.print();
		
		POP_T;
		POP_O;
		RegisterPoolManager::instance().pop();
}
