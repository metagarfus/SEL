#include <stdio.h>
#include <stdlib.h>
#include "syntax.h"

#define PRINT_ERROR(E, S, A) printf("Error: %d: " S, (E)->line, A)

void print_error(parse_error_code code, const parse_error *error) {
    if (error ==  NULL) {
        printf("Invalid error\n");
        return;
    }
    switch (code) {
        case PARSE_ERROR_OK:
            break;
        case PARSE_ERROR_MISSING_OPERAND:
            PRINT_ERROR(error, "missing operand for operation '%c'\n", get_operator_symbol(error->op));
            break;
        case PARSE_ERROR_MISSING_ARGUMENT:
            PRINT_ERROR(error, "empty or invalid argument '%s'\n", error->text);
            break;
        case PARSE_ERROR_UNEXPECTED_CHAR:
            PRINT_ERROR(error, "unexpected character '%s'\n", error->text);
            break;
        case PARSE_ERROR_NEAR:
            PRINT_ERROR(error, "syntax error near '%s'\n", error->text);
            break;
        case PARSE_ERROR_END_OF_INPUT:
            PRINT_ERROR(error, "reached unexpected end of input %s\n", "");
            break;
        default:
            PRINT_ERROR(error, "unknown error: %d\n", code);
            break;
    }
}