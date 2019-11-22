#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(arr == NULL || delim == NULL) {}
    else {
        int i = 0;
        
        while(arr[i]) {
            if(i > 0)
                write(1, delim, 1);
            
            mx_printstr(arr[i++]);
        }
        mx_printstr("\n");
    }
}
