#include <stdio.h>

int add_binary(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

void convert_to_base(int num, char base_rate) { // DOC: base_rate = {1; 5}
    const char digits[] = "0123456789ABCDEF";

    int base = 1 << base_rate;
    int *out;

    int sign = 1;
    char result[30];
    int index = 0;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    if (num < 0) {
        sign = -1;
        result[0] = '-';
        index++;
    }

    num *= sign;

    while (num > 0) {
        result[index] = digits[num % base];
        index++;
        num /= base;
    }

    result[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }
}


void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main(void) {
    printBinary(2 << 3);
    printf("%d\n", 2 << 3);
    printBinary(4);
    printBinary(8);

    return 0;
}