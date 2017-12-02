%{
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

%}
%token <double_value> DOUBLE_VALUE    
%token <integer_value> INTEGER         
%token <string_value> TAG             
%token <string_value> STRING

%type <string_value> TAG_OR_EMPTY

%type <tag_tuple> Definitions
%type <tag_tuple> Definition
%type <tag_tuple> Function
%type <tag_tuple> FunctionList
%type <tag_tuple> Expr
%type <tag_tuple> ExpOp
%type <tag_tuple> Access
%type <tag_tuple> Value
%type <tag_tuple> Arguments
%type <tag_tuple> ArgList
%type <tag_tuple> DOUBLE_EXPR  
%type <tag_tuple> INTEGER_EXPR              
%type <tag_tuple> STRING_EXPR

%type <access_path> AccessPathList
%type <access_path> AccessPath

%type <data_type> ArrowType
%type <data_type> ArrayType
%type <data_type> PointerType
%type <data_type> SimpleType
%type <data_type> ArgTypeList

%type <declaration> VarDeclaration
%type <declaration> VarDeclarationList
%type <declaration> VarDeclarations

%type <union_declaration> UnionDeclaration
%type <union_declaration> UnionDeclarationList

%type <mapping> Mapping
%type <mapping> MapsList

%type <case> Case
%type <case> CaseList

%token   
PLUS            
MINUS           
TIMES           
DIVIDE          
OPEN            
CLOSE           
COLON           
ASSIGN          
EQUALS          
OPEN_S_BRACKET  
CLOSE_S_BRACKET 
OPEN_BRACKET    
CLOSE_BRACKET   
INCLUDE         
DATATYPE        
WITH            
FUNCTION        
PROTOTYPE       
EXTERNAL        
ARROW           
DOUBLE_ARROW           
BYTE            
INT             
LONG            
DOUBLE          
CHARS
BOOLEAN           
ARRAY           
BOX             
UNBOX           
OF              
DYNAMIC         
APPLY           
IN              
LET             
FOR             
FOREACH         
FROM            
WHILE           
IF              
THEN            
ELSE            
CARDINAL        
DOLLAR          
NEW             
TYPEDEF         
COMMA           
AMPERSAND       
AND             
OR              
LTE             
GTE             
LT              
GT              
EQ              
NOT             
DOT             
IS              
STATIC
AS 
QUESTION_MARK
SEMICOLON
QUOTES
UNION
CASE
PIPE
DOUBLE_COLON
OTHERWISE

%left AND OR
%left LTE GTE GT LT EQ
%left PLUS MINUS
%left TIMES DIVIDE

%union{
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
    };
%start Stmt
%%
Stmt    :  Definitions         { output(&yy->state, make_definitions(@1.first_line, $1)); }


Definitions : Definition Definitions                                     { $$ = result_arg_list($1, $2);}
            | Definition                                                 { $$ = result_arg_list($1, NULL);}

Definition : Function                                                    { $$ = $1;  } 
            | INCLUDE STRING_EXPR                                        { $$ = make_include(@1.first_line, $2);  } 
            | TYPEDEF TAG EQUALS ArrowType                               { $$ = make_typedef(@1.first_line, $2, 1, $4);  }
            | TYPEDEF TAG                                                { $$ = make_typedef(@1.first_line, $2, 1, NULL);  }
            | STATIC VarDeclaration EQUALS Expr                          { $$ = make_static(@1.first_line, $2, $4, NULL);  }  
            | DATATYPE ArrowType AS TAG OPEN VarDeclarations CLOSE Expr 
                   WITH OPEN FunctionList CLOSE                          { $$ = make_datatype(@1.first_line, $4, 1, $2, $6, $8, $11);  }

Function : FUNCTION TAG OPEN VarDeclarations CLOSE COLON ArrowType EQUALS Expr  { $$ = make_function(@1.first_line, $2, 1, $4, $7, $9);  } 
         | PROTOTYPE TAG OPEN VarDeclarations CLOSE COLON ArrowType             { $$ = make_function(@1.first_line, $2, 1, $4, $7, NULL);  }

FunctionList : Function FunctionList                                     { $$ = result_arg_list($1, $2);}
             | Function                                                  { $$ = result_arg_list($1, NULL);}

ArrowType   : PointerType ARROW ArrowType                                { $$ = make_arrow_type(@1.first_line, $1, $3); }
            | OPEN ArgTypeList CLOSE ARROW ArrowType                     { $$ = make_arrow_type(@1.first_line, $2, $5); }        
            | OPEN CLOSE ARROW ArrowType                                 { $$ = make_arrow_type(@1.first_line, NULL, $4); }        
            | PointerType                                                { $$ = $1; }

PointerType : TIMES ArrayType                                            { $$ = make_pointer_type(@1.first_line, $2); }
            | TIMES SimpleType OPEN_S_BRACKET CLOSE_S_BRACKET            { $$ = make_array_pointer_type(@1.first_line, $2); }
            | BOX SimpleType OPEN_S_BRACKET CLOSE_S_BRACKET              { $$ = make_array_box_type(@1.first_line, $2); }
            | BOX ArrayType                                              { $$ = make_box_type(@1.first_line, $2); }
            | ArrayType                                                  { $$ = $1; }

ArrayType   : SimpleType OPEN_S_BRACKET INTEGER_EXPR CLOSE_S_BRACKET     { $$ = make_array_type(@1.first_line, $1, $3);}
            | SimpleType                                                 { $$ = $1; }

SimpleType : BYTE                                                  { $$ = make_byte_type(@1.first_line); }
           | INT                                                   { $$ = make_int_type(@1.first_line); }
           | LONG                                                  { $$ = make_long_type(@1.first_line); }
           | DOUBLE                                                { $$ = make_double_type(@1.first_line); }
           | BOOLEAN                                               { $$ = make_boolean_type(@1.first_line); }
           | OPEN_BRACKET VarDeclarationList CLOSE_BRACKET         { $$ = make_record_type(@1.first_line, $2); }
           | UNION OPEN_BRACKET UnionDeclarationList CLOSE_BRACKET { $$ = make_record_type(@1.first_line, $3); }           
           | TIMES QUESTION_MARK                                   { $$ = make_pointer_type(@1.first_line, NULL); }
           | QUESTION_MARK     QUESTION_MARK                       { $$ = make_box_type(@1.first_line, NULL); }
           | DYNAMIC                                               { $$ = make_dynamic_type(@1.first_line); }
           | CHARS                                                 { $$ = make_chars_type(@1.first_line); }
           | TAG                                                   { $$ = make_named_type(@1.first_line, $1, 1); }   
           | OPEN ArrowType CLOSE                                  { $$ = $2 }

ArgTypeList : PointerType COMMA ArgTypeList                       { $$ = result_type_list($1, $3);}
            | PointerType COMMA PointerType                       { $$ = result_type_list($1, NULL);}

VarDeclarations : VarDeclarationList                              { $$ = $1; }
                |                                                 { $$ = result_decl_list(NULL, NULL);}

VarDeclarationList : VarDeclaration COMMA VarDeclarationList      { $$ = result_decl_list($1, $3);}
                   | VarDeclaration                               { $$ = result_decl_list($1, NULL);}

VarDeclaration : TAG COLON ArrowType                              {$$ = make_declaration(@1.first_line, $1, 1, $3);}       
               | TAG                                              {$$ = make_declaration(@1.first_line, $1, 1, NULL);}       

UnionDeclarationList : UnionDeclaration PIPE UnionDeclarationList   { $$ = result_decl_list($1, $3);}
                     | UnionDeclaration                             { $$ = result_decl_list($1, NULL);}

UnionDeclaration : TAG ArrowType                                   {$$ = make_declaration(@1.first_line, $1, 1, $2);}       
                 | TAG                                             {$$ = make_declaration(@1.first_line, $1, 1, NULL);}    

Expr  : ExpOp ASSIGN Expr                                             { $$ = make_assign(@1.first_line, $1, $3); } //MTODO test performance
      | ExpOp COLON ArrowType                                         { $$ = make_convert(@1.first_line, $1, $3); }
      | ExpOp IS ArrowType                                            { $$ = make_is(@1.first_line, $1, $3); }
      | LET VarDeclaration EQUALS Expr IN Expr                        { $$ = make_let(@1.first_line, $2, $4, $6); } 
      | STATIC VarDeclaration EQUALS Expr IN Expr                     { $$ = make_static(@1.first_line, $2, $4, $6); }
      | IF Expr THEN Expr ELSE Expr                                   { $$ = make_if(@1.first_line, $2, $4, $6); }                                                                                        
      | CASE Expr OF OPEN CaseList CLOSE                              { $$ = make_case_expr(@1.first_line, $2, $5); }                                                                                        
      | FOR VarDeclaration EQUALS Expr COMMA Expr COMMA Expr IN Expr  { $$ = make_for(@1.first_line, $2, $4, $6, $8, $10); }
      | FOREACH VarDeclaration FROM Expr IN Expr                      { $$ = make_foreach(@1.first_line, $2, $4, $6); } 
      | WHILE Expr IN Expr                                            { $$ = make_while(@1.first_line, $2, $4); }
      | ExpOp                                                         { $$ = $1; }

ExpOp : ExpOp AND ExpOp                                             { $$ = make_exp(@1.first_line, OP_ADD, $1, $3); }
      | ExpOp OR ExpOp                                              { $$ = make_exp(@1.first_line, OP_SUB, $1, $3); }
      | ExpOp LTE ExpOp                                             { $$ = make_exp(@1.first_line, OP_LTE, $1, $3); }
      | ExpOp GTE ExpOp                                             { $$ = make_exp(@1.first_line, OP_GTE, $1, $3); }
      | ExpOp LT ExpOp                                              { $$ = make_exp(@1.first_line, OP_LT, $1, $3); }
      | ExpOp GT ExpOp                                              { $$ = make_exp(@1.first_line, OP_GT, $1, $3); }
      | ExpOp EQ ExpOp                                              { $$ = make_exp(@1.first_line, OP_EQ, $1, $3); }
      | ExpOp PLUS ExpOp                                            { $$ = make_exp(@1.first_line, OP_ADD, $1, $3); }
      | ExpOp MINUS ExpOp                                           { $$ = make_exp(@1.first_line, OP_SUB, $1, $3); }
      | ExpOp TIMES ExpOp                                           { $$ = make_exp(@1.first_line, OP_MUL, $1, $3);  }
      | ExpOp DIVIDE ExpOp                                          { $$ = make_exp(@1.first_line, OP_DIV, $1, $3);  }
      | Access                                                      { $$ = $1; }

Access : Value AccessPathList                                       { $$ = make_access(@1.first_line, $1, $2); }
       | Value                                                      { $$ = $1 }

AccessPathList : AccessPath AccessPathList                          { $$ = result_access_path_list($1, $2);}
               | AccessPath                                         { $$ = result_access_path_list($1, NULL);}

AccessPath : DOT TAG                                                { $$ = make_record_access_path(@1.first_line, $2, 1); }           
           | ARROW TAG                                              { $$ = make_record_deref_access_path(@1.first_line, $2, 1); }
           | DOUBLE_ARROW TAG                                       { $$ = make_record_ref_access_path(@1.first_line, $2, 1); }
           | OPEN_S_BRACKET Expr CLOSE_S_BRACKET                    { $$ = make_array_access_path(@1.first_line, $2); }
           | ARROW OPEN_S_BRACKET Expr CLOSE_S_BRACKET              { $$ = make_array_deref_access_path(@1.first_line, $3); }
           | DOUBLE_ARROW OPEN_S_BRACKET Expr CLOSE_S_BRACKET       { $$ = make_array_ref_access_path(@1.first_line, $3); }

Value : NOT Value                                                  { $$ = make_unary_exp(@1.first_line, OP_NOT, $2); }
      | PLUS Value                                                 { $$ = make_unary_exp(@1.first_line, OP_PLUS, $2); }
      | MINUS Value                                                { $$ = make_unary_exp(@1.first_line, OP_MINUS, $2); }
      | TIMES Value                                                { $$ = make_unary_exp(@1.first_line, OP_DEREF, $2); }
      | AMPERSAND Value                                            { $$ = make_unary_exp(@1.first_line, OP_REF, $2); }
      | CARDINAL Value                                             { $$ = make_unary_exp(@1.first_line, OP_LEN, $2); }
     // | DOLLAR Value                                             { $$ = make_unary_exp(@1.first_line, OP_FREF, $2); }
      | BOX Value                                                  { $$ = make_unary_exp(@1.first_line, OP_BOX, $2); }
      | UNBOX Value                                                { $$ = make_unary_exp(@1.first_line, OP_UNBOX, $2); }
      | DOUBLE_EXPR                                                { $$ = $1; }
      | INTEGER_EXPR                                               { $$ = $1; }
      | STRING_EXPR                                                { $$ = $1; }
      | BOX WITH Expr OF OPEN TAG IN Expr CLOSE                    { $$ = make_box_of(@1.first_line, $3, $6, 1, $8); }
      | ARRAY WITH Expr OF OPEN TAG IN Expr CLOSE                  { $$ = make_mut_array_of(@1.first_line, $3, $6, 1, $8); }
      | OPEN_S_BRACKET INTEGER_EXPR OF TAG IN Expr CLOSE_S_BRACKET { $$ = make_array_of(@1.first_line, $2, $4, 1, $6); }
      | NEW ArrowType OPEN Arguments CLOSE                         { $$ = make_new(@1.first_line, $2, $4); }                                                                   
      | OPEN_BRACKET VarDeclarationList APPLY Expr CLOSE_BRACKET   { $$ = make_lambda(@1.first_line, $2, $4); }
      | OPEN_S_BRACKET Arguments CLOSE_S_BRACKET                   { $$ = make_array(@1.first_line, $2); }        
      | TAG OPEN_BRACKET MapsList CLOSE_BRACKET                    { $$ = make_record(@1.first_line, $1, 1, $3); }        
      | TAG DOUBLE_COLON TAG OPEN_BRACKET Expr CLOSE_BRACKET       { $$ = make_union(@1.first_line, $1, 1, $3, $5); }        
      | TAG DOUBLE_COLON TAG OPEN_BRACKET OPEN_BRACKET MapsList CLOSE_BRACKET CLOSE_BRACKET { $$ = make_record_union(@1.first_line, $1, 1, $3, $6); }        
      | TAG DOUBLE_COLON TAG                                       { $$ = make_union(@1.first_line, $1, 1, $3, NULL); }        
      | TAG_OR_EMPTY OPEN Arguments CLOSE                          { $$ = make_tuple(@1.first_line, $1, 1, $3); }
      | TAG                                                        { $$ = make_tag(@1.first_line, $1, 1); }
                                                                  

TAG_OR_EMPTY : TAG                                                { $$ = $1; } 
             |                                                    { $$ = NULL; }

//StaticDeclaration : STATIC VarDeclaration EQUALS Expr IN Value

Arguments : ArgList                  { $$ = $1; }
          |                          { $$ = result_arg_list(NULL, NULL);}

ArgList : Expr COMMA ArgList         { $$ = result_arg_list($1, $3);}
        | Expr                       { $$ = result_arg_list($1, NULL);}

Mapping : VarDeclaration EQUALS Expr {$$ = make_mapping(@1.first_line, $1, $3);}

MapsList : Mapping COMMA MapsList    { $$ = result_maps_list($1, $3);}
         | Mapping                   { $$ = result_maps_list($1, NULL);}

Case : TAG VarDeclaration IN Expr    {$$ = make_case(@1.first_line, $1, $2, $4);}
     | TAG IN Expr                   {$$ = make_case(@1.first_line, $1, $3);}
     | OTHERWISE IN Expr             {$$ = make_case(@1.first_line, NULL, $3);}

CaseList : Case PIPE CaseList    { $$ = result_maps_list($1, $3);}
         | Case                  { $$ = result_maps_list($1, NULL);}
       
DOUBLE_EXPR : DOUBLE_VALUE                                              { $$ = make_double(@1.first_line, $1); }
INTEGER_EXPR : INTEGER                                                  { $$ = make_long(@1.first_line, $1); }
STRING_EXPR : STRING                                                    { $$ = make_string(@1.first_line, $1); }

%%

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
