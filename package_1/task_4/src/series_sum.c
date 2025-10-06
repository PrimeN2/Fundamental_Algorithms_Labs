#include <stdio.h>
#include <math.h>
#include "utils.h"

int calculate_e_series(double epsi, double *e) {
    if (e == NULL) {
        fprintf(stderr, "Error: e is not passed.\n");
        return -1;
    }

    (*e) = 1; 
    unsigned int n = 1;

    while (1) {
        double term = 1.0 / factorial(n);

        if (term < epsi) {
            break;
        }

        *e += term;
        n++;
    }

    return 0;
}

int calculate_pi_series(double epsi, double *pi) {
    if (pi == NULL) {
        fprintf(stderr, "Error: pi is not passed.\n");
        return -1;
    }

    *pi = 0;
    double term;
    unsigned int n = 1;

    while (1) {
        int sign = (n % 2 == 0) ? -1 : 1;
        term = (double)sign / (2 * n - 1);

        if (fabs(term) < epsi) {
            break;
        }

        *pi += term;
        n++;
    }

    *pi *= 4;

    return 0;
}

int calculate_ln2_series(double epsi, double *ln2) {
    if (ln2 == NULL) {
        fprintf(stderr, "Error: ln2 is not passed.\n");
        return -1;
    }

    double term;
    unsigned int n = 1;
    *ln2 = 0;

    while (1) {
        int sign = (n % 2 == 0) ? -1 : 1;
        term = (double)sign / n;

        if (fabs(term) < epsi) {
            break;
        }

        *ln2 += term;
        n++;
    }

    return 0;
}

int calculate_sqrt_x_series(double epsi, double *sqrt_x) {
    if (sqrt_x == NULL) {
        fprintf(stderr, "Error: sqrt x is not passed.\n");
        return -1;
    }

    unsigned int k = 2;
    double term;
    *sqrt_x = 1;

    while (1) {
        term = pow(2.0, pow(2.0, -(double)k));

        if (fabs(term) < epsi + 1) {
            break;
        }

        *sqrt_x *= term;
        k++;
    }

    return 0;
}

int calculate_gamma_series(double epsi, double *gamma) {
    if (gamma == NULL) {
        fprintf(stderr, "Error: gamma is not passed.\n");
        return -1;
    }

    unsigned int k = 2;
    double term;
    *gamma = 0;

    while (1) {
        int root = (int)sqrt((double)k);
        term = 1.0 / (root * root) - 1.0 / k;

        if (k > 500 && fabs(term) < epsi) {
            break;
        }

        *gamma += term;
        k++;
    }

    *gamma -= M_PI * M_PI / 6.0;

    return 0;
}
