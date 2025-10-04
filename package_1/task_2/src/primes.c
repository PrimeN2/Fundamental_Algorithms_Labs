#include <stdio.h>
#include <limits.h>
#include "primes.h"

static int is_prime(unsigned int n) {
    if (n < 2) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    for (unsigned int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

PrimeStatus find_nth_prime(unsigned int n, unsigned int *result) {
    if (n == 0 || result == NULL) {
        fprintf(stderr, "n is zero or result is not set");
        return PRIME_INVALID_INPUT;
    }

    unsigned int i = 2;
    unsigned int counter = 0;
    while (counter < n) {
        if (is_prime(i)) {
            counter++;

            if (counter == n) {
                *result = i;
                return PRIME_OK;
            }
        }

        if (i >= (UINT_MAX - 2)) {
            fprintf(stderr, "n is too big of a number");
            return PRIME_OVERFLOW_ERROR;
        }

        i++;
    }

    return PRIME_INVALID_INPUT;
}
