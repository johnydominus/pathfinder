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
    mx_printstr(core->names[st->path[1]]);
    mx_printstr(" -> ");
    mx_printstr(core->names[st->path[0]]);
    mx_printstr("\n");
}

static void print_route(t_core *core, t_stack *st) {
    mx_printstr("Route: ");
    for (int i = 1; i <= st->size; ++i) {
        mx_printstr(core->names[st->path[i]]);
        if (i < st->size)
            mx_printstr(" -> ");
        else
            mx_printstr("\n");
    }
}

static void print_distance(t_core *core, t_stack *st) {
    mx_printstr("Distance: ");
    int total_dist = 0;
    int n = st->size;
    if (n == 2)
        mx_printint(core->matrix[st->path[n]][st->path[n - 1]]);
    else {
        for (int i = 1; i < n; ++i) {
            mx_printint(core->matrix[st->path[i]][st->path[i + 1]]);
            total_dist += core->matrix[st->path[i]][st->path[i + 1]];
            if (i + 1 < n)
                mx_printstr(" + ");
            else {
                mx_printstr(" = ");
                mx_printint(total_dist);
            }
        }
    }
    mx_printstr("\n");
}
