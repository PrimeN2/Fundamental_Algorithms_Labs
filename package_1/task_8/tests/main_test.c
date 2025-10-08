#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "converter.h"

void test_convert_from_base(void) {
    long long result;
    int status;

    status = convert_from_base("10", 2, &result);
    assert(status == 0 && result == 2);

    status = convert_from_base("FF", 16, &result);
    assert(status == 0 && result == 255);

    status = convert_from_base("1A", 10, &result);
    assert(status == 3); 

    status = convert_from_base("10", 1, &result);
    assert(status == 1); 

    status = convert_from_base("10", 37, &result);
    assert(status == 1); 

    status = convert_from_base("", 10, &result);
    assert(status == 2); 

    status = convert_from_base("-10", 10, &result);
    assert(status == 0 && result == -10);

    status = convert_from_base("+10", 10, &result);
    assert(status == 0 && result == 10);

    status = convert_from_base("1234567890123456789", 10, &result);
    assert(status == 0); 
}

void test_convert_to_base(void) {
    char buffer[128];
    int status;

    status = convert_to_base(10, 2, buffer, sizeof(buffer));
    assert(status == 0 && strcmp(buffer, "1010") == 0);

    status = convert_to_base(255, 16, buffer, sizeof(buffer));
    assert(status == 0 && strcmp(buffer, "FF") == 0);

    status = convert_to_base(0, 10, buffer, sizeof(buffer));
    assert(status == 0 && strcmp(buffer, "0") == 0);

    status = convert_to_base(-10, 2, buffer, sizeof(buffer));
    assert(status == 0 && strcmp(buffer, "-1010") == 0);

    status = convert_to_base(LLONG_MIN, 10, buffer, sizeof(buffer));
    assert(status == 0); 

    status = convert_to_base(10, 1, buffer, sizeof(buffer));
    assert(status == 1); 

    status = convert_to_base(10, 37, buffer, sizeof(buffer));
    assert(status == 1); 

    char small_buffer[2];
    status = convert_to_base(10, 2, small_buffer, sizeof(small_buffer));
    assert(status == 2); 
}

int main(void) {
    test_convert_from_base();
    test_convert_to_base();
    printf("All tests passed.\n");
    return 0;
}
