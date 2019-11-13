#include <stdio.h>

char *mx_strnew (const int size);
int mx_strlen (const char *s);
int mx_strncmp (const char *s1, const char *s2, size_t n);

char *mx_strstr (const char *haystack, const char *needle) {
    if (!needle)
        return (char*)haystack;

    char *buf = (char*)haystack;    
    int need_len = mx_strlen(needle);

    while (buf) {
        if (!mx_strncmp(buf, needle, need_len))
            return buf;
        buf++;
    }

    return NULL;    
}
