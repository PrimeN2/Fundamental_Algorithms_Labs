#include <stdio.h>
#include <string.h>
#include "binary_conversion.h"

void test_convert_to_base(int num, int base_pow, const char* expected) {
    char buffer[30];
    convert_to_base(buffer, num, base_pow);

    printf("num: %d, base_pow: %d => %s | Expected: %s | %s\n",
           num, base_pow, buffer, expected,
           strcmp(buffer, expected) == 0 ? "PASS" : "FAIL");
}

int main(void) {
    printf("Running tests...\n");

    test_convert_to_base(7, 1, "111");      
    test_convert_to_base(8, 1, "1000");     
    test_convert_to_base(0, 1, "0");
    test_convert_to_base(15, 2, "33");      
    test_convert_to_base(255, 4, "FF");
    test_convert_to_base(10, 3, "12");      
    test_convert_to_base(-10, 4, "-A");

    printf("Tests completed.\n");
    return 0;
}
