#include <stdlib.h>
#include <string.h>
#include "type_checker.h"
#include "utils.h"
#include "errors.h"

hashtable *data_type_table = NULL;
hashtable *typedef_table = NULL;
hashtable *function_table = NULL;

#define TYPE_ERROR_PREFIX "Type Error: "

#define TYPE_ERROR(EXIT, LINE, MSG, ...) {\
    PRINTF_ERROR(TYPE_ERROR_PREFIX MSG "\n", LINE, __VA_ARGS__);\
    if(EXIT)\
        exit(1);\
    }
#define TYPE_MISMATCH_ERROR(EXIT, LINE, MSG, DECL_MSG, DECL_TYPE, ACTUAL_MSG, ACTUAL_TYPE, ...) {\
        TYPE_ERROR(0, LINE, MSG, __VA_ARGS__);\
        PRINTF_ERROR(DECL_MSG, LINE);\
        fprintf(stderr, ANSI_COLOR_GREEN);\
        print_type(stderr, DECL_TYPE);\
        fprintf(stderr, "\n");\
        PRINTF_ERROR(ACTUAL_MSG, LINE);\
        fprintf(stderr, ANSI_COLOR_RED);\
        print_type(stderr, ACTUAL_TYPE );\
        fprintf(stderr, "\n" ANSI_COLOR_RESET);\
        if(EXIT)\
            exit(1);\
}

#define MAX_FRAME_STACK_LEVEL 100

typedef struct {
    hashtable *table;
    free_variables_t *free_locals;
} frame_t;

typedef struct {
    frame_t items[MAX_FRAME_STACK_LEVEL];
    int size;
    tag_tuple *function;
} frame_stack_t;

typedef struct {
    value_data_type_t *type;
    int index;
} frame_type_item_t;

static void validate_inside_frame_stack(frame_stack_t *frame_stack) {
     if (frame_stack == NULL || frame_stack->size >= MAX_FRAME_STACK_LEVEL || frame_stack->size < 0) {
        fprintf(stderr, "ERROR: Outside function stack\n");
        exit(1);
    }
}

static void validate_item_frame_stack(frame_t *item) {
     if (item == NULL || item->table == NULL) {
        fprintf(stderr, "ERROR: Invalid function stack item\n");
        abort();            
    }
}

static void push_to_frame_stack(frame_stack_t *frame_stack, hashtable *types, free_variables_t *free_locals) {
    if (frame_stack->size >= MAX_FRAME_STACK_LEVEL) {
        fprintf(stderr, "ERROR: Function stack limit reached\n");
        exit(1);
    }
    frame_t item = {types, free_locals};
    frame_stack->items[frame_stack->size++] = item;
}

static void pop_frame_stack(frame_stack_t *frame_stack) {
    if (frame_stack->size <= 0) 
        return;
    frame_t item = {NULL, NULL};
    frame_stack->items[--frame_stack->size] = item;
}

static frame_t* peek_frame_stack(frame_stack_t *frame_stack) {
    if (frame_stack->size <= 0) 
        return NULL;
    return &frame_stack->items[frame_stack->size - 1];
}

static frame_type_item_t fetch_type_from_frame_stack(frame_stack_t *frame_stack, const char *name) {
    frame_type_item_t result = { NULL, -1 };
    const int size = frame_stack->size;
    for (int n = 0; n < size; n++) {
        frame_t item = frame_stack->items[size - 1 - n];
        validate_item_frame_stack(&item);
        value_data_type_t * type = (value_data_type_t *) hashtable_get(item.table, name);
        if (type != NULL) {
            result.type = type;
            result.index = n;
            return result;
        }
    }
    return result;
}

static void add_type_to_frame(frame_t *frame, const char *name, value_data_type_t *type) {
    //validate_inside_frame_stack(frame_stack);
    //frame_t frame = frame_stack->items[frame_stack->size - 1];
    validate_item_frame_stack(frame);
    value_data_type_t * previous = (value_data_type_t *) hashtable_get(frame->table, name);
    type->shadows = previous;
    hashtable_set(frame->table, name, type);
}

static void remove_type_from_frame(frame_t *frame, const char *name) {
    //validate_inside_frame_stack(frame_stack);
    //frame_t frame = frame_stack->items[frame_stack->size - 1];
    validate_item_frame_stack(frame);
    value_data_type_t * current = (value_data_type_t *) hashtable_get(frame->table, name);
    if (current != NULL && current->shadows != NULL)
        hashtable_set(frame->table, name, current->shadows);
    else
        hashtable_remove(frame->table, name);
}

/*static int exists_on_top_frame_stack(frame_stack_t *frame_stack, const char *name) {
    validate_inside_frame_stack(frame_stack);
    frame_t frame = frame_stack->items[frame_stack->size - 1];
    validate_item_frame_stack(frame);
    return hashtable_get(frame.table, name) != NULL;
}*/

static void undeclared_variable_error(int line, const char *name, tag_tuple * function) {
     inside_function_error(0, function);
     TYPE_ERROR(1, line, "Undeclared variable %s", name);
}

static int get_array_size(tag_tuple *expr) {
    if (expr == NULL || expr->type != TAG_TYPE_NUMBER || expr->value.number.value.type != NUMBER_TYPE_LONG) {
        TYPE_ERROR(1, expr != NULL ? expr->line_number : 0, "%s", "Invalid array index. Array indexes must be compile-time constant integers");
        return -1;
    }
    return expr->value.number.value.value.longint;
}

static const value_data_type_t *get_return_type(const value_data_type_t *data_type) {
    if (data_type->kind != DATA_KIND_ARROW)
        return data_type;
    return data_type->type.arrow.to;
}

static value_data_type_t *set_return_type(value_data_type_t *data_type, value_data_type_t *return_type) {
    if (data_type == NULL)
        return return_type;
    if (data_type->kind != DATA_KIND_ARROW)
        return data_type;
    return data_type->type.arrow.to = return_type;
}

//static value_data_type_t * make_arrow_from_args()

static int declaration_type_equals(declaration_t *declaration, declaration_t *other) {
    if (declaration == NULL || other == NULL)
        return declaration == NULL && other == NULL;
    return string_equals(declaration->name, other->name) 
        && type_equals(declaration->type, other->type);
}

static int decl_list_type_equals(declaration_t *declaration, declaration_t *other) {
    declaration_t *a, *b;
    for (a = declaration, b = other; a != NULL && b != NULL; a = a->next, b = b->next) {
        if (!declaration_type_equals(a, b))
            return 0;
    }
    return a == NULL && b == NULL;
}

static int type_list_type_equals(value_data_type_t *type, value_data_type_t *other) {
    value_data_type_t *a, *b;
    for (a = type, b = other; a != NULL && b != NULL; a = a->next, b = b->next) {
        if (!type_equals(a, b))
            return 0;
    }
    return a == NULL && b == NULL;
}

int type_equals(const value_data_type_t *data_type, const value_data_type_t *other) {
    if (data_type == NULL || other == NULL)
        return data_type == NULL && other == NULL;
    if (data_type->kind != other->kind)
        return 0;
    switch (data_type->kind) {
        case DATA_KIND_ARROW:
            return type_list_type_equals(data_type->type.arrow.from, other->type.arrow.from)
                && type_equals(data_type->type.arrow.to, other->type.arrow.to) ;
        case DATA_KIND_ARRAY:
             return type_equals(data_type->type.array.target, other->type.array.target) 
                && get_array_size(data_type->type.array.size) == get_array_size(other->type.array.size);
        case DATA_KIND_RECORD:
            //anonymous records are never equal
            return false; //decl_list_type_equals(data_type->type.record.fields, other->type.record.fields);
        case DATA_KIND_POINTER:
             return type_equals(data_type->type.pointer.target, other->type.pointer.target);
        case DATA_KIND_ARRAY_POINTER:
             return type_equals(data_type->type.pointer.target, other->type.pointer.target);
        case DATA_KIND_BOX:
             return type_equals(data_type->type.pointer.target, other->type.pointer.target);
        case DATA_KIND_ARRAY_BOX:
             return type_equals(data_type->type.pointer.target, other->type.pointer.target);
        case DATA_KIND_NAMED:
            return string_equals(data_type->type.named.name, other->type.named.name);
        case DATA_KIND_BOOLEAN:
        case DATA_KIND_BYTE:
        case DATA_KIND_INT:
        case DATA_KIND_LONG:
        case DATA_KIND_DOUBLE:
        case DATA_KIND_CHARS:
        case DATA_KIND_DYNAMIC:
        case DATA_KIND_UNIT:
        case DATA_KIND_NULL:
            return 1;
       }
    return 0;
}

static int type_numeric_order() {
ddw
CONTINUE HERE
}

const value_data_type_t * get_named_type(const char *name, int accept_datatypes) {
    value_data_type_t * type = NULL;
    if (accept_datatypes)
        type = data_type_table != NULL ? hashtable_get(data_type_table, name) : NULL;
    if  (type == NULL)
        type = typedef_table != NULL ? hashtable_get(typedef_table, name) : NULL;
    return type;
}

const value_data_type_t * get_underlying_type(const value_data_type_t *data_type) {
    if (data_type == NULL || data_type->kind != DATA_KIND_NAMED)
        return data_type;
    return get_named_type(data_type->type.named.name, 0);
}

static int type_can_be_dynamic(const value_data_type_t *data_type) {
    if (data_type == NULL)
        return 0;
    switch (data_type->kind) {
        case DATA_KIND_ARRAY:
        case DATA_KIND_RECORD:
        case DATA_KIND_POINTER:
        case DATA_KIND_ARRAY_POINTER:
        case DATA_KIND_UNIT:
            return 0;
        
        case DATA_KIND_NAMED: {
            const value_data_type_t *data_type = get_named_type(data_type->type.named.name, 1);
            return data_type != NULL && type_can_be_dynamic(data_type);
        }

        case DATA_KIND_ARROW:
        case DATA_KIND_BOX:
        case DATA_KIND_ARRAY_BOX:
        case DATA_KIND_BOOLEAN:
        case DATA_KIND_BYTE:
        case DATA_KIND_INT:
        case DATA_KIND_LONG:
        case DATA_KIND_DOUBLE:
        case DATA_KIND_CHARS:
        case DATA_KIND_DYNAMIC:
        case DATA_KIND_NULL:
            return 1;
    }
    return 0;
}

static int type_can_be_converted_to_ref(const value_data_type_t *src, const value_data_type_t *dest) {
    if (dest->kind != DATA_KIND_POINTER)
        return 0;
    value_data_type_t *dest_target = dest->type.pointer.target;
    value_data_type_t *src_target;
    if (src->kind == DATA_KIND_POINTER)
        src_target = src->type.pointer.target;
    else if (src->kind == DATA_KIND_BOX)
        src_target = src->type.box.target;
    else if(src->kind == DATA_KIND_ARRAY_POINTER || src->kind == DATA_KIND_ARRAY_BOX)
        return dest_target == NULL;
    else
        return 0;
    return (src_target == NULL && src->kind == DATA_KIND_POINTER)
            || dest_target == NULL 
            || type_equals(src_target, dest_target);
}

static int type_can_be_converted_to_array_box(const value_data_type_t *src, const value_data_type_t *dest) {
    if (dest->kind != DATA_KIND_ARRAY_BOX)
        return 0;
    value_data_type_t *dest_target = dest->type.array_pointer.target;
    value_data_type_t *src_target;
    if (IS_BOX_TO_ARRAY_TYPE(src))
        src_target = src->type.box.target->type.array.target;
    else
        return 0;
    return type_equals(src_target, dest_target);
}    

static int type_can_be_converted_to_array_ref(const value_data_type_t *src, const value_data_type_t *dest) {
    if (dest->kind == DATA_KIND_ARRAY_BOX)
        return type_can_be_converted_to_array_box(src, dest);
    if (dest->kind != DATA_KIND_ARRAY_POINTER)
        return 0;
    value_data_type_t *dest_target = dest->type.array_pointer.target;
    value_data_type_t *src_target;
    if (src->kind == DATA_KIND_ARRAY_POINTER)
        src_target = src->type.array_pointer.target;
    else if (src->kind == DATA_KIND_ARRAY_BOX)
        src_target = src->type.array_box.target;
    else if (IS_POINTER_TO_ARRAY_TYPE(src))
        src_target = src->type.pointer.target->type.array.target;
    else if (IS_BOX_TO_ARRAY_TYPE(src))
        src_target = src->type.box.target->type.array.target;
    else if (src->kind == DATA_KIND_POINTER && src->type.pointer.target == NULL)
        return 1;
    else
        return 0;
    return type_equals(src_target, dest_target);
}

static int type_can_be_converted_to(const value_data_type_t *src, const value_data_type_t *dest) {
    if (src == NULL || dest == NULL)
        return 0;
    return type_equals(get_underlying_type(src), get_underlying_type(dest))
        || (dest->kind == DATA_KIND_DYNAMIC && type_can_be_dynamic(src)) 
        || (src->kind == DATA_KIND_DYNAMIC && type_can_be_dynamic(dest))
        || type_can_be_converted_to_ref(src, dest)
        || type_can_be_converted_to_array_ref(src, dest)
        || (IS_NUM_OR_BOOL_TYPE(src) && IS_NUM_OR_BOOL_TYPE(dest))
        || (src->kind == DATA_KIND_NULL && IS_REF_TYPE(dest));
}

static value_data_type_t *type_get_assignable_target(const value_data_type_t *l_value_type) {
    if (l_value_type == NULL)
        return NULL;
    if (l_value_type->kind != DATA_KIND_BOX)
        return l_value_type->type.box.target;
    else if (l_value_type->kind != DATA_KIND_POINTER)
        return l_value_type->type.pointer.target;
    else
        return NULL;
}

static void fill_types(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack);

static void add_free_variable(declaration_t *declaration, int is_declaration_owner, frame_t *frame, tag_tuple *function) {
    free_variables_t *free_variables = frame->free_locals;
    hashtable *table = frame->table;
    if (free_variables == NULL)
        undeclared_variable_error(declaration->line_number, declaration->name, function);
    if (!is_declaration_owner)
        declaration = make_declaration(declaration->line_number, declaration->name, 0, declaration->type);
    declaration->next = frame->free_locals->variables;
    frame->free_locals->variables = declaration;
    hashtable_set(frame->table, declaration->name, declaration->type);
}

static value_data_type_t * fetch_type_by_var_name(int line_number, char *name, hashtable *static_table, frame_stack_t *frame_stack) {
    int index = -1;
    value_data_type_t *type = NULL;
    frame_type_item_t item = fetch_type_from_frame_stack(frame_stack, name);
    if(item.index >= 0 && item.type != NULL) {
        type = item.type;
        index = item.index;
    } else {
        type = (value_data_type_t *) hashtable_get(static_table, name);
        if (type == NULL)
            type = (value_data_type_t *) hashtable_get(function_table, name);
        else if(hashtable_get(function_table, name) != NULL)
            TYPE_ERROR(1, line_number, "Redefinition of symbol '%s'", name);
    }
    if(type != NULL && index > 0) {
        printf("%s is free!\n", name);
        validate_inside_frame_stack(frame_stack);
        frame_t *frame = peek_frame_stack(frame_stack);
        validate_item_frame_stack(frame);
        declaration_t *declaration = make_declaration(line_number, name, 0, type);
        add_free_variable(declaration, 1, frame, frame_stack->function);
    }
    return type;
}

static void add_escaping_free_variables(free_variables_t free_variables, frame_stack_t *frame_stack) {
    validate_inside_frame_stack(frame_stack);
    frame_t *frame = peek_frame_stack(frame_stack);
    validate_item_frame_stack(frame);
    declaration_t *arg;
    for (arg = free_variables.variables; arg != NULL; arg = arg->next) {
        if (hashtable_get(frame->table, arg->name) == NULL)
            add_free_variable(arg, 0, frame, frame_stack->function);
    }
}

static value_data_type_t* fill_arg_types(tag_tuple *arguments, hashtable *static_table, frame_stack_t *frame_stack) {
    value_data_type_t *last_type;
    tag_tuple *arg;
    for (arg = arguments; arg != NULL; arg = arg->next) {
        fill_types(arg, static_table, frame_stack);
        last_type = arg->data_type;
    }
    return last_type;
}

static value_data_type_t *fill_function_arg_decl_type(
                        const char *function_name, 
                        declaration_t *declarations, value_data_type_t * return_type,
                        hashtable *local_table) {
    declaration_t *arg;
    value_data_type_t *type = NULL, *arrow;
    arrow = make_arrow_type(arg->line_number, NULL, return_type); //MTODO ownership
    for (arg = declarations; arg != NULL; arg = arg->next) {
        if (arg->type == NULL)
            TYPE_ERROR(1, arg->line_number, "Missing type for argument '%s' of function '%s'", arg->name, function_name);
        if (hashtable_get(local_table, arg->name) != NULL)
            TYPE_ERROR(1, arg->line_number, "Redefinition of argument '%s' of function '%s'", arg->name, function_name);            
        hashtable_set(local_table, arg->name, arg->type);
        if (arg->type->next != NULL) 
            error_abort("Argument types is a list");
        if (type == NULL) {
            arrow->type.arrow.from = arg->type;
            type = arrow->type.arrow.from;
        } else {
            type->next = arg->type;
            type = type->next;
        }
    }
    return arrow;
}

static void fill_function_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    value_data_type_t * const return_type = root->value.function.return_type;
    const char * const function_name = root->value.function.name;
    value_data_type_t * const previous_type = hashtable_get(function_table, function_name);
    const int is_forward_declaration = root->value.function.body == NULL;
    if (previous_type != NULL && (!previous_type->is_forward_declaration || is_forward_declaration))
        TYPE_ERROR(1, root->line_number, "Redefinition of function '%s'", function_name); 
    if (hashtable_get(static_table, function_name) != NULL || hashtable_get(typedef_table, function_name) != NULL)
        TYPE_ERROR(1, root->line_number, "Redefinition of symbol '%s'", function_name);
    if (return_type == NULL)
        TYPE_ERROR(1, root->line_number, "Missing return type for function '%s'", function_name);
    root->value.function.local_types = hashtable_create();
    root->data_type = fill_function_arg_decl_type(function_name, 
                                                  root->value.function.arguments, return_type, 
                                                  root->value.function.local_types);
    if (root->data_type == NULL)
        error_abort("Failed to generate function type");
    root->data_type->is_forward_declaration = is_forward_declaration;
    hashtable_set(function_table, function_name, root->data_type);
    frame_stack->function = root;
    push_to_frame_stack(frame_stack, root->value.function.local_types, NULL);
    if (is_forward_declaration)
        return;
    fill_types(root->value.function.body, static_table, frame_stack);
    pop_frame_stack(frame_stack);
    frame_stack->function = NULL;
    if (!type_equals(return_type, root->value.function.body->data_type)) {
       TYPE_MISMATCH_ERROR(1, root->line_number, 
        "Wrong return type for function '" ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "'",
        "Declared type: ", return_type,
        "Returned type: ", root->value.function.body->data_type,
        function_name);
    }
    if (previous_type != NULL && !type_equals(root->data_type, previous_type)) {
       TYPE_MISMATCH_ERROR(1, root->line_number, 
        "Type differs from prototype for function '" ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "'",
        "Prototype type: ", root->data_type,
        "Function type : ", previous_type,
        function_name);
    }
}

static void fill_lambda_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    const char * const function_name = "{Anonymous}";
    root->value.lambda.local_types = hashtable_create();
    root->data_type = fill_function_arg_decl_type(function_name, 
                                                  root->value.lambda.arguments, NULL, 
                                                  root->value.lambda.local_types);
    push_to_frame_stack(frame_stack, root->value.function.local_types, &root->value.lambda.free_locals);
    fill_types(root->value.lambda.body, static_table, frame_stack);
    pop_frame_stack(frame_stack);
    add_escaping_free_variables(root->value.lambda.free_locals, frame_stack);
    if (root->value.lambda.body->data_type == NULL) {
        inside_function_error(0, frame_stack->function);
        TYPE_ERROR(1, root->line_number, "%s", "Missing return type for lambda expreesion ");
    }
    set_return_type(root->data_type, root->value.lambda.body->data_type);
}

static void fill_tag_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    char *name = root->value.tag.name;
    value_data_type_t *type = fetch_type_by_var_name(root->line_number, name, static_table, frame_stack);
    if (type == NULL)
        undeclared_variable_error(root->line_number, name, frame_stack->function);
    root->data_type = type;
}

static void fill_string_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    root->data_type = make_chars_type(root->line_number);
}

static void fill_number_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    if (root->value.number.value.type == NUMBER_TYPE_DOUBLE)
        root->data_type = make_double_type(root->line_number);
    else
        root->data_type = make_long_type(root->line_number);
}

static void fill_assign_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    if (root->value.assign.l_value == NULL || root->value.assign.r_value == NULL) {
        TYPE_ERROR(0, root->line_number, "%s", "Invalid assign");
        abort();
    }
    fill_types(root->value.assign.l_value, static_table, frame_stack);
    fill_types(root->value.assign.r_value, static_table, frame_stack);
    value_data_type_t *l_value_type = type_get_assignable_target(root->value.assign.l_value->data_type);
    if (l_value_type == NULL) {
        TYPE_ERROR(1, root->line_number, "%s", "Left value of assign is not assignable");
    } 
    if (!type_equals(l_value_type, root->value.assign.r_value->data_type)) {
        inside_function_error(0, frame_stack->function);
        TYPE_MISMATCH_ERROR(1, root->line_number, 
        "%s",
        "Assignable type: ", l_value_type,
        "Value type     : ", root->value.assign.r_value->data_type,
        "Wrong assign type");
    }
}

static void fill_function_call_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    tag_tuple * args = root->value.tuple.arguments;
    value_data_type_t * last_arg_type = fill_arg_types(args, static_table, frame_stack);
    if (root->value.tuple.name == NULL || root->value.tuple.name[0] == '\0') {
        root->data_type = last_arg_type; //MTODO ownership
        return;
    }
    char *function_name = root->value.tuple.name;
    value_data_type_t * const function_type = fetch_type_by_var_name(root->line_number, function_name, 
                                                                     static_table, frame_stack);
    if (function_type == NULL)
        TYPE_ERROR(1, root->line_number, "Undeclared function '%s'", function_name); 
    if (function_type->kind != DATA_KIND_ARROW)
        TYPE_ERROR(1, root->line_number, "Symbol is not a function: '%s'", function_name); 
    if (function_type->type.arrow.from == NULL)
        error_abort("Invalid function type");
    value_data_type_t* type = function_type->type.arrow.from;
    tag_tuple *arg = args;
    int i;
    for (i = 1; arg != NULL && type != NULL; arg = arg->next, type = type->next, i++) {
        if (arg == NULL || type == NULL || arg->data_type == NULL || !type_equals(type, arg->data_type))
            TYPE_MISMATCH_ERROR(1, arg->line_number, 
            "Wrong type for argument %d of function '" ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "'",
            "Expected type: ", type,
            "Provided type: ", arg->data_type,
            i, function_name);
    }
    int expected_args;
    int provided_args;
    for (provided_args = i - 1; arg != NULL; arg = arg->next, provided_args++);
    for (expected_args = i - 1; type != NULL; type = type->next, expected_args++);
    if (expected_args != provided_args) {
        TYPE_ERROR(0, root->line_number, 
        "Wrong number of arguments for function '" ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "'", function_name);
         TYPE_ERROR(1, root->line_number, "Expected %d got %d", expected_args, provided_args);
    }
    root->data_type = get_return_type(function_type); //MTODO ownership
}

static void fill_convert_type(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
    const tag_tuple * const subject = root->value.convert.subject;
    value_data_type_t * type = root->value.convert.type;
    if (subject == NULL)
        error_abort("Invalid convert");
    fill_types(subject, static_table, frame_stack);
    if (!type_can_be_converted_to(subject->data_type, type))
        TYPE_MISMATCH_ERROR(1, root->line_number, 
        "%s", 
        "Value type    : ", subject->data_type,
        "Requested type: ", type,
        "Incompatible types. Value cannot be converted."
        )
    root->data_type = type; //MTODO ownership
}
static void fill_types(tag_tuple *root, hashtable *static_table, frame_stack_t *frame_stack) {
     if (root == NULL)
        return;
    switch (root->type) {
        case TAG_TYPE_DEFINITIONS:
            fill_arg_types(root->value.definitions.arguments, static_table, frame_stack);
            break;
        case TAG_TYPE_FUNCTION:
            fill_function_type(root, static_table, frame_stack);
            break;
        case TAG_TYPE_LAMBDA:
            fill_lambda_type(root, static_table, frame_stack);
            break;
        case TAG_TYPE_TAG:
            fill_tag_type(root, static_table, frame_stack);
            break;
        case TAG_TYPE_STRING:
            fill_string_type(root, static_table, frame_stack);
            break;
        case TAG_TYPE_NUMBER:
            fill_number_type(root, static_table, frame_stack);
            break;
        /*case TAG_TYPE_EXPR:
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
        */case TAG_TYPE_ASSIGN:
            fill_assign_type(root, static_table, frame_stack);
            break;
        case TAG_TYPE_TUPLE: 
            fill_function_call_type(root, static_table, frame_stack);
            break;
        /*case TAG_TYPE_ARRAY: 
            print_arg_list(f, root->value.array.arguments, "[", "]", ", ");
            break;
        case TAG_TYPE_DATATYPE:
            fprintf(f, "datatype %s ", root->value.datatype.name);
            print_type(f, root->value.datatype.type);
            print_decl_list(f, root->value.datatype.ctor_arguments, " (", ")\n ");
            print_tree(f, root->value.datatype.ctor);
            print_arg_list(f, root->value.datatype.with, " with (\n", "\n)", ";\n ");
            break;
        */case TAG_TYPE_INCLUDE:
            root->data_type = make_unit_type(root->line_number);
            break;
        case TAG_TYPE_CONVERT:
            fill_convert_type(root, static_table, frame_stack);         
            break;
        case TAG_TYPE_IS:
            fill_arg_types(root->value.is.subject, static_table, frame_stack);
            root->data_type = make_boolean_type(root->line_number);     
            break;
        /*case TAG_TYPE_LET:
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
            break;*/
    }
}

hashtable *type_check(tag_tuple *tagtuple) {
    frame_stack_t frame_stack;
    memset(&frame_stack, 0, sizeof(frame_stack_t)); 
    hashtable * const static_table = hashtable_create();
    if (data_type_table == NULL)
        data_type_table = hashtable_create();
    if (typedef_table == NULL)
        typedef_table = hashtable_create();
    if (function_table == NULL)
        function_table = hashtable_create();
    fill_types(tagtuple, static_table, &frame_stack);
    return static_table;
}