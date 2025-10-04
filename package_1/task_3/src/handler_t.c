#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "handler_status.h"

static void swap_d(double *a, double *b) {
    double tmp = *b;
    *b = *a;
    *a = tmp;
}


static bool check__sqr_triangle(double a, double b, double c, double epsi) {
    if (c > b) {
        swap_d(&c, &b);
    }

    if (b > a) {
        swap_d(&b, &a);
    }

    if (fabs(a * a - (b * b + c * c)) < epsi) {
        return true;
    }
    else {
        return false;
    }
}

HandlerStatus handle_t(double epsi, double a, double b, double c, int *result) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return HANDLER_INVALID_INPUT; 
    }

    if (a + b <= c + epsi || a + c <= b + epsi || b + c <= a + epsi) {
        return HANDLER_INVALID_INPUT; 
    }

    if (check__sqr_triangle(a, b, c, epsi)){
        *result = 1;
    } else {
        *result = 0;
    }

    return HANDLER_OK;
}
