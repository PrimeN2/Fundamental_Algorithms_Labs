#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#define INITIAL_STACK_CAPACITY 4

#include <stdlib.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} stack_char_t;

int create_char_stack(stack_char_t *stack);
int push_char(stack_char_t *stack, char c);
int pop_char_stack(stack_char_t *stack, char *value);
int get_char_stack(stack_char_t *stack, char *value);
void free_char_stack(stack_char_t *stack);

#endif
