#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "flag_handler.h"
#include "custom_print.h"

typedef struct {
    char *str;        
    size_t len;       
    size_t max_len;   
} sbuf_str_t;

void sbuf_init_str(sbuf_str_t *sbuf, char *str, size_t max_len) {
    sbuf->str = str;
    sbuf->len = 0;
    sbuf->max_len = max_len - 1; 
}

int sbuf_add_str(sbuf_str_t *sbuf, char c) {
    if (sbuf->len >= sbuf->max_len) {
        return -1; 
    }
    sbuf->str[sbuf->len] = c;
    sbuf->len++;
    return 0;
}

void sbuf_terminate_str(sbuf_str_t *sbuf) {
    if (sbuf->len <= sbuf->max_len) {
        sbuf->str[sbuf->len] = '\0';
    }
}

int oversprintf(char *str, const char *format, ...) {
    if (!str || !format) {
        return -1;
    }

    size_t max_len = 1024; 
    sbuf_str_t buffer;
    sbuf_init_str(&buffer, str, max_len);

    va_list args;
    va_start(args, format);

    const char *f = format;
    while (*f != '\0') {
        if (*f != '%') {
            if (sbuf_add_str(&buffer, *f) != 0) {
                va_end(args);
                return -1;
            }
            f++;
        } else {
            f++; 

            if (*f == '\0') {
                if (sbuf_add_str(&buffer, '%') != 0) {
                    va_end(args);
                    return -1;
                }
                break;
            }

            if (!isalpha(*f)) {
                if (sbuf_add_str(&buffer, '%') != 0) {
                    va_end(args);
                    return -1;
                }
                continue;
            }

            char flag[3] = {0};
            if (*(f+1) && isalpha(*(f+1))) {
                flag[0] = *f;
                flag[1] = *(f+1);
                f += 2;
            } else {
                flag[0] = *f;
                f++;
            }

            if (strcmp(flag, "c") == 0) {
                char c = (char)va_arg(args, int);
                if (sbuf_add_str(&buffer, c) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "d") == 0) {
                int n = va_arg(args, int);
                char temp[12];
                int len = snprintf(temp, sizeof(temp), "%d", n);
                for (int i = 0; i < len; i++) {
                    if (sbuf_add_str(&buffer, temp[i]) != 0) {
                        va_end(args);
                        return -1;
                    }
                }
            } else {
                va_end(args);
                return -1;
            }
        }
    }

    sbuf_terminate_str(&buffer);
    va_end(args);
    return buffer.len;
}

void sbuf_init(sbuf_t *sbuf, int fd) {
    if (!sbuf) return;
    sbuf->buffered = 0;
    sbuf->len = 0;
    sbuf->fd = fd;
}

int sbuf_add(sbuf_t *sbuf, char c) {
    if (!sbuf) return -1;

    sbuf->buffer[sbuf->buffered] = c;
    sbuf->buffered++;
    sbuf->len++;

    if (sbuf->buffered == 4096) {
        ssize_t written = write(sbuf->fd, sbuf->buffer, sbuf->buffered);
        if (written < 0) return -1;
        sbuf->buffered = 0;
    }

    return 0;
}

int sbuf_flush(sbuf_t *sbuf) {
    if (!sbuf) return -1;
    if (sbuf->buffered > 0) {
        ssize_t written = write(sbuf->fd, sbuf->buffer, sbuf->buffered);
        if (written < 0) return -1;
        sbuf->buffered = 0;
    }
    return 0;
}

int overfprintf(FILE *stream, const char *format, ...) {
    if (!stream || !format) {
        return -1;
    }

    int fd = fileno(stream);
    if (fd == -1) {
        return -1;
    }

    va_list args;
    va_start(args, format);

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

            if (*f == '\0') {
                if (sbuf_add(&buffer, '%') != 0) {
                    va_end(args);
                    return -1;
                }
                break;
            }

            if (!isalpha(*f)) {
                if (sbuf_add(&buffer, '%') != 0) {
                    va_end(args);
                    return -1;
                }
                continue;
            }

            char flag[3] = {0};
            if (*(f+1) && isalpha(*(f+1))) {
                flag[0] = *f;
                flag[1] = *(f+1);
                f += 2;
            } else {
                flag[0] = *f;
                f++;
            }

            if (strcmp(flag, "c") == 0) {
                char c = (char)va_arg(args, int);
                if (handle_c(c, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "d") == 0) {
                int n = va_arg(args, int);
                if (handle_d(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "Ro") == 0) {
                int n = va_arg(args, int);
                if (handle_Ro(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "Zr") == 0) {
                unsigned int n = va_arg(args, unsigned int);
                if (handle_Zr(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "Cv") == 0) {
                int n = va_arg(args, int);
                int base = va_arg(args, int);
                if (handle_Cv(n, base, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "CV") == 0) {
                int n = va_arg(args, int);
                int base = va_arg(args, int);
                if (handle_CV(n, base, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "to") == 0) {
                const char *num_str = va_arg(args, const char *);
                int base = va_arg(args, int);
                if (handle_to(num_str, base, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "TO") == 0) {
                const char *num_str = va_arg(args, const char *);
                int base = va_arg(args, int);
                if (handle_TO(num_str, base, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "mi") == 0) {
                int n = va_arg(args, int);
                if (handle_mi(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "mu") == 0) {
                unsigned int n = va_arg(args, unsigned int);
                if (handle_mu(n, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "md") == 0) {
                double d = va_arg(args, double);
                if (handle_md(d, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else if (strcmp(flag, "mf") == 0) {
                float f = (float)va_arg(args, double);
                if (handle_mf(f, &buffer) != 0) {
                    va_end(args);
                    return -1;
                }
            } else {
                if (sbuf_add(&buffer, '%') != 0) {
                    va_end(args);
                    return -1;
                }
                if (sbuf_add(&buffer, flag[0]) != 0) {
                    va_end(args);
                    return -1;
                }
                if (flag[1] != '\0') {
                    if (sbuf_add(&buffer, flag[1]) != 0) {
                        va_end(args);
                        return -1;
                    }
                }
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
