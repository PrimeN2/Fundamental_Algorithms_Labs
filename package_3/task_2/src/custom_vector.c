#define VECTOR_TYPE int
#include "custom_vector.h"

static int resize_vector(Vector *v, size_t new_capacity) {
    if (v->capacity < new_capacity) { 
        VECTOR_TYPE *new_data = realloc(v->data, new_capacity * sizeof(VECTOR_TYPE));
        if (new_data == NULL) {
            return -1; 
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    return 0;
}

Vector *create_vector(size_t initial_capacity,
                        VECTOR_TYPE *(*copy_func)(const VECTOR_TYPE*),
                        void (*delete_func)(VECTOR_TYPE*),
                        int (*compare_func)(const VECTOR_TYPE*, const VECTOR_TYPE*)) {
    if (!copy_func || !delete_func) {
        return NULL;
    }

    Vector *v = malloc(sizeof(Vector));
    if (!v) return NULL; 

    v->data = malloc(initial_capacity * sizeof(VECTOR_TYPE));
    if (!v->data) { 
        free(v);
        return NULL;
    }

    v->capacity = initial_capacity;
    v->len = 0;
    v->copy_void_ptr = copy_func;
    v->delete_void_ptr = delete_func;
    v->compare_void_ptr = compare_func;

    return v;
}

void erase_vector(Vector *v) {
    if (!v || !v->data) {
        return;
    }

    if (v->delete_void_ptr) {
        for (size_t i = 0; i < v->len; ++i) {
            v->delete_void_ptr(&v->data[i]);
        }
    }

    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->len = 0;
    v->copy_void_ptr = NULL;
    v->delete_void_ptr = NULL;
    v->compare_void_ptr = NULL;
}

int is_equal_vector(const Vector *v1, const Vector *v2) {
    if (!v1 || !v2) return v1 == v2; 

    if (v1->len != v2->len) {
        return 0;
    }

    for (size_t i = 0; i < v1->len; i++) {
        if (v1->compare_void_ptr(&v1->data[i], &v2->data[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

void copy_vector(Vector *dest, const Vector *src) {
    if (!dest || !src) {
        return;
    }

    if (src == dest) {
        return;
    }

    erase_vector(dest);

    dest->compare_void_ptr = src->compare_void_ptr;
    dest->copy_void_ptr = src->copy_void_ptr;
    dest->delete_void_ptr = src->delete_void_ptr;

    if (src->len > dest->capacity) {
        if (resize_vector(dest, src->len) != 0) {
            return;
        }
    }

    for (size_t i = 0; i < src->len; ++i) {
        if (src->copy_void_ptr) {
            VECTOR_TYPE *copied_element = src->copy_void_ptr(&src->data[i]);
            if (!copied_element) {
                return;
            }

            dest->data[i] = *copied_element;
            free(copied_element); 
        } else {
            dest->data[i] = src->data[i];
        }
        dest->len++;
    }
}

Vector *copy_vector_new(const Vector *src) {
    if (!src) {
        return NULL;
    }

    Vector *new_v = create_vector(src->capacity, src->copy_void_ptr, src->delete_void_ptr, src->compare_void_ptr);
    if (!new_v) {
        return NULL;
    }

    copy_vector(new_v, src); 

    if (new_v->len != src->len) {
        delete_vector(new_v);
        return NULL;
    }

    return new_v;
}

void push_back_vector(Vector *v, const VECTOR_TYPE *value) {
    if (!v || !value) { 
        return;
    }

    if (v->len >= v->capacity) { 
        size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        if (resize_vector(v, new_capacity) != 0) {
            return; 
        }
    }

    VECTOR_TYPE *copied_element = v->copy_void_ptr(value);
    if (!copied_element) {
        return; 
    }

    v->data[v->len] = *copied_element;
    free(copied_element); 
    v->len++;
}

void delete_at_vector(Vector *v, size_t index) {
    if (!v || v->len <= index) { 
        return;
    }

    if (v->delete_void_ptr) {
        v->delete_void_ptr(&v->data[index]);
    }

    for (size_t i = index; i < v->len - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }

    v->len--;
}

VECTOR_TYPE *get_at_vector(const Vector* v, size_t index) {
    if (!v || index >= v->len) return NULL;
    return (VECTOR_TYPE*)&v->data[index];
}

void delete_vector(Vector *v) {
    if (!v) {
        return;
    }

    erase_vector(v);
    free(v);
}

#undef VECTOR_TYPE
