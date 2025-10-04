#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlers.h"

int test_handler(int condition, char *msg) {
    if (condition == 0) {
        fprintf(stderr, "%s", msg);
        return -1;
    }

    return 0;
}

int test_handle_h(void) {
    int output[100];
    int count = 0;
    int status = handle_h(5, output, &count);
    if (test_handler(status == OK, "handle_h failed") != 0) { return -1; }
    if (test_handler(count == 20, "handle_h returned wrong count") != 0) { return -1; }
    if (test_handler(output[0] == 5, "handle_h first element wrong") != 0) { return -1; }
    if (test_handler(output[1] == 10, "handle_h second element wrong") != 0) { return -1; }
    printf("test_handle_h passed\n");
    return 0;
}

int test_handle_p(void) {
    int is_prime_result;
    int status = handle_p(7, &is_prime_result);
    if (test_handler(status == OK, "handle_p failed") != 0) { return -1; }
    if (test_handler(is_prime_result == 1, "handle_p: 7 should be prime") != 0) { return -1; }
    printf("test_handle_p passed\n");
    return 0;
}

int test_handle_s(void) {
    char buffer[17];
    int status = handle_s(255, buffer);
    if (test_handler(status == OK, "handle_s failed") != 0) { return -1; }
    if (test_handler(strcmp(buffer, "FF") == 0, "handle_s: 255 should be FF") != 0) { return -1; }
    printf("test_handle_s passed\n");
    return 0;
}

int test_handle_a(void) {
    size_t sum;
    int status = handle_a(10, &sum);
    if (test_handler(status == OK, "handle_a failed") != 0) { return -1; }
    if (test_handler(sum == 55, "handle_a: sum 1..10 should be 55") != 0) { return -1; }
    printf("test_handle_a passed\n");
    return 0;
}

int test_handle_f(void) {
    size_t result;
    int status = handle_f(5, &result);
    if (test_handler(status == OK, "handle_f failed") != 0) { return -1; }
    if (test_handler(result == 120, "handle_f: 5! should be 120") != 0) { return -1; }
    printf("test_handle_f passed\n");
    return 0;
}

int test_handle_e(void) {
    size_t table[10][10];
    int status = handle_e(2, table);
    if (test_handler(status == OK, "handle_e failed") != 0) { return -1; }
    if (test_handler(table[0][0] == 1, "handle_e: 1^1 should be 1") != 0) { return -1; }
    printf("test_handle_e passed\n");
    return 0;
}

int main(void) {
    if (test_handle_h() != 0) return 1;
    if (test_handle_p() != 0) return 1;
    if (test_handle_s() != 0) return 1;
    if (test_handle_a() != 0) return 1;
    if (test_handle_f() != 0) return 1;
    if (test_handle_e() != 0) return 1;

    printf("All tests passed!\n");
    return 0;
}
