#ifndef VARIABLES_H
#define VARIABLES_H

#define INITIAL_CAPACITY 2
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
int free_variables(variables *vs);

#endif
