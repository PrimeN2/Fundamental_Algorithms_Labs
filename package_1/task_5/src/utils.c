#include "utils.h"
#include "processor.h"
#include <stdio.h>

void print_error(Status status) {
    switch (status) {
        case STATUS_OK:
            break;
        case STATUS_INVALID_INPUT:
            fprintf(stderr, "Ошибка: Неверные входные параметры.\n");
            break;
        case STATUS_FILE_ERROR:
            fprintf(stderr, "Ошибка: Не удалось открыть файл.\n");
            break;
        case STATUS_MEMORY_ERROR:
            fprintf(stderr, "Ошибка: Не хватает памяти.\n");
            break;
        case STATUS_UNKNOWN_FLAG:
            fprintf(stderr, "Ошибка: Неизвестный флаг.\n");
            break;
        case STATUS_INVALID_FLAG_FORMAT:
            fprintf(stderr, "Ошибка: Флаг должен начинаться с '-' или '/'.\n");
            break;
        default:
            fprintf(stderr, "Неизвестная ошибка.\n");
            break;
    }
}
