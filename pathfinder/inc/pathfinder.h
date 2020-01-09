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

typedef struct s_pathfinder {
    int vertices;
    int iter;
    int len;
    int temp_distance;
    int parsed_isls;
    char *isl1;
    char *isl2;
    char *file_data;
} t_pathfinder;


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

bool mx_parser(char **data, int *itr, int *verts, t_vertice **ad_lst);
bool mx_check_first_line(char *str, int *iter);
bool mx_check_lines(char *str, int *iter, int *vertices);
bool mx_check_errors(int argc, char **argv, int *iter, char **file_data);
t_vertice *mx_create_vertice(const char *name, int vertices);
t_edge *mx_create_edge(const char *vert_name, const int distance);
t_pathfinder *mx_create_pathfinder(void);
void mx_error(t_error error_type, char *filename);
