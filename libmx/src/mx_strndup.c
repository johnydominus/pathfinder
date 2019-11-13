#include <stdio.h>

char *mx_strnew (const int size);
char *mx_strncpy (char *dst, const char *src, size_t size);

char *mx_strndup (const char *s1, size_t n) {
    char *new_str = mx_strnew(n * sizeof(char));

    unsigned long i = 0;
    while (i < n && s1[i]) {
        new_str[i] = s1[i];
        i++;
    }
    
    while (i <= n)
        new_str[i++] = '\0';

    return new_str;
}
