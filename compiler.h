#ifndef COMPILER_H
#define COMPILER_H
#include <stdlib.h>
#include "tagtuple.h"

typedef struct value value_t;
typedef struct reference reference_t;

struct reference {
    char storage[128];
    char reference[128];
};

struct value_t {
    int type;
    union {
        int integer;
        double real;
        char *str;
        reference_t reference;
    } value;
};


void sel_compile(FILE * output, const tag_tuple *root);

#endif /* COMPILER_H */