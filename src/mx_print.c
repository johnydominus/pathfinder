#include "pathfinder.h"

static void print_line(void);
static void print_path(t_core *core, t_stack *st);
static void print_route(t_core *core, t_stack *st);
static void print_distance();

void mx_print(t_core *core, t_stack *st) {
    static bool first_line = true;
    if(first_line)
        first_line = false;
    else
        mx_printstr("\n");
    print_line();
    mx_printstr("\n");
    print_path(core, st);
    print_route(core, st);
    print_distance(core, st);
    print_line();
}

static void print_line(void) {
    char s[]= "========================================";
    mx_printstr(s);
}

static void print_path(t_core *core, t_stack *st) {
    mx_printstr("Path: ");
    mx_printstr(core->names[st->path[0]]);
    mx_printstr(" -> ");
    mx_printstr(core->names[st->path[1]]);
    mx_printstr("\n");
}

static void print_route(t_core *core, t_stack *st) {
    mx_printstr("Route: ");
    for (int i = st->size; i >= 2; --i) {
        mx_printstr(core->names[st->path[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(core->names[st->path[1]]);
    mx_printstr("\n");
}

static void print_distance(t_core *core, t_stack *st) {
    mx_printstr("Distance: ");
    int total_dist = 0;
    for (int i = st->size - 1; i >= 2; --i) {
        int dist = core->matrix[st->path[i]][st->path[i + 1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        int dist = core->matrix[st->path[2]][st->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
        total_dist = core->matrix[st->path[2]][st->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
}
