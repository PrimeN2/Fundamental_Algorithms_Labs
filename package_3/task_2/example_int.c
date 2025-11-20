#include "int_vector.h"
#include <stdio.h>

int main(void) {
    Vector *v = create_vector(2, copy_int, delete_int, compare_int);

    int nums[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        push_back_vector(v, &nums[i]);
    }

    printf("Int Vector Size: %zu, Capacity: %zu\n", v->len, v->capacity);
    for (size_t i = 0; i < v->len; i++) {
        printf("%d ", *get_at_vector(v, i));
    }
    printf("\n");

    Vector *v2 = copy_vector_new(v);
    printf("Is equal after copy: %s\n", is_equal_vector(v, v2) ? "Yes" : "No");

    int new_val = 40;
    push_back_vector(v, &new_val);

    printf("Is equal after push: %s\n", is_equal_vector(v, v2) ? "Yes" : "No");

    delete_at_vector(v, 0);
    printf("After delete at 0: ");
    for (size_t i = 0; i < v->len; i++) {
        printf("%d ", *get_at_vector(v, i));
    }
    printf("\n");

    copy_vector(v2, v);
    printf("Copied vector: ");
    for (size_t i = 0; i < v2->len; i++) {
        printf("%d ", *get_at_vector(v2, i));
    }
    printf("\n");

    delete_vector(v);
    delete_vector(v2);
    return 0;
}
