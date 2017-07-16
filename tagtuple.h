#ifndef TAGTUPLE_H
#define TAGTUPLE_H

#include <stdint.h>

#define NUMBER_SCALE_MULTIPLIER 100000000

typedef enum {
    TAG_TYPE_TAG,
    TAG_TYPE_STRING,
    TAG_TYPE_NUMBER,
    TAG_TYPE_TUPLE,
    TAG_TYPE_BLOCK,
    TAG_TYPE_EXPR
} tag_type;

#define IS_NORMAL_FORM(X) ( (X) != TAG_TYPE_EXPR  && (X) != TAG_TYPE_TUPLE )

typedef struct  {
    int64_t value;
    uint8_t scale;
} number;

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
} operation;

typedef struct tag_tuple {
    tag_type type;
    uint32_t line_number;
    struct tag_tuple *next; 
    
    union {
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

        struct {
            struct tag_tuple *tuple;
        } block;

        struct {
            struct tag_tuple *left, *right;
            operation op;
        } expr;

        struct {
            number value;
        }  number;

    } value;
} tag_tuple;

tag_tuple* make_exp(int line, operation op, tag_tuple *left, tag_tuple *right);
tag_tuple* make_tuple(int line, char *name, int is_name_owner, tag_tuple *arg_list);
tag_tuple* make_block(int line, char *name, int is_name_owner, tag_tuple *arg_list);
tag_tuple* make_tag(int line, char *name, int is_name_owner);
tag_tuple* make_string(int line, char *value);
tag_tuple* make_number(int line, double value);
void print_tree(tag_tuple* root);
char get_operator_symbol(operation op);
void release_tagtuple(tag_tuple* root);
int get_children(tag_tuple* root, tag_tuple **children, int size);
int arg_len(tag_tuple *root);

#endif /* TAGTUPLE_H */