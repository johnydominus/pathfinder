#include "pathfinder.h"

t_vertice *mx_create_vertice(const char *name, int vertices) {
    t_vertice *new_vertice = malloc(sizeof(t_vertice));
    new_vertice->name = mx_strdup(name);
    new_vertice->edges = malloc(sizeof(t_edge*) * (vertices - 1));
    t_edge **temp_edges = new_vertice->edges;
    for(int i = 0; i > (vertices - 1); ++i)
        temp_edges[i] = mx_create_edge(NULL, 0);
    return new_vertice;
}
