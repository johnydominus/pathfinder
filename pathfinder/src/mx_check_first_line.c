#include "pathfinder.h"

int mx_check_first_line (char *str, int *iter) {
    if(str[0] == '\n')
        return false;
    for(int i = 0; str[i] != '\n'; ++i) {
        *iter = i;
        if(!mx_isdigit(str[i])) {
            if(i == 0 && str[i] == '-')
                continue;
            else            
                return false;
        }
    }
    return true;
}
