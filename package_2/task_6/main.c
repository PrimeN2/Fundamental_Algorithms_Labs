#include <stdio.h>
#include "vector.h"

int main(int argc, char **argv) {
    vector test_int_vector = {
        .capacity = 0,
        .size = 0
    };
    init_vector(&test_int_vector, sizeof(int));

    int a = 60;
    int b = 2;

    int popped_value;

    push_vector(&test_int_vector, &a);
    push_vector(&test_int_vector, &b);
    pop_vector(&test_int_vector, &popped_value);
    printf("%d", *((int *)get_vector(&test_int_vector, 0)));
    printf("\n");

    printf("%zu", test_int_vector.capacity);




    return 0;
}
