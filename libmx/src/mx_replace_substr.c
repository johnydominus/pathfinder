#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(!str || !sub || !replace)
        return NULL;

    int sub_len = mx_strlen(sub);
    int diff = mx_strlen(replace) - sub_len;
    char *res = mx_strnew(mx_strlen(str) + (diff * mx_count_substr(str, sub)));
    int i = 0;
    int j = 0;

    while(str[i]) {
        if(mx_strncmp(&str[i], sub, sub_len) == 0) {
            mx_strncpy(&res[j], replace, sub_len);
            i += sub_len;
            j += sub_len;
        } 
        else
            res[j++] = str[i++];
    }
    
    res[j] = '\0';
    return res;
}
