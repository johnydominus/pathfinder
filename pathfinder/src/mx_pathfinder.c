#include "pathfinder.h"

void mx_pathfinder(t_vertice **ad_lst) {
    t_list **path_vertices = NULL;
    t_list **path_edges = NULL;
    t_list *temp = *path_vertices;
    int itr = 0;

    temp = mx_create_node(ad_lst[itr]->name);
    
}