#include "integrals.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main(void) {
    double result;
    StatusCode status;

    status = compute_integral_a(1e-6, &result);
    assert(status == SUCCESS);
    assert(!isnan(result) && !isinf(result));

    status = compute_integral_b(1e-6, &result);
    assert(status == SUCCESS);
    assert(!isnan(result) && !isinf(result));

    status = compute_integral_c(1e-6, &result);
    assert(status == SUCCESS);
    assert(!isnan(result) && !isinf(result));

    status = compute_integral_d(1e-6, &result);
    assert(status == SUCCESS);
    assert(!isnan(result) && !isinf(result));

    status = compute_integral_a(-1.0, &result);
    assert(status == INVALID_ARGUMENT);

    status = compute_integral_a(1e-6, NULL);
    assert(status == INVALID_ARGUMENT);

    printf("All tests passed.\n");
    return 0;
}
