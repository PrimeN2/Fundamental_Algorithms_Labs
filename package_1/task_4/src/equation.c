#include <stdio.h>
#include <math.h>

int calculate_e_equation(double epsi, double *e) {
    if (e == NULL) {
        fprintf(stderr, "No e were passed.\n");
        return -1;
    }

    double x = 1.0;

    // ln(x) = 1 => ln(x) - 1 = 0
    while(1) {
        if (fabs(log(x) - 1) < epsi) {
            break;
        }

        x += 1e-6;

        if (x > 5) {
            fprintf(stderr, "Value was not found within range (Probably the step is too big).\n");
            return -1;
        }
    }

    *e = x;

    return 0;
}

int calculate_pi_equation(double epsi, double *pi) {
    if (pi == NULL) {
        fprintf(stderr, "No pi was passed.\n");
        return -1;
    }

    double x = 1.0;

    while (1) {
        if (fabs(cos(x) + 1) < epsi) {
            break;
        }

        x += 1e-6;

        if (x > 5) {
            fprintf(stderr, "No value find within range (Probably delta is too big).\n");
            return -1;
        }
    }

    *pi = x;

    return 0;
}

int calculate_ln2_equation(double epsi, double *ln2) {
    if (ln2 == NULL) {
        fprintf(stderr, "ln2 wasn't passed.\n");
        return -1;
    }

    double x = 0.0;

    while (1) {
        if (fabs(pow(M_E, x) - 2) < epsi) {
            break;
        }

        x += 1e-6;

        if (x >= 1) {
            fprintf(stderr, "No value find within range (Probably delta is too big).\n");
            return -1;
        }
    }

    *ln2 = x;

    return 0;
}

int calculate_sqrt_x_equation(double epsi, double *sqrt_x) {
    if (sqrt_x == NULL) {
        fprintf(stderr, "sqrt_x wasn't passed.\n");
        return -1;
    }

    double x = 1.0;

    while (1) {
        if (fabs(pow(x, 2) - 2) < epsi) {
            break;
        }

        x += 1e-6;

        if (x >= 2) {
            fprintf(stderr, "No value find within range (Probably delta is too big).\n");
            return -1;
        }
    }

    *sqrt_x = x;

    return 0;
}

static int is_prime(unsigned long long n) {
    if (n < 2) {
        return 0;
    }

    if (n == 2 || n == 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (unsigned long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

int calculate_gamma_equation(unsigned long long limit, long double *gamma) {
    if (gamma == NULL) {
        fprintf(stderr, "sqrt_x wasn't passed.\n");
        return -1;
    }

    unsigned long long p = 2;
    long double log_term = 0.0;
    unsigned long long last_prime = 0;
    *gamma = 1.0;

    for (; p < limit; p++) {
        if (is_prime(p)) {
            log_term += logl((p - 1.0L) / (long double)p);
            last_prime = p;
        }
    }

    long double log_p = logl((long double)last_prime);
    *gamma = -(logl(log_p) + log_term);

    return 0;
}
