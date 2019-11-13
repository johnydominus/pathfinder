#include <stdio.h>

char *mx_strnew (const int n);
int mx_strlen (const char *str);

char *mx_strcpy(char *dst, const char *src){
    if (dst == NULL) { 
        return dst;
    } else {
        char *ptr = dst;

        while ((*dst++ = *src++) != '\0');

        return ptr;
    }
}
