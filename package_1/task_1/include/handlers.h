#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdio.h>

typedef enum {
    OK = 0,
    INVALID_INPUT = 1,
} Status;

Status handle_h(const int x, int *output, int *count);
Status handle_p(const int x, int *is_prime);
Status handle_s(const int x, char *output);
Status handle_e(const int x, size_t output[10][10]);
Status handle_a(const int x, size_t *sum);
Status handle_f(const int x, size_t *factorial);

#endif
