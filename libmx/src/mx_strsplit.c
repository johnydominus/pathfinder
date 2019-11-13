#include <stdio.h>

char *mx_strtrim_delim (const char *s, const char delim);
char *mx_strndup (const char *s, size_t n);
int mx_count_words (const char *s, char delimiter);
int mx_strlen_delim (const char *s, char delim);

char **mx_strsplit (const char *s, char c) {
    char **arr = NULL;
    int i = 0;
    int j = 0;

    char *s_trim = mx_strtrim_delim(s, c);

    printf("1\n");
    while (s_trim[i]) {
        if (s_trim[i] != c){
            arr[j++] = mx_strndup(&s_trim[i], mx_strlen_delim(&s_trim[i], c));
            printf("2\n");
            i += mx_strlen_delim(&s_trim[i], c);
        } else {
            i++;
            printf("3\n");
        }
    }
    printf("4\n");
    arr[j] = NULL;

    return arr;
}
