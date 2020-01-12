#include "pathfinder.h"

int mx_check_edge_presence(t_edge **edges, char *content, int edges_num) {
    int i = 0;
    if(!edges)
        return -2;
    else {
        for(i = 0; i <= edges_num; ++i) {
            if(i == edges_num)
                return -1;
            else if(mx_compare_edge_names(edges[i], content)) {
                return i;
            }
        }
    }
    return i;
}
