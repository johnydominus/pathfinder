#include <unistd.h>

int mx_strlen(const char *str);

void mx_printerr(const char *s){
    write(2, s, mx_strlen(s) * sizeof(char));
}
