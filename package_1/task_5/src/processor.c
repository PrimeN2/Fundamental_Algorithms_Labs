#include "processor.h"
#include "utils.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void init_flags(ProcessFlags* flags) {
    if (!flags) return;
    flags->exclude_digits = 0;
    flags->count_latin = 0;
    flags->count_other = 0;
    flags->replace_other_hex = 0;
    flags->input_path = NULL;
    flags->output_path = NULL;
}

Status parse_args(int argc, char* argv[], ProcessFlags* flags) {
    if (!argv || !flags) return STATUS_INVALID_INPUT;
    if (argc < 2) return STATUS_INVALID_INPUT;

    const char* flag_str = argv[1];
    int has_n = 0;

    if (flag_str[0] != '-' && flag_str[0] != '/') {
        return STATUS_INVALID_FLAG_FORMAT;
    }

    if (strlen(flag_str) >= 2 && flag_str[1] == 'n') {
        has_n = 1;
    }

    if (has_n && argc < 4) {
        return STATUS_INVALID_INPUT;
    } 
    if (!has_n && argc < 3) {
        return STATUS_INVALID_INPUT;
    }

    const char* actual_flag = has_n ? &flag_str[2] : &flag_str[1];

    if (strcmp(actual_flag, "d") == 0) {
        flags->exclude_digits = 1;
    } else if (strcmp(actual_flag, "i") == 0) {
        flags->count_latin = 1;
    } else if (strcmp(actual_flag, "s") == 0) {
        flags->count_other = 1;
    } else if (strcmp(actual_flag, "a") == 0) {
        flags->replace_other_hex = 1;
    } else {
        return STATUS_UNKNOWN_FLAG;
    }

    flags->input_path = argv[2];
    if (has_n) {
        flags->output_path = argv[3];
    } else {
        size_t len = strlen(argv[2]);
        char* out_name = malloc(len + 5); 
        if (!out_name) return STATUS_MEMORY_ERROR;
        strcpy(out_name, "out_");
        strcat(out_name, argv[2]);
        flags->output_path = out_name;
    }

    return STATUS_OK;
}

Status process_file(const ProcessFlags* flags) {
    if (!flags || !flags->input_path) return STATUS_INVALID_INPUT;

    FILE* infile = fopen(flags->input_path, "r");
    if (!infile) return STATUS_FILE_ERROR;

    FILE* outfile = fopen(flags->output_path, "w");
    if (!outfile) {
        fclose(infile);
        return STATUS_FILE_ERROR;
    }

    char buffer[4096];

    while (fgets(buffer, sizeof(buffer), infile)) {
        char* line = buffer;
        size_t len = strlen(line);

        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }

        if (flags->exclude_digits) {
            char temp[4096] = "";
            size_t j = 0;
            for (size_t i = 0; i < len; i++) {
                if (!isdigit((unsigned char)line[i])) {
                    temp[j++] = line[i];
                }
            }
            temp[j] = '\0';
            strcpy(buffer, temp);
            len = j;
        }

        if (flags->count_latin) {
            int latin_count = 0;
            for (size_t i = 0; i < len; i++) {
                if (isalpha((unsigned char)line[i]) && 
                    ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))) {
                    latin_count++;
                }
            }
            fprintf(outfile, "%d\n", latin_count);
        } else if (flags->count_other) {
            int other_count = 0;
            for (size_t i = 0; i < len; i++) {
                unsigned char c = line[i];
                if (!(isalpha(c) || isdigit(c) || c == ' ')) {
                    other_count++;
                }
            }
            fprintf(outfile, "%d\n", other_count);
        } else if (flags->replace_other_hex) {
            for (size_t i = 0; i < len; i++) {
                unsigned char c = line[i];
                if (!(isdigit(c) || c == ' ')) {
                    fprintf(outfile, "%02X", c);
                } else {
                    fputc(c, outfile);
                }
            }
            fputc('\n', outfile);
        } else {
            fprintf(outfile, "%s\n", buffer);
        }
    }

    fclose(infile);
    fclose(outfile);

    return STATUS_OK;
}
