#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "handler_status.h"

static bool double_equal(double a, double b, double epsilon) {
    return fabs(a - b) <= epsilon;
}

static int solve_square_equation(double epsi, double a, double b, double c, double *roots) {
    if (roots == NULL) {
        fprintf(stderr, "The pointer is NULL.\n");
        return -1;
    }

    if (double_equal(a, 0.0, epsi)) {
        return 1;
    }

    double D = b * b - 4 * a * c;
    
    if (D < -epsi) {
        return 1;
    } else if (D <= epsi) {
        roots[0] = (-b) / (2 * a);
        roots[1] = roots[0];
        return 0;
    } else {
        roots[0] = (-b - sqrt(D)) / (2 * a);
        roots[1] = (-b + sqrt(D)) / (2 * a);
        return 0;
    }

}

static void generate_permutations(double ks[3], double perms[6][3]) {
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            for (int k = 0; k < 3; k++) {
                if (k == i || k == j) continue;
                perms[idx][0] = ks[i];
                perms[idx][1] = ks[j];
                perms[idx][2] = ks[k];
                idx++;
            }
        }
    }
}

HandlerStatus handle_q(double epsi, double k_1, double k_2, double k_3, double solutions[6][2], int *soulutions_count) {
    double ks[3] = {k_1, k_2, k_3};
    double perms[6][3];
    generate_permutations(ks, perms);
    
    double roots[2];
    int pos = 0;
    *soulutions_count = 0;

    for (int i = 0; i < 6; i++) {
        double a_i = perms[i][0];
        double b_i = perms[i][1];
        double c_i = perms[i][2];

        int roots_status = solve_square_equation(epsi, a_i, b_i, c_i, roots);

        if (roots_status == -1) {
            fprintf(stderr, "Roots not passed.\n");
            return -1;
        } else if (roots_status == 0) {
            solutions[pos][0] = roots[0];
            solutions[pos][1] = roots[1];
            pos++;
            *soulutions_count += 1;
        }
    }

    return HANDLER_OK;
}
