#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "number_utils.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 2;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fclose(input_file);
        fprintf(stderr, "Error: Cannot open output file '%s'\n", argv[2]);
        return 3;
    }

    char buffer[4096];
    int line_count = 0;
    int total_errors = 0;

    while (fgets(buffer, sizeof(buffer), input_file)) {
        line_count++;
        char *token = strtok(buffer, " \t\n");
        while (token) {
            char cleaned[4096];
            size_t clean_len = 0;
            for (size_t i = 0; token[i]; i++) {
                if (isalnum(token[i])) {
                    cleaned[clean_len++] = toupper(token[i]);
                }
            }
            cleaned[clean_len] = '\0';

            if (clean_len == 0) {
                token = strtok(NULL, " \t\n");
                continue;
            }

            int min_base = find_minimal_base(cleaned);
            if (min_base == -1) {
                fprintf(stderr, "Error: Invalid number format at line %d: '%s'\n", line_count, token);
                total_errors++;
                token = strtok(NULL, " \t\n");
                continue;
            }

            long long decimal_value = convert_to_decimal(cleaned, min_base);
            if (decimal_value == LLONG_MIN) {
                fprintf(stderr, "Error: Overflow during conversion at line %d: '%s'\n", line_count, token);
                total_errors++;
                token = strtok(NULL, " \t\n");
                continue;
            }

            fprintf(output_file, "%s %d %lld\n", cleaned, min_base, decimal_value);
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(input_file);
    fclose(output_file);

    if (total_errors > 0) {
        fprintf(stderr, "Total errors encountered: %d\n", total_errors);
        return 4;
    }

    return 0;
}
