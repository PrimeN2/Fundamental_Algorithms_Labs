#include "has_finite_representation.h"
#include <stdio.h>

static void print_result(frs_status_t status) {
    switch (status) {
        case FRS_SUCCESS:
            printf("Успешно выполнено\n");
            break;
        case FRS_INVALID_BASE:
            printf("Ошибка: некорректное основание\n");
            break;
        case FRS_INVALID_COUNT:
            printf("Ошибка: некорректное количество аргументов\n");
            break;
        case FRS_INVALID_NUMBER:
            printf("Ошибка: некорректное число (должно быть в диапазоне (0;1))\n");
            break;
        case FRS_MEMORY_ERROR:
            printf("Ошибка: не удалось выделить память\n");
            break;
        case FRS_INVALID_EPSILON:
            printf("Ошибка: некорректное значение эпсилон (должно быть положительным)\n");
            break;
        default:
            printf("Неизвестная ошибка\n");
            break;
    }
}

int main(void) {
    double epsilon = 1e-9;
    
    printf("Основание 2\n");
    frs_status_t status = check_finite_representation(2, 4, epsilon, 0.5, 0.25, 0.2, 0.1);
    print_result(status);
    
    printf("\nОснование 10\n");
    status = check_finite_representation(10, 3, epsilon, 0.5, 0.125, 0.333333333);
    print_result(status);
    
    printf("\nОснование 60 \n");
    status = check_finite_representation(60, 3, epsilon, 0.5, 0.25, 0.333333333);
    print_result(status);
    
    printf("\nОснование 3 \n");
    status = check_finite_representation(3, 4, epsilon, 0.5, 0.333333333, 0.666666666, 0.1);
    print_result(status);
    
    printf("\nНекорректное основание\n");
    status = check_finite_representation(1, 2, epsilon, 0.5, 0.25);
    print_result(status);
    
    printf("\nНекорректное число\n");
    status = check_finite_representation(2, 2, epsilon, 0.5, 1.5);
    print_result(status);
    
    printf("\nДробь 1/3 с основанием 3\n");
    status = check_finite_representation(3, 1, epsilon, 1.0/3.0);
    print_result(status);
    
    printf("\nДробь 1/4 в системе с основанием 10\n");
    status = check_finite_representation(10, 1, epsilon, 0.25);
    print_result(status);
    
    return 0;
}
