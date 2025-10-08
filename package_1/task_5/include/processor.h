#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STATUS_OK = 0,
    STATUS_INVALID_INPUT,
    STATUS_FILE_ERROR,
    STATUS_MEMORY_ERROR,
    STATUS_UNKNOWN_FLAG,
    STATUS_INVALID_FLAG_FORMAT
} Status;

typedef struct {
    int exclude_digits;      
    int count_latin;         
    int count_other;         
    int replace_other_hex;  
    const char* input_path;
    const char* output_path;
} ProcessFlags;

void init_flags(ProcessFlags* flags);

Status parse_args(int argc, char* argv[], ProcessFlags* flags);

Status process_file(const ProcessFlags* flags);

#endif 
