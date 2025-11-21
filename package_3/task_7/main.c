#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[100];

    if (fgets(filename, sizeof(filename), stdin)) {
        filename[strcspn(filename, "\n")] = '\0';
    } else {
        perror("Can't read input filename.\n");
        return -1;
    }

    return 0;
}