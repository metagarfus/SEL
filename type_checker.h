#ifndef TYPE_CHECKER_H
#define TYPE_CHECKER_H

#include <stdint.h>
#include <stdio.h>
#include "tagtuple.h"
#include "datastructs/hashtable.h"

#define IS_REF_KIND(X) ((X) == DATA_KIND_POINTER || (X) == DATA_KIND_BOX)

#define IS_REF_TYPE(X) IS_REF_KIND((X)->kind)

#define IS_NUM_KIND(X) ((X) == DATA_KIND_LONG || (X) == DATA_KIND_INT || (X) == DATA_KIND_BYTE || (X) == DATA_KIND_DOUBLE)

#define IS_NUM_TYPE(X) IS_NUM_KIND((X)->kind)

#define IS_NUM_OR_BOOL_KIND(X) (IS_NUM_KIND(X) || (X) == DATA_KIND_BOOLEAN)

#define IS_NUM_OR_BOOL_TYPE(X) IS_NUM_OR_BOOL_KIND((X)->kind)

#define IS_POINTER_TO_ARRAY_TYPE(X) ((X)->kind == DATA_KIND_POINTER\
                                     && (X)->type.pointer.target != NULL\
                                     && (X)->type.pointer.target->kind == DATA_KIND_ARRAY)
                                     
#define IS_BOX_TO_ARRAY_TYPE(X) ((X)->kind == DATA_KIND_BOX\
                                 && src->type.box.target != NULL\
                                 && src->type.box.target->kind == DATA_KIND_ARRAY)

const value_data_type_t * get_named_type(const char *name, int accept_datatypes);

int type_equals(const value_data_type_t *data_type, const value_data_type_t *other);

hashtable *type_check(tag_tuple *tagtuple);

#endif /* TYPE_CHECKER_H */