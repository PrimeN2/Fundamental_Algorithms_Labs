#include "vector.h"

void init_vector(vector *v, size_t elem_size) {
    v->elem_size = elem_size;
    v->capacity = 0;
    v->size = 0;
    v->data = NULL;
}

void destroy_vector(vector *v) {
    if (v->data) {
        free(v->data);
        v->data = NULL; 
    }

    v->size = 0;
    v->capacity = 0;
}

