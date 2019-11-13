#include <stdlib.h>

int mx_abs(int n);
char *mx_strnew(const int size);
void mx_str_reverse(char *s);

char *mx_itoa(int number) {
    int len = 1;
    int minus = 0;
    int i = 0;
    char *num = NULL;

    if (number == -2147483648) {
        num = "-2147483648";
    }
    else if (number == 0) {
        num = "0";
    }
    else {
        if ((minus = number) < 0) { 
            len++;
            number = -number;
        }

        int temp = number;

        while ((temp / 10) > 0) {
            len++;
            temp /= 10;
        }

        num = mx_strnew(len);

        while (number != 0) {
            num[i++] = number % 10 + '0';
            number /= 10;
        }
        ///num[i++] = number % 10 + '0';

        if (minus < 0)
            num[i++] = '-';

        mx_str_reverse(num);
    }

    return num;
}
