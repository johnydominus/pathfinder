#include "pathfinder.h"

int check_vertice_presence(t_vertice *ad_list, char *content, int vertices);
bool check_edge_presence(t_vertice *vertice, char *content);
bool compare_names(t_vertice *vertice, char *name);
bool parse_island(t_vertice *adj_list, char *isl1, char *isl2, int dist);

int main(int argc, char **argv) {
    int vertices;
    int iter;
    int len;
    char *file_data = NULL;
    t_vertice *adjacency_list = NULL;

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

    iter = 0;
    vertices = mx_atoi(file_data);
    if(vertices < 1) {
        mx_error(INVALID_ISLANDS_NUM, NULL);
        return 0;
    }
    adjacency_list = malloc(sizeof(t_vertice*) * vertices);

    while(!mx_isalpha(file_data[iter]))
        ++iter;

    int parsed_islands = 0;
    char *island1 = NULL;
    char *island2 = NULL;
    int temp_distance = 0;
    t_vertice *temp_vertice = adjacency_list;

    while(file_data[iter]) {
        if(parsed_islands > vertices) {
            mx_error(INVALID_ISLANDS_NUM, NULL);
            return 0;
        }
        len = mx_strlen_delim(&file_data[iter], '-');           //writing line data to temp variables
        island1 = mx_strndup(&file_data[iter], len);
        iter += ++len;

        len = mx_strlen_delim(&file_data[iter], ',');
        island2 = mx_strndup(&file_data[iter], len);
        iter += ++len;

        temp_distance = mx_atoi(&file_data[iter]);
        while(file_data[iter] && !mx_isalpha(file_data[iter]))
            ++iter;
        
        if(parse_island(adjacency_list, island1, island2, temp_distance))
            ++parsed_islands;
        if(parse_island(adjacency_list, island2, island1, temp_distance))
            ++parsed_islands;

        temp_vertice = &adjacency_list[parsed_islands];         //parsing islands

    }
}

bool parse_island(t_vertice *adj_list, char *isl1, char *isl2, int dist) {
    int x = check_vertice_presence(adjacency_list, island1, parsed_islands);
    bool new_island = false;
    if(x == -2)
        return -1;
    else if(x == -1) {
        temp_vertice = mx_create_vertice(island1);
        new_island = true;
    }
    else {
        if(check_edge_presence(temp_vertice, island2)) {}
        else {
            int it = 0;
            t_edge *temp_edge = &temp_vertice->edges[it];
            while(temp_edge) {
                ++it;
                temp_edge = &temp_vertice->edges[it];
            }
            temp_edge = mx_create_edge(island2, temp_distance);
        }            
    }    
    return new_island;
}

int check_vertice_presence(t_vertice *ad_list, char *content, int vertices) {
    int i = 0;

    if(!ad_list) {
        return -2;
    }
    else {
        for(i = 0; i <= vertices; ++i) {
            if(i == vertices)
                return -1;
            else if(compare_names(&ad_list[i], content))
                break;
        }
    }
    return i;
}

bool check_edge_presence(t_vertice *vertice, char *content) {
    t_edge *temp_edge = vertice->edges;
    while(temp_edge) {
        if(!mx_strcmp(temp_edge->vertice_name, content))
            return true;
        ++temp_edge; 
    }
    return false;
}

bool compare_names(t_vertice *vertice, char *name) {
    if(vertice && vertice->name && !mx_strcmp(vertice->name, name))
        return true;
    else
        return false;
}
