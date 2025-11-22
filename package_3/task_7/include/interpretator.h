#ifndef INTERPRETATOR_H
#define INTERPRETATOR_H

#include "variables.h"

typedef struct {
    variables vs;
    char *current_str;
    size_t current_idx;

} interpretator_state;

int create_interpretator(interpretator_state *state);
int interpretate_str(interpretator_state *state, char *str);

#endif
