#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tagtuple.h"
#include "utils.h"

#define EMPTY_IF_NULL(X, CLONE) (X != NULL ? ( CLONE ? clone_string(X) : X ): "")

static tag_tuple *make(int line){
    tag_tuple * const tuple = (tag_tuple*) malloc(sizeof(tag_tuple));
    memset(tuple, 0, sizeof(tag_tuple));
    tuple->line_number = line + 1;
    return tuple;
}

tag_tuple* make_exp(int line, operation op, tag_tuple *left, tag_tuple *right) {
    printf("make_exp \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_EXPR;
    tuple->value.expr.op = op;
    tuple->value.expr.left = left;
    tuple->value.expr.right = right;
    return tuple;
}

tag_tuple* make_tuple(int line, char *name, int is_name_owner, tag_tuple *arg_list) {
    printf("make_tuple %s<--\n", name);
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_TUPLE;
    tuple->value.tuple.name = EMPTY_IF_NULL(name, !is_name_owner);
    tuple->value.tuple.arguments = arg_list;
    return tuple;
}

tag_tuple* make_block(int line, char *name, int is_name_owner, tag_tuple *arg_list) {
    printf("make_block \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_BLOCK;
    tuple->value.block.tuple = make_tuple(line, name, is_name_owner, arg_list);
    return tuple;
}

tag_tuple* make_tag(int line, char *name, int is_name_owner) {
    printf("make_tag \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_TAG;
    tuple->value.tag.name = EMPTY_IF_NULL(name, !is_name_owner);
    return tuple;
}

tag_tuple* make_string(int line, char *value) {
    printf("make_string \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_STRING;
    tuple->value.string.value = EMPTY_IF_NULL(value, 1);
    return tuple;
}

tag_tuple* make_number(int line, double value) {
    printf("make_number \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_NUMBER;
    value = value * NUMBER_SCALE_MULTIPLIER;
    tuple->value.number.value.value = (uint64_t) (value + ((value > 0) - (value < 0)) * 0.5);
    tuple->value.number.value.scale = -1;
    return tuple;
}

char get_operator_symbol(operation op) {
     switch(op) {
        case OP_ADD:
            return '+';
        case OP_SUB:
            return '-';
        case OP_MUL:
            return '*';
        case OP_DIV:
            return '/';       
    }
    return ' ';
}

void print_tree(tag_tuple* root) {
    if (root == NULL)
        return;
  //  printf("%d : ", root->line_number);
    switch (root->type) {
        case TAG_TYPE_TAG:
            printf("%s", root->value.tag.name);
            break;
        case TAG_TYPE_STRING:
            printf("%s", root->value.string.value);
            break;
        case TAG_TYPE_NUMBER:
            printf("%lld", root->value.number.value.value);
            break;
        case TAG_TYPE_EXPR:
            printf("(");
            print_tree(root->value.expr.left);
            printf(" %c ", get_operator_symbol(root->value.expr.op));
            print_tree(root->value.expr.right);
            printf(")");
            break;
        case TAG_TYPE_TUPLE:
            printf("%s", root->value.tuple.name);
            printf(" (");
            tag_tuple *arg;
            for (arg = root->value.tuple.arguments; arg != NULL; arg = arg->next) { 
                print_tree(arg);
                printf(", ");
            }
            printf(")");
            break;

        case TAG_TYPE_BLOCK:
            printf("block: ");
            print_tree(root->value.block.tuple);
            break;
    }
}

void release_tagtuple(tag_tuple* root) {
    if (root == NULL)
        return;
    switch (root->type) {
        case TAG_TYPE_TAG:
            free(root->value.tag.name);
            break;
        case TAG_TYPE_STRING:
            free(root->value.string.value);
            break;
        case TAG_TYPE_NUMBER:
            break;
        case TAG_TYPE_EXPR:
            release_tagtuple(root->value.expr.left);
            release_tagtuple(root->value.expr.right);
            break;
        case TAG_TYPE_TUPLE:
            free(root->value.tuple.name);
            tag_tuple *arg, *next;
            for (arg = root->value.tuple.arguments; arg != NULL; arg = next) {
                next = arg->next;
                release_tagtuple(arg);
            }
            break;
        case TAG_TYPE_BLOCK:
            release_tagtuple(root->value.block.tuple);
            break;
    }
    free(root);
}

int arg_len(tag_tuple *root) {
    if (root->type != TAG_TYPE_TUPLE)
        return 0;
    tag_tuple *arg;
    int i;
    for (arg = root->value.tuple.arguments, i = 0; arg != NULL; arg = arg->next, i++) 
        ;
    return i;
}

int get_children(tag_tuple *root, tag_tuple **children, int size) {
     int i = 0;
     if (root->type == TAG_TYPE_EXPR) {
        if (size > 0)
            children[i++] = root->value.expr.left; 
        if (size > 1)
            children[i++] = root->value.expr.right;
    } else if (root->type == TAG_TYPE_TUPLE) {
        tag_tuple *arg;
        for (arg = root->value.tuple.arguments, i = 0; arg != NULL && i < size; arg = arg->next, i++) 
            children[i] = arg;
    }
    return i;
}