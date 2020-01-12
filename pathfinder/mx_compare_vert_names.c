#include "pathfinder.h"

bool mx_compare_vert_names(t_vertice *vertice, char *name) {
    if(vertice && vertice->name && !mx_strcmp(vertice->name, name))
        return true;
    else
        return false;
}
