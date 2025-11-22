#include "stack_char.h"

int create_char_stack(stack_char_t *stack) {
    stack->data = malloc(INITIAL_STACK_CAPACITY * sizeof(char));
    if (!stack->data) {
        return -1;
    }
    
    stack->size = 0;
    stack->capacity = INITIAL_STACK_CAPACITY;
    
    return 0;
}

int push_char(stack_char_t *stack, char c) {
    if (stack->size >= stack->capacity) {
        size_t new_capacity = stack->capacity * 2;
        char *new_data = realloc(stack->data, new_capacity * sizeof(char));
        if (!new_data) return -1;
        
        stack->data = new_data;
        stack->capacity = new_capacity;
    }
    
    stack->data[stack->size] = c;
    stack->size++;
    return 0;
}

int pop_char_stack(stack_char_t *stack, char *value) {
    if (stack->size == 0) {
        return -1;
    }
    
    *value = stack->data[stack->size - 1];
    stack->size--;

    return 0;
}

int get_char_stack(stack_char_t *stack, char *value) {
    if (stack->size == 0) {
        return -1;  
    }

    *value = stack->data[stack->size - 1];
    return 0;
}

void free_char_stack(stack_char_t *stack) {
    if (!stack) return;
    
    free(stack->data);
}
