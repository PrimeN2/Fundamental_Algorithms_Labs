#include <stdio.h>

void convert_to_base(int num, char base_rate) { // DOC: base_rate = {1; 5}
    int base = 2 << (base_rate - 1);

    
}

void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main(void) {
    printBinary(2 << 3);
    printf("%d\n", 2 << 3);
    printBinary(4);
    printBinary(8);

    return 0;
}