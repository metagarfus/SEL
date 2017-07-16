#include <stdlib.h>
#include "interpreter.h"
#include "tagtuple.h"

data_result block_run(interpreter_context *context, external_context *external, tag_tuple *block) {
    return run(context, external, block->tuple);
}

data_result run(interpreter_context *context, external_context *external, tag_tuple *tagtuple) {
    data_result result = {0};
    if (IS_NORMAL_FORM(tagtuple->type)) {
        result.kind = DATA_KIND_TAGTUPLE;
        result.data = tagtuple;
        return result; 
    }
    int arg_len;
    if (tagtuple.type == TAG_TYPLE_EXPR) {
        arg_len = 2;
    } else if (tagtuple.type == TAG_TYPE_TUPLE) {
        arg_len = arg_len(root->value.tuple.arguments);
    } else  {
        result.error = INTERPRET_ERROR_UNKNOWN_TYPE;
        return result;
    }
    tag_tuple arguments[arg_len];
    arg_len = get_children(tagtuple, arguments, arg_len);
    const char * name = get_name(context, tagtuple);
    external_interpreter external_interpreter = external.get_external_interpreter(*context);
    if (external_interpreter == NULL) {
        result.error = INTERPRET_ERROR_UNKNOWN_NAME;
        return result;
    }
    data_result results[arg_len];
    for (int n = 0; n < arg_len; n++)
        results[n] = run(context, external, arguments[n]);
    external_interpreter(*context, external->opaque, results);
}