#ifndef INTEGRALS_H
#define INTEGRALS_H

#include <stdio.h>

typedef enum {
    SUCCESS = 0,
    INVALID_ARGUMENT,
    MEMORY_ALLOCATION_FAILED,
    NUMERICAL_CONVERGENCE_FAILED,
    DOMAIN_ERROR
} StatusCode;

StatusCode compute_integral_a(double epsilon, double *result);
StatusCode compute_integral_b(double epsilon, double *result);
StatusCode compute_integral_c(double epsilon, double *result);
StatusCode compute_integral_d(double epsilon, double *result);

#endif
