#include "pathfinder.h"

t_core *mx_create_core(void) {
    t_core *new_core = malloc(sizeof(t_core));

    new_core->verts = 0;
    new_core->iter = 0;
    new_core->len = 0;
    new_core->distance = 0;
    new_core->prsd_isls = 0;
    new_core->isl1 = NULL;
    new_core->isl2 = NULL;
    new_core->text = NULL;
    new_core->names = NULL;
    for (int i = 0; i < new_core->verts; ++i)
        new_core->names[i] = NULL;
    new_core->matrix = NULL;
    return new_core;
}
