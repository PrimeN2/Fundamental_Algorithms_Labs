#include <stdio.h>

static int add_binary(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

static int substract_binary(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    
    return a;
}

static int int_divide_pot_binary(int num, int pow) { // pot == power of two
    return num >> pow;
}

static int divide_for_carry_pot_binary(int num, int pow) {
    int tmp = num >> pow;
    tmp = tmp << pow;

    return num ^ tmp;
}   

static int reverse_binary(int num) {
    num = ~num;
    num = add_binary(num, 1);

    return num;
}

int convert_to_base(char result[], int num, int base_pow) { // DOC: base_rate = {1; 5}
    if (base_pow > 5 || base_pow < 1) {
        perror("Error: Wrong base power.\n");
        return -1;
    }

    const char digits[] = "0123456789ABCDEF";

    int base = 1 << base_pow;

    int sign = 1;
    int index = 0;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return 0;
    }

    if (num < 0) {
        sign = -1;
        result[0] = '-';
        index = add_binary(index, 1);
        num = reverse_binary(num);
    }

    int original_index = index;

    while (num > 0) {
        int carry = divide_for_carry_pot_binary(num, base_pow);
        result[index] = digits[carry];
        index = add_binary(index, 1);
        num = int_divide_pot_binary(num, base_pow);
    }

    result[index] = '\0';

    int start = (result[0] == '-') ? 1 : 0;
    int end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start = add_binary(start, 1);
        end = substract_binary(end, 1);
    }

    return 0;
}

int main(void) {
    char buffer[30];
    convert_to_base(buffer, -7, 1);
    printf("%s\n", buffer);
    return 0;
}