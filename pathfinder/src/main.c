#include "pathfinder.h"

int main(int argc, char **argv) {
    int vertices;
    int iter;
    int len;
    char *file_data = NULL;
    //t_list **adjacency_list = NULL;

    if(argc != 2) {
        mx_printerr(ERR_INVALID_ARG_NUM);
        return 0;
    }

    file_data = mx_file_to_str(argv[1]);

    if(file_data == NULL) {
        mx_printerr(ERR_NO_FILE(argv[1]));
        return 0;
    }

    if(mx_strlen(file_data) == 0) {
        mx_printerr(ERR_EMPTY_FILE(argv[1]));
        return 0;
    }

    if(mx_check_first_line(argv[1], &iter) == false) {
        mx_printerr(ERR_INVALID_FIRST_LINE);
        return 0;
    }

    vertices = mx_atoi(file_data);

    while(file_data[iter]) {
        len = mx_strlen_delim(&file_data[iter], '-');
        //adjacency_list = mx_create_node();
    }
}
