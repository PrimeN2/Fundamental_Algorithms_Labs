#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H

#include <stdlib.h>

typedef struct {
    char *word;
    size_t len;
} Word_t;

typedef struct {

} Buffer;

int extract_words(const char *line, Word **words, size_t max_str_len);
int format_line();

#endif