#include "stack_int.h"

int create_int_stack(stack_int_t *stack) {
    stack->data = malloc(INITIAL_STACK_CAPACITY * sizeof(int));
    if (!stack->data) {
        return -1;
    }
    
    stack->size = 0;
    stack->capacity = INITIAL_STACK_CAPACITY;
    return 0;
}

int push_int(stack_int_t *stack, const int n) {
    if (stack->size >= stack->capacity) {
        size_t new_capacity = stack->capacity * 2;
        int *new_data = realloc(stack->data, new_capacity * sizeof(int));
        if (!new_data) return -1;
        
        stack->data = new_data;
        stack->capacity = new_capacity;
    }
    
    stack->data[stack->size] = n;
    stack->size++;

    return 0;
}

int pop_int_stack(stack_int_t *stack, int *value) {
    if (stack->size == 0) {
        return -1;
    }
    
    *value = stack->data[stack->size - 1];
    stack->size--;

    return 0;
}

void free_int_stack(stack_int_t *stack) {
    if (!stack) return;
    
    free(stack->data);
}
