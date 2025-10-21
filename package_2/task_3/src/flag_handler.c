#include <stdio.h>
#include <unistd.h>
#include "custom_print.h"

int handle_c(char c, sbuf_t *buffer) {
    if (sbuf_add(buffer, c) != 0) {
        return -1;
    }

    return 0;
}

int handle_d(int n, sbuf_t *buffer) {
    int num = n;

    if (num < 0) {
        if (sbuf_add(buffer, '-') != 0) {
            return -1;
        } 

        num = -num;
    }

    if (num == 0) {
        if (sbuf_add(buffer, '0') != 0) {
            return -1;
        } 

        return 0;
    }

    char rev_num[12];
    int num_len = 0;

    while (num != 0) {
        rev_num[num_len] = (num % 10) + '0';
        num_len++;
        num /= 10;
    }

    for (int i = num_len - 1; i >= 0; --i) {
        if (sbuf_add(buffer, rev_num[i]) != 0) {
            return -1;
        } 
    }

    return 0;
}

