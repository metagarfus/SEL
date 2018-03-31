/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 231 "syntax.y" /* yacc.c:1909  */

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
    

#line 144 "syntax.tab.h" /* yacc.c:1909  */
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
