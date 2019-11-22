#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int cntr = 0;
    char hexadecimal[100];
    char *res_str = mx_strnew(cntr);

    while(nbr != 0) {
        if((nbr%16) < 10)
            hexadecimal[cntr++] = 48 + (nbr%16);
        else 
            hexadecimal[cntr++] = 87 + (nbr%16);
        
        nbr /=16;
    }

    for(int i = 0; i < cntr; i++)
        res_str[i] = hexadecimal[cntr - 1 - i];

    return res_str;
}
