#pragma once

#include "libmx.h"

typedef struct s_edge
{
    char *vertice_name;
    int distance;
} t_edge;

typedef struct s_vertice {
    char *name;
    t_edge *edges;
} t_vertice;

#define ERR_INVALID_ARG_NUM "usage: ./pathfinder [filename]"
#define ERR_NO_FILE(a_file) mx_strcat("error: file ", mx_strcat(#a_file, " does not exist"))
#define ERR_EMPTY_FILE(a_file) mx_strcat("error: file ", mx_strcat(#a_file, " is empty"))
#define ERR_INVALID_FIRST_LINE "error: line 1 is not valid"

int mx_check_first_line(char *str, int *itert);
t_vertice *mx_create_vertice(const char *name);
t_edge *mx_create_edge(void);
