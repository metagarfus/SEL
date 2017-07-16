#include <string.h>
#include <stdlib.h>
#include "utils.h"
char *clone_string(char *string) {
    if (string == NULL)
        return NULL;
    const int len = strlen(string);
    char * const result = (char *) malloc(len + 1);
    strcpy(result, string);
    return result;
}