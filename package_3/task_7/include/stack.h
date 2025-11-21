#ifndef STACK_H
#define STACK_H

#define RESIZE_FACTOR 2

#include <stdlib.h>

typedef struct {
    char name;
    int value;
} variable;

typedef struct {
    variable *data;
    size_t size;
    size_t capacity;
} variables;

int create_variables(variables *vs, size_t initial_capacity);
int add_variable(variables *vs, char name, int value);
int get_variable(variables *vs, char name, int *out_value);
int print_all(variables *vs);

#endif