#include <stdio.h>

int mx_isspace(char c);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strndup(const char *s1, size_t n);

char *mx_strtrim(const char *str) {
    int st_spaces = 0;
    int end_spaces = mx_strlen(str);

    while(mx_isspace(str[st_spaces])){
        st_spaces++;
    }

    while(mx_isspace(str[end_spaces - 1])){
        end_spaces--;
    }

    return mx_strndup (&str[st_spaces], end_spaces - st_spaces);  
}
