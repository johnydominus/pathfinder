#include "pathfinder.h"

t_list *check_presence(t_list **ad_list, char *content);
bool compare_names(t_vertice *vertice, char *name);

int main(int argc, char **argv) {
    int vertices;
    int iter;
    int len;
    char *file_data = NULL;
    t_list **adjacency_list = NULL;

    if(argc != 2) {
        mx_error(INVALID_ARG_NUM, NULL);
        return 0;
    }

    len = open(argv[1], O_RDONLY);

    if(len < 0) {
        close(len);
        mx_error(NO_FILE, argv[1]);
        return 0;
    }

    file_data = mx_file_to_str(argv[1]);
    close(len);

    if(mx_strlen(file_data) == 0) {
        mx_error(EMPTY_FILE, argv[1]);
        return 0;
    }
    
    if(mx_check_first_line(file_data, &iter) == false) {
        mx_error(INVALID_FIRST_LINE, NULL);
        return 0;
    }
    iter += 2;
    
    len = mx_check_lines(file_data, &iter);
    if(len) {
        mx_error(INVALID_LINE, mx_itoa(len));
        return 0;
    }

    vertices = mx_atoi(file_data);
    iter = 0;

    while(file_data[iter]) {
        char *island1 = NULL;
        char *island2 = NULL;
        //int temp_distance = 0;
        t_list *temp_list = NULL;

        len = mx_strlen_delim(&file_data[iter], '-');
        mx_strncpy(island1, &file_data[iter], len);
        printf("%s\n", island1);
        iter += ++len;
        
        len = mx_strlen_delim(&file_data[iter], ',');
        mx_strncpy(island2, &file_data[iter], len);
        printf("%s\n", island2);
        iter += ++ len;

        temp_list = check_presence(adjacency_list, island1);
        //if(temp_list)
        //    temp_list->data->name
        //*adjacency_list = mx_create_node(content);
        len = mx_strlen_delim(&file_data[iter], ',');
    }
}

t_list *check_presence(t_list **ad_list, char *content) {
    t_list *iter_list = *ad_list;
    
    if(!iter_list) {}
    else {
        while(iter_list->next) {
            if(compare_names(iter_list->data, content))
                break;
            else
                iter_list = iter_list->next;
        }
    }
    return iter_list;
}

bool compare_names(t_vertice *vertice, char *name) {
    if(!mx_strcmp(vertice->name, name))
        return true;
    else
        return false;
}
