#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <limits.h>

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

void test_header(char *testname) {
    printf("\n\n-----TESTING %s-----\n\n", testname);
}

void tu_output(char *tu) {
    if(!mx_strcmp(tu, "test"))
        printf("Test output:\n");
    else if(!mx_strcmp(tu, "user"))
        printf("User output:\n");

}

int main (int argc, char *argv[]) {
    if(argc < 2) {printf("usage:\n./test 'name of a function' //to test certain function\n./test all //to test all available functions\n");
        return 0;
    }

    if(!mx_strcmp(argv[1], "all")) {
        printf("\n                        TESTING YOUR LIBRARY!\n\n");
        printf("----------------------\n|-----UTILS PACK-----|\n----------------------\n");
    }

    if(!mx_strcmp(argv[1], "mx_printchar") || !mx_strcmp(argv[1], "all")) {
        test_header("MX_PRINTCHAR");                                //MX_PRINTCHAR

        char printmechar = 'l';

        printf("Test output:\n");
        putchar(printmechar);
        putchar('\n');
        putchar('\n');

        printf("User output:\n");
        mx_printchar(printmechar);
        putchar('\n');
    }
    
    if(!mx_strcmp(argv[1], "mx_print_unicode") || !mx_strcmp(argv[1], "all")) {
        test_header("MX_PRINT_UNICODE");                            //MX_PRINT_UNICODE
            
        wchar_t c = 0x2605;

        printf("Test output:\n");
        
        my_print_unicode(c);
        putchar('\n');
        putchar('\n');

        printf("User output:\n");
        mx_print_unicode(c);
        putchar('\n');
    }

    if(!mx_strcmp(argv[1], "mx_printstr") || !mx_strcmp(argv[1], "all")) {
        printf("\n\n-----TESTING MX_PRINTSTR-----\n\n");            //MX_PRINTSTR

        char *printstr_s = "This is a test string";

        printf("Test output:\n");
        printf("%s\n\n", printstr_s);
        
        printf("User output:\n");
        mx_printstr(printstr_s);
        putchar('\n');
    }
    
    if(!mx_strcmp(argv[1], "mx_print_strarr") || !mx_strcmp(argv[1], "all")) {
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
    }

    if(!mx_strcmp(argv[1], "mx_printint") || !mx_strcmp(argv[1], "all")) {
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
    }

    if(!mx_strcmp(argv[1], "mx_pow") || !mx_strcmp(argv[1], "all")) {
        printf("\n\n-----TESTING MX_POW-----\n\n");                 //MX_POW
        printf("Test output:\n");
        printf("%.3f\n%.3f\n%.3f\n%.3f\n\n", pow(2,3), pow(5,0), pow(7.5, 3), pow(2,55));

        printf("User output:\n");
        printf("%.3f\n%.3f\n%.3f\n%.3f\n", mx_pow(2,3), mx_pow(5,0), mx_pow(7.5, 3), mx_pow(2,55));
    }

    if(!mx_strcmp(argv[1], "mx_sqrt") || !mx_strcmp(argv[1], "all")) {
        printf("\n\n-----TESTING MX_SQRT-----\n\n");                //MX_SQRT
        printf("Test output:\n");
        printf("%.0f\n%.0f\n%.0f\n\n", sqrt(25), sqrt(207025), sqrt(INT_MAX + 1));

        printf("User output:\n");
        printf("%d\n%d\n%d\n", mx_sqrt(25), mx_sqrt(207025), mx_sqrt(INT_MAX + 1));

/*        printf("\n\n-----TESTING MX_NBR_TO_HEX-----\n\n");          //MX_NBR_TO_HEX

        printf("Test output:\n");
        printf("%s\n%s\n%s\n%s\n\n", my_nbr_to_hex(52), my_nbr_to_hex(1000), my_nbr_to_hex(0), my_nbr_to_hex(10));

        printf("User output:\n");
        printf("%s\n%s\n%s\n%s\n\n", mx_nbr_to_hex(52), mx_nbr_to_hex(1000), mx_nbr_to_hex(0), mx_nbr_to_hex(10));
    }
*/
    if(!mx_strcmp(argv[1], "mx_itoa") || !mx_strcmp(argv[1], "all")) {
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
    }

 /*   if(!mx_strcmp(argv[1], "mx_quicksort") || !mx_strcmp(argv[1], "all")) {             
        test_header("MX_QUICKSORT");
        char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael", NULL};
        char *arr1[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Beef Tannen", NULL};
        char d = '\n';

        tu_output("test");
        printf("2\n");
        printf("%s\n%s\n%s\n%s\n\n", arr[0], arr[1], arr[3], arr[2]);
        printf("2\n");
        printf("%s\n%s\n%s\n%s\n%s\n%s\n\n", arr1[0], arr1[4], arr1[2], arr1[3], arr1[5], arr1[1]);

        tu_output("user");
        printf("%d\n", mx_quicksort(arr, 0, 3));
        mx_print_strarr(arr, &d);
        printf("\n%d\n", mx_quicksort(arr1, 0, 5));
        mx_print_strarr(arr1, &d);
    }
*/
    if(!mx_strcmp(argv[1], "all"))
        printf("\n\n-----------------------\n|-----STRING PACK-----|\n-----------------------\n");

    if(!mx_strcmp(argv[1], "mx_swap_char") || !mx_strcmp(argv[1], "all")) {
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
    }

    if(!mx_strcmp(argv[1], "mx_str_reverse") || !mx_strcmp(argv[1], "all")) {              //MX_STR_REVERSE
    
        test_header("MX_STR_REVERSE");
        char s[] = "game over";
        tu_output("test");
        printf("%s\nrevo emag\n\n", s);
          
        tu_output("user");
        printf("%s\n", s);
        mx_str_reverse(s);
        printf("%s\n", s);
    }

    if(!mx_strcmp(argv[1], "mx_strtrim") || !mx_strcmp(argv[1], "all")) {                   //MX_STRTRIM
        printf("\n\n-----TESTING MX_STRTRIM-----\n\n");
        char *name = "\f  My name... is Neo \t\n";
        printf("Test output:\n");
        printf("%s", name);
        printf("My name... is Neo\n\n");

        printf("User output:\n");
        printf("%s", name);
        printf("%s\n\n", mx_strtrim(name));
    }

    if(!mx_strcmp(argv[1], "mx_strcpy") || !mx_strcmp(argv[1], "all")) {                    //MX_STRCPY
        test_header("MX_STRCPY");
        char str[] = "Hello!";
        tu_output("test");
        printf("%s\n%s\n\n", str, str);

        tu_output("user");
        printf("%s\n", str);
        char *str1 = mx_strnew(6);
        mx_strcpy(str1, str);
        printf("%s\n", str1);
    }

    if(!mx_strcmp(argv[1], "mx_strncpy") || !mx_strcmp(argv[1], "all")) {                   //MX_STRNCPY
        test_header("MX_STRNCPY");
        char src[] = "Hello, World!";
        char *dst = mx_strnew(4);
        
        tu_output("test");
        printf("%s\nHell\n\n", src);

        tu_output("user");
        printf("%s\n", src);
        mx_strncpy(dst, src, 4);
        printf("%s\n", dst);
    }

    if(!mx_strcmp(argv[1], "mx_strndup") || !mx_strcmp(argv[1], "all")) {                   //MX_STRNDUP
        test_header("MX_STRNDUP");
        char src1[] = "Abatur processing flash";
        
        tu_output("test");
        printf("%s\nAbat\n\n", src1);
        
        tu_output("user");
        printf("%s\n%s\n", src1, mx_strndup(src1, 4));
    }

    if(!mx_strcmp(argv[1], "mx_strstr") || !mx_strcmp(argv[1], "all")) {                    //MX_STRSTR
        test_header("MX_STRSTR");
        const char largestring[] = "Foo Bar Baz";
        const char smallstring[] = "Bar";
        
        tu_output("test");
        printf("%s\n%s\nBar Baz\n\n", largestring, smallstring);

        tu_output("user");
        printf("%s\n%s\n", largestring, smallstring);
        char *ptr = mx_strstr(largestring, smallstring);
        printf("%s\n", ptr);
    }

    if(!mx_strcmp(argv[1], "mx_strjoin") || !mx_strcmp(argv[1], "all")) {                   //MX_STRJOIN
        test_header("MX_STRJOIN");
        char *s1 = "dodge ";
        char *s2 = "this";
        char *s3 = NULL;
        tu_output("test");
        printf("%s%s\n%s\n%s\n\n", s1, s2, s1, NULL);

        tu_output("user");
        printf("%s\n", mx_strjoin(s1, s2));
        printf("%s\n", mx_strjoin(s1, s3));
        printf("%s\n", mx_strjoin(s3, s3));
    }

    if(!mx_strcmp(argv[1], "mx_read_line") || !mx_strcmp(argv[1], "all")) {                 //MX_READ_LINE
        printf("\n\n-----TESTING MX_READ_LINE------\n\n");
        int fd = open("fragment", O_RDONLY);
        char *str = NULL;
        int res;
        
        //NOTE!!! before starting the test create the "fragment" file with corresponding text

        printf("Test output:\n");
        printf("The hotel was abandoned a\n25\n\n0\ner a fire licked its way accross\n");
        printf("the polyester carpeting, destroying several rooms as it\n");
        printf("spooled soot up the walls and ceiling, leaving patterns of\n");
        printf("permanent shadow\n163\n\n");

        printf("User output:\n");

        res = mx_read_line(&str, 20, 'f', fd);
        printf("%s\n%d\n", str, res);
        res = mx_read_line(&str, 35, 't', fd);
        printf("%s\n%d\n", str, res);
        res = mx_read_line(&str, 4, '.', fd);
        printf("%s\n%d\n", str, res);
    }

    if(!mx_strcmp(argv[1], "mx_replace_substr") || !mx_strcmp(argv[1], "all")) {            //MX_REPLACE_SUBSTR
        printf("\n\n------TESTING MX_REPLACE_SUBSTR-----\n\n");

        char *strn1 = "McDonalds";
        char *sub1 = "ald";
        char *replace1 = "ut";
        
        char *strn2 = "Ururu turu";
        char *sub2 = "ru";
        char *replace2 = "tas";

        printf("Test output:\n");
        printf("%s\n%s\n%s\n", strn1, sub1, replace1);
        printf("McDonuts\n\n");
        printf("%s\n%s\n%s\n", strn2, sub2, replace2);
        printf("Utastas tutas\n\n");
        
        printf("User output:\n");
        printf("%s\n%s\n%s\n", strn1, sub1, replace1);
        printf("%s\n\n", mx_replace_substr(strn1, sub1, replace1));
        printf("%s\n%s\n%s\n", strn2, sub2, replace2);
        printf("%s\n", mx_replace_substr(strn2, sub2, replace2));
    }

    if(!mx_strcmp(argv[1], "mx_del_extra_spaces") || !mx_strcmp(argv[1], "all")) {              //MX_DEL_EXTRA_SPACES
        printf("\n\n-----TESTING MX_DEL_EXTRA_SPACES-----\n\n");

        char *name1 = "\f   My name... \n   is \r Neo   \f\t";
        printf("Test output:\n");
        printf("%s\n", name1);
        printf("My name... is Neo\n");

        printf("User output:\n");
        printf("%s\n", name1);
        printf("%s\n\n\n", mx_del_extra_spaces(name1));
    }

    if (!mx_strcmp(argv[1], "mx_get_substr_index") || !mx_strcmp(argv[1], "all")) {        //MX_GET_SUBSTR_INDEX
            test_header("MX_GET_SUBSTR_INDEX");
            
            tu_output("user");
            printf("%d\n", mx_get_substr_index("McDonalds", "Don"));
            printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
            printf("%d\n", mx_get_substr_index("McDonalds", "Donatello"));
            printf("%d\n", mx_get_substr_index("McDonalds", NULL));
            printf("%d\n", mx_get_substr_index(NULL, "Don"));
    }

    if (!mx_strcmp(argv[1], "mx_count_substr") || !mx_strcmp(argv[1], "all")) {           //MX_COUNT_SUBSTR
            test_header("MX_COUNT_SUBSTR");

            tu_output("user");
            char *str = "yo, yo, yo, Neo";
            char *sub = "yo";

            printf("%d\n", mx_count_substr(str, sub));
            printf("%d\n", mx_count_substr(str, NULL));
            printf("%d\n", mx_count_substr(NULL, sub));
    }

    if (!mx_strcmp(argv[1], "mx_strsplit") || !mx_strcmp(argv[1], "all")) {               //MX_STRSPLIT
            test_header("MX_STRSPLIT");
            
            tu_output("user");
            char *s = "**Good bye,**Mr.*Anderson.****";
            char **arr = mx_strsplit(s, '*');
            const char c = '\n';
            mx_print_strarr(arr, &c);
            char *s1 = " Knock, knock, Neo. ";
            char **arr1 = mx_strsplit(s1, ' ');
            mx_print_strarr(arr1, &c);            
    }
    
    if (!mx_strcmp(argv[1], "mx_file_to_str") || !mx_strcmp(argv[1], "all")) {            //MX_FILE_TO_STR
            test_header("MX_FILE_TO_STR");

            tu_output("user");
            printf("%s", mx_file_to_str("afile"));
    }

    if(!mx_strcmp(argv[1], "all"))
        printf("--------------------\n|-----MEM PACK-----|\n--------------------\n");

    if (!mx_strcmp(argv[1], "mx_memset") || !mx_strcmp(argv[1], "all")) {                 //MX_MEMSET
            test_header("MX_MEMSET");
            char str[50];

            tu_output("test");
            mx_strcpy(str, "This is libmx.h library function");
            puts(str);
            printf("$$$$$$$ libmx.h library function\n");

            tu_output("user");
            puts(str);
            mx_memset(str, '$', 7);
            puts(str);
    }

    if (!mx_strcmp(argv[1], "mx_memcpy") || !mx_strcmp(argv[1], "all")) {                 //MX_MEMCPY
            
            test_header("MX_MEMCPY");
            tu_output("user");
            char dst[] = "This is destination string.";
            char src[] = "NO MORE ";

            puts(dst);

            mx_memcpy(dst, src, 8);
            puts(dst);
    }

    if (!mx_strcmp(argv[1], "mx_memcpy") || !mx_strcmp(argv[1], "all")) {                //MX_MEMCCPY
            test_header("MX_MEMCPY");
            
            tu_output("user");
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
    }
    
    if (!mx_strcmp(argv[1], "mx_memcmp") || !mx_strcmp(argv[1], "all")) {             //MX_MEMCMP
            test_header("MX_MEMCMP");
            
            tu_output("user");
            unsigned char src[15] = "1234567890";
            unsigned char dst[15] = "1234567890";
            int res;

            if ((res = mx_memcmp(src, dst, 10)) == 0)
                puts ("Memory areas are identical");
            else 
                printf ("Memory areas differ.\n%d\n", res);
    } 

    if(!mx_strcmp(argv[1], "all"))
        printf("---------------------\n|-----LIST PACK-----|\n---------------------\n");

    if(!mx_strcmp(argv[1], "mx_sort_list") || !mx_strcmp(argv[1], "all")) {
        printf("\n\n-----TESTNG MX_SORT_LIST-----\n\n");                                        //MX_SORT_LIST
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
    }

    if(!mx_strcmp(argv[1], "mx_list_size") || !mx_strcmp(argv[1], "all")) {                     //MX_LIST_SIZE
        test_header("MX_LIST_SIZE & MX_PUSH_BACK");

        int d1 = 1, d2 = 2, d3 = 3;
        t_list *aList1 = mx_create_node(&d1);
        mx_push_back(&aList1, &d2);
        mx_push_back(&aList1, &d3);

        tu_output("test");
        printf("3\n\n");

        tu_output("user");

        printf("%d\n", mx_list_size(aList1));
    }

    if (!mx_strcmp(argv[1], "mx_pop_back") || !mx_strcmp(argv[1], "all")) {               //MX_POP_BACK
            test_header("MX_POP_BACK");
            tu_output("user");
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
    }           
    
    if (!mx_strcmp(argv[1], "mx_pop_front") || !mx_strcmp(argv[1], "all")) {              //MX_POP_FRONT
            test_header("MX_POP_FRONT");
            tu_output("user");
            
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
    }

    if (!mx_strcmp(argv[1], "mx_push_back") || !mx_strcmp(argv[1], "all")) {              //MX_PUSH_BACK
            test_header("MX_PUSH_BACK");
            tu_output("user");
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
    }
   
    if (0) {} 
    else if(0) {                    //MX_STRDEL
        char *str = mx_strnew(6);
        str = "Hello!";
            
        printf("%s\n", str);
        mx_strdel(&str);
        printf("%s\n", str);
    } else if (0) {
        char *name = "****My name... is Neo****";
        printf("%s\n", mx_strtrim_delim(name, '*'));
    } else if (0) {
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
