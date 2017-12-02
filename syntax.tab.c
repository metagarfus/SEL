/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOUBLE_VALUE = 258,
     INTEGER = 259,
     TAG = 260,
     STRING = 261,
     PLUS = 262,
     MINUS = 263,
     TIMES = 264,
     DIVIDE = 265,
     OPEN = 266,
     CLOSE = 267,
     COLON = 268,
     ASSIGN = 269,
     EQUALS = 270,
     OPEN_S_BRACKET = 271,
     CLOSE_S_BRACKET = 272,
     OPEN_BRACKET = 273,
     CLOSE_BRACKET = 274,
     INCLUDE = 275,
     DATATYPE = 276,
     WITH = 277,
     FUNCTION = 278,
     PROTOTYPE = 279,
     EXTERNAL = 280,
     ARROW = 281,
     DOUBLE_ARROW = 282,
     BYTE = 283,
     INT = 284,
     LONG = 285,
     DOUBLE = 286,
     CHARS = 287,
     BOOLEAN = 288,
     ARRAY = 289,
     BOX = 290,
     UNBOX = 291,
     OF = 292,
     DYNAMIC = 293,
     APPLY = 294,
     IN = 295,
     LET = 296,
     FOR = 297,
     FOREACH = 298,
     FROM = 299,
     WHILE = 300,
     IF = 301,
     THEN = 302,
     ELSE = 303,
     CARDINAL = 304,
     DOLLAR = 305,
     NEW = 306,
     TYPEDEF = 307,
     COMMA = 308,
     AMPERSAND = 309,
     AND = 310,
     OR = 311,
     LTE = 312,
     GTE = 313,
     LT = 314,
     GT = 315,
     EQ = 316,
     NOT = 317,
     DOT = 318,
     IS = 319,
     STATIC = 320,
     AS = 321,
     QUESTION_MARK = 322,
     SEMICOLON = 323,
     QUOTES = 324,
     UNION = 325,
     CASE = 326,
     PIPE = 327,
     DOUBLE_COLON = 328,
     OTHERWISE = 329
   };
#endif
/* Tokens.  */
#define DOUBLE_VALUE 258
#define INTEGER 259
#define TAG 260
#define STRING 261
#define PLUS 262
#define MINUS 263
#define TIMES 264
#define DIVIDE 265
#define OPEN 266
#define CLOSE 267
#define COLON 268
#define ASSIGN 269
#define EQUALS 270
#define OPEN_S_BRACKET 271
#define CLOSE_S_BRACKET 272
#define OPEN_BRACKET 273
#define CLOSE_BRACKET 274
#define INCLUDE 275
#define DATATYPE 276
#define WITH 277
#define FUNCTION 278
#define PROTOTYPE 279
#define EXTERNAL 280
#define ARROW 281
#define DOUBLE_ARROW 282
#define BYTE 283
#define INT 284
#define LONG 285
#define DOUBLE 286
#define CHARS 287
#define BOOLEAN 288
#define ARRAY 289
#define BOX 290
#define UNBOX 291
#define OF 292
#define DYNAMIC 293
#define APPLY 294
#define IN 295
#define LET 296
#define FOR 297
#define FOREACH 298
#define FROM 299
#define WHILE 300
#define IF 301
#define THEN 302
#define ELSE 303
#define CARDINAL 304
#define DOLLAR 305
#define NEW 306
#define TYPEDEF 307
#define COMMA 308
#define AMPERSAND 309
#define AND 310
#define OR 311
#define LTE 312
#define GTE 313
#define LT 314
#define GT 315
#define EQ 316
#define NOT 317
#define DOT 318
#define IS 319
#define STATIC 320
#define AS 321
#define QUESTION_MARK 322
#define SEMICOLON 323
#define QUOTES 324
#define UNION 325
#define CASE 326
#define PIPE 327
#define DOUBLE_COLON 328
#define OTHERWISE 329




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include "heading.h"
#include "tagtuple.h"
#include "utils.h"
#include "syntax.h"
#include "errors.h"

int yyerror(char *s);
int yylex(void);

typedef struct {
    int current_line;
    int lines_read;
    int interactive;
    FILE *stream;
    char last_read_char[2];
    parse_output output;
} state;

typedef struct {state state;} yycontext;
yycontext *yy;

/*#define YY_INPUT(yy, buf, result, max_size)             \
  {                                                     \
    int yyc= getc(yy->state.stream);                    \
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);        \
    yy->state.lines_read += yyc == '\n'                 \
    yyprintf((stderr, "<%c>", yyc));                    \
    yy->state.last_read_char[0] = yyc;                  \
  }*/

static tag_tuple *result_arg_list(tag_tuple *head, tag_tuple * previous_head) {
    if (head != NULL)
        head->next = previous_head;
    else
        head = previous_head;
    return head;
}

static mapping_t *result_maps_list(mapping_t *head, mapping_t * previous_head ) {
    if (head != NULL)
        head->next = previous_head;
    else
        head = previous_head;
    return head;
}

static declaration_t * result_decl_list(declaration_t *head, declaration_t * previous_head) {
    if (head != NULL)
        head->next = previous_head;
    else
        head = previous_head;
    return head;
}

static access_path_t *result_access_path_list(access_path_t *head, access_path_t * previous_head ) {
    if (head != NULL)
        head->next = previous_head;
    else
        head = previous_head;
    return head;
}

static value_data_type_t * result_type_list(value_data_type_t *head, value_data_type_t * previous_head) {
    if (head != NULL)
        head->next = previous_head;
    else
        head = previous_head;
    return head;
}

static void error(state *state, parse_error_code code, operation op, char *text) {
    if (state->output.error_code != PARSE_ERROR_OK)
        return; 
    tag_tuple * const root = state->output.error_code == PARSE_ERROR_OK ? state->output.value.root : NULL;
    state->output.error_code = code; 
    state->output.value.error.op = op;
    if (text != NULL) {
        int len = sizeof(state->output.value.error.text) - 1;
        strncpy(state->output.value.error.text, text, len);
        state->output.value.error.text[len] = '\0';
    } else {
        state->output.value.error.text[0] = '\0';
    }
    state->output.value.error.line = state->lines_read + 1;
    state->output.value.error.leftover = root;
    if (root != NULL)
        fprintf(stderr, "LEFTOVER\n");
}

static void output(state *state, tag_tuple * root) {
    if (state->output.error_code == PARSE_ERROR_OK)
        release_tagtuple(state->output.value.root);
    else     
        release_tagtuple(state->output.value.error.leftover);
    state->output.error_code = PARSE_ERROR_OK;
    state->output.value.root = root;
}
#define WHITE_SPACE(X) ((X) == ' ' || (X) == '\t' || (X) == '\r' || (X) == '\n')

static void unexpexted_character_error(state *state, char *buf, int pos, int len) {
  // if (pos > 0 && pos < len && !WHITE_SPACE(buf[pos - 1]))  
  //      state->last_read_char[0] = buf[pos - 1];
    if (state->last_read_char[0] <= 0)
        error(state, PARSE_ERROR_END_OF_INPUT, 0, "");    
    else
        error(state, PARSE_ERROR_UNEXPECTED_CHAR, 0, state->last_read_char);
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 231 "syntax.y"
{
        tag_tuple * tag_tuple;
        value_data_type_t *data_type;
        mapping_t *mapping;
        declaration_t *declaration;
        union_declaration_t *union_declaration;
        case_t *case; 
        char *text;
        access_path_t *access_path;
        double double_value;
        int64_t integer_value;
        char *string_value;
    }
/* Line 193 of yacc.c.  */
#line 371 "syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 396 "syntax.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    20,    23,
      28,    41,    51,    59,    62,    64,    68,    74,    79,    81,
      84,    89,    94,    97,    99,   104,   106,   108,   110,   112,
     114,   116,   120,   125,   128,   131,   133,   135,   137,   141,
     145,   149,   151,   152,   156,   158,   162,   164,   168,   170,
     173,   175,   179,   183,   187,   194,   201,   208,   215,   226,
     233,   238,   240,   244,   248,   252,   256,   260,   264,   268,
     272,   276,   280,   284,   286,   289,   291,   294,   296,   299,
     302,   305,   309,   314,   319,   322,   325,   328,   331,   334,
     337,   340,   343,   345,   347,   349,   359,   369,   377,   383,
     389,   393,   398,   405,   414,   418,   423,   425,   427,   428,
     430,   431,   435,   437,   441,   445,   447,   452,   456,   460,
     464,   466,   468,   470
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    78,    77,    -1,    78,    -1,
      79,    -1,    20,   106,    -1,    52,     5,    15,    81,    -1,
      52,     5,    -1,    65,    88,    15,    91,    -1,    21,    81,
      66,     5,    11,    86,    12,    91,    22,    11,    80,    12,
      -1,    23,     5,    11,    86,    12,    13,    81,    15,    91,
      -1,    24,     5,    11,    86,    12,    13,    81,    -1,    79,
      80,    -1,    79,    -1,    82,    26,    81,    -1,    11,    85,
      12,    26,    81,    -1,    11,    12,    26,    81,    -1,    82,
      -1,     9,    83,    -1,     9,    84,    16,    17,    -1,    35,
      84,    16,    17,    -1,    35,    83,    -1,    83,    -1,    84,
      16,   105,    17,    -1,    84,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    33,    -1,    18,    87,    19,    -1,
      70,    18,    89,    19,    -1,     9,    67,    -1,    67,    67,
      -1,    38,    -1,    32,    -1,     5,    -1,    11,    81,    12,
      -1,    82,    53,    85,    -1,    82,    53,    82,    -1,    87,
      -1,    -1,    88,    53,    87,    -1,    88,    -1,     5,    13,
      81,    -1,     5,    -1,    90,    72,    89,    -1,    90,    -1,
       5,    81,    -1,     5,    -1,    92,    14,    91,    -1,    92,
      13,    81,    -1,    92,    64,    81,    -1,    41,    88,    15,
      91,    40,    91,    -1,    65,    88,    15,    91,    40,    91,
      -1,    46,    91,    47,    91,    48,    91,    -1,    71,    91,
      37,    11,   103,    12,    -1,    42,    88,    15,    91,    53,
      91,    53,    91,    40,    91,    -1,    43,    88,    44,    91,
      40,    91,    -1,    45,    91,    40,    91,    -1,    92,    -1,
      92,    55,    92,    -1,    92,    56,    92,    -1,    92,    57,
      92,    -1,    92,    58,    92,    -1,    92,    59,    92,    -1,
      92,    60,    92,    -1,    92,    61,    92,    -1,    92,     7,
      92,    -1,    92,     8,    92,    -1,    92,     9,    92,    -1,
      92,    10,    92,    -1,    93,    -1,    96,    94,    -1,    96,
      -1,    95,    94,    -1,    95,    -1,    63,     5,    -1,    26,
       5,    -1,    27,     5,    -1,    16,    91,    17,    -1,    26,
      16,    91,    17,    -1,    27,    16,    91,    17,    -1,    62,
      96,    -1,     7,    96,    -1,     8,    96,    -1,     9,    96,
      -1,    54,    96,    -1,    49,    96,    -1,    35,    96,    -1,
      36,    96,    -1,   104,    -1,   105,    -1,   106,    -1,    35,
      22,    91,    37,    11,     5,    40,    91,    12,    -1,    34,
      22,    91,    37,    11,     5,    40,    91,    12,    -1,    16,
     105,    37,     5,    40,    91,    17,    -1,    51,    81,    11,
      98,    12,    -1,    18,    87,    39,    91,    19,    -1,    16,
      98,    17,    -1,     5,    18,   101,    19,    -1,     5,    73,
       5,    18,    91,    19,    -1,     5,    73,     5,    18,    18,
     101,    19,    19,    -1,     5,    73,     5,    -1,    97,    11,
      98,    12,    -1,     5,    -1,     5,    -1,    -1,    99,    -1,
      -1,    91,    53,    99,    -1,    91,    -1,    88,    15,    91,
      -1,   100,    53,   101,    -1,   100,    -1,     5,    88,    40,
      91,    -1,     5,    40,    91,    -1,    74,    40,    91,    -1,
     102,    72,   103,    -1,   102,    -1,     3,    -1,     4,    -1,
       6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   246,   246,   249,   250,   252,   253,   254,   255,   256,
     257,   260,   261,   263,   264,   266,   267,   268,   269,   271,
     272,   273,   274,   275,   277,   278,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   294,
     295,   297,   298,   300,   301,   303,   304,   306,   307,   309,
     310,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   337,   338,   340,   341,   343,   344,
     345,   346,   347,   348,   350,   351,   352,   353,   354,   355,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   376,   377,   381,
     382,   384,   385,   387,   389,   390,   392,   393,   394,   396,
     397,   399,   400,   401
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOUBLE_VALUE", "INTEGER", "TAG",
  "STRING", "PLUS", "MINUS", "TIMES", "DIVIDE", "OPEN", "CLOSE", "COLON",
  "ASSIGN", "EQUALS", "OPEN_S_BRACKET", "CLOSE_S_BRACKET", "OPEN_BRACKET",
  "CLOSE_BRACKET", "INCLUDE", "DATATYPE", "WITH", "FUNCTION", "PROTOTYPE",
  "EXTERNAL", "ARROW", "DOUBLE_ARROW", "BYTE", "INT", "LONG", "DOUBLE",
  "CHARS", "BOOLEAN", "ARRAY", "BOX", "UNBOX", "OF", "DYNAMIC", "APPLY",
  "IN", "LET", "FOR", "FOREACH", "FROM", "WHILE", "IF", "THEN", "ELSE",
  "CARDINAL", "DOLLAR", "NEW", "TYPEDEF", "COMMA", "AMPERSAND", "AND",
  "OR", "LTE", "GTE", "LT", "GT", "EQ", "NOT", "DOT", "IS", "STATIC", "AS",
  "QUESTION_MARK", "SEMICOLON", "QUOTES", "UNION", "CASE", "PIPE",
  "DOUBLE_COLON", "OTHERWISE", "$accept", "Stmt", "Definitions",
  "Definition", "Function", "FunctionList", "ArrowType", "PointerType",
  "ArrayType", "SimpleType", "ArgTypeList", "VarDeclarations",
  "VarDeclarationList", "VarDeclaration", "UnionDeclarationList",
  "UnionDeclaration", "Expr", "ExpOp", "Access", "AccessPathList",
  "AccessPath", "Value", "TAG_OR_EMPTY", "Arguments", "ArgList", "Mapping",
  "MapsList", "Case", "CaseList", "DOUBLE_EXPR", "INTEGER_EXPR",
  "STRING_EXPR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   105,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     4,     2,     4,
      12,     9,     7,     2,     1,     3,     5,     4,     1,     2,
       4,     4,     2,     1,     4,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     2,     1,     1,     1,     3,     3,
       3,     1,     0,     3,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     6,     6,     6,     6,    10,     6,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     2,     1,     2,     2,
       2,     3,     4,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     9,     9,     7,     5,     5,
       3,     4,     6,     8,     3,     4,     1,     1,     0,     1,
       0,     3,     1,     3,     3,     1,     4,     3,     3,     3,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,   123,     6,    37,     0,     0,     0,    26,    27,    28,
      29,    36,    30,     0,    35,     0,     0,     0,    18,    23,
      25,     0,     0,     8,    46,     0,     1,     3,     0,     0,
      33,    19,    25,     0,     0,    18,     0,     0,    44,    22,
      25,    34,     0,     0,     0,     0,    42,    42,     0,     0,
     108,    33,     0,     0,    38,     0,     0,    31,     0,     0,
      50,     0,    48,     0,    15,   122,     0,     0,    41,     0,
       7,    45,   121,   106,   108,   108,   108,   108,     0,     0,
     108,   108,     0,     0,     0,   108,   108,   108,     0,   108,
     108,     0,   108,     9,    61,    73,    75,     0,    92,    93,
      94,    20,    17,    40,    39,     0,    43,    21,    49,    32,
       0,    42,    24,     0,     0,     0,     0,    85,    86,    87,
     112,     0,   109,    93,     0,   108,   108,    90,    91,     0,
       0,     0,     0,     0,    89,     0,    88,    84,     0,     0,
     108,   108,   108,   108,     0,   108,   108,   108,   108,   108,
     108,   108,   108,     0,   108,     0,     0,     0,    74,    77,
     108,    16,    47,     0,     0,     0,     0,   115,     0,   104,
     108,   100,     0,   108,     0,     0,   108,   108,   108,   108,
     108,   108,   108,     0,    69,    70,    71,    72,    52,    51,
      62,    63,    64,    65,    66,    67,    68,    53,     0,    79,
     108,    80,   108,    78,    76,     0,   108,     0,    12,   108,
       0,   101,   108,   111,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,    81,     0,     0,   105,
       0,   108,   113,   114,     0,     0,   108,    99,     0,     0,
     108,   108,   108,   108,    98,   108,     0,     0,   120,     0,
      82,    83,     0,    11,    44,     0,   102,     0,     0,     0,
      54,     0,    59,    56,    55,   108,     0,   108,     0,    57,
       0,     0,    97,   108,   108,   108,   117,   108,   118,   119,
      14,     0,   103,     0,     0,     0,   116,    13,    10,    96,
      95,   108,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,   291,    44,    28,    29,    30,
      46,    77,    78,    48,    71,    72,   130,   104,   105,   168,
     169,   106,   107,   131,   132,   177,   178,   258,   259,   108,
     109,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -211
static const yytype_int16 yypact[] =
{
      42,    35,    80,    12,    73,    75,    76,    92,  -211,    42,
    -211,  -211,  -211,  -211,   448,     0,    76,  -211,  -211,  -211,
    -211,  -211,  -211,   478,  -211,    47,    99,    54,    95,  -211,
     106,   112,   114,   111,   119,   120,  -211,  -211,    69,    80,
      47,  -211,   121,   113,   126,   -11,   128,   123,    90,  -211,
     129,  -211,   139,   141,    80,   145,    76,    76,    80,    80,
     332,  -211,    22,    80,  -211,   432,   130,  -211,    76,    65,
      80,   133,    82,   147,  -211,  -211,   142,   149,  -211,   150,
    -211,  -211,  -211,    -5,   550,   550,   550,   228,    76,   143,
     516,   550,    76,    76,    76,   332,   332,   550,    80,   550,
     550,    76,   332,  -211,   196,  -211,    -2,   156,  -211,  -211,
    -211,  -211,  -211,   115,  -211,    80,  -211,  -211,  -211,  -211,
     139,    76,  -211,   157,   158,    76,   164,  -211,  -211,  -211,
     124,   155,  -211,   136,   135,   332,   332,  -211,  -211,   163,
     165,   137,   144,   132,  -211,   172,  -211,  -211,   170,   151,
     550,   550,   550,   550,    80,   332,   550,   550,   550,   550,
     550,   550,   550,    80,   332,    11,    74,   181,  -211,    -2,
     280,  -211,  -211,   177,    80,    80,   175,   146,   176,   179,
     332,  -211,   193,   332,   171,   174,   332,   332,   332,   332,
     332,   280,   332,   189,    13,    13,  -211,  -211,  -211,  -211,
      43,    43,    37,    37,    37,    37,    37,  -211,   184,  -211,
     332,  -211,   332,  -211,  -211,   190,   332,   192,  -211,   332,
      76,  -211,   384,  -211,   173,   198,   201,   204,   180,   166,
     182,  -211,   191,   209,   183,    -1,  -211,   210,   212,  -211,
     218,   332,  -211,  -211,    76,   222,   332,  -211,   238,   242,
     332,   332,   332,   332,  -211,   332,    16,   208,   186,   237,
    -211,  -211,   248,  -211,     5,   246,  -211,   244,   226,   227,
    -211,   215,  -211,  -211,  -211,   332,   232,   332,    -1,  -211,
      25,   256,  -211,   332,   332,   332,  -211,   332,  -211,  -211,
      25,   264,  -211,   266,   268,   241,  -211,  -211,  -211,  -211,
    -211,   332,  -211
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,   282,  -211,  -197,     4,     1,    -8,    61,    83,
     230,   -49,   -14,    -6,   187,  -211,   -59,   202,  -211,   131,
    -211,   220,  -211,  -151,   117,  -211,  -210,  -211,    23,  -211,
      79,   301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -111
static const yytype_int16 yytable[] =
{
      35,   103,    47,    27,   256,    13,  -107,    45,    79,    14,
     243,    15,    43,   125,   164,    54,   209,    31,    16,   215,
     219,    34,   152,   153,   165,   166,    75,   210,    17,    18,
      19,    20,    21,    22,   265,    23,   142,   143,    24,   111,
     233,    11,    65,   149,   150,   151,   152,   153,     3,     4,
     150,   151,   152,   153,   116,    74,   275,   113,    68,    80,
      81,   167,     1,     2,   112,     3,     4,    25,   126,    75,
      26,   118,   173,   257,   134,    41,   184,   185,    32,   211,
      33,    34,   117,   290,    49,    13,   139,   140,   141,    14,
     212,    15,    36,   290,     5,   148,   199,    42,    16,   145,
     158,   159,   160,   161,   162,   208,    50,     6,    17,    18,
      19,    20,    21,    22,    51,    23,   171,    52,    24,   176,
      53,    54,    55,    56,   225,    57,    58,   228,   229,   230,
     231,   232,    59,   234,    76,    60,    61,    62,    64,    63,
      66,    76,    67,    68,    70,    69,    73,    25,    76,    75,
      26,   237,   119,   238,   120,   198,   115,   240,   121,   122,
     242,   123,   124,   245,   207,   135,   133,   170,    65,   179,
     174,   175,   181,   182,   183,   217,   218,   180,   186,   190,
     187,   188,   263,   191,   189,   192,   213,   267,   193,   216,
     219,   270,   271,   272,   273,   221,   274,   222,   224,   220,
     235,   236,   239,   150,   151,   152,   153,   241,   226,   154,
     155,   227,   248,   246,   176,   249,   286,   247,   288,   251,
     250,   254,   252,   255,   293,   294,   295,   260,   296,   261,
     134,    82,    75,    83,    11,    84,    85,    86,   264,   253,
     262,   266,   302,   268,    87,  -110,    88,   269,   277,   279,
     276,   156,   157,   158,   159,   160,   161,   162,   278,   280,
     163,   282,    89,    90,    91,   281,   283,   284,   285,    92,
      93,    94,   287,    95,    96,   292,   298,    97,   299,    98,
     300,   301,    99,    82,    75,    83,    11,    84,    85,    86,
     100,    37,  -110,   101,   297,   114,    87,   223,    88,   102,
     214,   289,    12,     0,   127,   128,   129,   172,     0,     0,
     137,   138,     0,     0,    89,    90,    91,   144,     0,   146,
     147,    92,    93,    94,     0,    95,    96,     0,     0,    97,
       0,    98,     0,     0,    99,    82,    75,    83,    11,    84,
      85,    86,   100,     0,     0,   101,     0,     0,    87,     0,
      88,   102,   194,   195,   196,   197,     0,     0,   200,   201,
     202,   203,   204,   205,   206,     0,    89,    90,    91,     0,
       0,     0,     0,    92,    93,    94,     0,    95,    96,     0,
       0,    97,     0,    98,     0,     0,    99,    82,    75,    83,
      11,    84,    85,    86,   100,     0,     0,   101,     0,     0,
      87,     0,   244,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,     0,     0,     0,     0,    92,    93,    94,     0,    95,
      96,     0,     0,    97,     0,    98,     0,    13,    99,     0,
       0,    14,     0,    39,     0,     0,   100,     0,     0,   101,
      16,     0,     0,    13,     0,   102,     0,    38,     0,    39,
      17,    18,    19,    20,    21,    22,    16,    23,     0,     0,
      24,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,     0,    13,     0,     0,    24,    38,     0,    39,
       0,     0,     0,     0,     0,     0,    16,     0,     0,    25,
       0,     0,    26,     0,     0,     0,    17,    18,    19,    20,
      21,    22,     0,     0,     0,    40,    24,     0,    26,    82,
      75,    83,    11,    84,    85,    86,     0,     0,     0,     0,
       0,     0,    87,     0,    88,     0,     0,     0,   136,     0,
       0,     0,     0,     0,     0,    25,     0,     0,    26,     0,
      89,    90,    91,    82,    75,    83,    11,    84,    85,    86,
       0,     0,     0,     0,     0,    97,    87,    98,    88,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,    98,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,   100
};

static const yytype_int16 yycheck[] =
{
       6,    60,    16,     2,     5,     5,    11,    15,    57,     9,
     220,    11,    12,    18,    16,    26,     5,     5,    18,   170,
      15,     5,     9,    10,    26,    27,     4,    16,    28,    29,
      30,    31,    32,    33,   244,    35,    95,    96,    38,    17,
     191,     6,    53,   102,     7,     8,     9,    10,    23,    24,
       7,     8,     9,    10,    68,    54,    40,    65,    53,    58,
      59,    63,    20,    21,    63,    23,    24,    67,    73,     4,
      70,    70,   121,    74,    88,    14,   135,   136,     5,     5,
       5,     5,    17,   280,    23,     5,    92,    93,    94,     9,
      16,    11,     0,   290,    52,   101,   155,    14,    18,    98,
      57,    58,    59,    60,    61,   164,    23,    65,    28,    29,
      30,    31,    32,    33,    67,    35,   115,    18,    38,   125,
      66,    26,    16,    11,   183,    11,    15,   186,   187,   188,
     189,   190,    13,   192,    55,    15,    67,    16,    12,    26,
      12,    62,    19,    53,     5,    16,     5,    67,    69,     4,
      70,   210,    19,   212,    72,   154,    26,   216,    11,    17,
     219,    12,    12,   222,   163,    22,    87,    11,    53,     5,
      13,    13,    17,    37,    39,   174,   175,    53,    15,    47,
      15,    44,   241,    11,    40,    15,     5,   246,    37,    12,
      15,   250,   251,   252,   253,    19,   255,    18,     5,    53,
      11,    17,    12,     7,     8,     9,    10,    15,    37,    13,
      14,    37,    11,    40,   220,    11,   275,    19,   277,    53,
      40,    12,    40,    40,   283,   284,   285,    17,   287,    17,
     244,     3,     4,     5,     6,     7,     8,     9,   244,    48,
      22,    19,   301,     5,    16,    17,    18,     5,    40,    12,
     256,    55,    56,    57,    58,    59,    60,    61,    72,    11,
      64,    17,    34,    35,    36,    19,    40,    40,    53,    41,
      42,    43,    40,    45,    46,    19,    12,    49,    12,    51,
      12,    40,    54,     3,     4,     5,     6,     7,     8,     9,
      62,     9,    12,    65,   290,    65,    16,   180,    18,    71,
     169,   278,     1,    -1,    84,    85,    86,   120,    -1,    -1,
      90,    91,    -1,    -1,    34,    35,    36,    97,    -1,    99,
     100,    41,    42,    43,    -1,    45,    46,    -1,    -1,    49,
      -1,    51,    -1,    -1,    54,     3,     4,     5,     6,     7,
       8,     9,    62,    -1,    -1,    65,    -1,    -1,    16,    -1,
      18,    71,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    -1,    45,    46,    -1,
      -1,    49,    -1,    51,    -1,    -1,    54,     3,     4,     5,
       6,     7,     8,     9,    62,    -1,    -1,    65,    -1,    -1,
      16,    -1,    18,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,    45,
      46,    -1,    -1,    49,    -1,    51,    -1,     5,    54,    -1,
      -1,     9,    -1,    11,    -1,    -1,    62,    -1,    -1,    65,
      18,    -1,    -1,     5,    -1,    71,    -1,     9,    -1,    11,
      28,    29,    30,    31,    32,    33,    18,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,     5,    -1,    -1,    38,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    67,    38,    -1,    70,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      34,    35,    36,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    49,    16,    51,    18,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    23,    24,    52,    65,    76,    77,    78,
      79,     6,   106,     5,     9,    11,    18,    28,    29,    30,
      31,    32,    33,    35,    38,    67,    70,    81,    82,    83,
      84,     5,     5,     5,     5,    88,     0,    77,     9,    11,
      67,    83,    84,    12,    81,    82,    85,    87,    88,    83,
      84,    67,    18,    66,    26,    16,    11,    11,    15,    13,
      15,    67,    16,    26,    12,    53,    12,    19,    53,    16,
       5,    89,    90,     5,    81,     4,   105,    86,    87,    86,
      81,    81,     3,     5,     7,     8,     9,    16,    18,    34,
      35,    36,    41,    42,    43,    45,    46,    49,    51,    54,
      62,    65,    71,    91,    92,    93,    96,    97,   104,   105,
     106,    17,    81,    82,    85,    26,    87,    17,    81,    19,
      72,    11,    17,    12,    12,    18,    73,    96,    96,    96,
      91,    98,    99,   105,    87,    22,    22,    96,    96,    88,
      88,    88,    91,    91,    96,    81,    96,    96,    88,    91,
       7,     8,     9,    10,    13,    14,    55,    56,    57,    58,
      59,    60,    61,    64,    16,    26,    27,    63,    94,    95,
      11,    81,    89,    86,    13,    13,    88,   100,   101,     5,
      53,    17,    37,    39,    91,    91,    15,    15,    44,    40,
      47,    11,    15,    37,    92,    92,    92,    92,    81,    91,
      92,    92,    92,    92,    92,    92,    92,    81,    91,     5,
      16,     5,    16,     5,    94,    98,    12,    81,    81,    15,
      53,    19,    18,    99,     5,    91,    37,    37,    91,    91,
      91,    91,    91,    98,    91,    11,    17,    91,    91,    12,
      91,    15,    91,   101,    18,    91,    40,    19,    11,    11,
      40,    53,    40,    48,    12,    40,     5,    74,   102,   103,
      17,    17,    22,    91,    88,   101,    19,    91,     5,     5,
      91,    91,    91,    91,    91,    40,    88,    40,    72,    12,
      11,    19,    17,    40,    40,    53,    91,    40,    91,   103,
      79,    80,    19,    91,    91,    91,    91,    80,    12,    12,
      12,    40,    91
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 246 "syntax.y"
    { output(&yy->state, make_definitions((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].tag_tuple))); ;}
    break;

  case 3:
#line 249 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (2)].tag_tuple), (yyvsp[(2) - (2)].tag_tuple));;}
    break;

  case 4:
#line 250 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (1)].tag_tuple), NULL);;}
    break;

  case 5:
#line 252 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple);  ;}
    break;

  case 6:
#line 253 "syntax.y"
    { (yyval.tag_tuple) = make_include((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].tag_tuple));  ;}
    break;

  case 7:
#line 254 "syntax.y"
    { (yyval.tag_tuple) = make_typedef((yylsp[(1) - (4)]).first_line, (yyvsp[(2) - (4)].string_value), 1, (yyvsp[(4) - (4)].data_type));  ;}
    break;

  case 8:
#line 255 "syntax.y"
    { (yyval.tag_tuple) = make_typedef((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].string_value), 1, NULL);  ;}
    break;

  case 9:
#line 256 "syntax.y"
    { (yyval.tag_tuple) = make_static((yylsp[(1) - (4)]).first_line, (yyvsp[(2) - (4)].declaration), (yyvsp[(4) - (4)].tag_tuple), NULL);  ;}
    break;

  case 10:
#line 258 "syntax.y"
    { (yyval.tag_tuple) = make_datatype((yylsp[(1) - (12)]).first_line, (yyvsp[(4) - (12)].string_value), 1, (yyvsp[(2) - (12)].data_type), (yyvsp[(6) - (12)].declaration), (yyvsp[(8) - (12)].tag_tuple), (yyvsp[(11) - (12)].tag_tuple));  ;}
    break;

  case 11:
#line 260 "syntax.y"
    { (yyval.tag_tuple) = make_function((yylsp[(1) - (9)]).first_line, (yyvsp[(2) - (9)].string_value), 1, (yyvsp[(4) - (9)].declaration), (yyvsp[(7) - (9)].data_type), (yyvsp[(9) - (9)].tag_tuple));  ;}
    break;

  case 12:
#line 261 "syntax.y"
    { (yyval.tag_tuple) = make_function((yylsp[(1) - (7)]).first_line, (yyvsp[(2) - (7)].string_value), 1, (yyvsp[(4) - (7)].declaration), (yyvsp[(7) - (7)].data_type), NULL);  ;}
    break;

  case 13:
#line 263 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (2)].tag_tuple), (yyvsp[(2) - (2)].tag_tuple));;}
    break;

  case 14:
#line 264 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (1)].tag_tuple), NULL);;}
    break;

  case 15:
#line 266 "syntax.y"
    { (yyval.data_type) = make_arrow_type((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].data_type), (yyvsp[(3) - (3)].data_type)); ;}
    break;

  case 16:
#line 267 "syntax.y"
    { (yyval.data_type) = make_arrow_type((yylsp[(1) - (5)]).first_line, (yyvsp[(2) - (5)].data_type), (yyvsp[(5) - (5)].data_type)); ;}
    break;

  case 17:
#line 268 "syntax.y"
    { (yyval.data_type) = make_arrow_type((yylsp[(1) - (4)]).first_line, NULL, (yyvsp[(4) - (4)].data_type)); ;}
    break;

  case 18:
#line 269 "syntax.y"
    { (yyval.data_type) = (yyvsp[(1) - (1)].data_type); ;}
    break;

  case 19:
#line 271 "syntax.y"
    { (yyval.data_type) = make_pointer_type((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].data_type)); ;}
    break;

  case 20:
#line 272 "syntax.y"
    { (yyval.data_type) = make_array_pointer_type((yylsp[(1) - (4)]).first_line, (yyvsp[(2) - (4)].data_type)); ;}
    break;

  case 21:
#line 273 "syntax.y"
    { (yyval.data_type) = make_array_box_type((yylsp[(1) - (4)]).first_line, (yyvsp[(2) - (4)].data_type)); ;}
    break;

  case 22:
#line 274 "syntax.y"
    { (yyval.data_type) = make_box_type((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].data_type)); ;}
    break;

  case 23:
#line 275 "syntax.y"
    { (yyval.data_type) = (yyvsp[(1) - (1)].data_type); ;}
    break;

  case 24:
#line 277 "syntax.y"
    { (yyval.data_type) = make_array_type((yylsp[(1) - (4)]).first_line, (yyvsp[(1) - (4)].data_type), (yyvsp[(3) - (4)].tag_tuple));;}
    break;

  case 25:
#line 278 "syntax.y"
    { (yyval.data_type) = (yyvsp[(1) - (1)].data_type); ;}
    break;

  case 26:
#line 280 "syntax.y"
    { (yyval.data_type) = make_byte_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 27:
#line 281 "syntax.y"
    { (yyval.data_type) = make_int_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 28:
#line 282 "syntax.y"
    { (yyval.data_type) = make_long_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 29:
#line 283 "syntax.y"
    { (yyval.data_type) = make_double_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 30:
#line 284 "syntax.y"
    { (yyval.data_type) = make_boolean_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 31:
#line 285 "syntax.y"
    { (yyval.data_type) = make_record_type((yylsp[(1) - (3)]).first_line, (yyvsp[(2) - (3)].declaration)); ;}
    break;

  case 32:
#line 286 "syntax.y"
    { (yyval.data_type) = make_record_type((yylsp[(1) - (4)]).first_line, (yyvsp[(3) - (4)].union_declaration)); ;}
    break;

  case 33:
#line 287 "syntax.y"
    { (yyval.data_type) = make_pointer_type((yylsp[(1) - (2)]).first_line, NULL); ;}
    break;

  case 34:
#line 288 "syntax.y"
    { (yyval.data_type) = make_box_type((yylsp[(1) - (2)]).first_line, NULL); ;}
    break;

  case 35:
#line 289 "syntax.y"
    { (yyval.data_type) = make_dynamic_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 36:
#line 290 "syntax.y"
    { (yyval.data_type) = make_chars_type((yylsp[(1) - (1)]).first_line); ;}
    break;

  case 37:
#line 291 "syntax.y"
    { (yyval.data_type) = make_named_type((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].string_value), 1); ;}
    break;

  case 38:
#line 292 "syntax.y"
    { (yyval.data_type) = (yyvsp[(2) - (3)].data_type) ;}
    break;

  case 39:
#line 294 "syntax.y"
    { (yyval.data_type) = result_type_list((yyvsp[(1) - (3)].data_type), (yyvsp[(3) - (3)].data_type));;}
    break;

  case 40:
#line 295 "syntax.y"
    { (yyval.data_type) = result_type_list((yyvsp[(1) - (3)].data_type), NULL);;}
    break;

  case 41:
#line 297 "syntax.y"
    { (yyval.declaration) = (yyvsp[(1) - (1)].declaration); ;}
    break;

  case 42:
#line 298 "syntax.y"
    { (yyval.declaration) = result_decl_list(NULL, NULL);;}
    break;

  case 43:
#line 300 "syntax.y"
    { (yyval.declaration) = result_decl_list((yyvsp[(1) - (3)].declaration), (yyvsp[(3) - (3)].declaration));;}
    break;

  case 44:
#line 301 "syntax.y"
    { (yyval.declaration) = result_decl_list((yyvsp[(1) - (1)].declaration), NULL);;}
    break;

  case 45:
#line 303 "syntax.y"
    {(yyval.declaration) = make_declaration((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].string_value), 1, (yyvsp[(3) - (3)].data_type));;}
    break;

  case 46:
#line 304 "syntax.y"
    {(yyval.declaration) = make_declaration((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].string_value), 1, NULL);;}
    break;

  case 47:
#line 306 "syntax.y"
    { (yyval.union_declaration) = result_decl_list((yyvsp[(1) - (3)].union_declaration), (yyvsp[(3) - (3)].union_declaration));;}
    break;

  case 48:
#line 307 "syntax.y"
    { (yyval.union_declaration) = result_decl_list((yyvsp[(1) - (1)].union_declaration), NULL);;}
    break;

  case 49:
#line 309 "syntax.y"
    {(yyval.union_declaration) = make_declaration((yylsp[(1) - (2)]).first_line, (yyvsp[(1) - (2)].string_value), 1, (yyvsp[(2) - (2)].data_type));;}
    break;

  case 50:
#line 310 "syntax.y"
    {(yyval.union_declaration) = make_declaration((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].string_value), 1, NULL);;}
    break;

  case 51:
#line 312 "syntax.y"
    { (yyval.tag_tuple) = make_assign((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 52:
#line 313 "syntax.y"
    { (yyval.tag_tuple) = make_convert((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].data_type)); ;}
    break;

  case 53:
#line 314 "syntax.y"
    { (yyval.tag_tuple) = make_is((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].data_type)); ;}
    break;

  case 54:
#line 315 "syntax.y"
    { (yyval.tag_tuple) = make_let((yylsp[(1) - (6)]).first_line, (yyvsp[(2) - (6)].declaration), (yyvsp[(4) - (6)].tag_tuple), (yyvsp[(6) - (6)].tag_tuple)); ;}
    break;

  case 55:
#line 316 "syntax.y"
    { (yyval.tag_tuple) = make_static((yylsp[(1) - (6)]).first_line, (yyvsp[(2) - (6)].declaration), (yyvsp[(4) - (6)].tag_tuple), (yyvsp[(6) - (6)].tag_tuple)); ;}
    break;

  case 56:
#line 317 "syntax.y"
    { (yyval.tag_tuple) = make_if((yylsp[(1) - (6)]).first_line, (yyvsp[(2) - (6)].tag_tuple), (yyvsp[(4) - (6)].tag_tuple), (yyvsp[(6) - (6)].tag_tuple)); ;}
    break;

  case 57:
#line 318 "syntax.y"
    { (yyval.tag_tuple) = make_case_expr((yylsp[(1) - (6)]).first_line, (yyvsp[(2) - (6)].tag_tuple), (yyvsp[(5) - (6)].case)); ;}
    break;

  case 58:
#line 319 "syntax.y"
    { (yyval.tag_tuple) = make_for((yylsp[(1) - (10)]).first_line, (yyvsp[(2) - (10)].declaration), (yyvsp[(4) - (10)].tag_tuple), (yyvsp[(6) - (10)].tag_tuple), (yyvsp[(8) - (10)].tag_tuple), (yyvsp[(10) - (10)].tag_tuple)); ;}
    break;

  case 59:
#line 320 "syntax.y"
    { (yyval.tag_tuple) = make_foreach((yylsp[(1) - (6)]).first_line, (yyvsp[(2) - (6)].declaration), (yyvsp[(4) - (6)].tag_tuple), (yyvsp[(6) - (6)].tag_tuple)); ;}
    break;

  case 60:
#line 321 "syntax.y"
    { (yyval.tag_tuple) = make_while((yylsp[(1) - (4)]).first_line, (yyvsp[(2) - (4)].tag_tuple), (yyvsp[(4) - (4)].tag_tuple)); ;}
    break;

  case 61:
#line 322 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 62:
#line 324 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_ADD, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 63:
#line 325 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_SUB, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 64:
#line 326 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_LTE, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 65:
#line 327 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_GTE, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 66:
#line 328 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_LT, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 67:
#line 329 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_GT, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 68:
#line 330 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_EQ, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 69:
#line 331 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_ADD, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 70:
#line 332 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_SUB, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple)); ;}
    break;

  case 71:
#line 333 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_MUL, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple));  ;}
    break;

  case 72:
#line 334 "syntax.y"
    { (yyval.tag_tuple) = make_exp((yylsp[(1) - (3)]).first_line, OP_DIV, (yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple));  ;}
    break;

  case 73:
#line 335 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 74:
#line 337 "syntax.y"
    { (yyval.tag_tuple) = make_access((yylsp[(1) - (2)]).first_line, (yyvsp[(1) - (2)].tag_tuple), (yyvsp[(2) - (2)].access_path)); ;}
    break;

  case 75:
#line 338 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple) ;}
    break;

  case 76:
#line 340 "syntax.y"
    { (yyval.access_path) = result_access_path_list((yyvsp[(1) - (2)].access_path), (yyvsp[(2) - (2)].access_path));;}
    break;

  case 77:
#line 341 "syntax.y"
    { (yyval.access_path) = result_access_path_list((yyvsp[(1) - (1)].access_path), NULL);;}
    break;

  case 78:
#line 343 "syntax.y"
    { (yyval.access_path) = make_record_access_path((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].string_value), 1); ;}
    break;

  case 79:
#line 344 "syntax.y"
    { (yyval.access_path) = make_record_deref_access_path((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].string_value), 1); ;}
    break;

  case 80:
#line 345 "syntax.y"
    { (yyval.access_path) = make_record_ref_access_path((yylsp[(1) - (2)]).first_line, (yyvsp[(2) - (2)].string_value), 1); ;}
    break;

  case 81:
#line 346 "syntax.y"
    { (yyval.access_path) = make_array_access_path((yylsp[(1) - (3)]).first_line, (yyvsp[(2) - (3)].tag_tuple)); ;}
    break;

  case 82:
#line 347 "syntax.y"
    { (yyval.access_path) = make_array_deref_access_path((yylsp[(1) - (4)]).first_line, (yyvsp[(3) - (4)].tag_tuple)); ;}
    break;

  case 83:
#line 348 "syntax.y"
    { (yyval.access_path) = make_array_ref_access_path((yylsp[(1) - (4)]).first_line, (yyvsp[(3) - (4)].tag_tuple)); ;}
    break;

  case 84:
#line 350 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_NOT, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 85:
#line 351 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_PLUS, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 86:
#line 352 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_MINUS, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 87:
#line 353 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_DEREF, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 88:
#line 354 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_REF, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 89:
#line 355 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_LEN, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 90:
#line 357 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_BOX, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 91:
#line 358 "syntax.y"
    { (yyval.tag_tuple) = make_unary_exp((yylsp[(1) - (2)]).first_line, OP_UNBOX, (yyvsp[(2) - (2)].tag_tuple)); ;}
    break;

  case 92:
#line 359 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 93:
#line 360 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 94:
#line 361 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 95:
#line 362 "syntax.y"
    { (yyval.tag_tuple) = make_box_of((yylsp[(1) - (9)]).first_line, (yyvsp[(3) - (9)].tag_tuple), (yyvsp[(6) - (9)].string_value), 1, (yyvsp[(8) - (9)].tag_tuple)); ;}
    break;

  case 96:
#line 363 "syntax.y"
    { (yyval.tag_tuple) = make_mut_array_of((yylsp[(1) - (9)]).first_line, (yyvsp[(3) - (9)].tag_tuple), (yyvsp[(6) - (9)].string_value), 1, (yyvsp[(8) - (9)].tag_tuple)); ;}
    break;

  case 97:
#line 364 "syntax.y"
    { (yyval.tag_tuple) = make_array_of((yylsp[(1) - (7)]).first_line, (yyvsp[(2) - (7)].tag_tuple), (yyvsp[(4) - (7)].string_value), 1, (yyvsp[(6) - (7)].tag_tuple)); ;}
    break;

  case 98:
#line 365 "syntax.y"
    { (yyval.tag_tuple) = make_new((yylsp[(1) - (5)]).first_line, (yyvsp[(2) - (5)].data_type), (yyvsp[(4) - (5)].tag_tuple)); ;}
    break;

  case 99:
#line 366 "syntax.y"
    { (yyval.tag_tuple) = make_lambda((yylsp[(1) - (5)]).first_line, (yyvsp[(2) - (5)].declaration), (yyvsp[(4) - (5)].tag_tuple)); ;}
    break;

  case 100:
#line 367 "syntax.y"
    { (yyval.tag_tuple) = make_array((yylsp[(1) - (3)]).first_line, (yyvsp[(2) - (3)].tag_tuple)); ;}
    break;

  case 101:
#line 368 "syntax.y"
    { (yyval.tag_tuple) = make_record((yylsp[(1) - (4)]).first_line, (yyvsp[(1) - (4)].string_value), 1, (yyvsp[(3) - (4)].mapping)); ;}
    break;

  case 102:
#line 369 "syntax.y"
    { (yyval.tag_tuple) = make_union((yylsp[(1) - (6)]).first_line, (yyvsp[(1) - (6)].string_value), 1, (yyvsp[(3) - (6)].string_value), (yyvsp[(5) - (6)].tag_tuple)); ;}
    break;

  case 103:
#line 370 "syntax.y"
    { (yyval.tag_tuple) = make_record_union((yylsp[(1) - (8)]).first_line, (yyvsp[(1) - (8)].string_value), 1, (yyvsp[(3) - (8)].string_value), (yyvsp[(6) - (8)].mapping)); ;}
    break;

  case 104:
#line 371 "syntax.y"
    { (yyval.tag_tuple) = make_union((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].string_value), 1, (yyvsp[(3) - (3)].string_value), NULL); ;}
    break;

  case 105:
#line 372 "syntax.y"
    { (yyval.tag_tuple) = make_tuple((yylsp[(1) - (4)]).first_line, (yyvsp[(1) - (4)].string_value), 1, (yyvsp[(3) - (4)].tag_tuple)); ;}
    break;

  case 106:
#line 373 "syntax.y"
    { (yyval.tag_tuple) = make_tag((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].string_value), 1); ;}
    break;

  case 107:
#line 376 "syntax.y"
    { (yyval.string_value) = (yyvsp[(1) - (1)].string_value); ;}
    break;

  case 108:
#line 377 "syntax.y"
    { (yyval.string_value) = NULL; ;}
    break;

  case 109:
#line 381 "syntax.y"
    { (yyval.tag_tuple) = (yyvsp[(1) - (1)].tag_tuple); ;}
    break;

  case 110:
#line 382 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list(NULL, NULL);;}
    break;

  case 111:
#line 384 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (3)].tag_tuple), (yyvsp[(3) - (3)].tag_tuple));;}
    break;

  case 112:
#line 385 "syntax.y"
    { (yyval.tag_tuple) = result_arg_list((yyvsp[(1) - (1)].tag_tuple), NULL);;}
    break;

  case 113:
#line 387 "syntax.y"
    {(yyval.mapping) = make_mapping((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].declaration), (yyvsp[(3) - (3)].tag_tuple));;}
    break;

  case 114:
#line 389 "syntax.y"
    { (yyval.mapping) = result_maps_list((yyvsp[(1) - (3)].mapping), (yyvsp[(3) - (3)].mapping));;}
    break;

  case 115:
#line 390 "syntax.y"
    { (yyval.mapping) = result_maps_list((yyvsp[(1) - (1)].mapping), NULL);;}
    break;

  case 116:
#line 392 "syntax.y"
    {(yyval.case) = make_case((yylsp[(1) - (4)]).first_line, (yyvsp[(1) - (4)].string_value), (yyvsp[(2) - (4)].declaration), (yyvsp[(4) - (4)].tag_tuple));;}
    break;

  case 117:
#line 393 "syntax.y"
    {(yyval.case) = make_case((yylsp[(1) - (3)]).first_line, (yyvsp[(1) - (3)].string_value), (yyvsp[(3) - (3)].tag_tuple));;}
    break;

  case 118:
#line 394 "syntax.y"
    {(yyval.case) = make_case((yylsp[(1) - (3)]).first_line, NULL, (yyvsp[(3) - (3)].tag_tuple));;}
    break;

  case 119:
#line 396 "syntax.y"
    { (yyval.case) = result_maps_list((yyvsp[(1) - (3)].case), (yyvsp[(3) - (3)].case));;}
    break;

  case 120:
#line 397 "syntax.y"
    { (yyval.case) = result_maps_list((yyvsp[(1) - (1)].case), NULL);;}
    break;

  case 121:
#line 399 "syntax.y"
    { (yyval.tag_tuple) = make_double((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].double_value)); ;}
    break;

  case 122:
#line 400 "syntax.y"
    { (yyval.tag_tuple) = make_long((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].integer_value)); ;}
    break;

  case 123:
#line 401 "syntax.y"
    { (yyval.tag_tuple) = make_string((yylsp[(1) - (1)]).first_line, (yyvsp[(1) - (1)].string_value)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2552 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 403 "syntax.y"


int yyerror(char *s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c  
  PRINTF_ERROR("%s at symbol \"%s\"\n", yylineno, s, yytext);
  exit(1);
}

static void init_iteractive_state(state *state) {
    state->interactive = 1;
    state->stream = stdin;
}

void tagtuple_interactive(void (*run)(parse_output output)) {
    if (run == NULL)
        return;
    yycontext ctx;
    memset(&ctx, 0, sizeof(yycontext));
    init_iteractive_state(&ctx.state);
    yy = &ctx;
    while (yyparse()) {
        const parse_output output = ctx.state.output;
        run(output);
        if (feof(ctx.state.stream))
            break;
        memset(&ctx.state, 0, sizeof(state));
        init_iteractive_state(&ctx.state);
    }
}

parse_output tagtuple_parse(FILE *stream) {
    extern FILE *yyin;
    yycontext ctx;
    memset(&ctx, 0, sizeof(yycontext));
    ctx.state.interactive = 0;
    ctx.state.stream = stream;
    yy = &ctx;
    yyin = stream;
    yyparse();
    const parse_output output = ctx.state.output;
    return output;
}

