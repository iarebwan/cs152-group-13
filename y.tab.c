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
#line 1 "bajj-er_parse.y" /* yacc.c:339  */

#include "CodeNode.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "y.tab.h"

extern FILE* yyin;
extern int yylex(void);
void yyerror(const char *msg);
extern int yyparse();
//extern int currline;
extern int linenum;
int cur_arg = 0;
int temp = 0;
char *identToken;
int numberToken;
int labelNum = 0;
int numTemp = 0;

std::string create_temp() {
  std::stringstream ssm;
  ssm << std::string("_temp") << numTemp++;
  return ssm.str();
}
std::string decl_temp_code(std::string &temp){
  CodeNode *node = new CodeNode;
  node->name = temp;
  node->code = "";
  node->code = std::string(". ") + temp + std::string("\n");
  return node->code;
}

#line 103 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    RETURN = 258,
    INPUT = 259,
    OUTPUT = 260,
    NUMBER = 261,
    NUM = 262,
    WHILE = 263,
    IF = 264,
    ELIF = 265,
    ELSE = 266,
    FUNC = 267,
    PLUS = 268,
    MINUS = 269,
    MULTI = 270,
    DIVISION = 271,
    LESS = 272,
    GREATER = 273,
    EQUAL = 274,
    NOT_EQUAL = 275,
    LE_EQ = 276,
    GE_EQ = 277,
    COMMENT = 278,
    L_BRACKET = 279,
    R_BRACKET = 280,
    L_C_BRACKET = 281,
    R_C_BRACKET = 282,
    L_PAREN = 283,
    R_PAREN = 284,
    ASSIGN = 285,
    SEMICOLON = 286,
    COMMA = 287,
    FOR = 288,
    ID = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "bajj-er_parse.y" /* yacc.c:355  */

  char* op_val;
  struct CodeNode *codenode;

#line 183 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    76,    85,    91,   102,   124,   137,   148,
     158,   167,   174,   180,   186,   192,   197,   202,   206,   207,
     211,   215,   221,   232,   242,   249,   259,   268,   277,   288,
     308,   309,   314,   321,   324,   332,   352,   355,   364,   374,
     384,   394,   402,   410,   418,   426,   434,   442,   450,   456,
     467,   478,   485,   488,   494,   500,   507,   519,   527,   536,
     544
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "INPUT", "OUTPUT", "NUMBER",
  "NUM", "WHILE", "IF", "ELIF", "ELSE", "FUNC", "PLUS", "MINUS", "MULTI",
  "DIVISION", "LESS", "GREATER", "EQUAL", "NOT_EQUAL", "LE_EQ", "GE_EQ",
  "COMMENT", "L_BRACKET", "R_BRACKET", "L_C_BRACKET", "R_C_BRACKET",
  "L_PAREN", "R_PAREN", "ASSIGN", "SEMICOLON", "COMMA", "FOR", "ID",
  "$accept", "prog_start", "functions", "function", "args", "statements",
  "statement", "return", "num", "if", "elsify", "elif", "else", "while",
  "for", "input", "output", "exp", "bool_exp", "term", "factor",
  "declaration", "parameters", "function_call", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -10,   -27,    24,   -44,   -10,   -13,   -44,   -44,     5,    -5,
       4,     9,   -44,    26,     5,     1,   -44,    10,    30,    36,
      34,    51,    51,    68,    15,    66,    69,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,    12,   -11,    43,
      91,   -44,   -44,    75,    12,    88,    12,    86,    96,    89,
      93,    12,    12,    94,     1,    98,    13,    12,    12,    12,
      12,    99,    47,    25,    70,     1,     1,    88,    51,     0,
     100,    43,   101,   -44,   -44,   -44,    91,    91,   -44,   -44,
     -44,   -44,   102,    43,   103,    12,    12,    12,    12,    12,
      12,   -44,   108,   109,    97,    12,   -44,    49,    52,    72,
      82,    84,    90,   -44,   104,   107,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,    51,   112,   -44,   104,   -44,    12,   113,
       1,   -44,    41,     1,   114,     1,   115,   -44,   116,   -44,
     -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     4,     0,     1,     5,     9,     0,
       0,     8,    56,     0,     9,    12,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    15,    16,
      17,    18,    19,    20,    13,    14,    53,     0,    54,    25,
      41,    51,    55,     0,     0,    56,     0,     0,     0,     0,
       0,    59,     0,     0,    10,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    12,     0,     0,    57,
       0,    22,    55,     6,    11,    52,    39,    40,    49,    50,
      37,    38,    53,    26,    55,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,    35,    32,     0,    58,    43,    42,    44,
      47,    45,    46,     0,     0,    29,    32,    31,     0,     0,
      12,    30,     0,    12,     0,    12,     0,    34,     0,    33,
      36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   123,   -44,   126,   -43,   -44,   -44,   121,   -44,
      14,   -44,   -44,   -44,   -44,   -44,   -44,   -16,   -19,    59,
      61,    11,    50,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    25,    26,    27,    28,    29,
     115,   116,   117,    30,    31,    32,    33,    69,    47,    40,
      41,    34,    70,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    39,     1,    48,    17,    18,    19,     5,    20,    21,
      22,    74,     9,    57,    58,     8,    36,    51,    36,    11,
     -24,    56,    92,    93,     6,    11,    57,    58,    62,    12,
      64,    82,    95,    13,    23,    24,    71,    72,    37,    35,
      37,    14,    75,    51,    38,    52,    55,    83,    84,    94,
      35,    35,    15,    37,    57,    58,    57,    58,    43,    55,
      57,    58,    57,    58,    44,    57,    58,   125,    45,    97,
      98,    99,   100,   101,   102,    49,    81,   124,   107,    46,
     126,   108,   128,    57,    58,    57,    58,    85,    86,    87,
      88,    89,    90,    53,   119,    57,    58,    57,    58,    91,
      54,   109,   122,    57,    58,    35,    59,    60,    35,    61,
      35,   110,    65,   111,   113,   114,    76,    77,    63,   112,
      78,    79,    66,    67,    68,    73,    51,     7,    80,    96,
     121,   105,   -23,   -27,   -28,   103,   104,   118,   120,   123,
      16,   127,   129,   130,    50,   106
};

static const yytype_uint8 yycheck[] =
{
      15,    17,    12,    22,     3,     4,     5,    34,     7,     8,
       9,    54,     7,    13,    14,    28,     6,    28,     6,     8,
      31,    37,    65,    66,     0,    14,    13,    14,    44,    34,
      46,     6,    32,    29,    33,    34,    52,    52,    28,    54,
      28,    32,    29,    28,    34,    30,    34,    63,    63,    68,
      65,    66,    26,    28,    13,    14,    13,    14,    28,    34,
      13,    14,    13,    14,    28,    13,    14,    26,    34,    85,
      86,    87,    88,    89,    90,     7,    29,   120,    29,    28,
     123,    29,   125,    13,    14,    13,    14,    17,    18,    19,
      20,    21,    22,    27,   113,    13,    14,    13,    14,    29,
      31,    29,   118,    13,    14,   120,    15,    16,   123,    34,
     125,    29,    26,    29,    10,    11,    57,    58,    30,    29,
      59,    60,    26,    34,    31,    31,    28,     4,    29,    29,
     116,    34,    31,    31,    31,    27,    27,    30,    26,    26,
      14,    27,    27,    27,    23,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    36,    37,    38,    34,     0,    37,    28,     7,
      39,    56,    34,    29,    32,    26,    39,     3,     4,     5,
       7,     8,     9,    33,    34,    40,    41,    42,    43,    44,
      48,    49,    50,    51,    56,    58,     6,    28,    34,    52,
      54,    55,    58,    28,    28,    34,    28,    53,    53,     7,
      43,    28,    30,    27,    31,    34,    52,    13,    14,    15,
      16,    34,    52,    30,    52,    26,    26,    34,    31,    52,
      57,    52,    58,    31,    40,    29,    54,    54,    55,    55,
      29,    29,     6,    52,    58,    17,    18,    19,    20,    21,
      22,    29,    40,    40,    53,    32,    29,    52,    52,    52,
      52,    52,    52,    27,    27,    34,    57,    29,    29,    29,
      29,    29,    29,    10,    11,    45,    46,    47,    30,    53,
      26,    45,    52,    26,    40,    26,    40,    27,    40,    27,
      27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    39,    39,    39,
      40,    40,    40,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    42,    42,    43,    43,    43,    44,
      45,    45,    45,    46,    47,    48,    49,    50,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    57,    57,    57,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     9,     3,     1,     0,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     4,     4,     4,     6,
       2,     1,     0,     5,     4,     5,    10,     4,     4,     3,
       3,     1,     5,     5,     5,     5,     5,     5,     3,     3,
       3,     1,     3,     1,     1,     1,     2,     1,     3,     0,
       4
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
#line 71 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("prog_start->epsilon\n");
	printf("/n");
}
#line 1370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("we be parsing \n");
//printf("prog_start->functions\n");
CodeNode *code_node = (yyvsp[0].codenode);
printf("%s\n", code_node->code.c_str());

}
#line 1382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("function -> function\n");
//Should be good?
CodeNode *function = (yyvsp[0].codenode);
(yyval.codenode) = function;
}
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("function -> function functions\n");
//Should be done?
CodeNode *func1 = (yyvsp[-1].codenode);
CodeNode *funcs = (yyvsp[0].codenode);
CodeNode *node = new CodeNode;
node->code = func1->code + funcs->code;
(yyval.codenode) = node;
}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("function-> FUNC ID L_PAREN args R_PAREN L_C_BRACKET statments R_C_BRACKET SEMICOLON  \n");
CodeNode *node = new CodeNode;
std::string func_name = (yyvsp[-7].op_val);
node->code ="";

// ADD Function NAME
node->code += std::string("func ") + func_name + std::string("\n");

//add args
CodeNode *args = (yyvsp[-5].codenode);
node->code += args->code;

//add statments
CodeNode *statements = (yyvsp[-2].codenode);
node->code += statements->code;
//endfunc
node->code += std::string("endfunc\n");
(yyval.codenode) = node;
cur_arg = 0;
}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("arguments -> COMMA arguments\n");
//Should be done?
CodeNode *node = new CodeNode;
std::stringstream arg_nums;
arg_nums << std::string("$") << cur_arg++;
CodeNode *dec = (yyvsp[-2].codenode);
CodeNode *args = (yyvsp[0].codenode);
node->code = dec->code;
node->code += std::string("= ") + dec->name + std::string(", ") + arg_nums.str() + std::string("\n");
node->code += args->code;
(yyval.codenode) = node;
}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("arguments -> argument\n");
//Should be done?
CodeNode *node = new CodeNode;
std::stringstream arg_nums;
arg_nums << std::string("$") << cur_arg++;
CodeNode *dec = (yyvsp[0].codenode);
node->code = dec->code;
node->code += std::string("= ") + dec->name + std::string(", ") + arg_nums.str() + std::string("\n");
(yyval.codenode) = node;
}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 148 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//should be done
CodeNode *node = new CodeNode;
cur_arg = 0;
(yyval.codenode) = node;
}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statements -> statement SEMICOLON\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
//printf("going into statement SEMICOLON\n");
node->code = (yyvsp[-1].codenode)->code;
//printf("we are out from statement\n");
(yyval.codenode) = node;
}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statements -> statement SEMICOLON statement\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
node->code = (yyvsp[-2].codenode)->code + (yyvsp[0].codenode)->code;
(yyval.codenode) = node;
}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 174 "bajj-er_parse.y" /* yacc.c:1646  */
    {
CodeNode *node = new CodeNode;
(yyval.codenode) = node;
}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statment -> declaration\n");
//Done i think?
CodeNode *dec = (yyvsp[0].codenode);
(yyval.codenode) = dec;
}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 186 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statement-> function_call\n");
// Place holder but probs shouldnt do function_call as it does nothing by itself (need to assign)
CodeNode *node = new CodeNode;
(yyval.codenode) = node;
}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 192 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//Done?
CodeNode *num = (yyvsp[0].codenode);
(yyval.codenode) = num;
}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 197 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statement->if\n");
CodeNode *node = (yyvsp[0].codenode);
(yyval.codenode) = node;
}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statement->while\n");
//TODO PHASE 4
}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 206 "bajj-er_parse.y" /* yacc.c:1646  */
    {printf("statement->for\n");}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 207 "bajj-er_parse.y" /* yacc.c:1646  */
    {
    CodeNode *input = (yyvsp[0].codenode);
    (yyval.codenode) = input;
}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 211 "bajj-er_parse.y" /* yacc.c:1646  */
    {
    CodeNode *output = (yyvsp[0].codenode);
    (yyval.codenode) = output;
}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 215 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statement->return\n");
CodeNode *node = (yyvsp[0].codenode);
//std::cout << std::string("our ret code: ") << node->code << std::endl;
(yyval.codenode) = node;
}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 222 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("statement->ID ASSIGN exp\n");
//TODO
std::string var_name = (yyvsp[-2].op_val);

CodeNode *node = new CodeNode;
node->code = (yyvsp[0].codenode)->code;
node->code += std::string("= ") + var_name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
(yyval.codenode) = node;
}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "bajj-er_parse.y" /* yacc.c:1646  */
    {
CodeNode *node = new CodeNode;
node->name = (yyvsp[-2].op_val);
//std::cout << "func_call code: " << $3->code << std::endl;
node->code += (yyvsp[0].codenode)->code;
node->code += std::string("= ") + (yyvsp[-2].op_val) + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
(yyval.codenode) = node;
}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 242 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("return->RETURN ID\n");
CodeNode *node = new CodeNode;
node->name = (yyvsp[0].op_val);
node->code = std::string("ret ") + (yyvsp[0].op_val) + std::string("\n");
(yyval.codenode) = node;
}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("return->RETURN EXP\n");
CodeNode *node = (yyvsp[0].codenode);
//std::cout << std::string("exp name: ") << node->name  << std::endl;
node->code += std::string("ret ") + (yyvsp[0].codenode)->name + std::string("\n");
//std::cout << std::string("we coming outta return exp") << std::endl;
(yyval.codenode) = node;
}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 259 "bajj-er_parse.y" /* yacc.c:1646  */
    {
CodeNode *numDec = new CodeNode;
std::string var_name = (yyvsp[-2].op_val);
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
numDec->code += (yyvsp[0].codenode)->code;
numDec->code += std::string("= ") + var_name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
(yyval.codenode) = numDec;
}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 268 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("num -> NUM ID ASSIGN NUMBER\n");
std::string var_name = (yyvsp[-2].op_val);
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
numDec->code += std::string("= ") + var_name + std::string(", ") + (yyvsp[0].op_val) + std::string("\n");
(yyval.codenode) = numDec;
}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("num -> NUM ID ASSIGN function_call\n");
CodeNode *node = new CodeNode;
node->name = (yyvsp[-2].op_val);
node->code += std::string(". ") + (yyvsp[-2].op_val) + std::string("\n");
node->code += (yyvsp[0].codenode)->code;
node->code += std::string("= ") + (yyvsp[-2].op_val) + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
(yyval.codenode) = node;
}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 288 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("if -> IF bool_exp L_C_BRACKET statements R_C_BRACKET elsify\n");
CodeNode *node = new CodeNode;
std::stringstream ifState;
std::stringstream skip;
ifState << std::string("label") << labelNum++;
skip << std::string("label") << labelNum++;
//std::cout << std::string("going into bool: ") << std::endl;
CodeNode * boolExp =  (yyvsp[-4].codenode);
node->code += std::string("?:= ") + ifState.str() + std::string(", ") + boolExp->name + std::string("\n");
node->code += std::string(":= ") + skip.str() + std::string("\n"); 
node->code +=  std::string(": ") + ifState.str() + std::string("\n");
//std::cout << std::string("going into statments: ") << std::endl;
node->code += (yyvsp[-2].codenode)->code;
node->code += std::string(": ") + skip.str() + std::string("\n");
node->code += (yyvsp[0].codenode)->code;
(yyval.codenode) = node;
}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 308 "bajj-er_parse.y" /* yacc.c:1646  */
    {printf("elsify -> elif SEMICOLON elsify\n");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 309 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("elsify -> else SEMICOLON\n");
CodeNode *node = (yyvsp[0].codenode);
(yyval.codenode) = node;
}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 314 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("elsify->epsilon\n");
CodeNode *node = new CodeNode;
(yyval.codenode) = node;
}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 321 "bajj-er_parse.y" /* yacc.c:1646  */
    {printf("elif -> elif bool_exp L_C_BRACKET statements R_C_BRACKET\n");}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 324 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("else -> else L_C_BRACKET statements R_C_BRACKET\n");
//should just push up the code since it is else statement (must be run if no other options)
CodeNode *node = (yyvsp[-1].codenode);
(yyval.codenode) = node;
}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 332 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("while -> WHILE bool_exp L_C_BRACKET statement R_C_BRACKET\n");
CodeNode *node = new CodeNode;
std::stringstream ifState;
std::stringstream skip;
std::stringstream start;
CodeNode * boolExp =  (yyvsp[-3].codenode);
ifState << std::string("label") << labelNum++;
skip << std::string("label") << labelNum++;
start << std::string("label") << labelNum++;
node->code += std::string(": ") + start.str();
node->code += std::string("?:= ") + ifState.str() + std::string(", ") + boolExp->name + std::string("\n");
node->code += std::string(":= ") + skip.str() + std::string("\n");
node->code +=  std::string(": ") + ifState.str() + std::string("\n");
node->code += (yyvsp[-1].codenode)->code;
node->code += std::string(":= ") + start.str() + std::string("\n");
node->code += std::string(": ") + skip.str() + std::string("\n");
}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 352 "bajj-er_parse.y" /* yacc.c:1646  */
    {printf("for -> FOR num ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON num ASSIGN exp L_C_BRACKET statements R_C_BRACKET\n");}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 355 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("input -> INPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  std::string id = (yyvsp[-1].op_val);
  exp->code = std::string(".< ") + id + std::string("\n");
  (yyval.codenode) = exp;
}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 364 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("output -> OUTPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  exp->code = (yyvsp[-1].codenode)->code;
  exp->code += std::string(".> ") + (yyvsp[-1].codenode)->name + std::string("\n");
  (yyval.codenode) = exp;
}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 374 "bajj-er_parse.y" /* yacc.c:1646  */
    {
   CodeNode *node = new CodeNode;
   CodeNode *num1 = (yyvsp[-2].codenode);
   CodeNode *num2 = (yyvsp[0].codenode);
   std::string temp = create_temp();
   node->code = (yyvsp[-2].codenode)->code + (yyvsp[0].codenode)->code + decl_temp_code(temp);
   node->code += std::string("+ ") + temp + std::string(", ") + (yyvsp[-2].codenode)->name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
   node->name = temp;
   (yyval.codenode) = node;
}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 384 "bajj-er_parse.y" /* yacc.c:1646  */
    {
   CodeNode *node = new CodeNode;
   CodeNode *num1 = (yyvsp[-2].codenode);
   CodeNode *num2 = (yyvsp[0].codenode);
   std::string temp = create_temp();
   node->code = (yyvsp[-2].codenode)->code + (yyvsp[0].codenode)->code + decl_temp_code(temp);
   node->code += std::string("- ") + temp + std::string(", ") + (yyvsp[-2].codenode)->name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
   node->name = temp;
   (yyval.codenode) = node;
}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 394 "bajj-er_parse.y" /* yacc.c:1646  */
    {
   CodeNode *term = (yyvsp[0].codenode);
   (yyval.codenode) = term;
}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 402 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string("> ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 410 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string("< ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 418 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string("== ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 426 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string("<= ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 434 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string(">= ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 442 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = (yyvsp[-3].codenode)->code + (yyvsp[-1].codenode)->code + decl_temp_code(temp);
  node->code += std::string("!= ") + temp + std::string(", ") + (yyvsp[-3].codenode)->name + std::string(", ") + (yyvsp[-1].codenode)->name + std::string("\n");
  node->name = temp;
  (yyval.codenode) = node;
}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 450 "bajj-er_parse.y" /* yacc.c:1646  */
    {
CodeNode *node = (yyvsp[-1].codenode);
(yyval.codenode) = node;
}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 456 "bajj-er_parse.y" /* yacc.c:1646  */
    {
// printf("term -> term MULTI factor\n");
   CodeNode *node = new CodeNode;
   CodeNode *num1 = (yyvsp[-2].codenode);
   CodeNode *num2 = (yyvsp[0].codenode);
   std::string temp = create_temp();
   node->code = (yyvsp[-2].codenode)->code + (yyvsp[0].codenode)->code + decl_temp_code(temp);
   node->code += std::string("* ") + temp + std::string(", ") + (yyvsp[-2].codenode)->name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
   node->name = temp;
   (yyval.codenode) = node;
}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "bajj-er_parse.y" /* yacc.c:1646  */
    {
// printf("term -> term DIVISION factor\n");
   CodeNode *node = new CodeNode;
   CodeNode *num1 = (yyvsp[-2].codenode);
   CodeNode *num2 = (yyvsp[0].codenode);
   std::string temp = create_temp();
   node->code = (yyvsp[-2].codenode)->code + (yyvsp[0].codenode)->code + decl_temp_code(temp);
   node->code += std::string("/ ") + temp + std::string(", ") + (yyvsp[-2].codenode)->name + std::string(", ") + (yyvsp[0].codenode)->name + std::string("\n");
   node->name = temp;
   (yyval.codenode) = node;
}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 478 "bajj-er_parse.y" /* yacc.c:1646  */
    {
   CodeNode *factor = (yyvsp[0].codenode);
   (yyval.codenode) = factor;
}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 485 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("factor->L_PAREN exp R_PAREN\n");
}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 488 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  node->name = (yyvsp[0].op_val);
  node->code = "";
  (yyval.codenode) = node;
}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 494 "bajj-er_parse.y" /* yacc.c:1646  */
    {
  CodeNode *node = new CodeNode;
  node->name = (yyvsp[0].op_val);
  node->code = "";
  (yyval.codenode) = node;
}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 500 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("factor -> function_call\n");
 CodeNode *node = (yyvsp[0].codenode);
 (yyval.codenode) = node;
}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 507 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//Done?
//printf("declaration -> NUM ID\n");
std::string var_name = (yyvsp[0].op_val);
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
(yyval.codenode) = numDec;
}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 519 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//Done?
CodeNode *node = new CodeNode;
CodeNode *expr = (yyvsp[0].codenode);
node->code = std::string("param ") + expr->name + std::string("\n");
node->code += expr->code;
(yyval.codenode) = node;
}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 527 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//Done?
CodeNode *node = new CodeNode;
CodeNode *expr = (yyvsp[-2].codenode);
CodeNode *nParam = (yyvsp[0].codenode);
node->code = std::string("param ") + expr->name + std::string("\n");
node->code += expr->code  + nParam->code; 
(yyval.codenode) = node;
}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 536 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//should be empty
CodeNode *node = new CodeNode;
(yyval.codenode) = node;
}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 544 "bajj-er_parse.y" /* yacc.c:1646  */
    {
//printf("function_call -> ID L_PAREN exp R_PAREN\n");
//CHECK TODO
CodeNode *node = new CodeNode;
std::string func = (yyvsp[-3].op_val);
CodeNode *params = (yyvsp[-1].codenode);

std::string temp = create_temp();

//code
node->code = params->code + decl_temp_code(temp);
node->code += std::string("call ") + func + std::string(", ") + temp + std::string("\n");
node->name = temp;
//std::cout << "code from func: " << node->code << std::endl;
(yyval.codenode) = node;
}
<<<<<<< HEAD
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2095 "y.tab.c" /* yacc.c:1646  */
=======
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2096 "y.tab.c" /* yacc.c:1646  */
>>>>>>> cf8c5e4e00eeabdbae07eab07b7910c57cc0e49d
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
<<<<<<< HEAD
#line 561 "bajj-er_parse.y" /* yacc.c:1906  */
=======
#line 562 "bajj-er_parse.y" /* yacc.c:1906  */
>>>>>>> cf8c5e4e00eeabdbae07eab07b7910c57cc0e49d


int  main() {
yyin = stdin;
do{
  yyparse();
}
while(!feof(yyin));
return 0;
}
 void yyerror (char const *s) {
   //fprintf (stderr, "This is an error: %s at line %d \n", s, linenum);
	
   printf("** Line %d: %s\n", linenum,s);
 }
