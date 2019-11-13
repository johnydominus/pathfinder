#include <stdlib.h>

int mx_strlen(const char *text);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, char *src);

char *mx_strdup(const char *str){
    char *new_str = mx_strnew(mx_strlen(str) * sizeof(char));
    mx_strcpy(new_str, (char*)str);
    return new_str;
}
