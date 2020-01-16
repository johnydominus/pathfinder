#include "pathfinder.h"

int main(int argc, char **argv) {
    t_core *core = mx_create_core();
    if (!mx_check_errors(argc, argv, &core->iter, &core->text)
        || !mx_nparser(core))
        return 0;
    mx_pathfinder(core);
    mx_free_everything(core);
}
