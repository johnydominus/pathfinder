#include "pathfinder.h"

bool mx_check_first_line (char *str, int *iter) {
    if(str[0] == '\n') {
        mx_error(INVALID_FIRST_LINE, NULL);
        return false;
    }
    for(int i = 0; str[i] != '\n'; ++i) {
        ++(*iter);
        if(!mx_isdigit(str[i])) {
            if(i == 0 && str[i] == '-')
                continue;
            else {
                mx_error(INVALID_FIRST_LINE, NULL);
                return false;
            }
        }
    }
    ++(*iter);
    return true;
}
