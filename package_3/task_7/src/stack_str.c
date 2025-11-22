#include "stack_str.h"
#include <string.h>

int create_str_stack(stack_str_t *stack) {
    stack->data = malloc(INITIAL_STACK_CAPACITY * sizeof(char*));
    if (!stack->data) {
        return -1;
    }
    
    stack->size = 0;
    stack->capacity = INITIAL_STACK_CAPACITY;
    
    return 0;
}

int push_string(stack_str_t *stack, const char *str) {
    if (stack->size >= stack->capacity) {
        size_t new_capacity = stack->capacity * 2;
        char **new_data = realloc(stack->data, new_capacity * sizeof(char*));
        if (!new_data) return -1;
        
        stack->data = new_data;
        stack->capacity = new_capacity;
    }
    
    stack->data[stack->size] = malloc(strlen(str) + 1);
    if (!stack->data[stack->size]) return -1;
    
    strcpy(stack->data[stack->size], str);
    stack->size++;
    return 0;
}

int pop_str_stack(stack_str_t *stack, char **value) {
    if (stack->size == 0) {
        return -1;
    }
    
    *value = stack->data[stack->size - 1];

    stack->data[stack->size - 1] = NULL;
    stack->size--;

    return 0;
}

int get_str_stack(stack_str_t *stack, char **value) {
    if (stack->size == 0) {
        *value = NULL;
        return 0;
    }

    *value = stack->data[stack->size - 1];

    return 0;
}


void free_str_stack(stack_str_t *stack) {
    if (!stack) return;
    
    for (size_t i = 0; i < stack->size; i++) {
        free(stack->data[i]);
    }
    
    free(stack->data);
}
