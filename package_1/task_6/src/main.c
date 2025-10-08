#include "integrals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <epsilon>\n", argv[0]);
        return 1;
    }

    char *endptr;
    double epsilon = strtod(argv[1], &endptr);
    if (*endptr != '\0' || epsilon <= 0.0) {
        fprintf(stderr, "Error: epsilon must be a positive real number.\n");
        return 1;
    }

    double result_a, result_b, result_c, result_d;
    StatusCode status;

    status = compute_integral_a(epsilon, &result_a);
    if (status != SUCCESS) {
        fprintf(stderr, "Error computing integral a\n");
        return 1;
    }

    status = compute_integral_b(epsilon, &result_b);
    if (status != SUCCESS) {
        fprintf(stderr, "Error computing integral b\n");
        return 1;
    }

    status = compute_integral_c(epsilon, &result_c);
    if (status != SUCCESS) {
        fprintf(stderr, "Error computing integral c\n");
        return 1;
    }

    status = compute_integral_d(epsilon, &result_d);
    if (status != SUCCESS) {
        fprintf(stderr, "Error computing integral d\n");
        return 1;
    }

    printf("Integral a: %.10f\n", result_a);
    printf("Integral b: %.10f\n", result_b);
    printf("Integral c: %.10f\n", result_c);
    printf("Integral d: %.10f\n", result_d);

    return 0;
}
