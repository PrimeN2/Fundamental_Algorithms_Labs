#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "handler_q.h"
#include "handler_m.h"
#include "handler_t.h"
#include "handler_status.h"

static int parse_str_to_d(char *str, double *result) {
    if (str == NULL || *str == '\0') {
        return -1;
    }

    char *endptr;
    double value = strtod(str, &endptr);

    if (*endptr != '\0' && *endptr != '\n') {
        return -1;
    }

    *result = value;
    return 0;
}

static int parse_str_to_l(char *str, long *result) {
    if (str == NULL || *str == '\0') {
        return -1;
    }

    char *endptr;
    long value = strtol(str, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        return -1;
    }

    *result = value;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        return 1;
    }

    if (argv[1][0] != '-' && argv[1][0] != '/') {
        fprintf(stderr, "Error: Flag expected.\n");
        return 1;
    }

    if (strlen(argv[1]) > 2) {
        fprintf(stderr, "Incorrect flag.\n");
        return 1;
    }

    char flag = argv[1][1];

    switch (flag) {
        case 'q': {
            if (argc != 6) {
                fprintf(stderr, "Error: Wrong amount of arguments.\n");
                return 1;
            }

            double epsi;
            double k_1, k_2, k_3;

            if (parse_str_to_d(argv[2], &epsi) != 0 || 
                parse_str_to_d(argv[3], &k_1) != 0 ||
                parse_str_to_d(argv[4], &k_2) != 0 ||
                parse_str_to_d(argv[5], &k_3) != 0) 
            {
                fprintf(stderr, "Error: Erorr ocured while parsing arguments.\n");
                return 1;
            }
            double solutions[6][2];
            int solutions_count;
            HandlerStatus status = handle_q(epsi, k_1, k_2, k_3, solutions, &solutions_count);

            if (status == HANDLER_OK) {
                for (int i = 0; i < solutions_count; i++) {
                    printf("%lf, %lf\n", solutions[i][0], solutions[i][1]);
                }
            } else {
                fprintf(stderr, "Error: An erorr occured while handling.\n");
                return -1;
            }

            break;
        }
        case 'm': {
            if (argc != 4) {
                fprintf(stderr, "Error: wrong number of arguments.\n");
                return 1;
            }

            long num_1, num_2;

            if (parse_str_to_l(argv[2], &num_1) != 0 || parse_str_to_l(argv[3], &num_2) != 0) {
                fprintf(stderr, "Erorr: An erorr occured while parsing.\n");
                return 1;
            }

            if (num_1 == 0 || num_2 == 0) {
                fprintf(stderr, "Erorr: Arguments must be non zero.\n");
                return 1;
            }

            int result;
            HandlerStatus status = handle_m(num_1, num_2, &result);

            if (status == HANDLER_OK) {
                if (result == 1) {
                    printf("%ld is multiple for %ld\n", num_1, num_2);
                } else {
                    printf("%ld is not multiple for %ld\n", num_1, num_2);
                }
            }

            break;
        }
        case 't': {
            if (argc != 6) {
                fprintf(stderr, "Error: Wrong amount of arguments.\n");
                return 1;
            }

            double epsi;
            double a, b, c;

            if (parse_str_to_d(argv[2], &epsi) != 0 || 
                parse_str_to_d(argv[3], &a) != 0 ||
                parse_str_to_d(argv[4], &b) != 0 ||
                parse_str_to_d(argv[5], &c) != 0) 
            {
                fprintf(stderr, "Error: Erorr ocured while parsing arguments.\n");
                return 1;
            }

            int result;
            HandlerStatus status = handle_t(epsi, a, b, c, &result);

            if (status == HANDLER_INVALID_INPUT) {
                fprintf(stderr, "Erorr: The input is invalid.\n");
                return 1;
            } else if (status == HANDLER_OK) {
                if (result == 1) {
                    printf("Square trignale with sides: %lf %lf %lf is valid\n", a, b, c);
                } else {
                    printf("Square trignale with sides: %lf %lf %lf is degenerate\n", a, b, c);
                }
            }

            break;
        }
        default: {
            fprintf(stderr, "Error: Incorrect flag.\n");
        }
    }

    return 0;
}
