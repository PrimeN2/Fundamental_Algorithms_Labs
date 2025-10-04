#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "handler_q.h"
#include "handler_m.h"
#include "handler_t.h"
#include "handler_status.h"

static void test_handler_q(void) {
    double epsi = 1e-6;
    double solutions[6][2];
    int solutions_count = 0;

    HandlerStatus status = handle_q(epsi, 1.0, -2.0, 1.0, solutions, &solutions_count);
    assert(status == HANDLER_OK);
    assert(solutions_count > 0);

    assert(fabs(solutions[0][0] - 1.0) < epsi);
    assert(fabs(solutions[0][1] - 1.0) < epsi);

    printf("test_handler_q passed.\n");
}

static void test_handler_m(void) {
    int result;

    HandlerStatus status = handle_m(4, 2, &result);
    assert(status == HANDLER_OK);
    assert(result == 1);

    status = handle_m(5, 2, &result);
    assert(status == HANDLER_OK);
    assert(result == 0);
}

static void test_handler_t(void) {
    int result;

    HandlerStatus status = handle_t(1e-6, 3, 4, 5, &result);
    assert(status == HANDLER_OK);
    assert(result == 1);

    status = handle_t(1e-6, 5, 12, 13, &result);
    assert(status == HANDLER_OK);
    assert(result == 1);

    status = handle_t(1e-6, 2, 3, 4, &result);
    assert(status == HANDLER_OK);
    assert(result == 0);

    status = handle_t(1e-6, 3, 4, 7, &result);
    assert(status == HANDLER_INVALID_INPUT);
}

int main(void) {
    test_handler_q();
    test_handler_m();
    test_handler_t();

    return 0;
}
