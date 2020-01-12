#include "pathfinder.h"

int main(int argc, char **argv) {
    t_core *core = mx_create_core();
    if(!mx_check_errors(argc, argv, &core->iter, &core->text)
    || !mx_nparser(core))
        return 0;

    printf("-----\n");
    for(int i = 0; i < core->verts; ++i) {
        for(int j = 0; j < core->verts; ++j) {
            printf("%d\t", core->matrix[i][j]);
        }
        printf("\n");
    }
}
