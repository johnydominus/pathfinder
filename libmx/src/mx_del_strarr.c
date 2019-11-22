#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **temp = *arr;

    while(temp != NULL)
        mx_strdel(temp++);

    free(arr);
    arr = NULL;
}
