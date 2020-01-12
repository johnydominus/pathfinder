#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **temp = *arr;
    char ***tempp = arr;

    while(**tempp != NULL)
        mx_strdel((temp)++);

    free(temp);
    *arr = NULL;
}
