#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "series_sum.h"
#include "limit.h"
#include "equation.h"

#define EPS 1e-3 

int main(void) {
    double epsi = 0.000010;
    unsigned long long limit = 30;
    unsigned long long limit_for_gamma = 100000ULL;

    double result;
    long double long_result;

    assert(calculate_e_series(epsi, &result) == 0);
    assert(fabs(result - 2.718) < EPS);

    assert(calculate_pi_series(epsi, &result) == 0);
    assert(fabs(result - 3.142) < EPS);

    assert(calculate_ln2_series(epsi, &result) == 0);
    assert(fabs(result - 0.693) < EPS);

    assert(calculate_sqrt_x_series(epsi, &result) == 0);
    assert(fabs(result - 1.414) < EPS);

    assert(calculate_gamma_series(epsi, &result) == 0);
    assert(fabs(result - 0.490) < EPS);

    assert(calculate_e_limit(limit, &result) == 0);
    assert(fabs(result - 2.674) < EPS);

    assert(calculate_pi_limit(limit, &result) == 0);
    assert(fabs(result - 3.168) < EPS);

    assert(calculate_ln2_limit(limit, &result) == 0);
    assert(fabs(result - 0.701) < EPS);

    assert(calculate_sqrt_x_limit(epsi, &result) == 0);
    assert(fabs(result - 1.414) < EPS);

    assert(calculate_gamma_limit(limit, &result) == 0);
    assert(fabs(result - 0.570) < EPS);

    assert(calculate_e_equation(epsi, &result) == 0);
    assert(fabs(result - 2.718) < EPS);

    assert(calculate_pi_equation(epsi, &result) == 0);
    assert(fabs(result - 3.137) < EPS);

    assert(calculate_ln2_equation(epsi, &result) == 0);
    assert(fabs(result - 0.693) < EPS);

    assert(calculate_sqrt_x_equation(epsi, &result) == 0);
    assert(fabs(result - 1.414) < EPS);

    assert(calculate_gamma_equation(limit_for_gamma, &long_result) == 0);
    assert(fabsl(long_result - 0.577L) < EPS);

    printf("All rounded numerical tests passed successfully.\n");
    return 0;
}
