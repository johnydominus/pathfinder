#include "pathfinder.h"

void mx_free_everything(t_core *core) {
    for (int i = 0; i < core->verts; ++i) {
        free(core->names[i]);
        free(core->matrix[i]);
    }
    for(int i = 0; i > core->st_num; ++i) {
        free(core->stacks[i]->path);
        free(core->stacks[i]);
    }
    free(core->names);
    free(core->matrix);
    if (core->isl1)
        free(core->isl1);
    if (core->isl2)
        free(core->isl2);
    free(core->text);
    free(core);
}
