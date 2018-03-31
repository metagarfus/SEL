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
#line 1 "syntax.y" /* yacc.c:339  */

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


#line 179 "syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 231 "syntax.y" /* yacc.c:355  */

        tag_tuple * tag_tuple;
        value_data_type_t *data_type;
        mapping_t *mapping;
        declaration_t *declaration;
        union_declaration_t *union_declaration;
        case_t *union_case;
        char *text;
        access_path_t *access_path;
        double double_value;
        int64_t integer_value;
        char *string_value;
    

#line 309 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 340 "syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "STRING_EXPR", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF -211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-211)))

#define YYTABLE_NINF -111

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,   282,  -211,  -197,     4,     1,    -8,    61,    83,
     230,   -49,   -14,    -6,   187,  -211,   -59,   202,  -211,   131,
    -211,   220,  -211,  -151,   117,  -211,  -210,  -211,    23,  -211,
      79,   301
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,   291,    44,    28,    29,    30,
      46,    77,    78,    48,    71,    72,   130,   104,   105,   168,
     169,   106,   107,   131,   132,   177,   178,   258,   259,   108,
     109,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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
     '$$ = $1'.

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
#line 246 "syntax.y" /* yacc.c:1646  */
    { output(&yy->state, make_definitions((yylsp[0]).first_line, (yyvsp[0].tag_tuple))); }
#line 1784 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 249 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[-1].tag_tuple), (yyvsp[0].tag_tuple));}
#line 1790 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 250 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[0].tag_tuple), NULL);}
#line 1796 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 252 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple);  }
#line 1802 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 253 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_include((yylsp[-1]).first_line, (yyvsp[0].tag_tuple));  }
#line 1808 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 254 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_typedef((yylsp[-3]).first_line, (yyvsp[-2].string_value), 1, (yyvsp[0].data_type));  }
#line 1814 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 255 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_typedef((yylsp[-1]).first_line, (yyvsp[0].string_value), 1, NULL);  }
#line 1820 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 256 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_static((yylsp[-3]).first_line, (yyvsp[-2].declaration), (yyvsp[0].tag_tuple), NULL);  }
#line 1826 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 258 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_datatype((yylsp[-11]).first_line, (yyvsp[-8].string_value), 1, (yyvsp[-10].data_type), (yyvsp[-6].declaration), (yyvsp[-4].tag_tuple), (yyvsp[-1].tag_tuple));  }
#line 1832 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 260 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_function((yylsp[-8]).first_line, (yyvsp[-7].string_value), 1, (yyvsp[-5].declaration), (yyvsp[-2].data_type), (yyvsp[0].tag_tuple));  }
#line 1838 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 261 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_function((yylsp[-6]).first_line, (yyvsp[-5].string_value), 1, (yyvsp[-3].declaration), (yyvsp[0].data_type), NULL);  }
#line 1844 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 263 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[-1].tag_tuple), (yyvsp[0].tag_tuple));}
#line 1850 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 264 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[0].tag_tuple), NULL);}
#line 1856 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 266 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_arrow_type((yylsp[-2]).first_line, (yyvsp[-2].data_type), (yyvsp[0].data_type)); }
#line 1862 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 267 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_arrow_type((yylsp[-4]).first_line, (yyvsp[-3].data_type), (yyvsp[0].data_type)); }
#line 1868 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 268 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_arrow_type((yylsp[-3]).first_line, NULL, (yyvsp[0].data_type)); }
#line 1874 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 269 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = (yyvsp[0].data_type); }
#line 1880 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_pointer_type((yylsp[-1]).first_line, (yyvsp[0].data_type)); }
#line 1886 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 272 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_array_pointer_type((yylsp[-3]).first_line, (yyvsp[-2].data_type)); }
#line 1892 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 273 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_array_box_type((yylsp[-3]).first_line, (yyvsp[-2].data_type)); }
#line 1898 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_box_type((yylsp[-1]).first_line, (yyvsp[0].data_type)); }
#line 1904 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = (yyvsp[0].data_type); }
#line 1910 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 277 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_array_type((yylsp[-3]).first_line, (yyvsp[-3].data_type), (yyvsp[-1].tag_tuple));}
#line 1916 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 278 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = (yyvsp[0].data_type); }
#line 1922 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 280 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_byte_type((yylsp[0]).first_line); }
#line 1928 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 281 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_int_type((yylsp[0]).first_line); }
#line 1934 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_long_type((yylsp[0]).first_line); }
#line 1940 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 283 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_double_type((yylsp[0]).first_line); }
#line 1946 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 284 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_boolean_type((yylsp[0]).first_line); }
#line 1952 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 285 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_record_type((yylsp[-2]).first_line, (yyvsp[-1].declaration)); }
#line 1958 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 286 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_record_type((yylsp[-3]).first_line, (yyvsp[-1].union_declaration)); }
#line 1964 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 287 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_pointer_type((yylsp[-1]).first_line, NULL); }
#line 1970 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 288 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_box_type((yylsp[-1]).first_line, NULL); }
#line 1976 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 289 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_dynamic_type((yylsp[0]).first_line); }
#line 1982 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 290 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_chars_type((yylsp[0]).first_line); }
#line 1988 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 291 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = make_named_type((yylsp[0]).first_line, (yyvsp[0].string_value), 1); }
#line 1994 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 292 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = (yyvsp[-1].data_type) }
#line 2000 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 294 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = result_type_list((yyvsp[-2].data_type), (yyvsp[0].data_type));}
#line 2006 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 295 "syntax.y" /* yacc.c:1646  */
    { (yyval.data_type) = result_type_list((yyvsp[-2].data_type), NULL);}
#line 2012 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 297 "syntax.y" /* yacc.c:1646  */
    { (yyval.declaration) = (yyvsp[0].declaration); }
#line 2018 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 298 "syntax.y" /* yacc.c:1646  */
    { (yyval.declaration) = result_decl_list(NULL, NULL);}
#line 2024 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "syntax.y" /* yacc.c:1646  */
    { (yyval.declaration) = result_decl_list((yyvsp[-2].declaration), (yyvsp[0].declaration));}
#line 2030 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 301 "syntax.y" /* yacc.c:1646  */
    { (yyval.declaration) = result_decl_list((yyvsp[0].declaration), NULL);}
#line 2036 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 303 "syntax.y" /* yacc.c:1646  */
    {(yyval.declaration) = make_declaration((yylsp[-2]).first_line, (yyvsp[-2].string_value), 1, (yyvsp[0].data_type));}
#line 2042 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 304 "syntax.y" /* yacc.c:1646  */
    {(yyval.declaration) = make_declaration((yylsp[0]).first_line, (yyvsp[0].string_value), 1, NULL);}
#line 2048 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 306 "syntax.y" /* yacc.c:1646  */
    { (yyval.union_declaration) = result_decl_list((yyvsp[-2].union_declaration), (yyvsp[0].union_declaration));}
#line 2054 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 307 "syntax.y" /* yacc.c:1646  */
    { (yyval.union_declaration) = result_decl_list((yyvsp[0].union_declaration), NULL);}
#line 2060 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 309 "syntax.y" /* yacc.c:1646  */
    {(yyval.union_declaration) = make_declaration((yylsp[-1]).first_line, (yyvsp[-1].string_value), 1, (yyvsp[0].data_type));}
#line 2066 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 310 "syntax.y" /* yacc.c:1646  */
    {(yyval.union_declaration) = make_declaration((yylsp[0]).first_line, (yyvsp[0].string_value), 1, NULL);}
#line 2072 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 312 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_assign((yylsp[-2]).first_line, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2078 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 313 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_convert((yylsp[-2]).first_line, (yyvsp[-2].tag_tuple), (yyvsp[0].data_type)); }
#line 2084 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 314 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_is((yylsp[-2]).first_line, (yyvsp[-2].tag_tuple), (yyvsp[0].data_type)); }
#line 2090 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 315 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_let((yylsp[-5]).first_line, (yyvsp[-4].declaration), (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2096 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 316 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_static((yylsp[-5]).first_line, (yyvsp[-4].declaration), (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2102 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 317 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_if((yylsp[-5]).first_line, (yyvsp[-4].tag_tuple), (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2108 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 318 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_case_expr((yylsp[-5]).first_line, (yyvsp[-4].tag_tuple), (yyvsp[-1].union_case)); }
#line 2114 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 319 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_for((yylsp[-9]).first_line, (yyvsp[-8].declaration), (yyvsp[-6].tag_tuple), (yyvsp[-4].tag_tuple), (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2120 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 320 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_foreach((yylsp[-5]).first_line, (yyvsp[-4].declaration), (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2126 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_while((yylsp[-3]).first_line, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2132 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 322 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2138 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 324 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_ADD, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2144 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 325 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_SUB, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2150 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 326 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_LTE, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2156 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 327 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_GTE, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2162 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 328 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_LT, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2168 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 329 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_GT, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2174 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 330 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_EQ, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2180 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 331 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_ADD, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2186 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 332 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_SUB, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple)); }
#line 2192 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 333 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_MUL, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple));  }
#line 2198 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 334 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_exp((yylsp[-2]).first_line, OP_DIV, (yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple));  }
#line 2204 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 335 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2210 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 337 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_access((yylsp[-1]).first_line, (yyvsp[-1].tag_tuple), (yyvsp[0].access_path)); }
#line 2216 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 338 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple) }
#line 2222 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 340 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = result_access_path_list((yyvsp[-1].access_path), (yyvsp[0].access_path));}
#line 2228 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 341 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = result_access_path_list((yyvsp[0].access_path), NULL);}
#line 2234 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 343 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_record_access_path((yylsp[-1]).first_line, (yyvsp[0].string_value), 1); }
#line 2240 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 344 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_record_deref_access_path((yylsp[-1]).first_line, (yyvsp[0].string_value), 1); }
#line 2246 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 345 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_record_ref_access_path((yylsp[-1]).first_line, (yyvsp[0].string_value), 1); }
#line 2252 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 346 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_array_access_path((yylsp[-2]).first_line, (yyvsp[-1].tag_tuple)); }
#line 2258 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 347 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_array_deref_access_path((yylsp[-3]).first_line, (yyvsp[-1].tag_tuple)); }
#line 2264 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 348 "syntax.y" /* yacc.c:1646  */
    { (yyval.access_path) = make_array_ref_access_path((yylsp[-3]).first_line, (yyvsp[-1].tag_tuple)); }
#line 2270 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 350 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_NOT, (yyvsp[0].tag_tuple)); }
#line 2276 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 351 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_PLUS, (yyvsp[0].tag_tuple)); }
#line 2282 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 352 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_MINUS, (yyvsp[0].tag_tuple)); }
#line 2288 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 353 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_DEREF, (yyvsp[0].tag_tuple)); }
#line 2294 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 354 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_REF, (yyvsp[0].tag_tuple)); }
#line 2300 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 355 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_LEN, (yyvsp[0].tag_tuple)); }
#line 2306 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 357 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_BOX, (yyvsp[0].tag_tuple)); }
#line 2312 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 358 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_unary_exp((yylsp[-1]).first_line, OP_UNBOX, (yyvsp[0].tag_tuple)); }
#line 2318 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 359 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2324 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 360 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2330 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 361 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2336 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 362 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_box_of((yylsp[-8]).first_line, (yyvsp[-6].tag_tuple), (yyvsp[-3].string_value), 1, (yyvsp[-1].tag_tuple)); }
#line 2342 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 363 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_mut_array_of((yylsp[-8]).first_line, (yyvsp[-6].tag_tuple), (yyvsp[-3].string_value), 1, (yyvsp[-1].tag_tuple)); }
#line 2348 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 364 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_array_of((yylsp[-6]).first_line, (yyvsp[-5].tag_tuple), (yyvsp[-3].string_value), 1, (yyvsp[-1].tag_tuple)); }
#line 2354 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 365 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_new((yylsp[-4]).first_line, (yyvsp[-3].data_type), (yyvsp[-1].tag_tuple)); }
#line 2360 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 366 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_lambda((yylsp[-4]).first_line, (yyvsp[-3].declaration), (yyvsp[-1].tag_tuple)); }
#line 2366 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 367 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_array((yylsp[-2]).first_line, (yyvsp[-1].tag_tuple)); }
#line 2372 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 368 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_record((yylsp[-3]).first_line, (yyvsp[-3].string_value), 1, (yyvsp[-1].mapping)); }
#line 2378 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 369 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_union((yylsp[-5]).first_line, (yyvsp[-5].string_value), 1, (yyvsp[-3].string_value), (yyvsp[-1].tag_tuple)); }
#line 2384 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 370 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_record_union((yylsp[-7]).first_line, (yyvsp[-7].string_value), 1, (yyvsp[-5].string_value), (yyvsp[-2].mapping)); }
#line 2390 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 371 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_union((yylsp[-2]).first_line, (yyvsp[-2].string_value), 1, (yyvsp[0].string_value), NULL); }
#line 2396 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 372 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_tuple((yylsp[-3]).first_line, (yyvsp[-3].string_value), 1, (yyvsp[-1].tag_tuple)); }
#line 2402 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 373 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_tag((yylsp[0]).first_line, (yyvsp[0].string_value), 1); }
#line 2408 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 376 "syntax.y" /* yacc.c:1646  */
    { (yyval.string_value) = (yyvsp[0].string_value); }
#line 2414 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 377 "syntax.y" /* yacc.c:1646  */
    { (yyval.string_value) = NULL; }
#line 2420 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 381 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = (yyvsp[0].tag_tuple); }
#line 2426 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 382 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list(NULL, NULL);}
#line 2432 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 384 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[-2].tag_tuple), (yyvsp[0].tag_tuple));}
#line 2438 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 385 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = result_arg_list((yyvsp[0].tag_tuple), NULL);}
#line 2444 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 387 "syntax.y" /* yacc.c:1646  */
    {(yyval.mapping) = make_mapping((yylsp[-2]).first_line, (yyvsp[-2].declaration), (yyvsp[0].tag_tuple));}
#line 2450 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 389 "syntax.y" /* yacc.c:1646  */
    { (yyval.mapping) = result_maps_list((yyvsp[-2].mapping), (yyvsp[0].mapping));}
#line 2456 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 390 "syntax.y" /* yacc.c:1646  */
    { (yyval.mapping) = result_maps_list((yyvsp[0].mapping), NULL);}
#line 2462 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 392 "syntax.y" /* yacc.c:1646  */
    {(yyval.union_case) = make_case((yylsp[-3]).first_line, (yyvsp[-3].string_value), (yyvsp[-2].declaration), (yyvsp[0].tag_tuple));}
#line 2468 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 393 "syntax.y" /* yacc.c:1646  */
    {(yyval.union_case) = make_case((yylsp[-2]).first_line, (yyvsp[-2].string_value), (yyvsp[0].tag_tuple));}
#line 2474 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 394 "syntax.y" /* yacc.c:1646  */
    {(yyval.union_case) = make_case((yylsp[-2]).first_line, NULL, (yyvsp[0].tag_tuple));}
#line 2480 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 396 "syntax.y" /* yacc.c:1646  */
    { (yyval.union_case) = result_maps_list((yyvsp[-2].union_case), (yyvsp[0].union_case));}
#line 2486 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 397 "syntax.y" /* yacc.c:1646  */
    { (yyval.union_case) = result_maps_list((yyvsp[0].union_case), NULL);}
#line 2492 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 399 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_double((yylsp[0]).first_line, (yyvsp[0].double_value)); }
#line 2498 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 400 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_long((yylsp[0]).first_line, (yyvsp[0].integer_value)); }
#line 2504 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 401 "syntax.y" /* yacc.c:1646  */
    { (yyval.tag_tuple) = make_string((yylsp[0]).first_line, (yyvsp[0].string_value)); }
#line 2510 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2514 "syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 403 "syntax.y" /* yacc.c:1906  */


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
