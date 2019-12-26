#include "pathfinder.h"

int mx_check_first_line (char *str, int *iter) {
    for(int i = 0; str[i] != '\n'; ++i) {
        *iter = i;
        if(!mx_isdigit(str[i]))
            return false;
    }
    return true;
}
