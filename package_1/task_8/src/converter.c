#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

static int char_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return -1;
}

static char digit_to_char(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    if (digit >= 10 && digit <= 35) {
        return 'A' + (digit - 10);
    }
    return '\0';
}

int convert_from_base(const char *str, int base, long long *result) {
    if (!str || !result || base < 2 || base > 36) {
        return 1;
    }

    const char *p = str;
    int sign = 1;

    if (*p == '-') {
        sign = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }

    if (*p == '\0') {
        return 2;
    }

    long long value = 0;
    while (*p) {
        int digit = char_to_digit(*p);
        if (digit < 0 || digit >= base) {
            return 3;
        }

        if (value > (LLONG_MAX - digit) / base) {
            return 4;
        }

        value = value * base + digit;
        p++;
    }

    if (sign == -1) {
        if (value > LLONG_MAX) {
            return 4;
        }
        value = -value;
    }

    *result = value;
    return 0;
}

int convert_to_base(long long num, int base, char *buffer, size_t buffer_size) {
    if (!buffer || buffer_size == 0 || base < 2 || base > 36) {
        return 1;
    }

    if (num == 0) {
        if (buffer_size < 2) {
            return 2;
        }
        buffer[0] = '0';
        buffer[1] = '\0';
        return 0;
    }

    int sign = 0;
    if (num < 0) {
        sign = -1;
        num = -num;
    }

    char temp[128];
    int idx = 0;

    while (num > 0) {
        if (idx >= 127) {
            return 3;
        }
        int remainder = num % base;
        temp[idx++] = digit_to_char(remainder);
        num /= base;
    }

    if (idx == 0) {
        if (buffer_size < 2) {
            return 2;
        }
        buffer[0] = '0';
        buffer[1] = '\0';
        return 0;
    }

    size_t total_len = idx + (sign ? 1 : 0);
    if (total_len + 1 > buffer_size) {
        return 2;
    }

    int pos = 0;
    if (sign == -1) {
        buffer[pos++] = '-';
    }

    for (int i = idx - 1; i >= 0; i--) {
        buffer[pos++] = temp[i];
    }
    buffer[pos] = '\0';

    return 0;
}
