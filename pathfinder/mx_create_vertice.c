#include "pathfinder.h"

t_vertice *mx_create_vertice(const char *name) {
    t_vertice *new_vertice = malloc(sizeof(t_vertice));
    new_vertice->name = mx_strdup(name);
    new_vertice->edges = NULL;

    return new_vertice;
}
