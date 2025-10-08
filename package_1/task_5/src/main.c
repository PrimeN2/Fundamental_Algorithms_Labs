#include "processor.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    ProcessFlags flags;
    init_flags(&flags);

    Status status = parse_args(argc, argv, &flags);
    if (status != STATUS_OK) {
        print_error(status);
        return 1;
    }

    status = process_file(&flags);
    if (status != STATUS_OK) {
        print_error(status);
        if (flags.output_path && !argv[3]) { 
            free((void*)flags.output_path);
        }
        return 1;
    }

    if (flags.output_path && !argv[3]) {
        free((void*)flags.output_path);
    }

    printf("Обработка завершена успешно.\n");
    return 0;
}
