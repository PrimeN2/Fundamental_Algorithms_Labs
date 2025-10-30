#ifndef OVERIO_H
#define OVERIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

typedef enum {
    OVERIO_SUCCESS = 0,
    OVERIO_INVALID_FORMAT,
    OVERIO_INVALID_INPUT,
    OVERIO_MEMORY_ERROR,
    OVERIO_FILE_ERROR,
    OVERIO_BUFFER_OVERFLOW,
    OVERIO_UNKNOWN_FLAG,
    OVERIO_INVALID_BASE,
    OVERIO_END_OF_INPUT
} overio_status_t;

int overfscanf(FILE *stream, const char *format, ...);

int oversscanf(const char *str, const char *format, ...);

#endif
