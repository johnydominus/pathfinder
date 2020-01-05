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
        if(error) 
            return error;
        error = check_sec_island(str, iter, &line);
        if(error) 
            return error;
        error = check_path(str, iter, &line);
        if(error) 
            return error;
        if(!str[*iter]) 
            break;
    }
    return 0;
}

static int check_first_island(char *str, int *iter, int *line) {
    while(true) {
        if(mx_isalpha(str[*iter])) {
            ++(*iter);
            continue; 
        }
        else if(str[*iter] == '-') {
            ++(*iter);
            break;
        }
        else
            return *line;
    }
    return 0;
}

static int check_sec_island(char *str, int *iter, int *line) {
    while (true) {
        if(mx_isalpha(str[*iter])) {
            ++(*iter); 
            continue;
        }
        else if(str[*iter] == ',') {
            ++(*iter);
            break;
        }
        else
            return *line;      
    }
    return 0;
}

static int check_path(char *str, int *iter, int *line) {
    while (true) {
        if(mx_isdigit(str[*iter])) {
            ++(*iter);
            continue;
        }
        else if(str[*iter] && str[*iter] == '\n') {
            ++(*iter);
            break;
        }
        else
            return *line;        
    }
    return 0;
}
