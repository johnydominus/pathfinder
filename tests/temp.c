static bool is_next(t_App *app, t_stack *st, int next);
void print_path_info(t_App *app, t_stack *st);

void restore_all_paths(t_App *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++) {
            t_stack *st = NULL;
            *st = malloc(sizeof(t_stack)); // i, j, v2, v3, ..., vn, i
            if ((*st) == NULL) exit(1);
-
            (*st)->max_size = app->SIZE;
            (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
            (*st)->path[0] = i;
            (*st)->path[1] = j;
            (*st)->size = 1;
            if (st->path[st->size] == st->path[0]) { //TODO: HERE IS WRONG CHECK should be some thing like:
                print_path_info(app, st);             // if (DM[i * size + j] - AM[j * size + k] == DM[i * size + k])
                return;
            }
            else { // recursive case
                // for all adjecency virtecies to j
                for (int next = 0; next < app->SIZE; next++) {
                    if (is_next(app, st, next)) {
                        // choose
                        if (st->size < st->max_size) {
                            st->size++;
                            st->path[st->size] = elem;
                        }
                        // explore
                        restore_path_Helper(app, st); //lines 15 - 
                        // un-choose
                        if (st->size > 1) {
                            st->size--;
                            return st->path[st->size + 1];
                        }                    
                    }
                }
            }
            free(st->path);
            free(st);
        }
    }
}

static bool is_next(t_App *app, t_stack *st, int next) {
    // is cur is matches short path
    int k = stack->path[stack->size];
    int i = st->path[0];
    int *AM = app->AM;
    int *DM = app->dist_M;
    int size = app->SIZE;

    if (k != next) {
        if (DM[i * size + k] - AM[k * size + next] == DM[i * size + next]) {
            return true;
        }
    }
    return false;
}

void print_path_info(t_App *app, t_stack *st) {
    static bool first_line = true;
    if (first_line) {
        first_line = false;
    }
    else {
        mx_printstr("\n");
    }
    char s[]= "========================================";
    mx_printstr(s);
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(get_name_by_id (st->path[0], app));
    mx_printstr(" -> ");
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");

    mx_printstr("Route: ");
    for(int i = st->size; i >= 2; i--) {
        mx_printstr(get_name_by_id(st->path[i], app));
        mx_printstr(" -> ");
    }
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");

    mx_printstr("Distance: ");
    int total_dist = 0;
    for(int i = st->size - 1; i >= 2; i--) {
        int dist = app->AM[st->path[i] * app->SIZE + st->path[i + 1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        int dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
       total_dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
    mx_printstr(s);
}