#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tagtuple.h"
#include "utils.h"

#define EMPTY_IF_NULL(X, CLONE) (X != NULL ? ( CLONE ? clone_string(X) : X ): "")

static tag_tuple *make(int line){
    tag_tuple * const tuple = (tag_tuple*) malloc(sizeof(tag_tuple));
    memset(tuple, 0, sizeof(tag_tuple));
    tuple->line_number = line;
    return tuple;
}

tag_tuple* make_definitions(int line, tag_tuple *arg_list) {
    //printf("make_definitions\n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_DEFINITIONS;
    tuple->value.definitions.arguments = arg_list;
    return tuple;
}

tag_tuple* make_datatype(int line, char *name, int is_name_owner, 
                        value_data_type_t *type, declaration_t *arguments, 
                        tag_tuple *body, tag_tuple *with) {
    //printf("make_definitions \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_DATATYPE;
    tuple->value.datatype.name = EMPTY_IF_NULL(name, !is_name_owner);
    tuple->value.datatype.type = type;
    tuple->value.datatype.ctor_arguments = arguments;
    tuple->value.datatype.ctor = body;
    tuple->value.datatype.with = with;
    return tuple;
}

tag_tuple* make_include(int line, tag_tuple *subject) {
    //printf("make_definitions \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_INCLUDE;
    tuple->value.include.subject = subject;
    return tuple;
}

tag_tuple* make_exp(int line, operation op, tag_tuple *left, tag_tuple *right) {
    //printf("make_exp \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_EXPR;
    tuple->value.expr.op = op;
    tuple->value.expr.left = left;
    tuple->value.expr.right = right;
    return tuple;
}

tag_tuple* make_unary_exp(int line, operation op, tag_tuple *subject) {
    //printf("make_unary_exp \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_UNARY_EXPR;
    tuple->value.unary_expr.op = op;
    tuple->value.unary_expr.subject = subject;
    return tuple;
}

tag_tuple* make_assign(int line, tag_tuple *l_value, tag_tuple *r_value) {
    //printf("make_assign \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_ASSIGN;
    tuple->value.assign.l_value = l_value;
    tuple->value.assign.r_value = r_value;
    return tuple;
}

tag_tuple* make_convert(int line, tag_tuple *subject, value_data_type_t *type) {
    //printf("make_convert \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_CONVERT;
    tuple->value.convert.subject = subject;
    tuple->value.convert.type = type;
    return tuple;
}

tag_tuple* make_is(int line, tag_tuple *subject, value_data_type_t *type) {
    //printf("make_is \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_IS;
    tuple->value.is.subject = subject;
    tuple->value.is.type = type;
    return tuple;
}

tag_tuple* make_tuple(int line, char *name, int is_name_owner, tag_tuple *arg_list) {
    //printf("make_tuple %s<--\n", name);
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_TUPLE;
    tuple->value.tuple.name = EMPTY_IF_NULL(name, !is_name_owner);
    tuple->value.tuple.arguments = arg_list;
    return tuple;
}

tag_tuple* make_let(int line, declaration_t *declaration, tag_tuple *init, tag_tuple *scope) {
    //printf("make_let \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_LET;
    tuple->value.let.declaration = declaration;
    tuple->value.let.init = init;
    tuple->value.let.scope = scope;
    return tuple;
}

tag_tuple* make_for(int line, declaration_t *declaration, tag_tuple *init, 
                    tag_tuple *condition, tag_tuple *post, tag_tuple *body) {
    //printf("make_for \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_FOR;
    tuple->value.for_loop.declaration = declaration;
    tuple->value.for_loop.init = init;
    tuple->value.for_loop.condition = condition;
    tuple->value.for_loop.post = post;
    tuple->value.for_loop.body = body;
    return tuple;
}

tag_tuple* make_while(int line, tag_tuple *condition, tag_tuple *body) {
    //printf("make_while \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_WHILE;
    tuple->value.while_loop.condition = condition;
    tuple->value.while_loop.body = body;
    return tuple;
}

tag_tuple* make_foreach(int line, declaration_t *declaration, tag_tuple *source, tag_tuple *body) {
    //printf("make_foreach \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_FOREACH;
    tuple->value.foreach.declaration = declaration;
    tuple->value.foreach.source = source;
    tuple->value.foreach.body = body;
    return tuple;
}

/*tag_tuple* make_block(int line, char *name, int is_name_owner, tag_tuple *arg_list) {
    printf("make_block \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_BLOCK;
    tuple->value.block.tuple = make_tuple(line, name, is_name_owner, arg_list);
    return tuple;
}*/

tag_tuple* make_access(int line, tag_tuple *source, access_path_t *path) {
    //printf("make_access \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_ACCESS;
    tuple->value.access.source = source;
    tuple->value.access.path = path;
    return tuple;
}

tag_tuple* make_array(int line, tag_tuple *arg_list) {
    //printf("make_array \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_ARRAY;
    tuple->value.array.arguments = arg_list;
    return tuple;
}

tag_tuple* make_tag(int line, char *name, int is_name_owner) {
    //printf("make_tag \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_TAG;
    tuple->value.tag.name = EMPTY_IF_NULL(name, !is_name_owner);
    return tuple;
}

tag_tuple* make_string(int line, char *value) {
    //printf("make_string \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_STRING;
    tuple->value.string.value = EMPTY_IF_NULL(value, 1);
    return tuple;
}

static tag_tuple *make_number(int line, number_type type) {
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_NUMBER;
    tuple->value.number.value.type = type;
    tuple->value.number.value.value.real = 0; 
    tuple->value.number.value.value.longint = 0;
    return tuple;
}

tag_tuple* make_double(int line, double value) {
    //printf("make_double \n");
    tag_tuple * const tuple = make_number(line, NUMBER_TYPE_DOUBLE);
    tuple->value.number.value.value.real = value; 
    return tuple;
}

tag_tuple* make_long(int line, int64_t value) {
    //printf("make_long %lld\n", value);
    tag_tuple * const tuple = make_number(line, NUMBER_TYPE_LONG);
    tuple->value.number.value.value.longint = value;
    return tuple;
}

tag_tuple* make_array_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init) {
    //printf("make_array_of \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_ARRAY_OF;
    tuple->value.array_of.size = size;
    tuple->value.array_of.counter_name = EMPTY_IF_NULL(counter_name, !is_name_owner);
    tuple->value.array_of.init = init;
    return tuple;
}

tag_tuple* make_mut_array_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init) {
    //printf("make_mut_array_of \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_MUT_ARRAY_OF;
    tuple->value.mut_array_of.size = size;
    tuple->value.mut_array_of.counter_name = EMPTY_IF_NULL(counter_name, !is_name_owner);
    tuple->value.mut_array_of.init = init;
    return tuple;
}

tag_tuple* make_box_of(int line, tag_tuple *size, char *counter_name, int is_name_owner, tag_tuple *init) {
    //printf("make_box_of \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_BOX_OF;
    tuple->value.box_of.size = size;
    tuple->value.box_of.counter_name = EMPTY_IF_NULL(counter_name, !is_name_owner);
    tuple->value.box_of.init = init;
   return tuple;
}

tag_tuple* make_function(int line, char *name, int is_name_owner, declaration_t *arguments, value_data_type_t *return_type, tag_tuple *body) {
    //printf("make_function\n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_FUNCTION;
    tuple->value.function.name = EMPTY_IF_NULL(name, !is_name_owner);
    tuple->value.function.arguments = arguments;
    tuple->value.function.return_type = return_type;
    tuple->value.function.body = body;
    return tuple;
}

tag_tuple* make_lambda(int line, declaration_t *arguments, tag_tuple *body) {
    //printf("make_lambda \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_LAMBDA;
    tuple->value.lambda.arguments = arguments;
    tuple->value.lambda.body = body;
    return tuple;
}

tag_tuple* make_new(int line, value_data_type_t *data_type, tag_tuple *arg_list) {
    //printf("make_new \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_NEW;
    tuple->value.new_datatype.data_type = data_type;
    tuple->value.new_datatype.arg_list = arg_list;
    return tuple;
}

tag_tuple* make_if(int line, tag_tuple *condition, tag_tuple *then_expr, tag_tuple *else_expr) {
    //printf("make_if \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_IF;
    tuple->value.if_cond.condition = condition;
    tuple->value.if_cond.then_expr = then_expr;
    tuple->value.if_cond.else_expr = else_expr;
    return tuple;
}

tag_tuple* make_record(int line, mapping_t *mappings) {
    //printf("make_record \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_RECORD;
    tuple->value.record.arguments = mappings;
    return tuple;
}

tag_tuple* make_typedef(int line, char *name, int is_name_owner, value_data_type_t *type) {
    //printf("make_typedef \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_TYPEDEF;
    tuple->value.typealias.name = EMPTY_IF_NULL(name, !is_name_owner);
    tuple->value.typealias.type = type;
    return tuple;
}

tag_tuple* make_static(int line, declaration_t *declaration, tag_tuple *init, tag_tuple *scope) {
    //printf("make_static \n");
    tag_tuple * const tuple = make(line);
    tuple->type = TAG_TYPE_STATIC;
    tuple->value.static_let.declaration = declaration;
    tuple->value.static_let.init = init;
    tuple->value.static_let.scope = scope;
    return tuple;
}

static access_path_t *make_access_path(int line){
    access_path_t * const path = (access_path_t*) malloc(sizeof(access_path_t));
    memset(path, 0, sizeof(access_path_t));
    path->line_number = line;
    return path;
}

static access_path_t  *make_indexed_access_path(int line, access_type type, tag_tuple *index) {
    access_path_t * const path = make_access_path(line);
    path->type = type;
    path->value.index = index;
    return path;
}

static access_path_t  *make_named_access_path(int line, access_type type, char *name, int is_name_owner) {
    access_path_t * const path = make_access_path(line);
    path->type = type;
    path->value.name = EMPTY_IF_NULL(name, !is_name_owner);
    return path;
}

access_path_t  *make_array_access_path(int line, tag_tuple *index) {
    //printf("make_array_access_path \n");
    access_path_t * const path = make_indexed_access_path(line, ACCESS_ARRAY, index);
    return path;
}

access_path_t  *make_array_deref_access_path(int line, tag_tuple *index) {
    //printf("make_array_deref_access_path \n");
    access_path_t * const path = make_indexed_access_path(line, ACCESS_DEREF_ARRAY, index);
    return path;
}

access_path_t  *make_array_ref_access_path(int line, tag_tuple *index) {
    //printf("make_array_ref_access_path \n");
    access_path_t * const path = make_indexed_access_path(line, ACCESS_REF_ARRAY, index);
    return path;
}

access_path_t  *make_record_access_path(int line, char *name, int is_name_owner) {
    //printf("make_record_access_path \n");
    access_path_t * const path = make_named_access_path(line, ACCESS_RECORD, name, is_name_owner);
    return path;
}

access_path_t  *make_record_deref_access_path(int line, char *name, int is_name_owner) {
    //printf("make_record_deref_access_path \n");
    access_path_t * const path = make_named_access_path(line, ACCESS_DEREF_RECORD, name, is_name_owner);
    return path;
}

access_path_t  *make_record_ref_access_path(int line, char *name, int is_name_owner) {
    //printf("make_record_ref_access_path \n");
    access_path_t * const path = make_named_access_path(line, ACCESS_REF_RECORD, name, is_name_owner);
    return path;
}

mapping_t* make_mapping(int line, declaration_t *variable, tag_tuple *value) {
    //printf("make_mapping \n");
    mapping_t * const mapping = (mapping_t*) malloc(sizeof(mapping_t));
    memset(mapping, 0, sizeof(mapping_t));
    mapping->line_number = line;
    mapping->variable = variable;
    mapping->value = value;
    return mapping;
}

declaration_t* make_declaration(int line, char *name, int is_name_owner, value_data_type_t *data_type) {
    //printf("make_declaration \n");
    declaration_t * const declaration = (declaration_t*) malloc(sizeof(declaration_t));
    memset(declaration, 0, sizeof(declaration_t));
    declaration->line_number = line;
    declaration->name = EMPTY_IF_NULL(name, !is_name_owner);
    declaration->type = data_type;
    return declaration;
}
static value_data_type_t *make_type(int line) {
    value_data_type_t * const type = (value_data_type_t*) malloc(sizeof(value_data_type_t));
    memset(type, 0, sizeof(value_data_type_t));
    type->line_number = line;
    return type;
}

value_data_type_t *make_named_type(int line, char *name, int is_name_owner) {
    //printf("make_named_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_NAMED;
    type->type.named.name = EMPTY_IF_NULL(name, !is_name_owner);
    return type;
}

value_data_type_t *make_chars_type(int line) {
    //printf("make_chars_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_CHARS;
    return type;
}

value_data_type_t *make_boolean_type(int line) {
    //printf("make_boolean_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_BOOLEAN;
    return type;
}

value_data_type_t *make_byte_type(int line) {
    //printf("make_byte_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_BYTE;
    return type;
}

value_data_type_t *make_int_type(int line) {
    //printf("make_int_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_INT;
    return type;
}

value_data_type_t *make_long_type(int line) {
    //printf("make_long_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_LONG;
    return type;
}

value_data_type_t *make_double_type(int line) {
    //printf("make_double_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_DOUBLE;
    return type;
}

value_data_type_t *make_dynamic_type(int line) {
    //printf("make_double_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_DYNAMIC;
    return type;
}

value_data_type_t *make_box_type(int line, value_data_type_t *data_type) {
    //printf("make_box_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_BOX;
    type->type.box.target = data_type;
    return type;
}

value_data_type_t *make_array_box_type(int line, value_data_type_t *data_type) {
    //printf("make_array_box_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_ARRAY_BOX;
    type->type.array_box.target = data_type;
    return type;
}

value_data_type_t *make_array_pointer_type(int line, value_data_type_t *data_type) {
    //printf("make_array_pointer_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_ARRAY_POINTER;
    type->type.array_pointer.target = data_type;
    return type;
}

value_data_type_t *make_record_type(int line, declaration_t *declarations) {
    //printf("make_record_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_RECORD;
    type->type.record.fields = declarations;
    return type;
}

value_data_type_t *make_array_type(int line, value_data_type_t *data_type, tag_tuple *size) {
    //printf("make_array_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_ARRAY;
    type->type.array.target = data_type;
    type->type.array.size = size;
    return type;
}

value_data_type_t *make_pointer_type(int line, value_data_type_t *data_type) {
    //printf("make_pointer_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_POINTER;
    type->type.pointer.target = data_type;
    return type;
}

value_data_type_t *make_arrow_type(int line, value_data_type_t *left, value_data_type_t *right) {
    //printf("make_arrow_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_ARROW;
    type->type.arrow.from = left;
    type->type.arrow.to = right;
    return type;
}

value_data_type_t *make_unit_type(int line) {
    //printf("make_unit_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_UNIT;
    return type;
}

value_data_type_t *make_null_type(int line) {
    //printf("make_null_type \n");
    value_data_type_t * const type = make_type(line);
    type->kind = DATA_KIND_NULL;
    return type;
}

const char* get_operator_symbol(operation op) {
     switch(op) {
        case OP_PLUS:
        case OP_ADD:
            return "+";
        case OP_MINUS:
        case OP_SUB:
            return "-";
        case OP_DEREF:
        case OP_MUL:
            return "*";
        case OP_DIV:
            return "/";
        case OP_AND:
            return "&&"; 
        case OP_OR:
            return "||";
        case OP_NOT:
            return "!";
        case OP_GT:
            return ">";
        case OP_GTE:
            return ">=";
        case OP_LT:
            return ">";
        case OP_LTE:
            return ">=";
        case OP_EQ:
            return "==";
        case OP_REF:
            return "&";
        case OP_FREF:
            return "$";
        case OP_BOX:
            return "box";
        case OP_UNBOX:
            return "unbox";
        case OP_LEN:
            return "#";
    }
    return " ";
}

void print_path(FILE *f, access_path_t *path) {
    if(path == NULL)
        return;
    switch(path->type) {
        case ACCESS_ARRAY:
            fprintf(f, "[");
            print_tree(f, path->value.index);
            fprintf(f, "]");
            break;
        case ACCESS_RECORD:
            fprintf(f, ".%s", path->value.name);
            break;
    }
}

static void print_path_list(FILE *f, access_path_t *paths) {
    access_path_t *arg;
    for (arg = paths; arg != NULL; arg = arg->next) 
        print_path(f, arg);
}

void print_declaration(FILE *f, declaration_t *declaration) {
    if(declaration == NULL)
        return;
    fprintf(f, "%s", declaration->name);
    if (declaration->type == NULL)
        return;
    fprintf(f, " : "); 
    print_type(f, declaration->type);
}

static void print_decl_list(FILE *f, declaration_t *declarations, const char *open, const char *close) {
    fprintf(f, "%s", open);
    declaration_t *arg;
    for (arg = declarations; arg != NULL; arg = arg->next) { 
        print_declaration(f, arg);
        fprintf(f, ", ");
    }
     fprintf(f, "%s", close);
}

static void print_mapping(FILE *f, mapping_t *mapping) {
    if(mapping == NULL)
        return;
     print_declaration(f, mapping->variable);
     fprintf(f, " = ");
     print_tree(f, mapping->value);
}

static void print_mapping_list(FILE *f, mapping_t *mapping) {
    mapping_t *arg;
    for (arg = mapping; arg != NULL; arg = arg->next) {
        print_mapping(f, arg);
        fprintf(f, ", ");
    }
}

static void print_arg_list(FILE *f, tag_tuple *arguments, const char *open, const char *close, const char *separator) {
    fprintf(f, "%s", open);
    tag_tuple *arg;
    for (arg = arguments; arg != NULL; arg = arg->next) { 
        print_tree(f, arg);
        fprintf(f, "%s", separator);
    }
     fprintf(f, "%s", close);
}

void print_type(FILE *f, value_data_type_t *data_type);

static void print_type_list(FILE *f, value_data_type_t *arguments, const char *open, const char *close, const char *separator) {
    fprintf(f, "%s", open);
    value_data_type_t *arg;
    for (arg = arguments; arg != NULL; arg = arg->next) { 
        print_type(f, arg);
        fprintf(f, "%s", separator);
    }
     fprintf(f, "%s", close);
}

void print_type(FILE *f, value_data_type_t *data_type) {
    if (data_type == NULL)
        return;
    switch (data_type->kind) {
        case DATA_KIND_ARROW:
            fprintf(f, "(");
            if (data_type->type.arrow.from != NULL && data_type->type.arrow.from->next == NULL)
                print_type(f, data_type->type.arrow.from);
            else            
                print_type_list(f, data_type->type.arrow.from, "(", ")", ", ");
            fprintf(f, " -> ");
            print_type(f, data_type->type.arrow.to);
            fprintf(f, ")");
            break;
        case DATA_KIND_ARRAY:
            fprintf(f, "(");
            print_type(f, data_type->type.array.target);
            fprintf(f, "[ ");
            print_tree(f, data_type->type.array.size);
            fprintf(f, "])");
            break;
        case DATA_KIND_RECORD:
            fprintf(f, "(");
            print_decl_list(f, data_type->type.record.fields, "(", ")");
            fprintf(f, ")");
            break;
        case DATA_KIND_POINTER:
            fprintf(f, "( *");
            print_type(f, data_type->type.pointer.target);
            fprintf(f, ")");
            break;
        case DATA_KIND_ARRAY_POINTER:
            fprintf(f, "( *");
            print_type(f, data_type->type.array_pointer.target);
            fprintf(f, "[]])");
            break;
        case DATA_KIND_BOX:
            fprintf(f, "( box ");
            print_type(f, data_type->type.array_pointer.target);
            fprintf(f, ")");
            break;
        case DATA_KIND_ARRAY_BOX:
            fprintf(f, "( box ");
            print_type(f, data_type->type.array_pointer.target);
            fprintf(f, "[])");
            break;
        case DATA_KIND_NAMED:
            fprintf(f, "%s", data_type->type.named.name);
            break;
        case DATA_KIND_BYTE:
            fprintf(f, "byte");
            break;
        case DATA_KIND_INT:
            fprintf(f, "int");
            break;
        case DATA_KIND_LONG:
            fprintf(f, "long");
            break;
        case DATA_KIND_DOUBLE:
            fprintf(f, "double");
            break;
        case DATA_KIND_CHARS:
            fprintf(f, "chars");
            break;
        case DATA_KIND_DYNAMIC:
            fprintf(f, "dynamic");
            break;
        case DATA_KIND_UNIT:
            fprintf(f, "unit");
            break;
        case DATA_KIND_NULL:
            fprintf(f, "null");
            break;
        case DATA_KIND_BOOLEAN:
            fprintf(f, "boolean");
            break;
       }
}

void print_tree(FILE *f, tag_tuple* root) {
    if (root == NULL)
        return;
  //  fprintf(f, "%d : ", root->line_number);
    switch (root->type) {
           case TAG_TYPE_DEFINITIONS: 
            {
                print_arg_list(f, root->value.definitions.arguments, "\n", "\n", ";\n ");
            }
            break;
        case TAG_TYPE_FUNCTION:
            fprintf(f, "(function %s ", root->value.function.name);
            print_decl_list(f, root->value.function.arguments, " (", ") ");
            fprintf(f, " : ");
            print_type(f, root->value.function.return_type);
            fprintf(f, "\n");
            print_tree(f, root->value.function.body);
            fprintf(f, ")");
            break;
        case TAG_TYPE_LAMBDA:
            fprintf(f, "( ");
            print_decl_list(f, root->value.lambda.arguments, " ", " => ");
            print_tree(f, root->value.lambda.body);
            fprintf(f, " )");
            break;
        case TAG_TYPE_TAG:
            fprintf(f, "%s", root->value.tag.name);
            break;
        case TAG_TYPE_STRING:
            fprintf(f, "%s", root->value.string.value);
            break;
        case TAG_TYPE_NUMBER:
            if (root->value.number.value.type == NUMBER_TYPE_DOUBLE)
                fprintf(f, "%lf", root->value.number.value.value.real);
            else
                fprintf(f, "%lld", root->value.number.value.value.longint);
            break;
        case TAG_TYPE_EXPR:
            fprintf(f, "(");
            print_tree(f, root->value.expr.left);
            fprintf(f, " %s ", get_operator_symbol(root->value.expr.op));
            print_tree(f, root->value.expr.right);
            fprintf(f, ")");
            break;
        case TAG_TYPE_UNARY_EXPR:
            fprintf(f, "%s (", get_operator_symbol(root->value.unary_expr.op));
            print_tree(f, root->value.unary_expr.subject);
            fprintf(f, ")");
            break;
        case TAG_TYPE_ASSIGN:
            fprintf(f, "(");
            print_tree(f, root->value.assign.l_value);
            fprintf(f, " := ");
            print_tree(f, root->value.assign.r_value);
            fprintf(f, ")");
            break;
        case TAG_TYPE_TUPLE: 
            fprintf(f, "%s", root->value.tuple.name);
             print_arg_list(f, root->value.tuple.arguments, " (", ")", ", ");
            break;
        case TAG_TYPE_ARRAY: 
            print_arg_list(f, root->value.array.arguments, "[", "]", ", ");
            break;
        case TAG_TYPE_DATATYPE:
            fprintf(f, "datatype %s ", root->value.datatype.name);
            print_type(f, root->value.datatype.type);
            print_decl_list(f, root->value.datatype.ctor_arguments, " (", ")\n ");
            print_tree(f, root->value.datatype.ctor);
            print_arg_list(f, root->value.datatype.with, " with (\n", "\n)", ";\n ");
            break;
        case TAG_TYPE_INCLUDE:
            fprintf(f, "include ");
            print_tree(f, root->value.include.subject);
            break;
        case TAG_TYPE_CONVERT:
            print_tree(f, root->value.convert.subject);
            fprintf(f, " : ");
            print_type(f, root->value.convert.type);            
            break;
        case TAG_TYPE_IS:
            print_tree(f, root->value.is.subject);
            fprintf(f, " is ");
            print_type(f, root->value.is.type);            
            break;
        case TAG_TYPE_LET:
            fprintf(f, "let ");
            print_declaration(f, root->value.let.declaration);
            fprintf(f, " = ");
            print_tree(f, root->value.let.init);
            fprintf(f, " in (\n");
            print_tree(f, root->value.let.scope);
            fprintf(f, "\n)");
            break;
        case TAG_TYPE_STATIC:
            fprintf(f, "static ");
            print_declaration(f, root->value.static_let.declaration);
            fprintf(f, " = ");
            print_tree(f, root->value.static_let.init);
            fprintf(f, " in (\n");
            print_tree(f, root->value.static_let.scope);
            fprintf(f, "\n)");
            break;
        case TAG_TYPE_FOR:
            fprintf(f, "for ");
            print_declaration(f, root->value.for_loop.declaration);
            fprintf(f, " = ");
            print_tree(f, root->value.for_loop.init);
            fprintf(f, ", ");
            print_tree(f, root->value.for_loop.condition);
            fprintf(f, ", ");
            print_tree(f, root->value.for_loop.post);
            fprintf(f, " in (\n");
            print_tree(f, root->value.for_loop.body);
            fprintf(f, "\n)");
            break;
        case TAG_TYPE_WHILE:
            fprintf(f, "while ");
            print_tree(f, root->value.while_loop.condition);
            fprintf(f, " in (\n");
            print_tree(f, root->value.while_loop.body);
            fprintf(f, "\n)");
            break;
        case TAG_TYPE_FOREACH:
            fprintf(f, "foreach ");
            print_declaration(f, root->value.foreach.declaration);
            fprintf(f, " from ");
            print_tree(f, root->value.foreach.source);
            fprintf(f, " in (\n");
            print_tree(f, root->value.foreach.body);
            fprintf(f, "\n)");
            break;
        case TAG_TYPE_ACCESS:
            fprintf(f, "(");
            print_tree(f, root->value.access.source);
            fprintf(f, ")");
            print_path_list(f, root->value.access.path);
            break;
        case TAG_TYPE_ARRAY_OF:
            fprintf(f, "[ ");
            print_tree(f, root->value.array_of.size);
            fprintf(f, "of %s in ", root->value.array_of.counter_name);
            print_tree(f, root->value.array_of.init);
            fprintf(f, " ]");
            break;
        case TAG_TYPE_MUT_ARRAY_OF:
            fprintf(f, "array ");
            print_tree(f, root->value.mut_array_of.size);
            fprintf(f, "of %s in ", root->value.mut_array_of.counter_name);
            print_tree(f, root->value.mut_array_of.init);
            fprintf(f, " ");
            break;
        case TAG_TYPE_BOX_OF:
            fprintf(f, "box ");
            print_tree(f, root->value.box_of.size);
            fprintf(f, "of %s in ", root->value.box_of.counter_name);
            print_tree(f, root->value.box_of.init);
            fprintf(f, " ");
            break;
        case TAG_TYPE_NEW:
            fprintf(f, "new ");
            print_type(f, root->value.new_datatype.data_type);
            print_arg_list(f, root->value.new_datatype.arg_list, "(", ")", ",");
            break;
        case TAG_TYPE_IF:
            fprintf(f, "if ");
            print_tree(f, root->value.if_cond.condition);
            fprintf(f, " then ");
            print_tree(f, root->value.if_cond.then_expr );
            fprintf(f, " else ");
            print_tree(f, root->value.if_cond.else_expr);
            break;
        case TAG_TYPE_RECORD:
            fprintf(f, "{ ");
            print_mapping_list(f, root->value.record.arguments);
            fprintf(f, " }");
            break;
        case TAG_TYPE_TYPEDEF:
            fprintf(f, "typedef %s ", root->value.typealias.name);
            print_type(f, root->value.typealias.type);
            break;
    }

    if(root->data_type != NULL) {
        fprintf(f, " [");
        print_type(f, root->data_type);
        fprintf(f, "]");
    }
}

void release_tagtuple(tag_tuple* root) {
    if (root == NULL)
        return;
    switch (root->type) {
        case TAG_TYPE_DEFINITIONS:
            {
                tag_tuple *arg, *next;
                for (arg = root->value.definitions.arguments; arg != NULL; arg = next) {
                    next = arg->next;
                    release_tagtuple(arg);
                }
            }
            break;
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
        case TAG_TYPE_UNARY_EXPR:
            release_tagtuple(root->value.unary_expr.subject);
            break;  
        case TAG_TYPE_ASSIGN:
            release_tagtuple(root->value.assign.l_value);
            release_tagtuple(root->value.assign.r_value);
            break;
        case TAG_TYPE_TUPLE:
            {
                //printf("HERE");
                free(root->value.tuple.name);
                tag_tuple *arg, *next;
                /*for (arg = root->value.tuple.arguments; arg != NULL; arg = next) {
                    next = arg->next;
                    release_tagtuple(arg);
                }*/
            }
            break;
        case TAG_TYPE_ARRAY:
            {
                tag_tuple *arg, *next;
                for (arg = root->value.array.arguments; arg != NULL; arg = next) {
                    next = arg->next;
                    release_tagtuple(arg);
                }
            }
            break;
    }
    free(root);
}

int arg_length(const tag_tuple *root) {
    int i;
    const tag_tuple *arg;
    for (arg = root, i = 0; arg != NULL; arg = arg->next, i++) 
        ;
    return i;
}

int get_children(const tag_tuple *root, tag_tuple **children, int size) {
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
