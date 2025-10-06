#include <math.h>
#include <stdio.h>
#include "utils.h"

int calculate_e_limit(unsigned long long limit, double *e) {
    if (e == NULL) {
        fprintf(stderr, "Error: e is not passed.\n");
        return -1;
    }

    *e = pow((1.0 + 1.0 / (double)limit), (double)limit);

    return 0;
}

int calculate_pi_limit(unsigned long long limit, double *pi) {
    if (pi == NULL) {
        fprintf(stderr, "Error: pi is not passed.\n");
        return -1;
    }

    double log_up = 4.0 * (limit * log(2.0) + lgamma(limit + 1.0));
    double log_down = log((double)limit) + 2.0 * lgamma(2.0 * limit + 1.0);

    double log_pi = log_up - log_down;

    *pi = exp(log_pi);

    return 0;
}

int calculate_ln2_limit(unsigned long long limit, double *ln2) {
    if (ln2 == NULL) {
        fprintf(stderr, "Error: ln2 is not passed.\n");
        return -1;
    }

    *ln2 = limit * (pow(2.0, 1 / (double)limit) - 1);

    return 0;
}

int calculate_sqrt_x_limit(double epsi, double *sqrt_x) {
    if (sqrt_x == NULL) {
        fprintf(stderr, "Error: sqrt_x is not passed.\n");
        return -1;
    }

    double x = -0.5;
    double next;

    while (1) {
        next = x - (x * x) / 2.0 + 1.0;
        if (fabs(next - x) < epsi)
            break;
        x = next;
    }

    *sqrt_x = x;

    return 0;
}

static double C(unsigned long long m, unsigned long long k) {
    double result = 1.0;

    for (unsigned long long i = 1; i <= k; i++) {
        result *= (double)(m - i + 1) / i;
    }

    return result;
}

int calculate_gamma_limit(unsigned long long limit, double *gamma) {
    if (gamma == NULL) {
        fprintf(stderr, "Error: gamma is not passed.\n");
        return -1;
    }

    *gamma = 0.0;

    for (unsigned long long k = 1; k <= limit; k++) {
        int sign = k % 2 == 0 ? 1 : -1;
        *gamma += C(limit, k) * ((double)sign / (double)k) * lgamma((double)(k + 1));
    }

    return 0;
}
