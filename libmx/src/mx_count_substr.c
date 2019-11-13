#include <stdio.h>

int mx_strlen (const char *s);
int mx_strncmp (const char *s, const char *s2, size_t n);

int mx_count_substr (const char *str, const char *sub) {
    if (!sub || !str)
        return -1;

    int i = 0;
    int sub_len = mx_strlen(sub);
    int cntr = 0;

    while (str[i]) {
        if(!mx_strncmp(&str[i], sub, sub_len))
            cntr++;
        i++;
    }

    return cntr;
}
