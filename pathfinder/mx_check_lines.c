#include "pathfinder.h"

static int check_first_island(char *str, int *iter, int *line);
static int check_sec_island(char *str, int *iter, int *line);
static int check_path(char *str, int *iter, int *line);

int mx_check_lines(char *str, int *iter) {
    int line = 1;
    int error = 0;

    while (true)
    {
        ++line;
        
        error = check_first_island(str, iter, &line);
        if(error) {
            printf("c\n");
            return error;
        }
        
        error = check_sec_island(str, iter, &line);
        if(error){
            putchar('b');
            return error;
        }

        error = check_path(str, iter, &line);
        if(error){
            putchar('d');
            return error;
        }
        if(!str[*iter])
            break;        
    }
    return 0;
}

static int check_first_island(char *str, int *iter, int *line) {
    int check = 0;

    while(true) {
        if(mx_isalpha(str[*iter]))
            continue; 
        else if(str[*iter] == '-' && check)
            break;
        else
            return *line;

        ++check;
        ++(*iter);
    }

    return 0;
}

static int check_sec_island(char *str, int *iter, int *line) {
    int check = 0;

    while (true) {
        if(mx_isalpha(str[*iter])) 
            continue;
        else if(str[*iter] == ',' && check)
            break;
        else
            return *line;
        ++check;
        ++(*iter);       
    }
    return 0;
}

static int check_path(char *str, int *iter, int *line) {
    int check = 0;

    while (true) {
        if(mx_isdigit(str[*iter]))
            continue;
        else if(str[*iter] == '\n' && check)
            break;
        else
            return *line;        
        ++check;
        ++(*iter);
    }
    return 0;
}
