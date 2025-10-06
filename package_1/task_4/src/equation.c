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

        x += 0.000001;

        if (x > 5) {
            fprintf(stderr, "Value was not found within range (Probably the step is too big).\n");
            return -1;
        }
    }

    *e = x;

    return 0;
}
