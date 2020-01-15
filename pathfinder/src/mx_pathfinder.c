#include "pathfinder.h"

static void floyd_marchall_alg(t_core *core, int **dist_matrix);
static void restore_path(t_core *core, t_stack *st, int **d_m);
static bool is_next(t_core *core, t_stack *st, int next, int **d_m);

void mx_pathfinder(t_core *core) {
    int **dist_matrix = (int**)malloc(sizeof(int*) * core->verts);
    for(int i = 0; i < core->verts; ++i) {
        dist_matrix[i] = (int*)malloc(sizeof(int) * core->verts);
        for(int j = 0; j < core->verts; ++j)
            dist_matrix[i][j] = core->matrix[i][j];
    }
    floyd_marchall_alg(core, dist_matrix);

    for(int i = 0; i < core->verts; ++i) {
        for(int j = i + 1; j < core->verts; ++j) {
            t_stack *st = (t_stack*)malloc(sizeof(t_stack));
            if((st) == NULL) exit(1);
            st->max_size = core->verts;
            st->path = malloc(st->max_size * sizeof(int) + 1);
            st->path[0] = i;
            st->path[1] = j;
            st->size = 1;
            restore_path(core, st, dist_matrix);
            free(st->path);
            free(st);
        }
    }
    for(int i = 0; i < core->verts; ++i)
        free(dist_matrix[i]);
    free(dist_matrix);
}

static void floyd_marchall_alg(t_core *core, int **dist_matrix) {
    int **dist = dist_matrix;
    for(int k = 0; k < core->verts; ++k) {
        for(int i = 0; i < core->verts; ++i) {
            for(int j = 0; j < core->verts; ++j) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

static void restore_path(t_core *core, t_stack *st, int **d_m) {
    if(st->path[st->size] == st->path[0]) {
        static bool first_line = true;
        if(first_line)
            first_line = false;
        else
            mx_printstr("\n");
        char s[]= "========================================";
        mx_printstr(s);
        mx_printstr("\n");
        mx_printstr("Path: ");
        mx_printstr(core->names[st->path[0]]);
        mx_printstr(" -> ");
        mx_printstr(core->names[st->path[1]]);
        mx_printstr("\n");
        mx_printstr("Route: ");
        for(int i = st->size; i >= 2; --i) {
            mx_printstr(core->names[st->path[i]]);
            mx_printstr(" -> ");
        }
        mx_printstr(core->names[st->path[1]]);
        mx_printstr("\n");
        mx_printstr("Distance: ");
        int total_dist = 0;
        for(int i = st->size - 1; i >= 2; --i) {
            int dist = core->matrix[st->path[i]][st->path[i + 1]];
            total_dist += dist;
            mx_printint(dist);
            mx_printstr(" + ");
        }
        if(total_dist != 0) {
            int dist = core->matrix[st->path[2]][st->path[1]];
            total_dist += dist;
            mx_printint(dist);
            mx_printstr(" = ");
        }
        else
            total_dist = core->matrix[st->path[2]][st->path[1]];
        mx_printint(total_dist);
        mx_printstr("\n");
        mx_printstr(s);
    return;
    }
    else {
        for(int next = 0; next < core->verts; ++next) {
            if(is_next(core, st, next, d_m)) {
                if(st->size < st->max_size) {
                    st->size++;
                    st->path[st->size] = next;
                    restore_path(core, st, d_m);
                    if(st->size > 1) {
                        st->size--;
                    }
                }
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
        if (DM[i][k] - AM[k][next] == DM[i][next]) {
            return true;
        }
    }
    return false;
}
