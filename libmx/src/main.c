#include <stdio.h>
#include <wchar.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

void mx_printstr(const char *str);
void mx_print_strarr (char **arr, const char *delim);
void mx_swap_char (char *s1, char *s2);
void mx_print_unicode (wchar_t c);
void mx_str_reverse (char *s);
char *mx_itoa (int n);
double mx_pow (double n, unsigned int pow);
void mx_strdel (char **str);
void *mx_strnew (const char size);
void mx_pop_back (t_list **head);
void mx_pop_front (t_list **head);
void mx_push_back (t_list **list, void *data);
int mx_get_char_index (const char *str, char c);
char *mx_strncpy (char *dst, const char *src, int len);
char *mx_strcpy (char *dst, const char *src);
char *mx_strndup (const char *s1, size_t n);
char *mx_strstr (const char *haystack, const char *needle);
char *mx_strtrim (const char *str);
char *mx_strtrim_delim (const char *str, const char delim);
char *mx_del_extra_spaces(const char *s);
char *mx_strjoin (const char *s1, const char *s2);
char *mx_strstr (const char *haystack, const char *needle);
char **mx_strsplit (const char *s, char c);
char *mx_file_to_str (const char *filename);
int mx_quicksort (char **arr, int left, int right);
int mx_get_substr_index (const char *str, const char *sub);
int mx_count_substr (const char *str, const char *sub);
int mx_strlen_delim (const char *s, char delim);
int mx_strcmp (const char *s1, const char *s2);
t_list *mx_create_node (void *data);
t_list *mx_sort_list (t_list *lst, bool (*cmp)(void *, void *));

bool cmp_char (void *a, void *b) {
    if (mx_strcmp((char*)a, (char*)b) > 0)
        return true;
    else
        return false;
}


int main (int argc, char **argv) {
    if (argc < 2) {
        printf ("Please enter the name of tested function.\n");
        return 0;
    }

    if (!strcmp(argv[1], "mx_print_strarr")) {                  //MX_PRINT_STRARR  
            char *arr1[] = {"Hello", "World!", "Baraban", NULL};
            char *del = "*";
            
            mx_print_strarr(arr1, del);

    } else if (!strcmp(argv[1], "mx_swap_char")) {              //MX_SWAP_CHAR
            char str1[] = "ONE";
    
            mx_swap_char(&str1[0], &str1[1]);
            printf("%s\n", str1);
            mx_swap_char(&str1[1], &str1[2]);
            printf("%s\n", str1);

    } else if (!strcmp(argv[1], "mx_print_unicode")) {          //MX_PRINT_UNICODE
            wchar_t c = 0x2605;    
            
            mx_print_unicode(c);
            putchar('\n');

    } else if (!strcmp(argv[1], "mx_pow")) {                    //MX_POW
            printf("%.3f\n", mx_pow(7, 3));

    } else if (!strcmp(argv[1], "mx_str_reverse")) {            //MX_STR_REVERSE
            char s[] = "game over";
            printf("%s\n", s);
            
            mx_str_reverse(s);
            printf("%s\n", s);
        
    } else if (!strcmp(argv[1], "mx_itoa")) {                   //MX_ITOA
            printf("%s\n", mx_itoa(0));
            printf("%s\n", mx_itoa(INT_MIN));
            printf("%s\n", mx_itoa(INT_MAX));
            printf("%s\n", mx_itoa(-123));
            printf("%s\n", mx_itoa(100));

    } else if (!strcmp(argv[1], "mx_strdel")) {                 //MX_STRDEL
            char *str = mx_strnew(6);
            str = "Hello!";
            printf("%s\n", str);
            mx_strdel(&str);
            printf("%s\n", str);

    } else if (!strcmp(argv[1], "mx_strcpy")) {                 //MX_STRCPY
            char str[] = "Hello!";
            char *str1 = mx_strnew(6);
            mx_strcpy(str1, str);
            printf("%s\n", str1);

    } else if (!strcmp(argv[1], "mx_strncpy")) {                //MX_STRNCPY
            char src[] = "Hello, World!";
            char *dst = mx_strnew(4);
            
            mx_strncpy(dst, src, 4);
            printf("%s\n", dst);

    } else if (!strcmp(argv[1], "mx_strndup")) {                //MX_STRNDUP
            char src[] = "Hello, World!";
            printf("%s\n", mx_strndup(src, 4));

    } else if (!strcmp(argv[1], "mx_strstr")) {                 //MX_STRSTR
            const char largestring[] = "Foo Bar Baz";
            const char smallstring[] = "Bar";
            char *ptr = mx_strstr(largestring, smallstring);
            printf("%s\n", ptr);

    } else if (!strcmp(argv[1], "mx_strtrim")) {                //MX_STRTRIM
            char *name = "\f  My name... is Neo \t\n";
            printf("%s\n", mx_strtrim(name));

    } else if (!strcmp(argv[1], "mx_strtrim_delim")) {
            char *name = "****My name... is Neo****";
            printf("%s\n", mx_strtrim_delim(name, '*'));
    
    }else if (!strcmp(argv[1], "mx_del_extra_spaces")) {       //MX_DEL_EXTRA_SPACES
            char *name = "\f   My name... \n   is \r Neo   \f\t";
            printf("%s\n", mx_del_extra_spaces(name));
    
    } else if (!strcmp(argv[1], "mx_strjoin")) {                //MX_STRJOIN
            char *s1 = "dodge ";
            char *s2 = "this";
            char *s3 = NULL;
            printf("%s\n", mx_strjoin(s1, s2));
            printf("%s\n", mx_strjoin(s1, s3));
            printf("%s\n", mx_strjoin(s3, s3));
    } else if (!strcmp(argv[1], "mx_quicksort")) {              //MX_QUICKSORT
            char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
            printf("%d\n", mx_quicksort(arr, 0, 3));
            char d = '\n';
            mx_print_strarr(arr, &d);
    } else if (!strcmp(argv[1], "mx_strstr")){                  //MX_STRSTR
            const char *largestring = "Foo Bar Baz";
            const char *smallstring = "Bar";
            const char *bam = "Baraban";
            char *ptr = NULL;

            ptr = mx_strstr(largestring, bam);
            printf("%s\n", ptr);
            ptr = mx_strstr(largestring, smallstring);
            printf("%s\n", ptr);
            printf("%s\n", mx_strstr(largestring, NULL));
    } else if (!strcmp(argv[1], "mx_get_substr_index")) {        //MX_GET_SUBSTR_INDEX
            printf("%d\n", mx_get_substr_index("McDonalds", "Don"));
            printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
            printf("%d\n", mx_get_substr_index("McDonalds", "Donatello"));
            printf("%d\n", mx_get_substr_index("McDonalds", NULL));
            printf("%d\n", mx_get_substr_index(NULL, "Don"));
    } else if (!strcmp(argv[1], "mx_count_substr")) {           //MX_COUNT_SUBSTR
            char *str = "yo, yo, yo, Neo";
            char *sub = "yo";

            printf("%d\n", mx_count_substr(str, sub));
            printf("%d\n", mx_count_substr(str, NULL));
            printf("%d\n", mx_count_substr(NULL, sub));
    } else if (!strcmp(argv[1], "mx_strlen_delim")) {           //MX_STRLEN_DELIM
            printf("%d\n", mx_strlen_delim("Don****", '*'));
    } else if (!strcmp(argv[1], "mx_strsplit")) {               //MX_STRSPLIT
            char *s = "**Good bye,**Mr.*Anderson.****";
            char **arr = mx_strsplit(s, '*');
            const char c = '\n';
            mx_print_strarr(arr, &c);
            char *s1 = " Knock, knock, Neo. ";
            char **arr1 = mx_strsplit(s1, ' ');
            mx_print_strarr(arr1, &c);            
    } else if (!strcmp(argv[1], "mx_file_to_str")) {
            printf("%s", mx_file_to_str("afile"));
    } else if (!strcmp(argv[1], "mx_pop_back")) {
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
    } else if (!strcmp(argv[1], "mx_pop_front")) {
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
    } else if (!strcmp(argv[1], "mx_push_back")) {
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
    } else if (!strcmp(argv[1], "mx_sort_list")) {
            char *s1 = "Allan";
            char *s2 = "Bob";
            char *s3 = "Clark";
            char *s4 = "Frank";

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
    } else {
            printf("There is no such function in test list.\n");
    }
}
