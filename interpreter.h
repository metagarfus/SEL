#ifndef INTERPRETER_H
#define INTERPRETER_H

#define DATA_KIND_TAG_TUPLE  0

#define INTERPRET_ERROR_OK           0
#define INTERPRET_ERROR_UNKNOWN_NAME 1
#define INTERPRET_ERROR_UNKNOWN_TYPE 2

typedef struct {
    int data_kind;
    int error;
    void *data;
} data_result;

typedef struct {
    int current_line;
    char add_name[128];
    char sub_name[128];
    char mul_name[128];
    char div_name[128];
} interpreter_context;

typedef data_result (* external_interpreter)(interpreter_context context, void *opaque, data_result* arguments);
typedef external_interpreter (* get_external_interpreter)(interpreter_context context, const char* name);

typedef struct {
    void *opaque;
    get_external_interpreter get_external_interpreter;
} interpreter_context;

data_result block_run(interpreter_context *context, external_context external, tag_tuple *block);
data_result interpreter_run(external_context external, tag_tuple *tagtuple);

#endif /* INTERPRETER_H */