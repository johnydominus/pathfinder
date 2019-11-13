#include <stdio.h>

int mx_strlen (const char *s);
char *mx_strnew (const int size);
char *mx_strndup (const char *s1, size_t n);

char *mx_strtrim_delim (const char *str, const char delim) {
    int st_delims = 0;
    int end_delims = mx_strlen(str);

    while (str[st_delims] == delim)
        st_delims++;

    while (str[end_delims - 1] == delim)
        end_delims--;

    return mx_strndup(&str[st_delims], end_delims - st_delims);
}
