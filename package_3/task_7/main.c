#include "interpretator.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Enter a filename: ");

    char filename[100];

    if (fgets(filename, sizeof(filename), stdin)) {
        filename[strcspn(filename, "\n")] = '\0';
    } else {
        perror("Can't read input filename.\n");
        return -1;
    }

    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        fprintf(stderr, "Can't open file: %s.\n", filename);
        return -1;
    }

    interpretator_state state;
    if (create_interpretator(&state) != 0) {
        perror("Can't create an interpretator.\n");
        return -1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (interpretate_str(&state, buffer) != 0) {
            perror("An error occured while interpretating.\n");
            return -1;
        }
    }

    printf("Name: %c, Value: %d.\n", state.vs.data[0].name, state.vs.data[0].value);
    printf("Name: %c, Value: %d.\n", state.vs.data[1].name, state.vs.data[1].value);
    printf("Name: %c, Value: %d.\n", state.vs.data[2].name, state.vs.data[2].value);
    printf("Name: %c, Value: %d.\n", state.vs.data[3].name, state.vs.data[3].value);
    
    free_variables(&state.vs);
    if (fclose(input_file) != 0) {
        perror("Error closing file.\n");
    }

    return 0;
}
