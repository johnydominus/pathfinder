#include <stdio.h>
#include <stdlib.h>

int mx_count_words(const char *str, char c);
int mx_strlen(const char *str);
int mx_strlen_delim(const char *str, char c);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_get_char_index(const char *str, char c);
char *mx_strndup(const char *s, size_t n);
char *mx_strdup(const char *s);

char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;

    int size_arr = mx_count_words(s, c);
    char **result = malloc(sizeof(char *) * (size_arr + 1));
    int len = 0;
    int i = 0;

    for (int j = 0; j < size_arr; ++j) {
        while (s[i] == c && s[i++]) {}
        len = mx_strlen_delim (&s[i], c);
        result[j] = mx_strndup(&s[i], len);
        i += len;
        len = 0;
    }

    result[size_arr] = NULL;
    return result;
}
