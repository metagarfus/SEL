#include <string.h>
#include <stdlib.h>
#include "utils.h"

char *clone_string(const char *string) {
    if (string == NULL)
        return NULL;
    const int len = strlen(string);
    char * const result = (char *) malloc(len + 1);
    strcpy(result, string);
    return result;
}

int string_equals(const char *a, const char *b) {
    if (a == NULL|| b == NULL)
        return a == NULL && b == NULL;
    return strcmp(a, b) == 0;
}