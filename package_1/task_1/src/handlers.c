#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "handlers.h"

Status handle_h(const int x, int *output, int *count) {
    *count = 0;

    if (x > 100) {
        return OK;
    }

    for (int i = x; i <= 100; i += x) {
        output[*count] = i;
        (*count)++;
    }

    return OK;
}

Status handle_p(const int x, int *is_prime) {
    if (x < 0) {
        return INVALID_INPUT;
    }

    if (x < 2) {
        *is_prime = 0;
        return OK;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            *is_prime = 0;
            return OK;
        }        
    }
    *is_prime = 1;

    return OK;
}

Status handle_s(const int x, char *output) {    
    if (x < 0) {
        return INVALID_INPUT;
    }
    if (x == 0) {
        output[0] = '0';
        output[1] = '\0';

        return OK;
    }

    int orig = x;
    int idx = 0;
    char tmp[17];

    while (orig > 0) {
        int digit = orig % 16;
        if (digit < 10) {
            tmp[idx] = '0' + digit;
        } else {
            tmp[idx] = 'A' + digit - 10;
        }
        idx++;
        orig /= 16;
    }

    for (int i = 0; i < idx; i++) {
        output[i] = tmp[idx - i - 1];
    }
    output[idx] = '\0';

    return OK;
}

Status handle_e(const int x, size_t output[10][10]) {
    if (x > 10 || x < 1) {
        return INVALID_INPUT;
    }

    for (int base = 1; base <= 10; base++) {
        for (int exp = 1; exp <= x; exp++) {
            output[base - 1][exp - 1] = pow(base, exp);
        }
    }

    return OK;
}

Status handle_a(const int x, size_t *sum) {
    if (x < 1) {
        return INVALID_INPUT;
    }

    *sum = x * (x + 1) / 2;
    
    return OK;
}

Status handle_f(const int x, size_t *factorial) {
    if (x < 0) {
        return INVALID_INPUT;
    }
    *factorial = 1;

    for (int i = 2; i <= x; i++) {
        (*factorial) *= i;
    }

    return OK;
}
