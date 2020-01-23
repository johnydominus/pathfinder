#pragma once

#include "libmx.h"

typedef struct s_stack {
        int *path;
        int size;
} t_stack;

typedef struct s_core {
    int verts;
    int iter;
    int len;
    int distance;
    int prsd_isls;
    int st_num;
    char *isl1;
    char *isl2;
    char *text;
    char **names;
    int **matrix;
    t_list **stacks;
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

t_core *mx_create_core(void);
void mx_error(t_error error_type, char *filename);
void mx_pathfinder(t_core *core);
void mx_free_everything(t_core *core);
void mx_print(t_core *core, t_stack *st);
bool mx_nparser(t_core *core);
bool mx_check_first_line(char *str, int *iter);
bool mx_check_lines(char *str, int *iter, int *vertices);
bool mx_check_errors(int argc, char **argv, int *iter, char **file_data);
bool mx_compare_stacks(t_stack *st1, t_stack *st2);
