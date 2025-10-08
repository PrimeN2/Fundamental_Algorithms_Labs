#include "processor.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_parse_d(void) {
    ProcessFlags flags;
    init_flags(&flags);
    char* args[] = {"program", "-d", "input.txt"};
    Status s = parse_args(3, args, &flags);
    assert(s == STATUS_OK);
    assert(flags.exclude_digits == 1);
    assert(strcmp(flags.input_path, "input.txt") == 0);
    assert(strncmp(flags.output_path, "out_", 4) == 0);
}

void test_parse_nd_with_output(void) {
    ProcessFlags flags;
    init_flags(&flags);
    char* args[] = {"program", "/nd", "input.txt", "output.txt"};
    Status s = parse_args(4, args, &flags);
    assert(s == STATUS_OK);
    assert(flags.exclude_digits == 1);
    assert(strcmp(flags.input_path, "input.txt") == 0);
    assert(strcmp(flags.output_path, "output.txt") == 0);
}

void test_invalid_flag(void) {
    ProcessFlags flags;
    init_flags(&flags);
    char* args[] = {"program", "-x", "input.txt"};
    Status s = parse_args(3, args, &flags);
    assert(s == STATUS_UNKNOWN_FLAG);
}

void test_insufficient_args(void) {
    ProcessFlags flags;
    init_flags(&flags);
    char* args[] = {"program", "-d"};
    Status s = parse_args(2, args, &flags);
    assert(s == STATUS_INVALID_INPUT);
}

void test_process_i(void) {
    FILE* f = fopen("test_input.txt", "w");
    fprintf(f, "Hello World 123\n");
    fclose(f);

    ProcessFlags flags;
    init_flags(&flags);
    char* args[] = {"program", "-i", "test_input.txt"};
    Status s = parse_args(3, args, &flags);
    assert(s == STATUS_OK);

    s = process_file(&flags);
    assert(s == STATUS_OK);

    FILE* out = fopen(flags.output_path, "r");
    char line[100];
    fgets(line, sizeof(line), out);
    fclose(out);

    assert(atoi(line) == 10);

    remove("test_input.txt");
    remove(flags.output_path);
    free((void*)flags.output_path);
}

int main(void) {
    test_parse_d();
    test_parse_nd_with_output();
    test_invalid_flag();
    test_insufficient_args();
    test_process_i();

    printf("All tests are passed.\n");
    return 0;
}
