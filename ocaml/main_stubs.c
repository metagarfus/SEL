#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>

int foreign_main(int argc, char **argv);

CAMLprim value caml_sel_main(value ml_array)
{
    CAMLparam1( ml_array );
    int argc = Wosize_val(ml_array);
    char *argv[argc];
    int i;
    for (i = 0; i < argc; i++)
        argv[i] =  String_val(Field(ml_array, i));
    CAMLreturn(Val_int(foreign_main(argc, argv)));
}