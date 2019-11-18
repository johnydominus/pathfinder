#include <stdio.h>

int mx_get_substr_index (const char *str, const char *sub);
int mx_strlen (const char *str);
char *mx_strnew (const int size);
char *mx_strdup (const char *str);

char *mx_replace_substr (const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;
    
    if (mx_get_substr_index (str, sub) == -1)
        return mx_strdup (str);

    int sub_len = mx_strlen(sub);
    int diff = mx_strlen(replace) - sub_len;
    int i = 0;
    int subs = 0;

    while (str[i]) {
        if (mx_get_substr_index (str, sub) >= 0) {
            diff = 0;
            subs = 0;
            return (char*)replace; //!!! 
        }
    }
    return (char*)replace;     //!!!
}
