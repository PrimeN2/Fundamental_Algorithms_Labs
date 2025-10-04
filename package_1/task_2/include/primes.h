#ifndef PRIMES_H
#define PRIMES_H

typedef enum {
    PRIME_OK = 0,
    PRIME_INVALID_INPUT,
    PRIME_OVERFLOW_ERROR
} PrimeStatus;

PrimeStatus find_nth_prime(unsigned int n, unsigned int *result);

#endif
