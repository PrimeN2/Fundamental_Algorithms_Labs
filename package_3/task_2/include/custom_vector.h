#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#ifndef VECTOR_TYPE
    #error "VECTOR_TYPE must be defined before including custom_vector.h"
#endif

#include <stdlib.h>

typedef struct {
    VECTOR_TYPE *data;
    size_t len;
    size_t capacity;

    VECTOR_TYPE *(*copy_void_ptr)(const VECTOR_TYPE*);
    void (*delete_void_ptr)(VECTOR_TYPE*);
    int (*compare_void_ptr)(const VECTOR_TYPE*, const VECTOR_TYPE*);
} Vector;

Vector *create_vector(size_t initial_capacity,
                    VECTOR_TYPE *(*copy_func)(const VECTOR_TYPE*),
                    void (*delete_func)(VECTOR_TYPE*),
                    int (*compare_func)(const VECTOR_TYPE*, const VECTOR_TYPE*));
void erase_vector(Vector *v);
int is_equal_vector(const Vector *v1, const Vector *v2);
void copy_vector(Vector *dest, const Vector *src); 
Vector *copy_vector_new(const Vector *src);
void push_back_vector(Vector *v, const VECTOR_TYPE *value);
VECTOR_TYPE* get_at_vector(const Vector* v, size_t index);
void delete_at_vector(Vector *v, size_t index);
void delete_vector(Vector *v);

#endif
