#include <stdlib.h>

void mx_strdel(char **str);

void mx_del_strarr(char ***arr) {
    char **temp = *arr;

    while(temp != NULL)
        mx_strdel(temp++);

    free(arr);
    arr = NULL;
}
