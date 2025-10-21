#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <stdlib.h>

#if defined(__linux__)
    #define ERRMSG_ARRAY_SIZE 134 
    extern const char* linux_error_messages[];
    #define ERRMSG_ARRAY linux_error_messages
    #define ERRMSG_ARRAY_SZ ERRMSG_ARRAY_SIZE
#elif defined(__APPLE__)
    #define ERRMSG_ARRAY_SIZE 107 
    extern const char* macos_error_messages[];
    #define ERRMSG_ARRAY macos_error_messages
    #define ERRMSG_ARRAY_SZ ERRMSG_ARRAY_SIZE
#else
    #define ERRMSG_ARRAY_SIZE 134
    extern const char* generic_error_messages[];
    #define ERRMSG_ARRAY generic_error_messages
    #define ERRMSG_ARRAY_SZ ERRMSG_ARRAY_SIZE
#endif

void *custom_memchr(const void *str, int c, size_t n);
int custom_memcmp(const void *str1, const void *str2, size_t n);
void *custom_memcpy(void *dest, const void *src, size_t n);
void *custom_memset(void *str, int c, size_t n);
char *custom_strncat(char *dest, const char *str, size_t n);
char *custom_strchr(const char *str, int c);
int custom_strncmp(const char *str1, const char *str2, size_t n);
char *custom_strncpy(char *dest, const char *src, size_t n);
size_t custom_strcspn(const char *str1, const char *str2);
char *custom_strerror(int errnum);
size_t custom_strlen(const char *str);
char *custom_strpbrk(const char *str1, const char *str2);
char *custom_strrchr(const char *str, int c);
char *custom_strstr(const char *haystack, const char *needle);
char *custom_strtok(char *str, const char *delim);

#endif
