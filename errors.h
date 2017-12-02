#ifndef TAGTUPLE_ERRORS_H
#define TAGTUPLE_ERRORS_H

#include "tagtuple.h"

#define ANSI_COLOR_BLACK   "\x1b[30m"   
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ERROR_MSG_PREFIX ANSI_COLOR_BOLD ANSI_COLOR_RED "ERROR: %d: " ANSI_COLOR_RESET ANSI_COLOR_BOLD

#define PRINTF_ERROR(MSG, ...) fprintf(stderr, ERROR_MSG_PREFIX MSG ANSI_COLOR_RESET, __VA_ARGS__) 

void inside_function_error(int do_exit, tag_tuple *function);
void error_abort(const char *msg);

#endif /* TAGTUPLE_ERRORS_H */