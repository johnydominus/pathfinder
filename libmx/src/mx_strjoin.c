#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if(s1 && s2) {
        int s1_len = mx_strlen(s1);
        int s2_len = mx_strlen(s2);
        char *res = mx_strnew((s1_len + s2_len) * sizeof(char*));

        mx_strncpy(res, s1, s1_len);
        mx_strncpy(res + s1_len, s2, s2_len);
        
        if (res)
            return res;
        else
            return NULL;
    } else if (s1 && !s2) {
        return mx_strdup(s1);
    } else if (!s1 && s2) { 
        return mx_strdup(s2);
    } else {
        return NULL;
    }
}
