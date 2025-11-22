#ifndef STACK_STR_H
#define STACK_STR_H

#define INITIAL_STACK_CAPACITY 4

#include <stdlib.h>

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} stack_str_t;

int create_str_stack(stack_str_t *stack);
int push_string(stack_str_t *stack, const char *str);
int pop_str_stack(stack_str_t *stack, char **value);
int get_str_stack(stack_str_t *stack, char **value);
void free_str_stack(stack_str_t *stack);

#endif
