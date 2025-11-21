#include "interpretator.h"
#include <stdio.h>
#include <ctype.h>

int interpretate_str(char *str) {
    if (!str) {
        perror("No string was obtained.\n");
        return -1;
    }

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            continue;
        }

    }
}
