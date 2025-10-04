#include <math.h>
#include "utils.h"

int calculate_e_limit(unsigned long long limit, double *e) {
    *e = pow((1.0 + 1.0 / (double)limit), (double)limit);

    return 0;
}

int calculate_pi_limit(unsigned long long limit, double *pi) {
    *pi = (pow((pow(2.0, (double)limit) * (double)factorial(limit)), 4.0)) / 
        (limit * pow((double)factorial(2.0 * limit), 2.0));

    return 0;
}

// int calculate_ln2_limit(unsigned long long limit, double *ln2);
// int calculate_sqrt_x_limit(unsigned long long limit, double *sqrt_x);
// int calculate_gamma_limit(unsigned long long limit, double *gamma);
