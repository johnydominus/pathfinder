char *mx_strnew(const int size);

char *mx_nbr_to_hex(unsigned long nbr){
    unsigned long remainder;
    int cntr = 0;
    int j = 0;
    
    char hexadecimal[100];
    
    while(nbr != 0){
        remainder = nbr%16;
        if(remainder < 10){
            hexadecimal[j++] = 48 + remainder;
            cntr++;
        }
        else{
            hexadecimal[j++] = 87 + remainder;
            cntr++;
        }
        nbr /=16;
    }

    char *res_str = mx_strnew(cntr);
    
    for(int i = 0; i < cntr; i++)
        res_str[i] = hexadecimal[cntr - 1 - i];

    return res_str;
}
