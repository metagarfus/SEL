/* Mini Calculator */
/* calc.lex */

%{
#include "heading.h"    
#include "utils.h"
#include "tagtuple.h"
#include "syntax.tab.h"
int yyerror(char *s);
%}
%option noyywrap
%%
      
"+"                                     { return PLUS; }          
"-"                                     { return MINUS; }
"*"                                     { return TIMES          ;}
"/"                                     { return DIVIDE         ;}
"("                                     { return OPEN           ;}
")"                                     { return CLOSE          ;}
":"                                     { return COLON          ;}
":="                                    { return ASSIGN         ;}
"="                                     { return EQUALS         ;}
"["                                     { return OPEN_S_BRACKET ;}
"]"                                     { return CLOSE_S_BRACKET;}
"{"                                     { return OPEN_BRACKET   ;}
"}"                                     { return CLOSE_BRACKET  ;}
"include"                               { return INCLUDE        ;}
"datatype"                              { return DATATYPE       ;}
"with"                                  { return WITH           ;}
"function"                              { return FUNCTION       ;}
"prototype"                             { return PROTOTYPE      ;}
"external"                              { return EXTERNAL       ;}
"->"                                    { return ARROW          ;}
"byte"                                  { return BYTE           ;}
"int"                                   { return INT            ;}
"long"                                  { return LONG           ;}
"double"                                { return DOUBLE         ;}
"chars"                                 { return CHARS          ;}
"array"                                 { return ARRAY          ;}
"box"                                   { return BOX            ;}
"unbox"                                 { return UNBOX          ;}
"of"                                    { return OF             ;}
"dynamic"                               { return DYNAMIC        ;}
"=>"                                    { return APPLY          ;}
"in"                                    { return IN             ;}
"let"                                   { return LET            ;}
"for"                                   { return FOR            ;} 
"foreach"                               { return FOREACH        ;} 
"from"                                  { return FROM           ;} 
"while"                                 { return WHILE          ;} 
"if"                                    { return IF             ;} 
"then"                                  { return THEN           ;} 
"else"                                  { return ELSE           ;} 
"#"                                     { return CARDINAL       ;} 
"$"                                     { return DOLLAR         ;} 
"new"                                   { return NEW            ;} 
"typedef"                               { return TYPEDEF        ;} 
","                                     { return COMMA          ;} 
"&"                                     { return AMPERSAND      ;} 
"&&"                                    { return AND            ;} 
"||"                                    { return OR             ;} 
"<="                                    { return LTE            ;} 
">="                                    { return GTE            ;} 
"<"                                     { return LT             ;} 
">"                                     { return GT             ;} 
"=="                                    { return EQ             ;} 
"!"                                     { return NOT            ;} 
"."                                     { return DOT            ;} 
"is"                                    { return IS             ;} 
"static"                                { return STATIC         ;}
"as"                                    { return AS; } 
"?"                                     { return QUESTION_MARK; }   
\"(\\.|[^\\"])*\"                       { yylval.string_value = yytext; return STRING; }
([0-9]*"."[0-9]*)("E"("-")?[0-9]+)?     { yylval.double_value = strtof(yytext, NULL); return DOUBLE_VALUE; }
"0x"?[0-9]+                             { yylval.integer_value = strtol(yytext, NULL, 0); return INTEGER;  }
[_a-zA-Z][_a-zA-Z0-9]*                  { yylval.string_value = clone_string(yytext); return TAG; }
[ \t]* 		                            {}
"//"[^\n]*[\n]                          { yylineno++;	} 
[\n]		                            { yylineno++;	}
.		                                { yyerror(""); exit(1);	}
