#include "pathfinder.h"

void mx_free_everything(t_core *core) {
    int i;
    for (i = 0; i < core->verts; ++i) {
        free(core->names[i]);
        free(core->matrix[i]);
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
