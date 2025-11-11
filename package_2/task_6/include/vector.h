#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} vector;

void init_vector(vector *v, size_t elem_size);
void destroy_vector(vector *v);
int push_vector(vector *v, const void *elem);
int pop_vector(vector *v, void *elem);
void* get_vector(const vector* v, size_t index);

#endif
