#pragma once

#include "libmx.h"

typedef struct s_edge
{
    char *vertice_name;
    int distance;
} t_edge;

typedef struct s_vertice {
    char *name;
    t_edge **edges;
    int edges_num;
} t_vertice;

typedef enum e_error {
    INVALID_ARG_NUM,
    NO_FILE,
    EMPTY_FILE,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_ISLANDS_NUM,
    WRONG_POINTER,
    DUPLICATE_EDGE
} t_error;

int mx_check_first_line(char *str, int *iter);
int mx_check_lines(char *str, int *iter);
t_vertice *mx_create_vertice(const char *name, int vertices);
t_edge *mx_create_edge(const char *vert_name, const int distance);
void mx_error(t_error error_type, char *filename);
