#include "pathfinder.h"

bool mx_compare_edge_names(t_edge *edge, char *name) {
    if(edge && edge->vertice_name && !mx_strcmp(edge->vertice_name, name))
        return true;
    else
        return false;        
}
