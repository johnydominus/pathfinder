#include "pathfinder.h"

t_edge *mx_create_edge(const char *vert_name, const int distance) {
    t_edge *new_edge = malloc(sizeof(t_edge));
    new_edge->vertice_name = mx_strdup(vert_name);
    new_edge->distance = distance;
    return new_edge;
}
