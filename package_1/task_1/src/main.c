#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handlers.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "In %s only number and 1 flag are allowed and required\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    if (argv[1][0] != '0' && x == 0) {
        fprintf(stderr, "Not a valid number %s.\n", argv[1]);
        return 1;
    }

    if ((argv[2][0] != '-' && argv[2][0] != '/') || strlen(argv[2]) != 2) {
        fprintf(stderr, "Flag must start with '-' or '/' and consist of one character.\n");
        return 1;
    }

    char flag = argv[2][1];

    Status status = OK; 

    switch (flag) {
        case 'h': {
            int multiples[100];
            int count = 0;
            status = handle_h(x, multiples, &count);

            if (status == OK) {
                if (count == 0) {
                    printf("There's no natural multiples to %d, that less or equal to 100\n", x);
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("%d ", multiples[i]);
                    }
                    printf("\n");
                }
            }
            break;
        }
        case 'p': {
            int is_prime;
            status = handle_p(x, &is_prime);

            if (status == INVALID_INPUT) {
                fprintf(stderr, "Cannot check a negative number for prime condition\n");
                return 1;
            } else {
                if (is_prime) {
                    printf("Number %d is prime number\n", x);
                } else {
                    printf("Number %d is composite number\n", x);
                }
            }
            break;
        }
        case 's': {
            char hex_num[17];
            status = handle_s(x, hex_num);
            if (status == OK) {
                printf("Hex digits of %d: ", x);
                for (int i = 0; hex_num[i] != '\0'; i++) {
                    printf("%c ", hex_num[i]);
                }
                printf("\n");
            } else {
                fprintf(stderr, "Do not handle negative numbers\n");
            }
            break;
        }
        case 'e': {
            size_t pow_table[10][10];
            status = handle_e(x, pow_table);

            if (status == OK) {
                printf("Powers table for base 1-10 with exponential from 0 to %d: ", x);
                for (int base = 1; base <= 10; base++) {
                    printf("Base %d: ", base);
                    for (int exp = 1; exp <= x; exp++) {
                        printf("%zu ", pow_table[base - 1][exp - 1]);
                    }
                    printf("\n");
                }
            } else {
                fprintf(stderr, "Number should be in range 1 <= x <= 10\n");
                return 1;
            }
            break;
        }
        case 'a': { 
            size_t sum = 0;
            status = handle_a(x, &sum);

            if (status == OK) {
                printf("Summarise of each natural number from 1 to %d is %zu\n", x, sum);
            } else {
                fprintf(stderr, "x must equal 1 or more\n");
                return 1;
            }
            break;
        }
        case 'f': {
            size_t factorial;
            status = handle_f(x, &factorial);

            if (status == OK) {
                printf("Factorial for %d is %zu\n", x, factorial);
            } else {
                fprintf(stderr, "x must be positive or zero\n");
                return 1;
            }
            break;
        }
        default: {
            fprintf(stderr, "Invalid flag\n");
            return 1;
        }
    }

    return 0;
}

