#include "pathfinder.h"

static void floyd_marchall_alg(t_core *core, int **dist_matrix);
static void restore_path(t_core *core, t_stack *st, int **d_m);
static bool is_next(t_core *core, t_stack *st, int next, int **d_m);
static void create_path(t_core *core, int i, int j, int **dist_matrix);

void mx_pathfinder(t_core *core) {
    int **dist_matrix = (int**)malloc(sizeof(int*) * core->verts);
    for (int i = 0; i < core->verts; ++i) {
        dist_matrix[i] = (int*)malloc(sizeof(int) * core->verts);
        for (int j = 0; j < core->verts; ++j)
            dist_matrix[i][j] = core->matrix[i][j];
    }
    floyd_marchall_alg(core, dist_matrix);
    for (int i = 0; i < core->verts; ++i) {
        for (int j = i + 1; j < core->verts; ++j)
            create_path(core, i, j, dist_matrix);
    }
    for(int i = 0; i < core->verts; ++i)
        free(dist_matrix[i]);
    free(dist_matrix);
    mx_printstr("\n");
}

static void floyd_marchall_alg(t_core *core, int **dist_matrix) {
    int **dist = dist_matrix;
    for (int k = 0; k < core->verts; ++k) {
        for (int i = 0; i < core->verts; ++i) {
            for (int j = 0; j < core->verts; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

static void restore_path(t_core *core, t_stack *st, int **d_m) {
    if (st->path[st->size] == st->path[0]) {
        mx_push_back(core->stacks, st);
        mx_print(core, st);
    }
    else {
        for (int next = 0; next < core->verts; ++next) {
            if (is_next(core, st, next, d_m)) {
                if (st->size < core->verts) {
                    st->size++;
                    st->path[st->size] = next;
                }
                restore_path(core, st, d_m);
                if (st->size > 1)
                        st->size--;
            }
        }
    }
}

static bool is_next(t_core *core, t_stack *st, int next, int **d_m) {
    int k = st->path[st->size];
    int i = st->path[0];
    int **AM = core->matrix;
    int **DM = d_m;

    if (k != next) {
        if (DM[i][k] - AM[k][next] == DM[i][next])
            return true;
    }
    return false;
}

static void create_path(t_core *core, int i, int j, int **dist_matrix) {
    t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
    if ((stack) == NULL)
        exit(1);
    stack->path = (int*)malloc(core->verts * sizeof(int) + 1);
    stack->path[0] = i;
    stack->path[1] = j;
    stack->size = 1;
    restore_path(core, stack, dist_matrix);
}
