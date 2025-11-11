#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define INITIAL_CAPACITY 4
#define GROWTH_FACTOR 2

void init_vector(vector *v, size_t elem_size) {
    v->data = malloc(INITIAL_CAPACITY * elem_size);

    if (v->data == NULL) {
        v->elem_size = 0;
        v->capacity = 0;
        v->size = 0;
    }

    v->elem_size = elem_size;
    v->capacity = INITIAL_CAPACITY;
    v->size = 0;
}

void destroy_vector(vector *v) {
    if (v->data) {
        free(v->data);
        v->data = NULL; 
    }

    v->size = 0;
    v->capacity = 0;
    v->elem_size = 0;
}

static int resize_vector(vector *v) {
    size_t new_capacity = v->capacity * GROWTH_FACTOR;
    void *new_data = realloc(v->data, new_capacity * v->elem_size);

    if (new_data == NULL) {
        return -1;
    }

    v->data = new_data;
    v->capacity = new_capacity;

    return 0;
}

int push_vector(vector *v, const void *elem) {
    if (v->size >= v->capacity) {
        if (resize_vector(v) != 0) {
            return -1;
        }
    }

    char *dest = (char *)v->data + (v->size * v->elem_size);

    memcpy(dest, elem, v->elem_size);
    v->size++;

    return 0;
}

int pop_vector(vector *v, void *elem) {
    if (v->size <= 0 || v == NULL || elem == NULL) {
        return -1;
    }

    char *src = (char *)v->data + ((v->size - 1) * v->elem_size);
    memcpy(elem, src, v->elem_size);
    v->size--;

    return 0;
}

void *get_vector(const vector *v, size_t idx) {
    if (idx >= v->size) {
        return NULL;
    }

    char *elem_ptr = (char *)v->data + (idx * v->elem_size);

    return (void *)elem_ptr;
}
