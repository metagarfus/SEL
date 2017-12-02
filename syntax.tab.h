/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 211 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
