#include <stdio.h>
#include "custom_print.h"

int main(void) {
    overfprintf(stdout, "Char: %c\n", 'A');
    overfprintf(stdout, "Int: %d\n", 123);
    overfprintf(stdout, "Roman: %Ro\n", 2024);
    overfprintf(stdout, "Fib: %Zr\n", 13);
    overfprintf(stdout, "Hex lower: %Cv\n", 255, 16);
    overfprintf(stdout, "Hex upper: %CV\n", 255, 16);
    overfprintf(stdout, "Str to dec: %to\n", "FF", 16);
    overfprintf(stdout, "Str to dec upper: %TO\n", "ff", 16);
    overfprintf(stdout, "Int dump: %mi\n", -12345);
    overfprintf(stdout, "Uint dump: %mu\n", 12345);
    overfprintf(stdout, "Float dump: %mf\n", 3.14f);
    overfprintf(stdout, "Double dump: %md\n", 3.14159);

    char buffer[1024];
    oversprintf(buffer, "Sprintf: %c %d %Ro", 'X', 42, 42);
    printf("Sprintf result: %s\n", buffer);

    return 0;
}
