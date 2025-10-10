#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "converter.h"

int main(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    int base;
    if (scanf("%d", &base) != 1) {
        fprintf(stderr, "Error: failed to read base.\n");
        return 2;
    }

    if (base < 2 || base > 36) {
        fprintf(stderr, "Error: base must be in range [2..36].\n");
        return 3;
    }

    char input[1024];
    long long max_abs = LLONG_MIN;
    char max_str[1024] = "";
    long long original_num;

    int found = 0;

    while (scanf("%1023s", input) == 1) {
        if (strcmp(input, "Stop") == 0) {
            break;
        }

        long long num;
        int status = convert_from_base(input, base, &num);
        if (status != 0) {
            fprintf(stderr, "Error: invalid number '%s' for base %d.\n", input, base);
            continue;
        }

        long long abs_num = num < 0 ? -num : num;
        if (!found || abs_num > max_abs) {
            max_abs = abs_num;
            original_num = num;
            strcpy(max_str, input);
            found = 1;
        }
    }

    if (!found) {
        fprintf(stderr, "Error: no valid numbers entered.\n");
        return 4;
    }

    int status;

    char result9[1024], result18[1024], result27[1024], result36[1024];

    status = convert_to_base(original_num, 9, result9, sizeof(result9));
    if (status != 0) {
        fprintf(stderr, "Error: conversion to base 9 failed.\n");
        return 6;
    }

    status = convert_to_base(original_num, 18, result18, sizeof(result18));
    if (status != 0) {
        fprintf(stderr, "Error: conversion to base 18 failed.\n");
        return 7;
    }

    status = convert_to_base(original_num, 27, result27, sizeof(result27));
    if (status != 0) {
        fprintf(stderr, "Error: conversion to base 27 failed.\n");
        return 8;
    }

    status = convert_to_base(original_num, 36, result36, sizeof(result36));
    if (status != 0) {
        fprintf(stderr, "Error: conversion to base 36 failed.\n");
        return 9;
    }

    printf("%lld\n", original_num);
    printf("%s\n", result9);
    printf("%s\n", result18);
    printf("%s\n", result27);
    printf("%s\n", result36);

    return 0;
}
