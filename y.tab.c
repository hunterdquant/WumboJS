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




/* Copy the first part of user declarations.  */
#line 4 "wumbo.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>
  #include <string.h>


  #include "sym_table.h"
  #include "exp_tree.h"
  #include "defs.h"
  #include "stmt.h"
  #include "decl.h"
  #include "gencode.h"


  extern FILE *yyin;
  extern long int LINE_COUNT;
  sym_stack_t *sym_table;
  FILE *wout;

#line 87 "y.tab.c" /* yacc.c:339  */

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
    PROGRAM = 258,
    VAR = 259,
    ARRAY = 260,
    OF = 261,
    INTEGER = 262,
    REAL = 263,
    FUNCTION = 264,
    PROCEDURE = 265,
    BBEGIN = 266,
    END = 267,
    ASSIGNOP = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    WHILE = 272,
    FOR = 273,
    DO = 274,
    TO = 275,
    DOTDOT = 276,
    ID = 277,
    INUM = 278,
    RNUM = 279,
    ADDOP = 280,
    MULOP = 281,
    RELOP = 282,
    NOT = 283
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define VAR 259
#define ARRAY 260
#define OF 261
#define INTEGER 262
#define REAL 263
#define FUNCTION 264
#define PROCEDURE 265
#define BBEGIN 266
#define END 267
#define ASSIGNOP 268
#define IF 269
#define THEN 270
#define ELSE 271
#define WHILE 272
#define FOR 273
#define DO 274
#define TO 275
#define DOTDOT 276
#define ID 277
#define INUM 278
#define RNUM 279
#define ADDOP 280
#define MULOP 281
#define RELOP 282
#define NOT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "wumbo.y" /* yacc.c:355  */

	char *sval;
	int ival;
	float fval;
	op_type opval;
	sym_stack_t *sym_stack_val;
	sym_node_t *sym_ref;
	stmt_t *stmt_val;
	exp_tree_t *exp_val;
	exp_list_t *exp_list_val;
	stmt_list_t *stmt_list_val;
	id_list_t *id_list;
	data_type_t *data_type;
	data_type_list_t *data_type_list;
	simple_type stype;

#line 200 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      29,    30,     2,     2,    33,     2,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    94,   140,   144,   153,   159,   176,   179,
     183,   190,   194,   200,   201,   204,   218,   217,   235,   234,
     252,   256,   262,   285,   317,   325,   329,   335,   339,   349,
     350,   352,   356,   363,   367,   375,   382,   396,   405,   414,
     422,   436,   451,   467,   471,   480,   486,   490,   499,   503,
     508,   517,   521,   530,   536,   555,   569,   575,   581,   586,
     594
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "ARRAY", "OF",
  "INTEGER", "REAL", "FUNCTION", "PROCEDURE", "BBEGIN", "END", "ASSIGNOP",
  "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "TO", "DOTDOT", "ID", "INUM",
  "RNUM", "ADDOP", "MULOP", "RELOP", "NOT", "'('", "')'", "';'", "'.'",
  "','", "':'", "'['", "']'", "$accept", "program", "$@1",
  "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "$@2", "$@3", "arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement",
  "matched_statement", "unmatched_statement", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,     1,    26,     8,  -104,    23,  -104,     0,  -104,    20,
      49,  -104,  -104,  -104,    73,  -104,    23,    64,  -104,    31,
      66,    67,     2,    59,  -104,    60,    27,  -104,  -104,    38,
      38,    69,    -4,  -104,    82,    65,  -104,  -104,  -104,    84,
    -104,  -104,  -104,    73,  -104,    63,  -104,  -104,    68,  -104,
      72,    72,    -8,  -104,  -104,    25,    25,    38,    80,    51,
      76,  -104,    85,    70,    90,    38,    38,  -104,     2,    38,
      64,    83,  -104,    23,    75,  -104,    77,    38,    38,    76,
    -104,    81,     2,    25,    38,    25,     2,    38,    22,  -104,
    -104,    71,  -104,  -104,  -104,    89,    46,    54,    74,  -104,
      39,    78,  -104,  -104,    96,    76,    88,  -104,  -104,    95,
    -104,    38,  -104,    93,    27,  -104,    23,    86,  -104,  -104,
       2,    38,  -104,    87,  -104,    53,  -104,  -104,  -104,    99,
     113,    27,     2,    74,  -104,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    60,     4,     0,     6,     0,
       0,     2,     5,    60,    60,     8,    60,     0,    14,     0,
       0,     0,    60,     0,    60,     0,     0,    16,    18,     0,
       0,     0,    41,    33,     0,    25,    27,    29,    30,     0,
      31,    26,    13,    60,     3,     0,    11,    12,     0,     9,
      60,    60,    53,    56,    57,     0,     0,     0,     0,    46,
      48,    51,     0,    39,     0,    60,     0,    24,     0,     0,
       0,     0,     7,    60,     0,    21,     0,    60,     0,    49,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      45,     0,    28,    32,    15,     0,     0,     0,     0,    19,
       0,     0,    58,    37,    29,    50,    47,    52,    35,     0,
      42,     0,    40,     0,     0,    20,    60,     0,    54,    55,
       0,     0,    44,     0,    22,     0,    17,    34,    38,     0,
       0,     0,     0,     0,    23,    36,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,   -16,    97,  -103,   -93,    79,  -104,  -104,
    -104,  -104,    91,  -104,   -14,  -104,  -104,   -64,   -74,     4,
      94,  -104,    43,   -28,    42,   -41,   -46,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    13,     7,    14,    48,    49,    17,    23,    24,
      50,    51,    74,    97,    33,    34,    35,    36,    37,    38,
      39,    40,    88,    89,    59,    60,    61,     8
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    58,    62,    25,    92,   117,    15,    18,   104,   -39,
      80,   124,     1,    22,    79,    41,    29,    15,   103,    30,
      31,    77,   108,     3,    32,    65,     4,    78,   134,    81,
       9,    66,    45,    10,    46,    47,    18,     5,    91,   107,
     136,    93,   105,    75,    75,     6,   127,    52,    53,    54,
     101,    11,   110,    56,    57,   111,    94,    96,    90,   109,
      52,    53,    54,    55,    10,    26,    56,    57,   135,   118,
      90,    12,   111,    20,    21,    22,    83,    16,    84,    10,
     114,    46,    47,   122,   115,   116,    10,   131,    27,    28,
      42,    63,    44,   129,    67,    82,    68,    69,    71,    72,
     125,    73,    85,    87,    86,    66,    95,   112,    99,    98,
     113,   102,   120,    83,   119,   121,   123,   126,   132,   133,
     100,    43,    70,   130,   128,    64,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      16,    29,    30,    17,    68,    98,    13,    14,    82,    13,
      56,   114,     3,    11,    55,    22,    14,    24,    82,    17,
      18,    29,    86,    22,    22,    29,     0,    35,   131,    57,
      30,    35,     5,    33,     7,     8,    43,    29,    66,    85,
     133,    69,    83,    50,    51,    22,   120,    22,    23,    24,
      78,    31,    30,    28,    29,    33,    70,    73,    65,    87,
      22,    23,    24,    25,    33,    34,    28,    29,   132,    30,
      77,    22,    33,     9,    10,    11,    25,     4,    27,    33,
      34,     7,     8,   111,    30,    31,    33,    34,    22,    22,
      31,    22,    32,   121,    12,    15,    31,    13,    35,    31,
     116,    29,    26,    13,    19,    35,    23,    36,    31,    34,
      21,    30,    16,    25,    36,    20,    23,    31,    19,     6,
      77,    24,    43,    36,   120,    31,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    22,     0,    29,    22,    40,    64,    30,
      33,    31,    22,    39,    41,    64,     4,    44,    64,    40,
       9,    10,    11,    45,    46,    51,    34,    22,    22,    14,
      17,    18,    22,    51,    52,    53,    54,    55,    56,    57,
      58,    64,    31,    41,    32,     5,     7,     8,    42,    43,
      47,    48,    22,    23,    24,    25,    28,    29,    60,    61,
      62,    63,    60,    22,    57,    29,    35,    12,    31,    13,
      44,    35,    31,    29,    49,    64,    49,    29,    35,    62,
      63,    60,    15,    25,    27,    26,    19,    13,    59,    60,
      64,    60,    54,    60,    51,    23,    40,    50,    34,    31,
      59,    60,    30,    54,    55,    62,    61,    63,    54,    60,
      30,    33,    36,    21,    34,    30,    31,    43,    30,    36,
      16,    20,    60,    23,    42,    40,    31,    55,    56,    60,
      36,    34,    19,     6,    42,    54,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    47,    46,    48,    46,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    11,     1,     3,     1,     6,     1,     1,
       8,     1,     1,     3,     1,     4,     0,     7,     0,     5,
       3,     1,     3,     5,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     6,     4,     8,     4,     6,     1,
       4,     1,     4,     1,     3,     1,     1,     3,     1,     2,
       3,     1,     3,     1,     4,     4,     1,     1,     3,     2,
       0
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
#line 95 "wumbo.y" /* yacc.c:1646  */
    {
		char *name = (yyvsp[-4].sval);
		sym_table = init_sym_stack(init_sym_table(), NULL, 0);
		gen_code_main(wout, name);

		proc_type_t *main = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)NULL)));
		sym_node_t *node = init_sym_node(name, PROC_NODE, main, 0);
		table_put(sym_table->scope, node);
		sym_table->sym_ref = node;
		id_list_t *id_list = (yyvsp[-2].id_list);
		int in = 0, out = 0;
		while (id_list) {
			if (!in && strcmp(id_list->id, "input")) {
				in = !in;
				proc_type_t *input = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)INTEGER_TYPE)));
				sym_node_t *node = init_sym_node("read", PROC_NODE, input, 0);
				table_put(sym_table->scope, node);
			} else if (!out && strcmp(id_list->id, "output")) {
				out = !out;
				proc_type_t *output = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)INTEGER_TYPE)));
				sym_node_t *node = init_sym_node("write", PROC_NODE, output, 0);
				table_put(sym_table->scope, node);
			}
			id_list = id_list->next;
		}
		destroy_id_list((yyvsp[-2].id_list));
	}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 126 "wumbo.y" /* yacc.c:1646  */
    {
		char *name = (yyvsp[-9].sval);

		(yyval.sym_stack_val) = sym_table;
		wprintf("\n");
		print_stmt_tree((yyvsp[-1].stmt_val), 0);
		semantic_check_body(sym_table, sym_table->sym_ref, (yyvsp[-1].stmt_val));
		gen_code_stmt(wout, (yyvsp[-1].stmt_val));
		gen_code_end_main(wout);
		destroy_stmt((yyvsp[-1].stmt_val));
		destroy_sym_stack(sym_table);
	}
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.id_list) = init_id_list((yyvsp[0].sval));
	}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "wumbo.y" /* yacc.c:1646  */
    {
		id_list_t *tmp = (yyvsp[-2].id_list);
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = init_id_list((yyvsp[0].sval));
		(yyval.id_list) = (yyvsp[-2].id_list);
	}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.id_list) = NULL;
	}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 160 "wumbo.y" /* yacc.c:1646  */
    {
		data_type_t *type = (yyvsp[-1].data_type);
		id_list_t *list = (yyvsp[-3].id_list);

		while (list) {
			if (table_get(sym_table->scope, list->id)) {
				panic("\nSymbol, %s, is defined more than once at line number %d.\n", list->id, LINE_COUNT);
			}
			sym_node_t *node = init_sym_node(list->id, PRIM_NODE, (yyvsp[-1].data_type), sym_table->scope->offset);
			sym_table->scope->offset+=4;
			table_put(sym_table->scope, node);
			list = list->next;
		}
		gen_code_variable_decl(wout, (yyvsp[-3].id_list));
		destroy_id_list((yyvsp[-3].id_list));
	}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 180 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.data_type) = init_data_type(SIMPLE_SYM, (void *)(yyvsp[0].stype));
	}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 184 "wumbo.y" /* yacc.c:1646  */
    {
		data_array_t *tmp = init_data_array((yyvsp[-5].ival), (yyvsp[-3].ival), (yyvsp[0].stype));
		(yyval.data_type) = init_data_type(ARRAY_SYM, (void *)tmp);
	}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stype) = INTEGER_TYPE;
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 195 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stype) = REAL_TYPE;
	}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 205 "wumbo.y" /* yacc.c:1646  */
    {
		int check = semantic_check_body(sym_table, sym_table->sym_ref, (yyvsp[0].stmt_val));
		if (!check) {
			panic("\nFunction is missing a return statement, line %d\n", LINE_COUNT);
		}
		print_stmt_tree((yyvsp[0].stmt_val), 0);
		gen_code_stmt(wout, (yyvsp[0].stmt_val));
		gen_code_func_end(wout);
		destroy_sym_stack(stack_pop(&sym_table));
		destroy_stmt((yyvsp[0].stmt_val));
	}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "wumbo.y" /* yacc.c:1646  */
    {
			if (table_get(sym_table->scope, (yyvsp[0].sval))) {
				panic("\nFunction or procedure with name, %s, already defined. Line %d\n", (yyvsp[0].sval), LINE_COUNT);
			}
			sym_table = stack_push(sym_table, init_sym_table(), NULL);
			gen_code_func_begin1(wout, (yyvsp[0].sval));
	}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "wumbo.y" /* yacc.c:1646  */
    {
		sym_stack_t *tmp = stack_pop(&sym_table);
		func_type_t *func = init_func_type((yyvsp[-3].data_type_list), (yyvsp[-1].stype));
		sym_node_t *node = init_sym_node(strdup((yyvsp[-5].sval)), FUNC_NODE, func, sym_table->scope->offset);
		table_put(sym_table->scope, node);
		sym_table = stack_push(sym_table, tmp->scope, table_put(sym_table->scope, node));
		gen_code_func_begin2(wout);
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 235 "wumbo.y" /* yacc.c:1646  */
    {
		if (table_get(sym_table->scope, (yyvsp[0].sval))) {
			panic("\nFunction or procedure with name, %s, already defined. Line %d\n", (yyvsp[0].sval), LINE_COUNT);
		}
		sym_table = stack_push(sym_table, init_sym_table(), NULL);
		gen_code_func_begin1(wout, (yyvsp[0].sval));
	}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "wumbo.y" /* yacc.c:1646  */
    {
		sym_stack_t *tmp = stack_pop(&sym_table);
		proc_type_t *proc = init_proc_type((yyvsp[-1].data_type_list));
		sym_node_t *node = init_sym_node(strdup((yyvsp[-3].sval)), PROC_NODE, proc, sym_table->scope->offset);
		sym_table = stack_push(sym_table, tmp->scope, table_put(sym_table->scope, node));
		gen_code_func_begin2(wout);
	}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 253 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.data_type_list) = (yyvsp[-1].data_type_list);
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 257 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.data_type_list) = NULL;
	}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 263 "wumbo.y" /* yacc.c:1646  */
    {
		data_type_t *type = (yyvsp[0].data_type);
		id_list_t *list = (yyvsp[-2].id_list);
		while (list) {
			sym_table->scope->offset-=4;
			sym_node_t *node = init_sym_node(list->id, PRIM_NODE, type, sym_table->scope->offset);
			table_put(sym_table->scope, node);
			list = list->next;
		}

		list = (yyvsp[-2].id_list);
		data_type_list_t *tmp = init_data_type_list(type);
		data_type_list_t *cur = tmp;
		list = list->next;
		while (list) {
			cur->next = init_data_type_list(type);
			cur = cur->next;
			list = list->next;
		}
		gen_code_identifier_list(wout, (yyvsp[-2].id_list));
		(yyval.data_type_list) = tmp;
	}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 286 "wumbo.y" /* yacc.c:1646  */
    {
		data_type_t *type = (yyvsp[0].data_type);
		id_list_t *list = (yyvsp[-2].id_list);
		wfprintf(wout, ", ");
		gen_code_identifier_list(wout, (yyvsp[-2].id_list));

		while (list) {
			sym_node_t *node = init_sym_node(strdup(list->id), PRIM_NODE, type, sym_table->scope->offset);
			table_put(sym_table->scope, node);
			list = list->next;
		}

		list = (yyvsp[-2].id_list);
		data_type_list_t *tmp = init_data_type_list(type);
		data_type_list_t *cur = tmp;
		list = list->next;
		while (list) {
			cur->next = init_data_type_list(type);
			cur = cur->next;
			list = list->next;
		}
		data_type_list_t *tmp2 = (yyvsp[-4].data_type_list);
		cur = tmp2;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = tmp;
		(yyval.data_type_list) = tmp2;
	}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 318 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(COMPOUND_STMT);
		tmp->stmt.compound_stmt.body_stmt = (yyvsp[-1].stmt_list_val);
		(yyval.stmt_val) = tmp;
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 326 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stmt_list_val) = (yyvsp[0].stmt_list_val);
	}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 330 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stmt_list_val) = NULL;
	}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 336 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stmt_list_val) = init_stmt_list((yyvsp[0].stmt_val));
	}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 339 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_list_t *tmp = (yyvsp[-2].stmt_list_val);
		while (tmp->next) {
			tmp = tmp->next;	
		}
		tmp->next = init_stmt_list((yyvsp[0].stmt_val));
		(yyval.stmt_list_val) = (yyvsp[-2].stmt_list_val);
	}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 349 "wumbo.y" /* yacc.c:1646  */
    {(yyval.stmt_val) = (yyvsp[0].stmt_val);}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 350 "wumbo.y" /* yacc.c:1646  */
    {(yyval.stmt_val) = (yyvsp[0].stmt_val);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 353 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stmt_val) = (yyvsp[0].stmt_val);
	}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 357 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(ASSIGNMENT_STMT);
		tmp->stmt.assn_stmt.sym_ref = (yyvsp[-2].sym_ref);
		tmp->stmt.assn_stmt.exp = (yyvsp[0].exp_val);
		(yyval.stmt_val) = tmp;
	}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 364 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.stmt_val) = (yyvsp[0].stmt_val);
	}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 368 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(IF_STMT);
		tmp->stmt.if_stmt.exp = (yyvsp[-4].exp_val);
		tmp->stmt.if_stmt.true_stmt = (yyvsp[-2].stmt_val);
		tmp->stmt.if_stmt.false_stmt = (yyvsp[0].stmt_val);
		(yyval.stmt_val) = tmp;
	}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 376 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(WHILE_STMT);
		tmp->stmt.while_stmt.exp = (yyvsp[-2].exp_val);
		tmp->stmt.while_stmt.body_stmt = (yyvsp[0].stmt_val);
		(yyval.stmt_val) = tmp;
	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 383 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *assn = init_stmt(ASSIGNMENT_STMT);
		assn->stmt.assn_stmt.sym_ref = (yyvsp[-6].sym_ref);
		assn->stmt.assn_stmt.exp = (yyvsp[-4].exp_val);
		stmt_t *tmp = init_stmt(FOR_STMT);
		tmp->stmt.for_stmt.exp_bound = (yyvsp[-2].exp_val);
		tmp->stmt.for_stmt.body_stmt = (yyvsp[0].stmt_val);
		tmp->stmt.for_stmt.assign_stmt = assn;
		(yyval.stmt_val) = tmp;
	}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 397 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(IF_STMT);
		ret_type t = get_exp_type((yyvsp[-2].exp_val));
		tmp->stmt.if_stmt.exp = (yyvsp[-2].exp_val);
		tmp->stmt.if_stmt.true_stmt = (yyvsp[0].stmt_val);
		tmp->stmt.if_stmt.false_stmt = NULL;
		(yyval.stmt_val) = tmp;
	}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 406 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(IF_STMT);
		tmp->stmt.if_stmt.exp = (yyvsp[-4].exp_val);
		tmp->stmt.if_stmt.true_stmt = (yyvsp[-2].stmt_val);
		tmp->stmt.if_stmt.false_stmt = (yyvsp[0].stmt_val);
		(yyval.stmt_val) = tmp;
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 415 "wumbo.y" /* yacc.c:1646  */
    {
		sym_node_t *ref = search_stack(sym_table, (yyvsp[0].sval));
		if (!ref) {
			panic("\nError \"%s\" not defined, line %d\n", (yyvsp[0].sval), LINE_COUNT);
		}
		(yyval.sym_ref) = ref;
	}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "wumbo.y" /* yacc.c:1646  */
    {
		sym_node_t *ref = search_stack(sym_table, (yyvsp[-3].sval));
		ret_type t = get_exp_type((yyvsp[-1].exp_val));
		if (!ref) {
			panic("\nError \"%s\" not defined, line %d\n", (yyvsp[-3].sval), LINE_COUNT);
		}
		if (t != INTEGER_RET) {
			panic("\nError ARRAY must be indexed using INTEGER type, line %d\n", LINE_COUNT);
		}
		(yyval.sym_ref) = ref;
	}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 437 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(PROCEDURE_STMT);
		sym_node_t *ref = search_stack(sym_table, (yyvsp[0].sval));
		wprintf("\n%s\n", ref->sym);
		if (!ref) {
			panic("\nProcedure with ID \"%s\" is not visable in this scope, line %d\n", (yyvsp[0].sval), LINE_COUNT);
		}
		if (ref->ntype != PROC_NODE) {
			panic("\n\"%s\" is not a procedure, line %d\n", (yyvsp[0].sval), LINE_COUNT);
		}
		tmp->stmt.proc_stmt.sym_ref = ref;
		tmp->stmt.proc_stmt.exp_list = NULL;
		(yyval.stmt_val) = tmp;
	}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 452 "wumbo.y" /* yacc.c:1646  */
    {
		stmt_t *tmp = init_stmt(PROCEDURE_STMT);
		sym_node_t *ref = search_stack(sym_table, (yyvsp[-3].sval));
		if (!ref) {
			panic("\nProcedure with ID \"%s\" is not visable in this scope, line %d\n", (yyvsp[-3].sval), LINE_COUNT);
		}
		if (ref->ntype != PROC_NODE) {
			panic("\n\"%s\" is not a procedure, line %d\n", (yyvsp[-3].sval), LINE_COUNT);
		}
		tmp->stmt.proc_stmt.sym_ref = ref;
		tmp->stmt.proc_stmt.exp_list = (yyvsp[-1].exp_list_val);
		(yyval.stmt_val) = tmp;
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 468 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_list_val) = init_exp_list((yyvsp[0].exp_val));
	}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 472 "wumbo.y" /* yacc.c:1646  */
    {
		exp_list_t *tmp = (yyvsp[-2].exp_list_val);
		while(tmp->next) {
			tmp = tmp->next;	
		}
		tmp->next = init_exp_list((yyvsp[0].exp_val));
		(yyval.exp_list_val) = (yyvsp[-2].exp_list_val);
	}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 481 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_list_val) = NULL;
	}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 487 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_val) = (yyvsp[0].exp_val);
	}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 491 "wumbo.y" /* yacc.c:1646  */
    {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)(yyvsp[-1].opval));
		(yyval.exp_val) = init_exp_tree(node);
		(yyval.exp_val)->right = (yyvsp[0].exp_val);
		(yyval.exp_val)->left = (yyvsp[-2].exp_val);
	}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 500 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_val) = (yyvsp[0].exp_val);
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 503 "wumbo.y" /* yacc.c:1646  */
    {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)(yyvsp[-1].opval));
		(yyval.exp_val) = init_exp_tree(node);
		(yyval.exp_val)->right = (yyvsp[0].exp_val);
	}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 509 "wumbo.y" /* yacc.c:1646  */
    {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)(yyvsp[-1].opval));
		(yyval.exp_val) = init_exp_tree(node);
		(yyval.exp_val)->right = (yyvsp[0].exp_val);
		(yyval.exp_val)->left = (yyvsp[-2].exp_val);
	}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 518 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_val) = (yyvsp[0].exp_val);
	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 522 "wumbo.y" /* yacc.c:1646  */
    {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)(yyvsp[-1].opval));
		(yyval.exp_val) = init_exp_tree(node);
		(yyval.exp_val)->right = (yyvsp[0].exp_val);
		(yyval.exp_val)->left = (yyvsp[-2].exp_val);
	}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 531 "wumbo.y" /* yacc.c:1646  */
    {
		sym_node_t *ref = search_stack(sym_table, (yyvsp[0].sval));
		exp_node_t *node = init_exp_node(VAR_EXP, (void *)ref);
		(yyval.exp_val) = init_exp_tree(node);
	}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 537 "wumbo.y" /* yacc.c:1646  */
    {
		sym_node_t *ref = search_stack(sym_table, (yyvsp[-3].sval));
		if (ref->ntype == PROC_NODE) {
			panic("\nProcedures have no return value and connot be used in expressions, line %d\n", LINE_COUNT);
		}
		func_exp_t *func = init_func_exp(ref, (yyvsp[-1].exp_list_val));
		exp_node_t *node = init_exp_node(FUNC_EXP, (void *)func);
		exp_list_t *exp_list = (yyvsp[-1].exp_list_val);
		data_type_list_t *dt_list = ref->ftype->types;
		while (exp_list && dt_list) {
			exp_list = exp_list->next;
			dt_list = dt_list->next;
		}
		if ((!dt_list && exp_list) || (dt_list && exp_list)) {
			panic("\nFunction, %s, does not have the required number of arguments, line %d\n", (yyvsp[-3].sval), LINE_COUNT);
		}
		(yyval.exp_val) = init_exp_tree(node);
	}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 556 "wumbo.y" /* yacc.c:1646  */
    {
		sym_node_t *ref = search_stack(sym_table, (yyvsp[-3].sval));
		array_exp_t *array = init_array_exp(ref, (yyvsp[-1].exp_val));
		exp_node_t *node = init_exp_node(ARRAY_EXP, (void *)array);
		ret_type t = get_exp_type((yyvsp[-1].exp_val));
		if (!ref) {
			panic("\nError \"%s\" not defined, line %d\n", (yyvsp[-3].sval), LINE_COUNT);
		}
		if (t != INTEGER_RET) {
			panic("\nError ARRAY must be indexed using INTEGER type, line %d\n", LINE_COUNT);
		}
		(yyval.exp_val) = init_exp_tree(node);
	}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 570 "wumbo.y" /* yacc.c:1646  */
    {
		int *val = &(yyvsp[0].ival);
		exp_node_t *node = init_exp_node(INTEGER_EXP, (void *)val);
		(yyval.exp_val) = init_exp_tree(node);
	}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 576 "wumbo.y" /* yacc.c:1646  */
    {
		float *val = &(yyvsp[0].fval);
		exp_node_t *node = init_exp_node(REAL_EXP, (void *)val);
		(yyval.exp_val) = init_exp_tree(node);
	}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 582 "wumbo.y" /* yacc.c:1646  */
    {
		(yyval.exp_val) = (yyvsp[-1].exp_val);
		(yyval.exp_val)->is_paren = 1;
	}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 587 "wumbo.y" /* yacc.c:1646  */
    {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)(yyvsp[-1].opval));
		(yyval.exp_val) = init_exp_tree(node);
		(yyval.exp_val)->right = (yyvsp[0].exp_val);
	}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2057 "y.tab.c" /* yacc.c:1646  */
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
#line 597 "wumbo.y" /* yacc.c:1906  */


int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr, "USAGE: ./wumbo <inputfile> <outputfile>");
		return -1;
	}
	
	FILE *input_file = fopen(argv[1], "r");

	if (!input_file) {
		fprintf(stderr, "Can't open input file: %s\n", argv[1]);
		return -1;
	}

	if (argc == 3) {
		wout = fopen(argv[2], "w");
	} else {
		wout = fopen("out.js", "w");
	}
	yyin = input_file;

	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
}
