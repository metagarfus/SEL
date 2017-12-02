#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void inside_function_error(int do_exit, tag_tuple *function) {
    if (function == NULL)
        return;
    PRINTF_ERROR("Inside function '" ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "' :\n", function->line_number, function->value.function.name);
    if (do_exit)
        exit(1);
}

void error_abort(const char *msg) {
    fprintf(stderr, ANSI_COLOR_BOLD ANSI_COLOR_RED "ERROR: %s\n" ANSI_COLOR_RESET, msg);
    abort();  
}