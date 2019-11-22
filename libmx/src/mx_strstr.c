#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if(!needle)
        return (char*)haystack;

    char *buf = (char*)haystack;    
    int need_len = mx_strlen(needle);

    while(buf) {
        if(!mx_strncmp(buf, needle, need_len))
            return buf;
        buf++;
    }

    return NULL;    
}
