#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "primes.h"

static int parse_input(const char *input, unsigned int *parsed_input) {
    if (input == NULL || *input == '\0') {
        return -1;
    }
    
    char *endptr;
    long value = strtol(input, &endptr, 10);

    if ((*endptr != '\0' && *endptr != '\n') || value < 0 || value > UINT_MAX) {
        return -1;
    }

    *parsed_input = (unsigned int)value;
    return 0;
}

int main(void) {
    char buffer[256];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Failed to read number of the requests.\n");
        return 1;
    }
    
    unsigned int T;
    if (parse_input(buffer, &T) != 0) {
        fprintf(stderr, "Cannot parse the number of requests.\n");
        return 1;
    }

    for (unsigned int i = 0; i < T; i++) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Erorr occured while reading request: %u.\n", i + 1);
            return 1;
        }

        unsigned int n;
        if (parse_input(buffer, &n) != 0) {
            fprintf(stderr, "Error occered while parsing request: %u.\n", i + 1);
            return 1;
        }

        unsigned int result;
        PrimeStatus status = find_nth_prime(n, &result);

        switch (status) {
            case PRIME_OK:
                printf("%u\n", result);
                break;
            case PRIME_INVALID_INPUT:
                fprintf(stderr, "Invalid input for request %u.\n", i + 1);
                return 1;
            case PRIME_OVERFLOW_ERROR:
                fprintf(stderr, "Number for request %u is too big", i + 1);
                return 1;
            default:
                fprintf(stderr, "An unkown error occured for request %u", i + 1);
                return 1;
        }
    }

    return 0;
}
