#include "pathfinder.h"

int check_vertice_presence(t_vertice **ad_list, char *content, int vertices);
int check_edge_presence(t_edge **edges, char *content, int edges_num);
bool compare_vert_names(t_vertice *vertice, char *name);
bool compare_edge_names(t_edge *edge, char *name);

int main(int argc, char **argv) {
    int vertices;
    int iter = 0;
    char *file_data = NULL;
    t_vertice **adj_list = NULL;

    if(!mx_check_errors(argc, argv, &iter, &file_data))
        return 0;
    //!
    //if(!mx_parser(&file_data, &iter, &vertices, adj_list))
    //    return 0;
    iter = 0;                                           //writing line data to temp variables
    vertices = mx_atoi(file_data);
    if(vertices == 0)
        return 0;
    adj_list = malloc(sizeof(t_vertice*) * vertices);
    while(!mx_isalpha(file_data[iter]))
        ++iter;
    
    int parsed_isls = 0;                                //parsing data
    char *isl1 = NULL;
    char *isl2 = NULL;
    int temp_distance = 0;
    int len;

    while(file_data[iter]) {
        if(parsed_isls > vertices) {
            mx_error(INVALID_ISLANDS_NUM, NULL);
            return 0;
        }
        len = mx_strlen_delim(&file_data[iter], '-');
        isl1 = mx_strndup(&file_data[iter], len);
        iter += ++len;

        len = mx_strlen_delim(&file_data[iter], ',');
        isl2 = mx_strndup(&file_data[iter], len);
        iter += ++len;

        temp_distance = mx_atoi(&file_data[iter]);
        while(file_data[iter] && !mx_isalpha(file_data[iter]))
            ++iter;
        
        int x = check_vertice_presence(adj_list, isl1, parsed_isls);
        int y;
        if(x == -2)
            mx_error(WRONG_POINTER, "check_vertice_presence()");
        else if(x == -1) {
            adj_list[parsed_isls] = mx_create_vertice(isl1, vertices);
            printf("%s parsed!\n", adj_list[parsed_isls]->name);
            x = parsed_isls;
            ++parsed_isls;
        }
        y = check_edge_presence(adj_list[x]->edges, isl1, adj_list[x]->edges_num);
        if(y == -2) {
            mx_error(WRONG_POINTER, "check_edge_presence()");
            return 0;
        }
        else if (y == -1) {
            int temp_edgnum = adj_list[x]->edges_num;
            adj_list[x]->edges[temp_edgnum] = mx_create_edge(isl2, temp_distance);
            ++adj_list[x]->edges_num;
            printf("Edge parsed: %s-%s,%d!\n", adj_list[x]->name, adj_list[x]->edges[temp_edgnum]->vertice_name, adj_list[x]->edges[temp_edgnum]->distance);
        }
        else {
            mx_error(DUPLICATE_EDGE, NULL);
            return 0;
        }
        
        x = check_vertice_presence(adj_list, isl2, parsed_isls);
        if(x == -2)
            mx_error(WRONG_POINTER, "check_vertice_presence()");
        else if(x == -1) {
            adj_list[parsed_isls] = mx_create_vertice(isl2, vertices);
            printf("%s parsed!\n", adj_list[parsed_isls]->name);
            x = parsed_isls;
            ++parsed_isls;
        }
        y = check_edge_presence(adj_list[x]->edges, isl2, adj_list[x]->edges_num);
        if(y == -2) {
            mx_error(WRONG_POINTER, "check_edge_presence()");
            return 0;
        }
        else if (y == -1) {
            int temp_edgnum = adj_list[x]->edges_num;
            adj_list[x]->edges[temp_edgnum] = mx_create_edge(isl1, temp_distance);
            ++adj_list[x]->edges_num;
            printf("Edge parsed: %s-%s,%d!\n", adj_list[x]->name, adj_list[x]->edges[temp_edgnum]->vertice_name, adj_list[x]->edges[temp_edgnum]->distance);
        }
        else {
            mx_error(DUPLICATE_EDGE, NULL);
            return 0;
        }
    }
    if(parsed_isls != vertices) {
        mx_error(INVALID_ISLANDS_NUM, NULL);
        return 0;
    }
    
       
}

int check_vertice_presence(t_vertice **ad_list, char *content, int verts) {
    int i = 0;
    if(!ad_list)
        return -2;
    else {
        for(i = 0; i <= verts; ++i) {
            if(i == verts)
                return -1;
            else if(compare_vert_names(ad_list[i], content)) {
                return i;
            }
        }
    }
    return i;
}

int check_edge_presence(t_edge **edges, char *content, int edges_num) {
    int i = 0;
    if(!edges)
        return -2;
    else {
        for(i = 0; i <= edges_num; ++i) {
            if(i == edges_num)
                return -1;
            else if(compare_edge_names(edges[i], content)) {
                printf("???\n");
                return i;
            }
        }
    }
    return i;
}

bool compare_vert_names(t_vertice *vertice, char *name) {
    if(vertice && vertice->name && !mx_strcmp(vertice->name, name))
        return true;
    else
        return false;
}

bool compare_edge_names(t_edge *edge, char *name) {
    if(edge && edge->vertice_name && !mx_strcmp(edge->vertice_name, name))
        return true;
    else
        return false;        
}
