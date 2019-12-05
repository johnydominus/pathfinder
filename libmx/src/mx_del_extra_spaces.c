#include "libmx.h"

static int final_length(const char *s);

char *mx_del_extra_spaces(const char *str) {
    char *pre = mx_strtrim(str);
    char *res = mx_strnew(final_length(pre));
    char *iter = res;
    
    if(!str)
        return NULL;

    while(*pre) {
        if(mx_isspace(*pre) && mx_isspace(*(pre + 1))) {}
        else {
            if(mx_isspace(*pre)) 
                *iter++ = ' ';
            else 
                *iter++ = *pre;
        ++pre;
        }
    }

    return res;
}

static int final_length(const char *s) {
    int spaces = 0;
    int len = 0;

    while(*s) {
        if(spaces) {}
        else
            ++len;

        if (mx_isspace(*s++))
            ++spaces;
        else
            spaces = 0;
    }
        
    return len;
}
