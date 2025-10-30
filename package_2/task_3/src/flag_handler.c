#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "flag_handler.h"

static int to_base_str(long long num, int base, char *buf, int uppercase) {
    if (base < 2 || base > 36) return -1;

    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    if (uppercase) {
        for (int i = 0; digits[i]; i++) {
            digits[i] = toupper(digits[i]);
        }
    }

    if (num == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }

    int neg = 0;
    if (num < 0 && base == 10) {
        neg = 1;
        num = -num;
    }

    char temp[65];
    int i = 0;
    while (num != 0) {
        temp[i++] = digits[num % base];
        num /= base;
    }

    if (neg) temp[i++] = '-';

    int len = i;
    for (int j = 0; j < len; j++) {
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';

    return len;
}

int handle_c(char c, sbuf_t *buffer) {
    if (!buffer) return -1;
    return sbuf_add(buffer, c);
}

int handle_d(int n, sbuf_t *buffer) {
    if (!buffer) return -1;

    if (n == 0) {
        return sbuf_add(buffer, '0');
    }

    int neg = 0;
    unsigned int num = n;
    if (n < 0) {
        neg = 1;
        num = -(unsigned int)n;  
    }

    char rev_num[12];
    int num_len = 0;

    while (num != 0) {
        rev_num[num_len++] = (num % 10) + '0';
        num /= 10;
    }

    if (neg) {
        if (sbuf_add(buffer, '-') != 0) return -1;
    }

    for (int i = num_len - 1; i >= 0; --i) {
        if (sbuf_add(buffer, rev_num[i]) != 0) return -1;
    }

    return 0;
}

int handle_Ro(int n, sbuf_t *buffer) {
    if (!buffer || n <= 0 || n > 3999) return -1;

    const char *romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int i = 0;

    while (n > 0) {
        while (n >= values[i]) {
            const char *r = romans[i];
            while (*r) {
                if (sbuf_add(buffer, *r) != 0) return -1;
                r++;
            }
            n -= values[i];
        }
        i++;
    }

    return 0;
}

int handle_Zr(unsigned int n, sbuf_t *buffer) {
    if (!buffer) return -1;
    if (n == 0) {
        if (sbuf_add(buffer, '0') != 0) return -1;
        return 0;
    }

    int fib[50];
    fib[0] = 1;
    fib[1] = 2;
    int idx = 2;
    while (fib[idx - 1] <= ((int)n)) {
        fib[idx] = fib[idx - 1] + fib[idx - 2];
        idx++;
    }

    int written = 0;
    for (int i = idx - 1; i >= 0; --i) {
        if (((int)n) >= fib[i]) {
            if (sbuf_add(buffer, '1') != 0) return -1;
            n -= fib[i];
            written = 1;
        } else if (written) {
            if (sbuf_add(buffer, '0') != 0) return -1;
        }
    }

    if (sbuf_add(buffer, '1') != 0) return -1; 

    return 0;
}

int handle_Cv(int n, int base, sbuf_t *buffer) {
    if (!buffer || base < 2 || base > 36) {
        base = 10;
    }
    char buf[65];
    int len = to_base_str(n, base, buf, 0);
    if (len <= 0) return -1;

    for (int i = 0; buf[i]; i++) {
        if (sbuf_add(buffer, buf[i]) != 0) return -1;
    }

    return 0;
}

int handle_CV(int n, int base, sbuf_t *buffer) {
    if (!buffer || base < 2 || base > 36) {
        base = 10;
    }
    char buf[65];
    int len = to_base_str(n, base, buf, 1);
    if (len <= 0) return -1;

    for (int i = 0; buf[i]; i++) {
        if (sbuf_add(buffer, buf[i]) != 0) return -1;
    }

    return 0;
}

int handle_to(const char *num_str, int base, sbuf_t *buffer) {
    if (!num_str || !buffer) return -1;
    if (base < 2 || base > 36) base = 10;

    long long result = 0;
    int neg = 0;
    const char *p = num_str;

    if (*p == '-') {
        neg = 1;
        p++;
    }

    while (*p) {
        int digit = -1;
        if (*p >= '0' && *p <= '9') digit = *p - '0';
        else if (*p >= 'a' && *p <= 'z') digit = *p - 'a' + 10;
        else if (*p >= 'A' && *p <= 'Z') digit = *p - 'A' + 10;
        else break;

        if (digit >= base) break;

        result = result * base + digit;
        p++;
    }

    if (neg) result = -result;

    char buf[65];
    int len = to_base_str(result, 10, buf, 0);
    if (len <= 0) return -1;

    for (int i = 0; buf[i]; i++) {
        if (sbuf_add(buffer, buf[i]) != 0) return -1;
    }

    return 0;
}

int handle_TO(const char *num_str, int base, sbuf_t *buffer) {
    if (!num_str || !buffer) return -1;
    if (base < 2 || base > 36) base = 10;

    long long result = 0;
    int neg = 0;
    const char *p = num_str;

    if (*p == '-') {
        neg = 1;
        p++;
    }

    while (*p) {
        int digit = -1;
        if (*p >= '0' && *p <= '9') digit = *p - '0';
        else if (*p >= 'A' && *p <= 'Z') digit = *p - 'A' + 10;
        else if (*p >= 'a' && *p <= 'z') digit = *p - 'a' + 10; 
        else break;

        if (digit >= base) break;

        result = result * base + digit;
        p++;
    }

    if (neg) result = -result;

    char buf[65];
    int len = to_base_str(result, 10, buf, 0);
    if (len <= 0) return -1;

    for (int i = 0; buf[i]; i++) {
        if (sbuf_add(buffer, buf[i]) != 0) return -1;
    }

    return 0;
}

int handle_mi(int n, sbuf_t *buffer) {
    if (!buffer) return -1;
    unsigned char *bytes = (unsigned char *)&n;
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            if (sbuf_add(buffer, ' ') != 0) return -1;
        }
        char byte_str[3];
        snprintf(byte_str, sizeof(byte_str), "%02x", bytes[i]);
        if (sbuf_add(buffer, byte_str[0]) != 0) return -1;
        if (sbuf_add(buffer, byte_str[1]) != 0) return -1;
    }
    return 0;
}

int handle_mu(unsigned int n, sbuf_t *buffer) {
    if (!buffer) return -1;
    unsigned char *bytes = (unsigned char *)&n;
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            if (sbuf_add(buffer, ' ') != 0) return -1;
        }
        char byte_str[3];
        snprintf(byte_str, sizeof(byte_str), "%02x", bytes[i]);
        if (sbuf_add(buffer, byte_str[0]) != 0) return -1;
        if (sbuf_add(buffer, byte_str[1]) != 0) return -1;
    }
    return 0;
}

int handle_md(double d, sbuf_t *buffer) {
    if (!buffer) return -1;
    unsigned char *bytes = (unsigned char *)&d;
    for (int i = 0; i < 8; i++) {
        if (i > 0) {
            if (sbuf_add(buffer, ' ') != 0) return -1;
        }
        char byte_str[3];
        snprintf(byte_str, sizeof(byte_str), "%02x", bytes[i]);
        if (sbuf_add(buffer, byte_str[0]) != 0) return -1;
        if (sbuf_add(buffer, byte_str[1]) != 0) return -1;
    }
    return 0;
}

int handle_mf(float f, sbuf_t *buffer) {
    if (!buffer) return -1;
    unsigned char *bytes = (unsigned char *)&f;
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            if (sbuf_add(buffer, ' ') != 0) {
                return -1;
            }
        }
        char byte_str[3];
        snprintf(byte_str, sizeof(byte_str), "%02x", bytes[i]);
        if (sbuf_add(buffer, byte_str[0]) != 0) return -1;
        if (sbuf_add(buffer, byte_str[1]) != 0) return -1;
    }
    return 0;
}
