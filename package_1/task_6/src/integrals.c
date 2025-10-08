#include "integrals.h"
#include <stdlib.h>
#include <math.h>

static double func_a(double x) {
    if (x == 0.0) {
        return 1.0;
    }
    return log(1.0 + x) / x;
}

static double func_b(double x) {
    return exp(-x * x / 2.0);
}

static double func_c(double x) {
    if (x == 1.0) {
        return 0.0;
    }
    return log(1.0 / (1.0 - x));
}

static double func_d(double x) {
    if (x == 0.0) {
        return 0.0;
    }
    return pow(x, x);
}

static double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

static StatusCode adaptive_trapezoidal(double (*f)(double), double a, double b, double epsilon, double *result) {
    if (epsilon <= 0.0) {
        return INVALID_ARGUMENT;
    }

    int n = 1;
    double prev_result = 0.0;
    double current_result = trapezoidal_rule(f, a, b, n);

    while (n < 10000000) {  
        n *= 2;
        prev_result = current_result;
        current_result = trapezoidal_rule(f, a, b, n);

        if (fabs(current_result - prev_result) < epsilon) {
            *result = current_result;
            return SUCCESS;
        }
    }

    *result = current_result; 
    return SUCCESS;  
}

StatusCode compute_integral_a(double epsilon, double *result) {
    if (result == NULL) {
        return INVALID_ARGUMENT;
    }
    return adaptive_trapezoidal(func_a, 0.0, 1.0, epsilon, result);
}

StatusCode compute_integral_b(double epsilon, double *result) {
    if (result == NULL) {
        return INVALID_ARGUMENT;
    }
    return adaptive_trapezoidal(func_b, 0.0, 1.0, epsilon, result);
}

StatusCode compute_integral_c(double epsilon, double *result) {
    if (result == NULL) {
        return INVALID_ARGUMENT;
    }
    return adaptive_trapezoidal(func_c, 0.0, 1.0, epsilon, result);
}

StatusCode compute_integral_d(double epsilon, double *result) {
    if (result == NULL) {
        return INVALID_ARGUMENT;
    }
    return adaptive_trapezoidal(func_d, 0.0, 1.0, epsilon, result);
}
