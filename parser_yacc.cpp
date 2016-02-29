/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parserparse
#define yylex           parserlex
#define yyerror         parsererror
#define yydebug         parserdebug
#define yynerrs         parsernerrs

#define yylval          parserlval
#define yychar          parserchar

/* Copy the first part of user declarations.  */
#line 29 "src/parser.y" /* yacc.c:339  */


#include <sys/types.h>
#include <sys/stat.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif

#include "typedefs.h"
#include "module.h"
#include "expression.h"
#include "value.h"
#include "function.h"
#include "printutils.h"
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
#define foreach BOOST_FOREACH

#include "boosty.h"

#define YYMAXDEPTH 20000

int parser_error_pos = -1;

int parserlex(void);
void yyerror(char const *s);

int lexerget_lineno(void);
int lexerlex_destroy(void);
int lexerlex(void);

std::stack<LocalScope *> scope_stack;
FileModule *rootmodule;

extern void lexerdestroy();
extern FILE *lexerin;
extern const char *parser_input_buffer;
const char *parser_input_buffer;
std::string parser_source_path;


#line 119 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int parserdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_ERROR = 258,
    TOK_MODULE = 259,
    TOK_FUNCTION = 260,
    TOK_IF = 261,
    TOK_ELSE = 262,
    TOK_FOR = 263,
    TOK_LET = 264,
    TOK_ID = 265,
    TOK_STRING = 266,
    TOK_USE = 267,
    TOK_NUMBER = 268,
    TOK_TRUE = 269,
    TOK_FALSE = 270,
    TOK_UNDEF = 271,
    LE = 272,
    GE = 273,
    EQ = 274,
    NE = 275,
    AND = 276,
    OR = 277,
    LET = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 74 "src/parser.y" /* yacc.c:355  */

  char *text;
  double number;
  class Value *value;
  class Expression *expr;
  class ModuleInstantiation *inst;
  class IfElseModuleInstantiation *ifelse;
  Assignment *arg;
  AssignmentList *args;

#line 194 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parserlval;

int parserparse (void);

#endif /* !YY_PARSER_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    43,     2,    33,     2,     2,
      40,    41,    31,    29,    44,    30,    36,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    37,
      26,    42,    27,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   143,   142,   145,   149,   150,   151,   155,
     157,   156,   170,   169,   179,   181,   185,   203,   208,   213,
     218,   224,   223,   233,   240,   245,   244,   257,   256,   270,
     272,   273,   277,   278,   279,   287,   288,   292,   303,   307,
     311,   315,   320,   325,   330,   334,   339,   343,   347,   351,
     355,   359,   363,   367,   371,   375,   379,   383,   387,   391,
     395,   399,   403,   407,   411,   415,   419,   423,   427,   431,
     435,   446,   451,   464,   471,   472,   476,   477,   481,   485,
     494,   497,   503,   512,   517,   526,   529,   535,   544,   548
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ERROR", "TOK_MODULE",
  "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_FOR", "TOK_LET", "TOK_ID",
  "TOK_STRING", "TOK_USE", "TOK_NUMBER", "TOK_TRUE", "TOK_FALSE",
  "TOK_UNDEF", "LE", "GE", "EQ", "NE", "AND", "OR", "LET", "'?'", "':'",
  "'<'", "'>'", "'!'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "']'",
  "'.'", "';'", "'{'", "'}'", "'('", "')'", "'='", "'#'", "','", "$accept",
  "input", "$@1", "statement", "$@2", "$@3", "inner_input", "assignment",
  "module_instantiation", "@4", "ifelse_statement", "$@5", "if_statement",
  "@6", "child_statements", "child_statement", "module_id",
  "single_module_instantiation", "expr", "list_comprehension_elements",
  "list_comprehension_elements_or_expr", "optional_commas", "vector_expr",
  "arguments_decl", "argument_decl", "arguments_call", "argument_call", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    63,    58,    60,    62,    33,    43,
      45,    42,    47,    37,    91,    93,    46,    59,   123,   125,
      40,    41,    61,    35,    44
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,     2,     3,   -17,   -57,     5,   -57,   159,   159,   159,
     -57,    88,   159,    37,    12,   -57,   -57,   -57,    31,    20,
     -57,    43,    57,   205,   205,    12,   -57,   -57,   -57,   -57,
      88,    13,   -57,   -57,   -57,   -57,   233,    80,    32,    32,
      61,    64,   -57,   -57,   -57,   -57,   -57,   205,   205,   205,
     144,   205,   257,   332,   -57,   -57,   -57,    80,    11,   453,
     -33,   -57,   -57,   -57,   -57,   -57,    63,    34,   -57,    34,
     233,   233,    -1,    -1,    -1,    67,    69,    70,    62,   373,
      77,    79,    71,   282,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   112,
     -57,   -57,   -57,   205,   -57,    62,   158,   205,    62,    83,
      87,    -5,     0,   205,   233,   233,   -57,   205,   -57,   -57,
      62,    94,   -57,   221,   221,   501,   501,   493,   473,   393,
     221,   221,    -1,    -1,    66,    66,    66,   413,   -57,    80,
     453,   233,   -57,   -57,   -57,   453,    32,   -57,    90,   205,
     -57,   307,    36,    38,   353,   205,   -57,   205,   -57,   -57,
     -57,   -57,    88,   205,   453,   197,   197,   197,   205,   -57,
     453,   453,   -57,   453,   453,   -57,   -57,   -57,   -57,   433,
      93,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,    36,    35,     3,     0,     0,     0,
       6,    14,     0,     0,     2,     9,     8,    23,    24,     0,
      21,     0,     0,     0,     0,     2,    35,    17,    20,    19,
      14,     0,    18,     1,     5,    25,    85,     0,    80,    80,
       0,    41,    43,    44,    38,    39,    40,     0,     0,     0,
      77,     0,     0,     0,     4,    15,     7,     0,    41,    88,
       0,    86,    32,    29,    34,    22,    83,    77,    81,    77,
      85,    85,    66,    64,    65,     0,     0,     0,    77,    78,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    16,    26,     0,    37,    77,     0,     0,    77,     0,
       0,     0,     0,     0,    85,    85,    76,     0,    48,    49,
      77,     0,    67,    57,    60,    58,    59,    62,    63,     0,
      56,    61,    54,    55,    51,    52,    53,     0,    42,     0,
      89,     0,    33,    31,    30,    84,    76,    10,     0,     0,
      70,     0,     0,     0,     0,    76,    50,     0,    69,    28,
      87,    82,     0,     0,    45,     0,     0,     0,     0,    46,
      79,    68,    11,    12,    75,    74,    73,    72,    71,     0,
       0,    47,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,    -4,   -57,   -11,   -57,   -57,   104,    33,    -3,   -57,
     -57,   -57,   -57,   -57,   -57,   -50,   -57,   -57,   -22,   -47,
     -29,   -21,   -57,    99,    -6,   -56,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    25,    14,   162,   180,    31,    15,    16,    37,
      17,    57,    18,   139,   106,    65,    19,    20,    59,   175,
     176,    81,    82,    67,    68,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    52,    53,    80,    27,    28,    29,   102,   104,    32,
      34,   105,    21,    22,   111,   112,     1,     2,     3,    30,
       4,    54,     5,    23,     6,    72,    73,    74,    79,    83,
      95,    96,    97,    98,    64,    99,   149,    33,    35,   105,
       7,   150,    66,     8,   105,     9,   109,    24,   110,    10,
      11,    71,    56,   103,    64,    12,   144,   116,   152,   153,
      36,   121,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   166,   108,   167,
     105,   140,   105,    38,   141,   145,     3,   146,     4,   159,
      26,   151,     1,     2,     3,   154,     4,    39,     5,   155,
      98,    70,    99,    64,    71,   107,    78,   113,     7,   114,
     115,     8,   118,     9,   119,   120,     7,    62,    63,     8,
     178,     9,   138,    12,   147,    10,    11,   164,   148,   156,
     182,    12,   163,   170,    55,   171,    64,   177,    69,   143,
     161,   173,   160,   174,   174,   164,   179,     0,     0,     0,
      75,   172,    76,    77,    41,    42,     0,    43,    44,    45,
      46,     0,     0,     0,     3,     3,     4,     4,     5,    26,
       0,     0,    47,    48,    49,     0,     0,     0,    50,     0,
       0,     0,     0,     0,    51,     0,     7,     7,    78,     8,
       8,     9,     9,     0,     0,    62,    63,   142,     0,     0,
       0,    12,    12,    75,     0,    76,    77,    41,    42,     0,
      43,    44,    45,    46,    40,    41,    42,     0,    43,    44,
      45,    46,     0,     0,     0,    47,    48,    49,     0,     0,
       0,    50,     0,    47,    48,    49,     0,    51,     0,    50,
      86,    87,    40,    58,    42,    51,    43,    44,    45,    46,
      93,    94,    95,    96,    97,    98,     0,    99,     0,     0,
       0,    47,    48,    49,     0,     0,     0,    50,     0,     0,
       0,     0,     0,    51,    84,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,     0,    93,    94,    95,    96,
      97,    98,     0,    99,     0,     0,     0,     0,   100,    84,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,     0,     0,   122,    84,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,     0,    93,    94,    95,    96,
      97,    98,     0,    99,     0,     0,     0,     0,   165,    84,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
       0,    93,    94,    95,    96,    97,    98,     0,    99,   101,
      84,    85,    86,    87,    88,    89,     0,    90,   168,    91,
      92,     0,    93,    94,    95,    96,    97,    98,   169,    99,
      84,    85,    86,    87,    88,    89,     0,    90,   117,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,    99,
      84,    85,    86,    87,    88,    89,     0,    90,   157,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,    99,
      84,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,   158,    99,
      84,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,   181,    99,
      84,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,    99,
      84,    85,    86,    87,    88,     0,     0,     0,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,    99,
      84,    85,    86,    87,     0,     0,     0,     0,     0,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,    99,
      93,    94,    95,    96,    97,    98,     0,    99
};

static const yytype_int16 yycheck[] =
{
      11,    23,    24,    50,     7,     8,     9,    57,    41,    12,
      14,    44,    10,    10,    70,    71,     4,     5,     6,    30,
       8,    25,    10,    40,    12,    47,    48,    49,    50,    51,
      31,    32,    33,    34,    37,    36,    41,     0,     7,    44,
      28,    41,    10,    31,    44,    33,    67,    42,    69,    37,
      38,    40,    39,    42,    57,    43,   106,    78,   114,   115,
      40,    82,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    41,    44,    41,
      44,   103,    44,    40,   105,   107,     6,   108,     8,   139,
      10,   113,     4,     5,     6,   117,     8,    40,    10,   120,
      34,    40,    36,   106,    40,    42,    44,    40,    28,    40,
      40,    31,    35,    33,    35,    44,    28,    37,    38,    31,
     167,    33,    10,    43,    41,    37,    38,   149,    41,    35,
      37,    43,    42,   155,    30,   157,   139,   166,    39,   106,
     146,   163,   141,   165,   166,   167,   168,    -1,    -1,    -1,
       6,   162,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,     6,     6,     8,     8,    10,    10,
      -1,    -1,    28,    29,    30,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    28,    28,    44,    31,
      31,    33,    33,    -1,    -1,    37,    38,    39,    -1,    -1,
      -1,    43,    43,     6,    -1,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,     9,    10,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,
      -1,    34,    -1,    28,    29,    30,    -1,    40,    -1,    34,
      19,    20,     9,    10,    11,    40,    13,    14,    15,    16,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    41,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      29,    30,    31,    32,    33,    34,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     8,    10,    12,    28,    31,    33,
      37,    38,    43,    46,    48,    52,    53,    55,    57,    61,
      62,    10,    10,    40,    42,    47,    10,    53,    53,    53,
      48,    51,    53,     0,    46,     7,    40,    54,    40,    40,
       9,    10,    11,    13,    14,    15,    16,    28,    29,    30,
      34,    40,    63,    63,    46,    51,    39,    56,    10,    63,
      70,    71,    37,    38,    53,    60,    10,    68,    69,    68,
      40,    40,    63,    63,    63,     6,     8,     9,    44,    63,
      64,    66,    67,    63,    17,    18,    19,    20,    21,    22,
      24,    26,    27,    29,    30,    31,    32,    33,    34,    36,
      41,    37,    60,    42,    41,    44,    59,    42,    44,    66,
      66,    70,    70,    40,    40,    40,    66,    25,    35,    35,
      44,    66,    41,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    10,    58,
      63,    66,    39,    52,    60,    63,    66,    41,    41,    41,
      41,    63,    70,    70,    63,    66,    35,    25,    35,    60,
      71,    69,    49,    42,    63,    41,    41,    41,    25,    35,
      63,    63,    48,    63,    63,    64,    65,    65,    64,    63,
      50,    35,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    46,    46,    48,    48,    48,    48,
      49,    48,    50,    48,    51,    51,    52,    53,    53,    53,
      53,    54,    53,    53,    55,    56,    55,    58,    57,    59,
      59,    59,    60,    60,    60,    61,    61,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     2,     1,     3,     1,     1,
       0,     8,     0,    10,     0,     2,     4,     2,     2,     2,
       2,     0,     3,     1,     1,     0,     4,     0,     6,     0,
       2,     2,     1,     3,     1,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     5,     5,     7,     3,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     5,     4,
       4,     5,     5,     5,     1,     1,     2,     0,     1,     4,
       0,     1,     4,     1,     3,     0,     1,     4,     1,     3
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
        case 3:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { rootmodule->registerUse(std::string((yyvsp[0].text))); }
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[0].inst)) scope_stack.top()->addChild((yyvsp[0].inst));
            }
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 157 "src/parser.y" /* yacc.c:1646  */
    {
                Module *newmodule = new Module();
                newmodule->definition_arguments = *(yyvsp[-2].args);
                scope_stack.top()->modules[(yyvsp[-4].text)] = newmodule;
                scope_stack.push(&newmodule->scope);
                free((yyvsp[-4].text));
                delete (yyvsp[-2].args);
            }
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "src/parser.y" /* yacc.c:1646  */
    {
                scope_stack.pop();
            }
#line 1507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {
                Function *func = Function::create((yyvsp[-6].text), *(yyvsp[-4].args), (yyvsp[0].expr));
                scope_stack.top()->functions[(yyvsp[-6].text)] = func;
                free((yyvsp[-6].text));
                delete (yyvsp[-4].args);
            }
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 186 "src/parser.y" /* yacc.c:1646  */
    {
                bool found = false;
                foreach (Assignment& iter, scope_stack.top()->assignments) {
                    if (iter.first == (yyvsp[-3].text)) {
                        iter.second = boost::shared_ptr<Expression>((yyvsp[-1].expr));
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    scope_stack.top()->assignments.push_back(Assignment((yyvsp[-3].text), boost::shared_ptr<Expression>((yyvsp[-1].expr))));
                }
                free((yyvsp[-3].text));
            }
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = (yyvsp[0].inst);
                if ((yyval.inst)) (yyval.inst)->tag_root = true;
            }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 209 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = (yyvsp[0].inst);
                if ((yyval.inst)) (yyval.inst)->tag_highlight = true;
            }
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = (yyvsp[0].inst);
                if ((yyval.inst)) (yyval.inst)->tag_background = true;
            }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 219 "src/parser.y" /* yacc.c:1646  */
    {
                delete (yyvsp[0].inst);
                (yyval.inst) = NULL;
            }
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = (yyvsp[0].inst);
                scope_stack.push(&(yyvsp[0].inst)->scope);
            }
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {
                scope_stack.pop();
                (yyval.inst) = (yyvsp[-1].inst);
            }
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = (yyvsp[0].ifelse);
            }
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.ifelse) = (yyvsp[0].ifelse);
            }
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "src/parser.y" /* yacc.c:1646  */
    {
                scope_stack.push(&(yyvsp[-1].ifelse)->else_scope);
            }
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "src/parser.y" /* yacc.c:1646  */
    {
                scope_stack.pop();
                (yyval.ifelse) = (yyvsp[-3].ifelse);
            }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 257 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.ifelse) = new IfElseModuleInstantiation();
                (yyval.ifelse)->arguments.push_back(Assignment("", boost::shared_ptr<Expression>((yyvsp[-1].expr))));
                (yyval.ifelse)->setPath(parser_source_path);
                scope_stack.push(&(yyval.ifelse)->scope);
            }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {
                scope_stack.pop();
                (yyval.ifelse) = (yyvsp[-1].ifelse);
            }
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 280 "src/parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[0].inst)) scope_stack.top()->addChild((yyvsp[0].inst));
            }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = (yyvsp[0].text); }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = strdup("for"); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 293 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.inst) = new ModuleInstantiation((yyvsp[-3].text));
                (yyval.inst)->arguments = *(yyvsp[-1].args);
                (yyval.inst)->setPath(parser_source_path);
                free((yyvsp[-3].text));
                delete (yyvsp[-1].args);
            }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr(true));
            }
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 308 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr(false));
            }
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr::undefined);
            }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 316 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLookup((yyvsp[0].text));
                free((yyvsp[0].text));
            }
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 321 "src/parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ExpressionMember((yyvsp[-2].expr), (yyvsp[0].text));
                free((yyvsp[0].text));
            }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 326 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr(std::string((yyvsp[0].text))));
                free((yyvsp[0].text));
            }
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 331 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr((yyvsp[0].number)));
            }
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 335 "src/parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ExpressionLet(*(yyvsp[-2].args), (yyvsp[0].expr));
                delete (yyvsp[-2].args);
            }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 340 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionRange((yyvsp[-3].expr), (yyvsp[-1].expr));
            }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 344 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionRange((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr));
            }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 348 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLcExpression((yyvsp[-1].expr));
            }
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 352 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionConst(ValuePtr(Value::VectorType()));
            }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 356 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = (yyvsp[-2].expr);
            }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 360 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionMultiply((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 364 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionDivision((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 368 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionModulo((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 372 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionPlus((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 376 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionMinus((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 380 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLess((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLessOrEqual((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 388 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionEqual((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 392 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionNotEqual((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 396 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionGreaterOrEqual((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 400 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionGreater((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 404 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLogicalAnd((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionLogicalOr((yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 412 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = (yyvsp[0].expr);
            }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 416 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionInvert((yyvsp[0].expr));
            }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 420 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionNot((yyvsp[0].expr));
            }
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 424 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = (yyvsp[-1].expr);
            }
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionTernary((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 432 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionArrayLookup((yyvsp[-3].expr), (yyvsp[-1].expr));
            }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 436 "src/parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ExpressionFunctionCall((yyvsp[-3].text), *(yyvsp[-1].args));
                free((yyvsp[-3].text));
                delete (yyvsp[-1].args);
            }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 447 "src/parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ExpressionLc("let", *(yyvsp[-2].args), (yyvsp[0].expr));
                delete (yyvsp[-2].args);
            }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 452 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = (yyvsp[0].expr);

                /* transform for(i=...,j=...) -> for(i=...) for(j=...) */
                for (int i = (yyvsp[-2].args)->size()-1; i >= 0; i--) {
                  AssignmentList arglist;
                  arglist.push_back((*(yyvsp[-2].args))[i]);
                  Expression *e = new ExpressionLc("for", arglist, (yyval.expr));
                    (yyval.expr) = e;
                }
                delete (yyvsp[-2].args);
            }
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 465 "src/parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ExpressionLc("if", (yyvsp[-2].expr), (yyvsp[0].expr));
            }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 482 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new ExpressionVector((yyvsp[0].expr));
            }
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 486 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = (yyvsp[-3].expr);
                (yyval.expr)->children.push_back((yyvsp[0].expr));
            }
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 494 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = new AssignmentList();
            }
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 498 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = new AssignmentList();
                (yyval.args)->push_back(*(yyvsp[0].arg));
                delete (yyvsp[0].arg);
            }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 504 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = (yyvsp[-3].args);
                (yyval.args)->push_back(*(yyvsp[0].arg));
                delete (yyvsp[0].arg);
            }
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 513 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arg) = new Assignment((yyvsp[0].text));
                free((yyvsp[0].text));
            }
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 518 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arg) = new Assignment((yyvsp[-2].text), boost::shared_ptr<Expression>((yyvsp[0].expr)));
                free((yyvsp[-2].text));
            }
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 526 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = new AssignmentList();
            }
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 530 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = new AssignmentList();
                (yyval.args)->push_back(*(yyvsp[0].arg));
                delete (yyvsp[0].arg);
            }
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 536 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.args) = (yyvsp[-3].args);
                (yyval.args)->push_back(*(yyvsp[0].arg));
                delete (yyvsp[0].arg);
            }
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arg) = new Assignment("", boost::shared_ptr<Expression>((yyvsp[0].expr)));
            }
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 549 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arg) = new Assignment((yyvsp[-2].text), boost::shared_ptr<Expression>((yyvsp[0].expr)));
                free((yyvsp[-2].text));
            }
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2092 "parser.tab.c" /* yacc.c:1646  */
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
#line 555 "src/parser.y" /* yacc.c:1906  */


int parserlex(void)
{
  return lexerlex();
}

void yyerror (char const *s)
{
  // FIXME: We leak memory on parser errors...
  PRINTB("ERROR: Parser error in line %d: %s\n", lexerget_lineno() % s);
}

FileModule *parse(const char *text, const char *path, int debug)
{
  lexerin = NULL;
  parser_error_pos = -1;
  parser_input_buffer = text;
  parser_source_path = boosty::absolute(std::string(path)).string();

  rootmodule = new FileModule();
  rootmodule->setModulePath(path);
  scope_stack.push(&rootmodule->scope);
  //        PRINTB_NOCACHE("New module: %s %p", "root" % rootmodule);

  parserdebug = debug;
  int parserretval = parserparse();
  lexerdestroy();
  lexerlex_destroy();

  if (parserretval != 0) return NULL;

  parser_error_pos = -1;
  scope_stack.pop();
  return rootmodule;
}
