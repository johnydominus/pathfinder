#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_strlen(s1);

    if(n < len)
        len = n;

    char *new_str = mx_strnew(len * sizeof(char));

    if(!new_str)
        return NULL;

    return mx_strncpy(new_str, s1, len);
}
