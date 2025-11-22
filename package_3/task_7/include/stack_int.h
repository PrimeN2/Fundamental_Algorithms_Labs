#ifndef STACK_INT_H
#define STACK_INT_H

#define INITIAL_STACK_CAPACITY 4

#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} stack_int_t;

int create_int_stack(stack_int_t *stack);
int push_int(stack_int_t *stack, const int n);
int pop_int_stack(stack_int_t *stack, int *value);
void free_int_stack(stack_int_t *stack);

#endif
