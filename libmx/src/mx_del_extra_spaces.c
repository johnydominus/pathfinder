char *mx_strtrim(const char *str);
char *mx_strnew(const int size);
int mx_isspace(char c);
static int final_length(const char *s);

char *mx_del_extra_spaces (const char *str) {
    char *pre = mx_strtrim(str);
    int spaces = 0;
    
    char *res = mx_strnew(final_length(pre));
    char *iter = res;

    while (*pre) {
        if(mx_isspace(*pre))
            spaces++;
        else
            spaces = 0;

        if (spaces > 1) {}
        else 
            *iter++ = *pre;
        pre++;
    }
    return res;
}

static int final_length(const char *s) {
    int spaces = 0;
    int len = 0;

    while(*s){
        if(spaces){}
        else
            len++;

        if (mx_isspace(*s++))
            spaces++;
        else
            spaces = 0;
    }
        
    return len;
}
