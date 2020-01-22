#include "pathfinder.h"

static bool check_argc(int argc);
static bool check_file(char **argv, char *file_data);
static bool check_vertices(char *file_data, int *vertices);

bool mx_check_errors(int argc, char **argv, int *iter, char **file_data) {
    *file_data = mx_file_to_str(argv[1]);
    int vertices;

    if(!check_argc(argc)
       || !check_file(argv, *file_data)
       || !mx_check_first_line(*file_data, iter)
       || !check_vertices(*file_data, &vertices) 
       || !mx_check_lines(*file_data, iter, &vertices)) {
        return false;
    }
    return true;
}

static bool check_argc(int argc) {
    if (argc != 2) {
        mx_error(INVALID_ARG_NUM, NULL);
        return false;
    }
    else
        return true;
}

static bool check_file(char **argv, char *file_data) {
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        close(fd);
        mx_error(NO_FILE, argv[1]);
        return false;
    }
    close(fd);
    if (mx_strlen(file_data) == 0) {
        mx_error(EMPTY_FILE, argv[1]);
        return false;
    }
    return true;
}

static bool check_vertices(char *file_data, int *vertices) {
    *vertices = mx_atoi(file_data);

    if (*vertices < 0) {
        mx_error(INVALID_ISLANDS_NUM, NULL);
        return false;
    }
    return true;
}
