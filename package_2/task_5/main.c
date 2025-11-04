#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "text_processor.h"

static int sreadl(char *buffer, size_t buffer_size, const char *prompt) {
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(buffer, buffer_size, stdin) == NULL) {
        perror("\nCannot parse input.\n");
        return 1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        perror("\nInput is too long.\n");
        return 1;
    }

    if (strlen(buffer) == 0) {
        perror("No input found.\n");
        return 1;
    }

    if (buffer[0] == '/' || (strlen(buffer) >= 2 && buffer[0] == '.' 
    && buffer[1] == '.' && (buffer[2] == '\0' || buffer[2] == '/'))) {
        perror("Input is absolute path or has relative marks.\n");
        return 1;
    }

    return 0;
}

int main(void) {
    const size_t MAX_FILENAME_LEN = 256;
    char input_filename[MAX_FILENAME_LEN];
    char output_filename[MAX_FILENAME_LEN];

    if (sreadl(input_filename, sizeof(input_filename), "Enter input filename: ") != 0) {
        perror("Cannot read input filename.\n");
        return 1;
    }

    if (sreadl(output_filename, sizeof(output_filename), "Введите имя выходного файла: ") != 0) {
        perror("Cannot read output filename.\n");
        return 1;
    }

    if (strcmp(input_filename, output_filename) == 0) {
        fprintf(stderr, "Input and output filenames are the same.\n", input_filename);
        return 1; 
    }

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Cannot open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Cannot create output file.\n");
        return 1;
    }

    const size_t MAX_LINE_LENGTH = 1024;
    char line[MAX_LINE_LENGTH];
    Word *words = NULL;

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        

        


    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}