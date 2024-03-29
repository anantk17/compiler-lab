/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "slpi.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    #include "exptree.h"
    #include "symboltable.h"

   int yylex(void); 
   extern struct SymbolTable st;
   extern struct LocalTable lt;
   extern struct arg_list alist;
   int type;
   int func_type;
   int sp=0,bp=0;
   FILE* outFile;
   char filename[50];

/* Line 371 of yacc.c  */
#line 86 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGIT = 258,
     EQUAL = 259,
     BOL = 260,
     ID = 261,
     READ = 262,
     WRITE = 263,
     IF = 264,
     THEN = 265,
     ELSE = 266,
     ENDIF = 267,
     WHILE = 268,
     DO = 269,
     ENDWHILE = 270,
     INTEGER = 271,
     DECL = 272,
     ENDDECL = 273,
     BOOLEAN = 274,
     FBEGIN = 275,
     RETURN = 276,
     END = 277,
     MAIN = 278,
     OR = 279,
     AND = 280,
     NOTEQUAL = 281,
     EQUALITY = 282,
     GTE = 283,
     LTE = 284,
     NOT = 285
   };
#endif
/* Tokens.  */
#define DIGIT 258
#define EQUAL 259
#define BOL 260
#define ID 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define INTEGER 271
#define DECL 272
#define ENDDECL 273
#define BOOLEAN 274
#define FBEGIN 275
#define RETURN 276
#define END 277
#define MAIN 278
#define OR 279
#define AND 280
#define NOTEQUAL 281
#define EQUALITY 282
#define GTE 283
#define LTE 284
#define NOT 285



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 19 "slpi.y"

    int ival;
    char* name;
    struct tree_node *nptr;
    struct arg_node *args;


/* Line 387 of yacc.c  */
#line 197 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 225 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,    45,     2,
      39,    40,    35,    33,    42,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      30,    24,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    31,    32,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    13,    16,    17,    21,    23,
      25,    29,    31,    33,    38,    39,    45,    47,    48,    51,
      54,    58,    62,    64,    67,    69,    72,    73,    74,    75,
      87,    88,    98,   102,   105,   106,   110,   114,   116,   121,
     124,   125,   130,   135,   141,   147,   153,   162,   173,   182,
     186,   190,   194,   198,   202,   206,   210,   214,   218,   222,
     226,   230,   234,   237,   241,   243,   245,   247,   252,   254,
     258,   260,   261,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    50,    51,    63,    67,    -1,    17,
      52,    18,    -1,    53,    52,    -1,    -1,    54,    55,    41,
      -1,    16,    -1,    19,    -1,    56,    42,    55,    -1,    56,
      -1,     6,    -1,     6,    43,     3,    44,    -1,    -1,     6,
      57,    39,    58,    40,    -1,    59,    -1,    -1,    60,    59,
      -1,    54,    61,    -1,    54,    61,    41,    -1,    62,    42,
      61,    -1,    62,    -1,    45,     6,    -1,     6,    -1,    63,
      64,    -1,    -1,    -1,    -1,    54,    65,     6,    39,    58,
      40,    66,    46,    69,    73,    47,    -1,    -1,    16,    68,
      23,    39,    40,    46,    69,    73,    47,    -1,    17,    70,
      18,    -1,    71,    70,    -1,    -1,    54,    72,    41,    -1,
       6,    42,    72,    -1,     6,    -1,    20,    74,    79,    22,
      -1,    75,    74,    -1,    -1,    78,    24,    76,    41,    -1,
       6,    24,    76,    41,    -1,     7,    39,    78,    40,    41,
      -1,     7,    39,     6,    40,    41,    -1,     8,    39,    76,
      40,    41,    -1,     9,    39,    76,    40,    10,    74,    12,
      41,    -1,     9,    39,    76,    40,    10,    74,    11,    74,
      12,    41,    -1,    13,    39,    76,    40,    14,    74,    15,
      41,    -1,    76,    33,    76,    -1,    76,    34,    76,    -1,
      76,    35,    76,    -1,    76,    36,    76,    -1,    76,    37,
      76,    -1,    76,    29,    76,    -1,    76,    30,    76,    -1,
      76,    32,    76,    -1,    76,    31,    76,    -1,    76,    28,
      76,    -1,    76,    27,    76,    -1,    76,    26,    76,    -1,
      76,    25,    76,    -1,    38,    76,    -1,    39,    76,    40,
      -1,     3,    -1,     6,    -1,    78,    -1,     6,    39,    77,
      40,    -1,     5,    -1,    77,    42,    76,    -1,    76,    -1,
      -1,     6,    43,    76,    44,    -1,    21,    76,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    46,    50,    53,    54,    57,    60,    61,
      64,    65,    68,    69,    70,    70,    74,    75,    77,    78,
      81,    84,    85,    88,    89,    91,    92,    95,    95,    95,
      98,    98,   101,   104,   105,   108,   111,   112,   115,   118,
     119,   122,   123,   124,   125,   126,   127,   128,   129,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   154,
     155,   156,   159,   162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "EQUAL", "BOL", "ID", "READ",
  "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "INTEGER", "DECL", "ENDDECL", "BOOLEAN", "FBEGIN", "RETURN", "END",
  "MAIN", "'='", "OR", "AND", "NOTEQUAL", "EQUALITY", "'>'", "'<'", "GTE",
  "LTE", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT", "'('", "')'", "';'",
  "','", "'['", "']'", "'&'", "'{'", "'}'", "$accept", "start", "$@1",
  "gdecl", "decllist", "decl", "dtype", "idlist", "declid", "$@2",
  "decarglist", "decargglist", "decargentry", "decargidlist", "decargid",
  "fdeflist", "fdef", "$@3", "$@4", "mainblock", "$@5", "LDefblock",
  "ldecllist", "ldecl", "lidlist", "Body", "slist", "stmt", "E",
  "carglist", "IDT", "RetStmt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    61,   279,   280,   281,   282,    62,
      60,   283,   284,    43,    45,    42,    47,    37,   285,    40,
      41,    59,    44,    91,    93,    38,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    49,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    57,    56,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    65,    66,    64,
      68,    67,    69,    70,    70,    71,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    78,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     3,     2,     0,     3,     1,     1,
       3,     1,     1,     4,     0,     5,     1,     0,     2,     2,
       3,     3,     1,     2,     1,     2,     0,     0,     0,    11,
       0,     9,     3,     2,     0,     3,     3,     1,     4,     2,
       0,     4,     4,     5,     5,     5,     8,    10,     8,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     1,     4,     1,     3,
       1,     0,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     6,    26,     8,     9,     0,     6,
       0,     0,     4,     5,    12,     0,    11,     8,    27,    25,
       3,     0,     0,     7,     0,     0,     0,     0,    17,    10,
       0,     0,    13,     0,     0,    16,     0,     0,    17,    24,
       0,    19,    22,    15,    18,     0,     0,    23,    20,     0,
       0,    28,    21,    34,     0,     0,     0,     0,    34,    40,
       0,     0,    37,     0,    32,    33,     0,     0,     0,     0,
       0,     0,    40,     0,    31,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    36,
      64,    68,    65,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,    38,     0,    29,    71,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    72,     0,     0,     0,     0,     0,
      73,    41,    70,     0,    63,    61,    60,    59,    58,    54,
      55,    57,    56,    49,    50,    51,    52,    53,    44,    43,
      45,    40,    40,    67,     0,     0,     0,    69,    40,     0,
       0,     0,    46,    48,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     8,     9,    33,    15,    16,    22,
      34,    35,    36,    41,    42,    11,    19,    26,    55,    20,
      25,    54,    57,    58,    63,    60,    71,    72,    95,   133,
      96,    85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     -78,     3,     7,   -78,    13,   -78,   -78,   -78,     1,    13,
      40,    49,   -78,   -78,   -25,    16,    24,    53,   -78,   -78,
     -78,    76,    50,   -78,    40,    62,    84,    51,    13,   -78,
      52,    55,   -78,     2,    56,   -78,    13,    57,    13,   -78,
      92,    72,    73,   -78,   -78,    68,    77,   -78,   -78,     2,
      99,   -78,   -78,    13,    98,    87,   128,   117,    13,    54,
     103,    99,   109,   111,   -78,   -78,   -15,   130,   145,   161,
     177,   147,    54,   143,   -78,    98,   128,   -78,    20,    20,
     179,    20,    20,    20,    20,   195,   -78,    20,   154,   -78,
     -78,   -78,   -12,    20,    20,    95,   -78,    75,    35,   192,
     146,   162,   178,   112,   -78,   129,   -78,    20,   -78,   194,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,   -78,   -78,   230,   231,   232,   223,   260,
     -78,   -78,   210,    46,   -78,   222,   233,    19,    19,    37,
      37,    37,    37,    47,    47,   -78,   -78,   -78,   -78,   -78,
     -78,    54,    54,   -78,    20,     0,   261,   210,    54,   234,
     236,   266,   -78,   -78,   238,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   -78,   271,   -78,    11,   257,   -78,   -78,
     244,   247,   -78,   235,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   224,   228,   -78,   211,   213,   -71,   -78,   -77,   -78,
     -59,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      73,    86,    97,     3,   100,   101,   102,   103,    39,    78,
     105,   158,   159,    73,   -14,    10,   108,   109,    21,    12,
      10,    99,    18,    90,     4,    91,    92,   107,    79,     6,
     132,    79,     7,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    14,    40,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    23,    93,    94,
      66,    67,    68,    69,    56,    17,    24,    70,     7,    56,
     118,   119,   120,   121,   122,   125,   -30,   157,    79,    27,
     155,   156,   120,   121,   122,    30,   153,   161,   154,    28,
      31,    37,    73,    73,    38,    32,    43,    45,    47,    73,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    48,    50,    49,    53,    51,    59,   124,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    61,    62,    64,   123,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      74,    76,    77,   130,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    87,    84,    80,
     131,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    81,    98,   127,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      82,   106,   128,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    83,   104,   129,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   126,   151,   134,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   148,   149,   150,   152,   162,   160,   163,   164,   165,
      13,    29,    46,    44,    52,    75,    65,    89,    88
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      59,    72,    79,     0,    81,    82,    83,    84,     6,    24,
      87,    11,    12,    72,    39,     4,    93,    94,    43,    18,
       9,    80,    11,     3,    17,     5,     6,    39,    43,    16,
     107,    43,    19,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     6,    45,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    41,    38,    39,
       6,     7,     8,     9,    53,    16,    42,    13,    19,    58,
      33,    34,    35,    36,    37,    40,    23,   154,    43,     3,
     151,   152,    35,    36,    37,    23,    40,   158,    42,    39,
       6,    39,   151,   152,    39,    44,    40,    40,     6,   158,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    41,    46,    42,    17,    40,    20,    44,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    46,     6,    18,    41,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      47,    42,    41,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    24,    21,    39,
      41,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    39,     6,    40,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      39,    47,    40,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    39,    22,    40,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    40,    10,    40,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    41,    41,    41,    14,    41,    15,    41,    12,    41,
       9,    24,    38,    36,    49,    61,    58,    76,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,    17,    51,    16,    19,    52,    53,
      54,    63,    18,    52,     6,    55,    56,    16,    54,    64,
      67,    43,    57,    41,    42,    68,    65,     3,    39,    55,
      23,     6,    44,    54,    58,    59,    60,    39,    39,     6,
      45,    61,    62,    40,    59,    40,    58,     6,    41,    42,
      46,    40,    61,    17,    69,    66,    54,    70,    71,    20,
      73,    46,     6,    72,    18,    70,     6,     7,     8,     9,
      13,    74,    75,    78,    47,    69,    42,    41,    24,    43,
      39,    39,    39,    39,    21,    79,    74,    24,    73,    72,
       3,     5,     6,    38,    39,    76,    78,    76,     6,    78,
      76,    76,    76,    76,    22,    76,    47,    39,    76,    76,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    41,    44,    40,    40,    40,    40,    40,
      41,    41,    76,    77,    40,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    41,    41,
      41,    10,    14,    40,    42,    74,    74,    76,    11,    12,
      15,    74,    41,    41,    12,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 46 "slpi.y"
    {fprintf(outFile,"START\nMOV BP, 0\n");}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 46 "slpi.y"
    {fprintf(outFile,"end: HALT\n");}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 50 "slpi.y"
    {clear_args();sp = st.memory;fprintf(outFile,"MOV SP,%d\n",sp);fprintf(outFile,"CALL main\n");fprintf(outFile,"JMP end\n");}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 53 "slpi.y"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 54 "slpi.y"
    {}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 57 "slpi.y"
    {}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 60 "slpi.y"
    {type = INT;}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 61 "slpi.y"
    {type = BOOL;}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 64 "slpi.y"
    {}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 65 "slpi.y"
    {}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 68 "slpi.y"
    { Ginstall((yyvsp[(1) - (1)].name),type,1);}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 69 "slpi.y"
    {Ginstall((yyvsp[(1) - (4)].name),type,(yyvsp[(3) - (4)].ival));}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 70 "slpi.y"
    {func_type = type;}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 70 "slpi.y"
    {Ginstall((yyvsp[(1) - (5)].name),func_type,0);clear_args();type =
       func_type;}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 74 "slpi.y"
    {}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 75 "slpi.y"
    {}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 77 "slpi.y"
    {}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 78 "slpi.y"
    {}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 81 "slpi.y"
    {}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 84 "slpi.y"
    {}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 85 "slpi.y"
    {}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 88 "slpi.y"
    {addArgs((yyvsp[(2) - (2)].name),type,1);}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 89 "slpi.y"
    {addArgs((yyvsp[(1) - (1)].name),type,0);}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 91 "slpi.y"
    {}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 92 "slpi.y"
    {}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 95 "slpi.y"
    {func_type = type;}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 95 "slpi.y"
    {installArgs((yyvsp[(3) - (6)].name));}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 95 "slpi.y"
    {(yyval.nptr)=mkFuncDefNode((yyvsp[(3) - (11)].name),(yyvsp[(10) - (11)].nptr),func_type);gen_code((yyval.nptr));clear_args();clear_local();type = func_type;}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 98 "slpi.y"
    {func_type = INT;}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 98 "slpi.y"
    {(yyval.nptr)=mkMainDefNode((yyvsp[(8) - (9)].nptr));gen_code((yyval.nptr));clear_args();clear_local(); type = func_type;}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 101 "slpi.y"
    { }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 104 "slpi.y"
    {}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 105 "slpi.y"
    {}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 108 "slpi.y"
    {}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 111 "slpi.y"
    {Linstall((yyvsp[(1) - (3)].name),type);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 112 "slpi.y"
    {Linstall((yyvsp[(1) - (1)].name),type);}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 115 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CFUNC,(yyvsp[(2) - (4)].nptr),(yyvsp[(3) - (4)].nptr),NULL);}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 118 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CSLIST,(yyvsp[(1) - (2)].nptr),(yyvsp[(2) - (2)].nptr),NULL);}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 119 "slpi.y"
    {(yyval.nptr) = NULL;}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 122 "slpi.y"
    {(yyval.nptr) = mkstmtNode(ASSG,(yyvsp[(1) - (4)].nptr),(yyvsp[(3) - (4)].nptr),NULL);}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 123 "slpi.y"
    {(yyval.nptr) = mkstmtNode(ASSG,mkID((yyvsp[(1) - (4)].name),NULL),(yyvsp[(3) - (4)].nptr),NULL);}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 124 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CREAD,(yyvsp[(3) - (5)].nptr), NULL,NULL);}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 125 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CREAD,mkID((yyvsp[(3) - (5)].name),NULL),NULL,NULL);}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 126 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CWRITE,(yyvsp[(3) - (5)].nptr), NULL,NULL);}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 127 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CIF,(yyvsp[(3) - (8)].nptr),(yyvsp[(6) - (8)].nptr),NULL);}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 128 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CIFELSE,(yyvsp[(3) - (10)].nptr),(yyvsp[(6) - (10)].nptr),(yyvsp[(8) - (10)].nptr));}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 129 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CWHILE,(yyvsp[(3) - (8)].nptr),(yyvsp[(6) - (8)].nptr),NULL);}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 132 "slpi.y"
    {(yyval.nptr) = mkOpNode('+',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 133 "slpi.y"
    {(yyval.nptr) = mkOpNode('-',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 134 "slpi.y"
    {(yyval.nptr) = mkOpNode('*',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 135 "slpi.y"
    {(yyval.nptr) = mkOpNode('/',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 136 "slpi.y"
    {(yyval.nptr) = mkOpNode('%',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 137 "slpi.y"
    {(yyval.nptr) = mkOpNode('>',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 138 "slpi.y"
    {(yyval.nptr) = mkOpNode('<',(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 139 "slpi.y"
    {(yyval.nptr) = mkOpNode(CLTE,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 140 "slpi.y"
    {(yyval.nptr) = mkOpNode(CGTE,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 141 "slpi.y"
    {(yyval.nptr) = mkOpNode(ISEQUAL,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 142 "slpi.y"
    {(yyval.nptr) = mkOpNode(ISNTEQUAL,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 143 "slpi.y"
    {(yyval.nptr) = mkOpNode(CAND,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 144 "slpi.y"
    {(yyval.nptr) = mkOpNode(COR,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 145 "slpi.y"
    {(yyval.nptr) = mkOpNode(CNOT,(yyvsp[(2) - (2)].nptr),NULL);}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 146 "slpi.y"
    {(yyval.nptr) = (yyvsp[(2) - (3)].nptr);}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 147 "slpi.y"
    {(yyval.nptr) = mkNUM((yyvsp[(1) - (1)].ival));}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 148 "slpi.y"
    {(yyval.nptr) = mkID((yyvsp[(1) - (1)].name),NULL);}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 149 "slpi.y"
    {(yyval.nptr) = (yyvsp[(1) - (1)].nptr);}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 150 "slpi.y"
    {(yyval.nptr) = mkFunc((yyvsp[(1) - (4)].name),(yyvsp[(3) - (4)].nptr));}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 151 "slpi.y"
    {(yyval.nptr) = mkBool((yyvsp[(1) - (1)].ival));}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 154 "slpi.y"
    {(yyval.nptr) = mkArgNode(CARG,(yyvsp[(1) - (3)].nptr),(yyvsp[(3) - (3)].nptr));}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 155 "slpi.y"
    {(yyval.nptr) = mkArgNode(CARG,NULL,(yyvsp[(1) - (1)].nptr));}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 156 "slpi.y"
    {(yyval.nptr) = NULL;}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 159 "slpi.y"
    {(yyval.nptr) = mkID((yyvsp[(1) - (4)].name),(yyvsp[(3) - (4)].nptr));}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 162 "slpi.y"
    {(yyval.nptr) = mkstmtNode(CRET,(yyvsp[(2) - (3)].nptr),NULL,NULL);}
    break;


/* Line 1787 of yacc.c  */
#line 2013 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 164 "slpi.y"


yyerror()
{
    printf("error");
    remove(filename);
    return ;
}

int main(int argc, char *argv[])
{
    int curr_line = 0;
    if(argc != 3)
    {
        printf("Usage: ./slpi input_filename output_filename\n");
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    outFile = fopen(argv[2],"w");
    strcpy(filename,argv[2]);
    st.head = NULL;
    st.tail = NULL;
    st.memory = 1535;
    lt.head = NULL;
    lt.tail = NULL;
    lt.memory = 1;
    lt.argmem = -3;
    alist.head = NULL;
    yyparse();
    fclose(yyin);
    return 1;
}
