#include "variables.h"
#include <stdio.h>

static int resize_variables(variables *vs, size_t new_capacity) {
    if (vs == NULL || new_capacity < vs->capacity) {
        perror("Wrong capacity value.\n");
        return -1;
    }

    variable *new_vs = realloc(vs->data, new_capacity);
    if (!new_vs) {
        perror("Cannot realloc variables.\n");
        return -1;
    }

    vs->data = new_vs;
    vs->capacity = new_capacity;

    return 0;
}

int create_variables(variables *vs, size_t initial_capacity) {
    vs->data = malloc(sizeof(variable) * initial_capacity);
    if (!vs->data) {
        perror("Cannot allocate memory for variables.\n");
        return -1;
    }

    vs->capacity = initial_capacity;
    vs->size = 0;

    return 0;
}


int add_variable(variables *vs, char name, int value) {
    variable new_v = {name, value};

    if (vs->size >= vs->capacity) {
        if (resize_variables(vs, vs->capacity * RESIZE_FACTOR) != 0) {
            perror("Cannot resize variables.\n");
            return -1;
        }
    }

    vs->data[vs->size] = new_v;
    vs->size++;

    return 0;
}

int get_variable(variables *vs, char name, int *out_value) {
    if (!vs) {
        return -1;
    }

    for (int i = 0; i < vs->size; ++i) {
        if (vs->data[i].name == name) {
            *out_value = vs->data[i].value;
            return 0;
        }
    }

    *out_value = -1;

    return 0;
}
