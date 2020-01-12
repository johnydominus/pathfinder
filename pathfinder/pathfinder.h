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

typedef struct s_core {
    int verts;
    int iter;
    int len;
    int distance;
    int prsd_isls;
    char *isl1;
    char *isl2;
    char *text;
    char **names;
    int **matrix;
} t_core;

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

t_vertice *mx_create_vertice(const char *name, int vertices);
t_edge *mx_create_edge(const char *vert_name, const int distance);
t_core *mx_create_core(void);
void mx_error(t_error error_type, char *filename);
bool mx_parser(t_core *core, t_vertice ***ad_lst);
bool mx_nparser(t_core *core);
bool mx_check_first_line(char *str, int *iter);
bool mx_check_lines(char *str, int *iter, int *vertices);
bool mx_check_errors(int argc, char **argv, int *iter, char **file_data);
bool mx_compare_vert_names(t_vertice *vertice, char *name);
bool mx_compare_edge_names(t_edge *edge, char *name);
int mx_check_vertice_presence(t_vertice **ad_list, char *content, int verts);
int mx_check_edge_presence(t_edge **edges, char *content, int edges_num);
int **mx_make_adj_matrix(t_vertice **adj_list, int verts);
