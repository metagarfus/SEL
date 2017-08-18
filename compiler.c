#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "compiler.h"

typedef struct function function_t;
typedef struct compiler_context compiler_context_t;
typedef struct compile_result compile_result_t;

struct function {
    function_t *next;
    tag_tuple *function;
};

struct compiler_context {
    int current_line;
    function_t *functions;    
} ;

struct compile_result {
    char temp_name[128];
};

static void new_temp_var(char* varname, int size) {
    static uint64_t temp_counter = 0;
    snprintf(varname, size, "temp_%llu", ++temp_counter);
}

static void add_function_to_backlog(tag_tuple *function) {
    static function_t *list = NULL;
    function_t *head = (function_t *) malloc(sizeof(function_t));
    head->next = list;
    list = head;
}

static const compile_result_t compile(FILE * output, compiler_context_t *context, const tag_tuple *tagtuple);

static const compile_result_t compile_tuple(FILE * output, compiler_context_t *context, const tag_tuple *tagtuple) {
    compile_result_t result = {0};
    int arg_len = arg_length(tagtuple);
    tag_tuple* arguments[arg_len];
    arg_len = get_children(tagtuple, arguments, arg_len);
    const char * name = tagtuple->value.tuple.name;
    /*data_result results[arg_len];
    for (int n = 0; n < arg_len; n++)
        results[n] = run(context, external, arguments[n]);*/
    if (name[0] == '\0') {
        for (int n = 0; n < arg_len; n++)
            result = compile(output, context, arguments[n]);
    } else if (strcmp(name, "let") == 0) {
        new_temp_var(result.temp_name, sizeof(result.temp_name));
        fprintf(output, "long long int %s;\n", result.temp_name);
        compile_result_t init = compile(output, context, arguments[1]);
        fprintf(output, "{\n");
        fprintf(output, "long long int %s = %s;\n", arguments[0]->value.tag.name, init.temp_name);        
        compile_result_t body = compile(output, context, arguments[2]);
        fprintf(output, "%s = %s;\n", result.temp_name, body.temp_name);
        fprintf(output, "} \n");
    } else if (strcmp(name, "print") == 0) {
        new_temp_var(result.temp_name, sizeof(result.temp_name));
        compile_result_t value = compile(output, context, arguments[0]);
        fprintf(output, "printf(\"%%lld\\n\", %s); \n", value.temp_name);
        fprintf(output, "long long int %s = %s;\n", result.temp_name, value.temp_name);
    } else if (strcmp(name, "function") == 0) {
         strncpy(result.temp_name, arguments[0]->value.tag.name, sizeof(result.temp_name));
    }
    return result;
}

static const compile_result_t compile(FILE * output, compiler_context_t *context, const tag_tuple *tagtuple) {
   compile_result_t result = {0};
   switch (tagtuple->type) {
    case TAG_TYPE_STRING:
        new_temp_var(result.temp_name, sizeof(result.temp_name));
        fprintf(output, "const char * %s = \"%s\";\n", result.temp_name, tagtuple->value.string.value);
        break;
    case TAG_TYPE_NUMBER:
        new_temp_var(result.temp_name, sizeof(result.temp_name));
        fprintf(output, "long long int %s = %lld;\n", result.temp_name, tagtuple->value.number.value.value);
        break;
    case TAG_TYPE_TAG:
        strncpy(result.temp_name, tagtuple->value.tag.name, sizeof(result.temp_name));
        break;
    case TAG_TYPE_EXPR: {
        compile_result_t left = compile(output, context, tagtuple->value.expr.left);
        compile_result_t right = compile(output, context, tagtuple->value.expr.right);
        new_temp_var(result.temp_name, sizeof(result.temp_name));
        fprintf(output, "long long int %s = %s %c %s;\n", result.temp_name, left.temp_name, get_operator_symbol(tagtuple->value.expr.op), right.temp_name);
        break;
        }
    case TAG_TYPE_TUPLE:
        return compile_tuple(output, context, tagtuple);
    case TAG_TYPE_BLOCK:
        return compile_tuple(output, context, tagtuple->value.block.tuple);
    }

   return result;
   
   /* compile_result result = {0};
    if (IS_NORMAL_FORM(tagtuple->type)) {
        result.data_kind = DATA_KIND_TAG_TUPLE;
        result.data = (void *)tagtuple;
        return result; 
    }
    int arg_len;
    if (tagtuple->type == TAG_TYPE_EXPR) {
        arg_len = 2;
    } else if (tagtuple->type == TAG_TYPE_TUPLE) {
        arg_len = arg_length(tagtuple->value.tuple.arguments);
    } else  {
        result.error = INTERPRET_ERROR_UNKNOWN_TYPE;
        return result;
    }
    tag_tuple* arguments[arg_len];
    arg_len = get_children(tagtuple, arguments, arg_len);
    const char * name = get_name(context, tagtuple);
    external_compiler external_compiler = external.get_external_compiler(context, external.opaque, name);
    if (external_compiler == NULL) {
        result.error = INTERPRET_ERROR_UNKNOWN_NAME;
        return result;
    }
    data_result results[arg_len];
    for (int n = 0; n < arg_len; n++)
        results[n] = run(context, external, arguments[n]);
    return external_compiler(context, external.opaque, results);*/

}

void sel_compile(FILE * output, const tag_tuple *root) {
    compiler_context_t context = {0};
    fprintf(output, "int main() {\n");
    compile_result_t result = compile(output, &context, root);
    fprintf(output, "printf(\"%%lld\\n\", %s);\n", result.temp_name);
    fprintf(output, "return 0; \n}\n");
}