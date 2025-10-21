#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "flag_handler.h"
#include "custom_print.h"

void sbuf_init(sbuf_t *sbuf, int fd) {
    sbuf->buffered = 0;
    sbuf->len = 0;
    sbuf->fd = fd;
}

int sbuf_add(sbuf_t *sbuf, char c) {
    sbuf->buffer[sbuf->buffered] = c;
    (sbuf->buffered)++;
    (sbuf->len)++;

    if (sbuf->buffered == 4096) {
        write(sbuf->fd, sbuf->buffer, sbuf->buffered);
        sbuf->buffered = 0;
    }

    return 0;
}

int sbuf_flush(sbuf_t *sbuf) {
    if (sbuf->buffered > 0) {
        write(sbuf->fd, sbuf->buffer, sbuf->buffered);
        sbuf->buffered = 0;
    }
    return 0;
}

int overfprintf(FILE *stream, const char *format, ...) {
    if (stream == NULL || format == NULL) {
        return -1;
    }

    va_list args;
    va_start(args, format);
    
    int fd = fileno(stream);
    sbuf_t buffer;
    sbuf_init(&buffer, fd);
    
    const char *f = format;
    while (*f != '\0') {
        if (*f != '%') {
            if (sbuf_add(&buffer, *f) != 0) {
                va_end(args);
                return -1;
            }
            f++;
        } else {            
            f++;
            const char *next_f = f + 1;
            char flag[3];
            
            if (*f == '\0' || *f == ' ') {
                va_end(args);
                return -1;
            }

            if (*next_f != ' ' && *next_f != '\0' && *next_f != '\n' && *next_f != '\t') {
                flag[0] = *f;
                flag[1] = *next_f;
                flag[2] = '\0';

                f += 2;
            } else {
                flag[0] = *f;
                flag[1] = '\0';

                f++;
            }

            if (!strcmp(flag, "c")) {
                char c = (char)va_arg(args, int);

                if (handle_c(c, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (!strcmp(flag, "d")) {
                int n = va_arg(args, int);

                if (handle_d(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                } 
            } else {
                va_end(args);
                return -1;
            }
        }
    }

    if (sbuf_flush(&buffer) != 0) {
        va_end(args);
        return -1;
    }

    va_end(args);

    return buffer.len;
}

int main(void) {
    printf("%d\n", overfprintf(stdout, "int: %d char: %c\n", 12, 'F'));

    return 0;
}
