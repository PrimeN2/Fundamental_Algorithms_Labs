#ifndef INTERPRETATOR_H
#define INTERPRETATOR_H

#include "variables.h"
#include <stdio.h>

typedef struct {
    variables vs;
    char *current_str;
    size_t current_idx;
    FILE *trace_file;
    int line_number;

} interpretator_state;

int create_interpretator(interpretator_state *state, FILE *tracefile);
int interpretate_str(interpretator_state *state, char *str);

#endif
