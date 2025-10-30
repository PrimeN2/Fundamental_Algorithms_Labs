#ifndef CUSTOM_PRINT_H
#define CUSTOM_PRINT_H

#include <stdio.h>

typedef struct {
    char buffer[4096];
    size_t buffered;
    size_t len;
    int fd;
} sbuf_t;

void sbuf_init(sbuf_t *sbuf, int fd);
int sbuf_add(sbuf_t *sbuf, char c);
int sbuf_flush(sbuf_t *sbuf);

int overfprintf(FILE *stream, const char *format, ...);
int oversprintf(char *str, const char *format, ...); 

#endif
