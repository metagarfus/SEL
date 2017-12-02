#ifndef TAGTUPLE_H
#define TAGTUPLE_H

#include <stdint.h>
#include <stdio.h>
#include "datastructs/hashtable.h"

//struct tag_tuple;

typedef enum {
    DATA_KIND_ARROW,
    DATA_KIND_ARRAY,
    DATA_KIND_RECORD,
    DATA_KIND_UNION,
    DATA_KIND_POINTER,
    DATA_KIND_ARRAY_POINTER,
    DATA_KIND_BOOLEAN,
    DATA_KIND_BYTE,
    DATA_KIND_INT,
    DATA_KIND_LONG,
    DATA_KIND_DOUBLE,
    DATA_KIND_CHARS,
    DATA_KIND_DYNAMIC,
    DATA_KIND_BOX,
    DATA_KIND_ARRAY_BOX,
    DATA_KIND_NAMED,
    DATA_KIND_UNIT,
    DATA_KIND_NULL,
} data_kind;

typedef struct value_data_type {
    data_kind kind;
    uint32_t line_number;
    struct value_data_type *next, *shadows;
    int is_forward_declaration;
    union {
        struct {
            struct value_data_type *from;
            struct value_data_type *to;
        } arrow;
        
        struct {
            struct value_data_type *target;
            struct tag_tuple *size;
        } array;
        
        struct {
            struct declaration *fields;
        } record;
        
        struct {
            struct declaration *options;
        } union;

        struct {
            struct value_data_type *target;
        } pointer;

        struct {
            struct value_data_type *target;
        } array_pointer;

        struct {
            struct value_data_type *target;
        } box;

        struct {
            struct value_data_type *target;
        } array_box;

        struct {
            const char *name;
        } named;
    } type;
} value_data_type_t;

typedef enum {
    NUMBER_TYPE_LONG,
    NUMBER_TYPE_DOUBLE,
} number_type;

typedef struct  {
    number_type type;
    union {
        int64_t longint;
        double real;
    } value;
} number;

typedef enum {
    OP_AND,
    OP_OR,
    OP_GT,
    OP_GTE,
    OP_LT,
    OP_LTE,
    OP_EQ,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_PLUS,
    OP_MINUS,
    OP_REF,
    OP_DEREF,
    OP_FREF,
    OP_NOT,
    OP_LEN,
    OP_BOX,
    OP_UNBOX,
    //OP_DESTROY
} operation;

typedef struct declaration {
    uint32_t line_number;
    struct declaration *next;
    char *name;
    value_data_type_t *type;
} declaration_t;

typedef struct free_variables {
    declaration_t *variables;
} free_variables_t;

typedef struct mapping {
    uint32_t line_number;
    struct mapping *next;
    declaration_t *variable;
    struct tag_tuple *value;
} mapping_t;

typedef struct case_option {
    uint32_t line_number;
    struct case_option *next;
    char *union_tag;
    declaration_t *variable;
    struct tag_tuple *value;
} case_option_t;

typedef enum {
    ACCESS_ARRAY,
    ACCESS_DEREF_ARRAY,    
    ACCESS_REF_ARRAY,
    ACCESS_RECORD,
    ACCESS_DEREF_RECORD,    
    ACCESS_REF_RECORD
} access_type;

typedef struct access_path {
    access_type type;
    uint32_t line_number;
    struct access_path *next;
    union {
        char *name; 
        struct tag_tuple *index;
    } value;
} access_path_t;

typedef enum {
    TAG_TYPE_DEFINITIONS,
    TAG_TYPE_FUNCTION,
    TAG_TYPE_LAMBDA,
    TAG_TYPE_DATATYPE,
    TAG_TYPE_INCLUDE,
    TAG_TYPE_TAG,
    TAG_TYPE_STRING,
    TAG_TYPE_NUMBER,
    TAG_TYPE_TUPLE,
//    TAG_TYPE_BLOCK,
    TAG_TYPE_EXPR,
    TAG_TYPE_UNARY_EXPR,
    TAG_TYPE_ARRAY,
    TAG_TYPE_ASSIGN,
    TAG_TYPE_CONVERT,
    TAG_TYPE_IS,
    TAG_TYPE_LET,
    TAG_TYPE_FOR,
    TAG_TYPE_WHILE,
    TAG_TYPE_FOREACH,
    TAG_TYPE_ACCESS,
    TAG_TYPE_ARRAY_OF,
    TAG_TYPE_MUT_ARRAY_OF,
    TAG_TYPE_BOX_OF,
    TAG_TYPE_NEW,
    TAG_TYPE_RECORD,
    TAG_TYPE_IF,
    TAG_TYPE_STATIC,
    TAG_TYPE_TYPEDEF,
    TAG_TYPE_UNION,
    TAG_TYPE_UNION_RECORD,
    TAG_TYPE_CASE,
} tag_type;

typedef struct tag_tuple {
    tag_type type;
    uint32_t line_number;
    struct tag_tuple *next; 
    value_data_type_t *data_type;

    union {
        struct {
            struct tag_tuple *arguments;  
        } definitions;

        struct {
            hashtable *local_types;
            char *name;
            value_data_type_t *return_type;
            declaration_t *arguments;  
            struct tag_tuple *body;
        } function;

        struct {
            hashtable *local_types;
            free_variables_t free_locals;
            declaration_t *arguments;  
            struct tag_tuple *body;
        } lambda;

         struct {
            char *name; 
            value_data_type_t *type;
        } typealias;

         struct {
            declaration_t *declaration;
            struct tag_tuple *init;
            struct tag_tuple *scope;
        } static_let;

        struct {
            char *name; 
            value_data_type_t *type;
            declaration_t *ctor_arguments;
            struct tag_tuple *ctor;
            struct tag_tuple *with;  
        } datatype;

        struct {
            struct tag_tuple *subject;
        } include;

        struct {
            char *name;
        } tag;

        struct {
            char *value;
        } string;

        struct {
            char *name;
            struct tag_tuple *arguments;  
        } tuple;

        /*struct {
            struct tag_tuple *tuple;
        } block;*/
    
        struct {
            struct tag_tuple *subject;
            value_data_type_t *type;
        } convert;
    
        struct {
            struct tag_tuple *subject;
            value_data_type_t *type;
        } is;

        struct {
            struct tag_tuple *left, *right;
            operation op;
        } expr;
        
        struct {
            struct tag_tuple *source;
            access_path_t *path;
        } access;

        struct {
            struct tag_tuple *subject;
            operation op;
        } unary_expr;

        struct {
            struct tag_tuple *arguments;  
        } array;

        struct {
            struct tag_tuple *size;
            char *counter_name; 
            struct tag_tuple *init;
        } array_of;

        struct {
            struct tag_tuple *size;
            char *counter_name; 
            struct tag_tuple *init;
        } mut_array_of;

        struct {
            struct tag_tuple *size;
            char *counter_name; 
            struct tag_tuple *init;
        } box_of;

        struct {
            value_data_type_t *data_type;
            struct tag_tuple *arg_list;
        } new_datatype;

        struct {
            mapping_t *arguments;  
        } record;

        struct {
            mapping_t *arguments;  
        } record;

        struct {
            struct tag_tuple *l_value, *r_value;
        } assign;

        struct {
           struct tag_tuple *l_value, *index;
        } get;

        struct {
            declaration_t *declaration;
            struct tag_tuple *init, *scope;
        } let;

        struct {
            declaration_t *declaration;
            struct tag_tuple *init, *condition, *post, *body;
        } for_loop;

        struct {
            struct tag_tuple *condition, *body;
        } while_loop;

        struct {
            declaration_t *declaration;
            struct tag_tuple *source, *body;
        } foreach;

        struct {
           struct tag_tuple *condition;
           struct tag_tuple *then_expr;
           struct tag_tuple *else_expr;
        } if_cond;

        struct {
            number value;
        }  number;

    } value;
} tag_tuple;

mapping_t* make_mapping(int line, declaration_t *variable, tag_tuple *value);
declaration_t* make_declaration(int line, char *name, int is_name_owner, value_data_type_t *data_type);
value_data_type_t *make_named_type(int line, char *name, int is_name_owner);
value_data_type_t *make_chars_type(int line);
value_data_type_t *make_boolean_type(int line);
value_data_type_t *make_byte_type(int line);
value_data_type_t *make_int_type(int line);
value_data_type_t *make_long_type(int line);
value_data_type_t *make_double_type(int line);
value_data_type_t *make_dynamic_type(int line);
value_data_type_t *make_unit_type(int line);
value_data_type_t *make_null_type(int line);
value_data_type_t *make_box_type(int line, value_data_type_t *data_type);
value_data_type_t *make_array_box_type(int line, value_data_type_t *data_type);
value_data_type_t *make_array_pointer_type(int line, value_data_type_t *data_type);
value_data_type_t *make_record_type(int line, declaration_t *declarations);
value_data_type_t *make_array_type(int line, value_data_type_t *data_type, tag_tuple *size);
value_data_type_t *make_pointer_type(int line, value_data_type_t *data_type);
value_data_type_t *make_arrow_type(int line, value_data_type_t *left, value_data_type_t *right);
access_path_t  *make_array_access_path(int line, tag_tuple *index);
access_path_t  *make_array_deref_access_path(int line, tag_tuple *index);
access_path_t  *make_array_ref_access_path(int line, tag_tuple *index);
access_path_t  *make_record_access_path(int line, char *name, int is_name_owner);
access_path_t  *make_record_deref_access_path(int line, char *name, int is_name_owner);
access_path_t  *make_record_ref_access_path(int line, char *name, int is_name_owner);
tag_tuple* make_definitions(int line, tag_tuple *arg_list);
tag_tuple* make_function(int line, char *name, int is_name_owner, declaration_t *arguments, value_data_type_t *return_type, tag_tuple *body);
tag_tuple* make_datatype(int line, char *name, int is_name_owner, value_data_type_t *type, declaration_t *arguments, tag_tuple *body, tag_tuple *with);
tag_tuple* make_typedef(int line, char *name, int is_name_owner, value_data_type_t *type);
tag_tuple* make_include(int line, tag_tuple *subject);
tag_tuple* make_exp(int line, operation op, tag_tuple *left, tag_tuple *right);
tag_tuple* make_convert(int line, tag_tuple *subject, value_data_type_t *data_type);
tag_tuple* make_is(int line, tag_tuple *subject, value_data_type_t *data_type);
tag_tuple* make_unary_exp(int line, operation op, tag_tuple *subject);
tag_tuple* make_assign(int line, tag_tuple *l_value, tag_tuple *r_value);
tag_tuple* make_access(int line, tag_tuple *source, access_path_t *access_path);
tag_tuple* make_tuple(int line, char *name, int is_name_owner, tag_tuple *arg_list);
tag_tuple* make_lambda(int line, declaration_t *arguments, tag_tuple *body);
tag_tuple* make_while(int line, tag_tuple *condition, tag_tuple *body);
tag_tuple* make_if(int line, tag_tuple *condition, tag_tuple *then_expr, tag_tuple *else_expr);
tag_tuple* make_foreach(int line, declaration_t *declaration, tag_tuple *source, tag_tuple *body);
tag_tuple* make_for(int line, declaration_t *declaration, tag_tuple *init, tag_tuple *condition, tag_tuple *post, tag_tuple *body);
tag_tuple* make_let(int line, declaration_t *declaration, tag_tuple *init, tag_tuple *scope);
tag_tuple* make_static(int line, declaration_t *declaration, tag_tuple *init, tag_tuple *scope);
tag_tuple* make_new(int line, value_data_type_t *data_type, tag_tuple *arg_list);
tag_tuple* make_box_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init);
tag_tuple* make_mut_array_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init);
tag_tuple* make_array_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init);
//tag_tuple* make_block(int line, char *name, int is_name_owner, tag_tuple *arg_list);
tag_tuple* make_array(int line, tag_tuple *arg_list);
tag_tuple* make_record(int line, mapping_t *mappings);
tag_tuple* make_tag(int line, char *name, int is_name_owner);
tag_tuple* make_string(int line, char *value);
tag_tuple* make_long(int line, int64_t value);
tag_tuple* make_double(int line, double value);

void print_type(FILE *f, value_data_type_t *data_type);
void print_tree(FILE *f, tag_tuple* root);
const char *get_operator_symbol(operation op);
void release_tagtuple(tag_tuple* root);
int get_children(const tag_tuple* root, tag_tuple **children, int size);
int arg_length(const tag_tuple *root);

#endif /* TAGTUPLE_H */