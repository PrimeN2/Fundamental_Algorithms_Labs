#include "int_vector.h"
#include <stdlib.h> 

VECTOR_TYPE *copy_int(const VECTOR_TYPE *value) {
    int *new_v = malloc(sizeof(VECTOR_TYPE));
    if (new_v == NULL) {
        return NULL;
    }

    *new_v = *value;
    return new_v;
}

void delete_int(int *value) {
    (void)value; 
}

int compare_int(const VECTOR_TYPE *v1, const VECTOR_TYPE *v2) {
    if (*v1 < *v2) return -1;
    if (*v1 > *v2) return 1;
    return 0; 
}

