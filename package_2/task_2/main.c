#include <stdio.h>
#include <string.h>
#include "custom_string.h"

int main(void) {
    char buf1[50], buf2[50];
    const char *s1 = "hello";
    const char *s2 = "world";
    char *tok1, *tok2;

    printf("memchr: %s\n", custom_memchr(s1, 'e', 5) == memchr(s1, 'e', 5) ? "PASS" : "FAIL");
    printf("memcmp: %s\n", custom_memcmp(s1, s2, 3) == memcmp(s1, s2, 3) ? "PASS" : "FAIL");
    printf("memcpy: %s\n", !strcmp((char*)custom_memcpy(buf1, s1, 6), (char*)memcpy(buf2, s1, 6)) ? "PASS" : "FAIL");
    printf("memset: %s\n", !strcmp((char*)custom_memset(buf1, 'A', 3), (char*)memset(buf2, 'A', 3)) ? "PASS" : "FAIL");
    strcpy(buf1, "hi ");
    strcpy(buf2, "hi ");
    printf("strncat: %s\n", !strcmp(custom_strncat(buf1, "world", 3), strncat(buf2, "world", 3)) ? "PASS" : "FAIL");
    printf("strchr: %s\n", custom_strchr(s1, 'l') == strchr(s1, 'l') ? "PASS" : "FAIL");
    printf("strncmp: %s\n", custom_strncmp(s1, s2, 3) == strncmp(s1, s2, 3) ? "PASS" : "FAIL");
    printf("strncpy: %s\n", !strcmp(custom_strncpy(buf1, s1, 10), strncpy(buf2, s1, 10)) ? "PASS" : "FAIL");
    printf("strcspn: %s\n", custom_strcspn(s1, "aeiou") == strcspn(s1, "aeiou") ? "PASS" : "FAIL");
    printf("strlen: %s\n", custom_strlen(s1) == strlen(s1) ? "PASS" : "FAIL");
    printf("strpbrk: %s\n", custom_strpbrk(s1, "aeiou") == strpbrk(s1, "aeiou") ? "PASS" : "FAIL");
    printf("strrchr: %s\n", custom_strrchr(s1, 'l') == strrchr(s1, 'l') ? "PASS" : "FAIL");
    printf("strstr: %s\n", custom_strstr("hello world", "world") == strstr("hello world", "world") ? "PASS" : "FAIL");
    strcpy(buf1, "a,b,c");
    strcpy(buf2, "a,b,c");
    tok1 = custom_strtok(buf1, ",");
    tok2 = strtok(buf2, ",");
    printf("strtok: %s\n", !strcmp(tok1, tok2) ? "PASS" : "FAIL");
    return 0;
}
