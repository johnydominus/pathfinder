#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

void my_print_unicode(wchar_t c);
void my_print_strarr(char **arr, const char *delim);
char *my_nbr_to_hex(unsigned long nbr);
char *my_itoa(int number);

static bool cmp_char (void *a, void *b) {
    if (mx_strcmp((char*)a, (char*)b) > 0)
        return true;
    else
        return false;
}

static void nbr_to_revhex(unsigned long *remainder,
                          unsigned long *nbr,
                          char *hex,
                          int *cntr);

static void swap(char *s1, char *s2)
{
  if(!s1 || !s2) {}
  else {
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
  }
}

int main () {

    printf("----------------------\n|-----UTILS PACK-----|\n----------------------\n\n\n");     

    printf("-----TESTING MX_PRINTCHAR-----\n\n");               //MX_PRINTCHAR

    char printmechar = 'l';

    printf("Test output:\n");
    putchar(printmechar);
    putchar('\n');
    putchar('\n');

    printf("User output:\n");
    mx_printchar(printmechar);
    putchar('\n');

    printf("\n\n-----TESTING MX_PRINT_UNICODE-----\n\n");       //MX_PRINT_UNICODE
           
    wchar_t c = 0x2605;

    printf("Test output:\n");
    
    my_print_unicode(c);
    putchar('\n');
    putchar('\n');

    printf("User output:\n");
    mx_print_unicode(c);
    putchar('\n');

    printf("\n\n-----TESTING MX_PRINTSTR-----\n\n");            //MX_PRINTSTR

    char *printstr_s = "This is a test string";

    printf("Test output:\n");
    printf("%s\n\n", printstr_s);
    
    printf("User output:\n");
    mx_printstr(printstr_s);
    putchar('\n');

    printf("\n\n-----TESTING MX_PRINT_STRARR-----\n\n");        //MX_PRINT_STRARR
            
    char *arr1[] = {"Hello", "World!", "Baraban", NULL};
    char *del = "*";
            
    printf("Test output:\n");
    if(*arr1 == NULL || del == NULL) {}
    else {
        int i = 0;
     
        while(arr1[i]) {
            if(i > 0)
                printf("%s", del);

            printf("%s", arr1[i++]);
        }
        putchar('\n');
        putchar('\n');
    }

    printf("User output:\n"); 
    mx_print_strarr(arr1, del);
    putchar('\n');

    printf("\n\n-----TESTING MX_PRINTINT-----\n\n");            //MX_PRINTINT
    
    int print_n = 153;
    int print_m = INT_MAX;
    int print_l = INT_MIN;
    int print_z = 0;

    printf("Test output:\n");
    printf("%d\n%d\n%d\n%d\n\n", print_n, print_m, print_l, print_z);

    printf("User output:\n");
    mx_printint(print_n);
    putchar('\n');
    mx_printint(print_m);
    putchar('\n');
    mx_printint(print_l);
    putchar('\n');
    mx_printint(print_z);
    putchar('\n');

    printf("\n\n-----TESTING MX_POW-----\n\n");                 //MX_POW
    printf("Test output:\n");
    printf("%.3f\n%.3f\n%.3f\n%.3f\n\n", pow(2,3), pow(5,0), pow(7.5, 3), pow(2,55));

    printf("User output:\n");
    printf("%.3f\n%.3f\n%.3f\n%.3f\n", mx_pow(2,3), mx_pow(5,0), mx_pow(7.5, 3), mx_pow(2,55));

    printf("\n\n-----TESTING MX_SQRT-----\n\n");                //MX_SQRT
    printf("Test output:\n");
    printf("%.0f\n%.0f\n%.0f\n\n", sqrt(25), sqrt(207025), sqrt(INT_MAX + 1));

    printf("User output:\n");
    printf("%d\n%d\n%d\n", mx_sqrt(25), mx_sqrt(207025), mx_sqrt(INT_MAX + 1));

    printf("\n\n-----TESTING MX_NBR_TO_HEX-----\n\n");          //MX_NBR_TO_HEX

    printf("Test output:\n");
    printf("%s\n%s\n%s\n%s\n\n", my_nbr_to_hex(52), my_nbr_to_hex(1000), my_nbr_to_hex(0), my_nbr_to_hex(10));

    printf("User output:\n");
    printf("%s\n%s\n%s\n%s\n\n", mx_nbr_to_hex(52), mx_nbr_to_hex(1000), mx_nbr_to_hex(0), mx_nbr_to_hex(10));

    printf("\n\n-----TESTING MX_ITOA-----\n\n");                //MX_ITOA

    printf("Test output:\n");
    printf("%s\n%s\n%s\n%s\n%s\n\n", my_itoa(0), 
                                     my_itoa(INT_MIN), 
                                     my_itoa(INT_MAX), 
                                     my_itoa(-123), 
                                     my_itoa(INT_MAX + 1));  

    printf("User output:\n");
    printf("%s\n%s\n%s\n%s\n%s\n\n", mx_itoa(0), 
                                     mx_itoa(INT_MIN), 
                                     mx_itoa(INT_MAX), 
                                     mx_itoa(-123), 
                                     mx_itoa(INT_MAX + 1));

    printf("\n\n-----TESTING MX_SWAP_CHAR-----\n\n");       //MX_SWAP_CHAR
    char str1[] = "ONE";

    printf("Test output:\n");
    swap(&str1[0],&str1[1]);
    printf("%s\n", str1);
    swap(&str1[1], &str1[2]);
    printf("%s\n\n", str1);

    char str2[] = "ONE";    

    printf("User output:\n");
    mx_swap_char(&str2[0], &str2[1]);
    printf("%s\n", str2);
    mx_swap_char(&str2[1], &str2[2]);
    printf("%s\n\n", str2);

    printf("\n\n-----TESTNG MX_SORT_LIST-----\n\n");        //MX_SORT_LIST
    char *n1 = "Allan";
    char *n2 = "Bob";
    char *n3 = "Clark";
    char *n4 = "Frank";

    t_list *aList = mx_create_node(n3);
    t_list *temp = aList;
    aList->next = mx_create_node(n2);
    aList->next->next = mx_create_node(n4);
    aList->next->next->next = mx_create_node(n1);    

    printf("Test output:\n");
    while (temp) {
        printf ("%s\n", temp->data);
        temp = temp->next;
    }
    printf("\nmx_sort_list function used\n\n%s\n%s\n%s\n%s\n\n\n", n1, n2, n3, n4);

    printf("User output:\n");
    temp = aList;
    while(temp) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }

    mx_sort_list(aList, cmp_char);
    printf("\nmx_sort_list function used.\n\n");
    temp = aList;
    while (temp) {
        printf ("%s\n", temp->data);
        temp = temp->next;   
    }

    printf("\n\n-----TESTING MX_STRTRIM-----\n\n");
    char *name = "\f  My name... is Neo \t\n";
    printf("Test output:\n");
    printf("%s", name);
    printf("My name... is Neo\n\n");

    printf("User output:\n");
    printf("%s", name);
    printf("%s\n\n", mx_strtrim(name));

    if (0) {                    //MX_POW
            printf("%.3f\n", mx_pow(7, 3));

    } else if (0) {            //MX_STR_REVERSE
            char s[] = "game over";
            printf("%s\n", s);
            
            mx_str_reverse(s);
            printf("%s\n", s);
        
    } else if (0) {                   //MX_ITOA
            printf("%s\n", mx_itoa(0));
            printf("%s\n", mx_itoa(INT_MIN));
            printf("%s\n", mx_itoa(INT_MAX));
            printf("%s\n", mx_itoa(-123));
            printf("%s\n", mx_itoa(100));

    } else if (0) {                 //MX_STRDEL
            char *str = mx_strnew(6);
            str = "Hello!";
            printf("%s\n", str);
            mx_strdel(&str);
            printf("%s\n", str);

    } else if (0) {                 //MX_STRCPY
            char str[] = "Hello!";
            char *str1 = mx_strnew(6);
            mx_strcpy(str1, str);
            printf("%s\n", str1);

    } else if (0) {                //MX_STRNCPY
            char src[] = "Hello, World!";
            char *dst = mx_strnew(4);
            
            mx_strncpy(dst, src, 4);
            printf("%s\n", dst);

    } else if (0) {                //MX_STRNDUP
            char src[] = "Hello, World!";
            printf("%s\n", mx_strndup(src, 4));

    } else if (0) {                 //MX_STRSTR
            const char largestring[] = "Foo Bar Baz";
            const char smallstring[] = "Bar";
            char *ptr = mx_strstr(largestring, smallstring);
            printf("%s\n", ptr);

    } else if (0) {                //MX_STRTRIM
            char *name = "\f  My name... is Neo \t\n";
            printf("%s\n", mx_strtrim(name));

    } else if (0) {
            char *name = "****My name... is Neo****";
            printf("%s\n", mx_strtrim_delim(name, '*'));
    
    }else if (0) {       //MX_DEL_EXTRA_SPACES
            char *name = "\f   My name... \n   is \r Neo   \f\t";
            printf("%s\n", mx_del_extra_spaces(name));
    
    } else if (0) {                //MX_STRJOIN
            char *s1 = "dodge ";
            char *s2 = "this";
            char *s3 = NULL;
            printf("%s\n", mx_strjoin(s1, s2));
            printf("%s\n", mx_strjoin(s1, s3));
            printf("%s\n", mx_strjoin(s3, s3));
    } else if (0) {              //MX_QUICKSORT
            char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
            printf("%d\n", mx_quicksort(arr, 0, 3));
            char d = '\n';
            mx_print_strarr(arr, &d);
    } else if (0){                  //MX_STRSTR
            const char *largestring = "Foo Bar Baz";
            const char *smallstring = "Bar";
            const char *bam = "Baraban";
            char *ptr = NULL;

            ptr = mx_strstr(largestring, bam);
            printf("%s\n", ptr);
            ptr = mx_strstr(largestring, smallstring);
            printf("%s\n", ptr);
            printf("%s\n", mx_strstr(largestring, NULL));
    } else if (0) {        //MX_GET_SUBSTR_INDEX
            printf("%d\n", mx_get_substr_index("McDonalds", "Don"));
            printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
            printf("%d\n", mx_get_substr_index("McDonalds", "Donatello"));
            printf("%d\n", mx_get_substr_index("McDonalds", NULL));
            printf("%d\n", mx_get_substr_index(NULL, "Don"));
    } else if (0) {           //MX_COUNT_SUBSTR
            char *str = "yo, yo, yo, Neo";
            char *sub = "yo";

            printf("%d\n", mx_count_substr(str, sub));
            printf("%d\n", mx_count_substr(str, NULL));
            printf("%d\n", mx_count_substr(NULL, sub));
    } else if (0) {           //MX_STRLEN_DELIM
            printf("%d\n", mx_strlen_delim("Don****", '*'));
    } else if (0) {               //MX_STRSPLIT
            char *s = "**Good bye,**Mr.*Anderson.****";
            char **arr = mx_strsplit(s, '*');
            const char c = '\n';
            mx_print_strarr(arr, &c);
            char *s1 = " Knock, knock, Neo. ";
            char **arr1 = mx_strsplit(s1, ' ');
            mx_print_strarr(arr1, &c);            
    } else if (0) {            //MX_FILE_TO_STR
            printf("%s", mx_file_to_str("afile"));
    } else if (0) {               //MX_POP_BACK
            char *s1 = "first"; 
            char *s2 = "second";
            t_list *aList = mx_create_node(s1);
            aList->next = mx_create_node(s2);
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");
            mx_pop_back(&aList);
            printf("mx_pop_back function used.\n");
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");         
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");             
    } else if (0) {              //MX_POP_FRONT
            char *s1 = "first";
            char *s2 = "second";
            t_list *aList = mx_create_node(s1);
            aList->next = mx_create_node(s2);
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");
            mx_pop_front(&aList);
            printf("mx_pop_front function used.\n");
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");
    } else if (0) {              //MX_PUSH_BACK
            char *s1 = "first";
            char *s2 = "second";
            t_list *aList = mx_create_node(s1);
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");
            mx_push_back(&aList, s2);
            printf("mx_push_back function used.\n");
            if(aList)
                printf("%s\n", aList->data);
            else
                printf("There is no list.\n");
            if(aList->next)
                printf("%s\n", aList->next->data);
            else
                printf("There is no second list.\n");
    } else if (0) {              //MX_SORT_LIST
            char *s1 = "Allan";
            char *s2 = "Bob";
            char *s3 = "Clark";
            char *s4 = "fourth";

            t_list *aList = mx_create_node(s3);
            t_list *temp = aList;
            aList->next = mx_create_node(s2);
            aList->next->next = mx_create_node(s4);
            aList->next->next->next = mx_create_node(s1);
            
            while (temp) {
                printf ("%s\n", temp->data);
                temp = temp->next;
            }

            mx_sort_list(aList, cmp_char);
            printf("mx_sort_list function used.\n");
            temp = aList;
            while (temp) {
                printf ("%s\n", temp->data);
                temp = temp->next;
            }
    } else if (0) {         //MX_REPLACE_SUBSTR
            char *str1 = "McDonalds";
            char *sub1 = "alds";
            char *replace1 = "uts";
            printf ("%s\n%s\n%s\n", str1, sub1, replace1);
            printf ("%s\n", mx_replace_substr(str1, sub1, replace1));
            char *str2 = "Ururu turu";
            char *sub2 = "ru";
            char *replace2 = "ta";
            printf ("%s\n%s\n%s\n", str2, sub2, replace2);
            printf ("%s\n", mx_replace_substr(str2, sub2, replace2));
    } else if (0) {              //MX_READ_LINE
            int fd = open("fragment", O_RDONLY);
            char *str = NULL;
            int res;
            res = mx_read_line(&str, 20, 'f', fd);
            printf("%s\n%d\n", str, res);
            res = mx_read_line(&str, 35, 't', fd);
            printf("%s\n%d\n", str, res);
            res = mx_read_line(&str, 4, 'z', fd);
            printf("%s\n%d\n", str, res);
    } else if (0) {                 //MX_MEMSET
            char str[50];

            mx_strcpy(str, "This is libmx.h library function");
            puts(str);

            mx_memset(str, '$', 7);
            puts(str);
    } else if (0) {                 //MX_MEMCPY
            char dst[] = "This is destination string.";
            char src[] = "NO MORE ";

            puts(dst);

            mx_memcpy(dst, src, 8);
            puts(dst);
    } else if (0) {                //MX_MEMCCPY
            char string1[60] = "Taj Mahal is a historic monument in India.";
            char buffer[61];
            char *pdest;
            printf("Function: _memccpy 42 characters or to character 'c'\n");
            printf("Source: %s\n", string1);
            pdest = mx_memccpy(buffer, string1, 'c', 42);
            *pdest = '\0';
            printf("Result: %s\n", buffer);
            printf("Length: %lu characters\n", strlen(buffer));
            printf("----------------\n");
            char *msg = "This is the string: not copied";
            char buffer1[80];
            mx_memset(buffer1, '\0', 80);
            mx_memccpy(buffer1, msg, ':', 80);
            printf("%s\n", buffer1);
    } else if (0) {
            unsigned char src[15] = "1234567890";
            unsigned char dst[15] = "1234567890";
            int res;

            if ((res = mx_memcmp(src, dst, 10)) == 0)
                puts ("Memory areas are identical");
            else 
                printf ("Memory areas differ.\n%d\n", res);
    } else {
            printf("There is no such function in test list.\n");
    }
}

void my_print_unicode(wchar_t c) {
    char str[5];

    if(c < 0x80) {
        str[0] = ((c >> 0) & 0x7F) | 0x00;
        str[1] = '\0';
        str[2] = '\0';
        str[3] = '\0';
        str[4] = '\0';
    }
    else if(c < 0x0800) {
        str[0] = ((c >> 6) & 0x1F) | 0xC0;
        str[1] = ((c >> 0) & 0x3F) | 0x80;
        str[2] = '\0';
        str[3] = '\0';
        str[4] = '\0';
    }
    else if(c < 0x010000) {
        str[0] = ((c >> 12) & 0x0F) | 0xE0;
        str[1] = ((c >> 6 ) & 0x3F) | 0x80;
        str[2] = ((c >> 0 ) & 0x3F) | 0x80;
        str[3] = '\0';
        str[4] = '\0';
    }
    else if(c < 0x110000) {
        str[0] = ((c >> 18) & 0x07) | 0xF0;
        str[1] = ((c >> 12) & 0x3F) | 0x80;
        str[2] = ((c >> 6 ) & 0x3F) | 0x80;
        str[3] = ((c >> 0 ) & 0x3F) | 0x80;
        str[4] = '\0';
    }
    write(1, str, mx_strlen(str));
}

void my_print_strarr(char **arr, const char *delim) {
    if(arr == NULL || delim == NULL) {}
    else {
        int i = 0;

        while(arr[i]) {
            if(i > 0)
                write(1, delim, 1);

            mx_printstr(arr[i++]);
        }
        mx_printstr("\n");
    }
}

static void nbr_to_revhex(unsigned long *remainder,
                          unsigned long *nbr,
                          char *hex,
                          int *cntr);

char *my_nbr_to_hex(unsigned long nbr) {
    unsigned long remainder;
    int j = 0;
    char hexadecimal[100];

    if(nbr == 0)
        return "0";

    nbr_to_revhex(&remainder, &nbr, hexadecimal, &j);

    char *res_str = mx_strnew(j);

    for(int i = 0; i < j; i++)
        res_str[i] = hexadecimal[j - 1 - i];

    return res_str;
}

static void nbr_to_revhex(unsigned long *remainder,
                          unsigned long *nbr,
                          char *hex,
                          int *cntr) {
    while(*nbr != 0) {
        *remainder = (*nbr)%16;
        if(*remainder < 10) {
            hex[(*cntr)++] = 48 + *remainder;
        }
        else
            hex[(*cntr)++] = 87 + *remainder;

        *nbr /= 16;
    }
}

char *my_itoa(int number) {
    int len = 1;
    int minus = 0;
    int i = 0;
    int temp;
    char *num = NULL;

    if (number == -2147483648)
        num = "-2147483648";
    else if (number == 0)
        num = "0";
    else {
        if ((minus = number) < 0) { 
            len++;
            number = -number;
        }

        temp = number;

        while ((temp / 10) > 0) {
            len++;
            temp /= 10;
        }

        num = mx_strnew(len);

        while (number != 0) {
            num[i++] = number % 10 + '0';
            number /= 10;
        }

        if (minus < 0)
            num[i++] = '-';

        mx_str_reverse(num);
    }

    return num;
}
