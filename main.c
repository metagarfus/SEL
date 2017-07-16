#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntax.h"

void print_usage() {
    printf ("sel [-i | <filename> ]\n");
}

void run(parse_output output) {
    if (output.error_code == PARSE_ERROR_OK) {
        print_tree(output.value.root);
        printf("\n");
        release_tagtuple(output.value.root);
    } else {
        print_error(output.error_code, &output.value.error);
        release_tagtuple(output.value.error.leftover);
    }
}

#ifdef __FOREIGN__C
int foreign_main(int argc, char **argv) {
#else
int main(int argc, char **argv) {
#endif
    if (argc != 2) {
        print_usage();
        return 1;
    }
    if (strcmp(argv[1], "-i") == 0)
        tagtuple_interactive(run);
    else if (argv[1][0] != '-') {
        FILE * file = fopen(argv[1], "r");
        run(tagtuple_parse(file));
        fclose(file);
    } else
          print_usage();
    return 0;
}