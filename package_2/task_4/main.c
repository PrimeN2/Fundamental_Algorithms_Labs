#include "overio.h"
#include <stdio.h>

int main(void) {
    int num;
    unsigned int unum;
    char str[100];

    printf("oversscanf:\n");
    oversscanf("XIV", "%Ro", &num);
    printf("input: XIV, read: %d\n", num);

    oversscanf("101", "%Zr", &unum);
    printf("input: 101, read: %u\n", unum);

    oversscanf("ff", "%Cv", &num, 16);
    printf("input: ff, read: %d\n", num);

    printf("\noverfscanf (fiel):\n");
    const char *input = "XIV 101 ff";
    FILE *f = fmemopen((void*)input, strlen(input) + 1, "r");
    overfscanf(f, "%Ro %Zr %Cv", &num, &unum, &num, 16);
    rewind(f);
    overfscanf(f, "%Ro %Zr %Cv", &num, &unum, &num, 16);
    printf("input: %s, read: %d %u %d\n", input, num, unum, num);
    fclose(f);

    printf("Enter roman numeral: ");
    if (scanf("%99s", str) == 1) {
        oversscanf(str, "%Ro", &num);
        printf("input: %s, read: %d\n", str, num);
    }

    return 0;
}
