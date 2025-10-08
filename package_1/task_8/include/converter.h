#ifndef CONVERTER_H
#define CONVERTER_H

int convert_from_base(const char *str, int base, long long *result);
int convert_to_base(long long num, int base, char *buffer, size_t buffer_size);

#endif
