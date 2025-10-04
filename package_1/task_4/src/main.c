#include <stdio.h>
#include "series_sum.h"
#include "limit.h"

int main(void) {
    double epsi;

    printf("Enter epsilon: ");
    if (scanf("%lf", &epsi) < 0) {
        fprintf(stderr, "Error: Invalid epsilon.\n");
        return 1;
    } 

    double e_series_sum;
    if (calculate_e_series(epsi, &e_series_sum) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("e by summarise of a series with approximation of %lf is equal to %lf\n", epsi, e_series_sum);

    double pi_series_sum;
    if (calculate_pi_series(epsi, &pi_series_sum) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("pi by summarise of a series with approximation of %lf is equal to %lf\n", epsi, pi_series_sum);

    double ln2_series_sum;
    if (calculate_ln2_series(epsi, &ln2_series_sum) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("ln2 by summarise of a series with approximation of %lf is equal to %lf\n", epsi, ln2_series_sum);

    double sqrt_x_series_sum;
    if (calculate_sqrt_x_series(epsi, &sqrt_x_series_sum) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("sqrt x by summarise of a series with approximation of %lf is equal to %lf\n", epsi, sqrt_x_series_sum);

    double gamma_series_sum;
    if (calculate_gamma_series(epsi, &gamma_series_sum) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("gamma by summarise of a series with approximation of %lf is equal to %lf\n", epsi, gamma_series_sum);

    unsigned long long limit = 5;

    double e_limit;
    if (calculate_e_limit(limit, &e_limit) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("e calculated by limit with n = %llu is equal to %lf\n", limit, e_limit);

    double pi_limit;
    if (calculate_pi_limit(limit, &pi_limit) != 0) {
        fprintf(stderr, "Error: An error occured.\n");
        return 1;
    }
    printf("pi calculated by limit with n = %llu is equal to %lf\n", limit, pi_limit);
}
