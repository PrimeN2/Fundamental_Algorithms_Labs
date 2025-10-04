#include "handler_status.h"

HandlerStatus handle_m(long num_1, long num_2, int *result) {
    if (num_1 % num_2 == 0) {
        *result = 1;
    } else {
        *result = 0;
    }

    return HANDLER_OK;
}
