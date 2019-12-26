#include "pathfinder.h"

t_edge *mx_create_edge(void) {
    t_edge *new_edge = malloc(sizeof(t_edge));
    new_edge->vertice_name = NULL;
    new_edge->distance = 0;

    return new_edge;
}
