#include "pathfinder.h"

static void print_line(void);
static void print_path(t_core *core, t_stack *stack);
static void print_route(t_core *core, t_stack *stack);
static void print_distance();

void mx_print(t_core *core, t_stack *stack) {
    static bool first_line = true;
    if(first_line)
        first_line = false;
    else
        mx_printstr("\n");
    print_line();
    mx_printstr("\n");
    print_path(core, stack);
    print_route(core, stack);
    print_distance(core, stack);
    print_line();
}

static void print_line(void) {
    char s[]= "========================================";
    mx_printstr(s);
}

static void print_path(t_core *core, t_stack *stack) {
    mx_printstr("Path: ");
    mx_printstr(core->names[stack->path[0]]);
    mx_printstr(" -> ");
    mx_printstr(core->names[stack->path[1]]);
    mx_printstr("\n");
}

static void print_route(t_core *core, t_stack *stack) {
    mx_printstr("Route: ");
    for (int i = stack->size; i >= 2; --i) {
        mx_printstr(core->names[stack->path[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(core->names[stack->path[1]]);
    mx_printstr("\n");
}

static void print_distance(t_core *core, t_stack *stack) {
    mx_printstr("Distance: ");
    int total_dist = 0;
    for (int i = stack->size - 1; i >= 2; --i) {
        int dist = core->matrix[stack->path[i]][stack->path[i + 1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        int dist = core->matrix[stack->path[2]][stack->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
        total_dist = core->matrix[stack->path[2]][stack->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
}
