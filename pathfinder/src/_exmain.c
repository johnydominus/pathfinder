#include "pathfinder.h"

int main(int argc, char **argv) {
    t_core *core = mx_create_core();
    
    t_vertice **adj_list = NULL;
    int **matrix = NULL;

    if(!mx_check_errors(argc, argv, &core->iter, &core->text))
        return 0;
    if(!mx_parser(core, &adj_list))
        return 0;
        /*
    core->iter = 0;                                           //writing line data to temp variables
    core->verts = mx_atoi(core->text);
    if(core->verts == 0)
        return 0;
    adj_list = malloc(sizeof(t_vertice*) * core->verts);
    while(!mx_isalpha(core->text[core->iter]))
        ++core->iter;                            

    while(core->text[core->iter]) {                //parsing data;
        if(core->prsd_isls > core->verts) {
            mx_error(INVALID_ISLANDS_NUM, NULL);
            return 0;
        }
        core->len = mx_strlen_delim(&core->text[core->iter], '-');
        core->isl1 = mx_strndup(&core->text[core->iter], core->len);
        core->iter += ++core->len;

        core->len = mx_strlen_delim(&core->text[core->iter], ',');
        core->isl2 = mx_strndup(&core->text[core->iter], core->len);
        core->iter += ++core->len;

        core->distance = mx_atoi(&core->text[core->iter]);
        while(core->text[core->iter] && !mx_isalpha(core->text[core->iter]))
            ++core->iter;
        
        int x = mx_check_vertice_presence(adj_list, core->isl1, core->prsd_isls);
        int y;
        if(x == -2)
            mx_error(WRONG_POINTER, "check_vertice_presence()");
        else if(x == -1) {
            adj_list[core->prsd_isls] = mx_create_vertice(core->isl1, core->verts);
            x = core->prsd_isls;
            ++core->prsd_isls;
        }
        y = mx_check_edge_presence(adj_list[x]->edges, core->isl1, adj_list[x]->edges_num);
        if(y == -2) {
            mx_error(WRONG_POINTER, "check_edge_presence()");
            return 0;
        }
        else if (y == -1) {
            int temp_edgnum = adj_list[x]->edges_num;
            adj_list[x]->edges[temp_edgnum] = mx_create_edge(core->isl2, core->distance);
            ++adj_list[x]->edges_num;
        }
        else {
            mx_error(DUPLICATE_EDGE, NULL);
            return 0;
        }
        
        x = mx_check_vertice_presence(adj_list, core->isl2, core->prsd_isls);
        if(x == -2)
            mx_error(WRONG_POINTER, "check_vertice_presence()");
        else if(x == -1) {
            adj_list[core->prsd_isls] = mx_create_vertice(core->isl2, core->verts);
            x = core->prsd_isls;
            ++core->prsd_isls;
        }
        y = mx_check_edge_presence(adj_list[x]->edges, core->isl2, adj_list[x]->edges_num);
        if(y == -2) {
            mx_error(WRONG_POINTER, "check_edge_presence()");
            return 0;
        }
        else if (y == -1) {
            int temp_edgnum = adj_list[x]->edges_num;
            adj_list[x]->edges[temp_edgnum] = mx_create_edge(core->isl1, core->distance);
            ++adj_list[x]->edges_num;
        }
        else {
            mx_error(DUPLICATE_EDGE, NULL);
            return 0;
        }
    }
    if(core->prsd_isls != core->verts) {
        mx_error(INVALID_ISLANDS_NUM, NULL);
        return 0;
    }
    */
    matrix = mx_make_adj_matrix(adj_list, core->verts);


}
