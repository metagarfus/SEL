#ifndef SYNTAX_H
#define SYNTAX_H
#include <stdio.h> 
#include "tagtuple.h"

typedef enum {
    PARSE_ERROR_OK,
    PARSE_ERROR_MISSING_OPERAND,
    PARSE_ERROR_MISSING_ARGUMENT,
    PARSE_ERROR_UNEXPECTED_CHAR,
    PARSE_ERROR_RESERVED,
    PARSE_ERROR_NEAR,
    PARSE_ERROR_END_OF_INPUT  
} parse_error_code;

typedef struct {
    int line;
    operation op;
    char text[128];
    tag_tuple *leftover;
} parse_error;

typedef struct {
    parse_error_code error_code;
    union {
        tag_tuple *root;
        parse_error error;
    } value;
} parse_output;

void print_error(parse_error_code code, const parse_error *error);

void tagtuple_interactive(void (*run)(parse_output output));

parse_output tagtuple_parse(FILE *stream) ;

#endif /*SYNTAX_H*/