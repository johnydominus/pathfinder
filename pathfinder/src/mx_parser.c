#include "pathfinder.h"

static bool init(t_core *core, t_vertice ***ad_lst);
static bool get_names_n_dstnce(t_core *core);
static bool create_graph(t_core *core, int isl, t_vertice ***ad_lst);
static bool create_edges(t_core *core, t_vertice *island, int isl);

bool mx_parser(t_core *core, t_vertice ***ad_lst) {
    if(!init(core, ad_lst))
        return false;
    while(core->text[core->iter]) {
        get_names_n_dstnce(core);
        if(!create_graph(core, 1, ad_lst) 
        || !create_graph(core, 2, ad_lst))
            return false;
    }
    return true;
}

static bool init(t_core *core, t_vertice ***ad_lst) {
    core->iter = 0;
    core->verts = mx_atoi(core->text);
    if(core->verts == 0)
        return false;
    *ad_lst = malloc(sizeof(t_vertice*) * core->verts);
    while (!mx_isalpha(core->text[core->iter]))
        ++core->iter;
    return true;
}

static bool get_names_n_dstnce(t_core *core) {
    if(core->prsd_isls > core->verts) {
        mx_error(INVALID_ISLANDS_NUM, NULL);
        return false;
    }   
    core->len = mx_strlen_delim(&core->text[core->iter], '-');
    core->isl1 = mx_strndup(&core->text[core->iter], core->len);
    core->iter += ++core->len;
    core->len = mx_strlen_delim(&core->text[core->iter], ',');
    core->isl1 = mx_strndup(&core->text[core->iter], core->len);
    core->iter += ++core->len;
    core->distance = mx_atoi(&core->text[core->iter]);
    while(core->text[core->iter] && !mx_isalpha(core->text[core->iter]))
        ++core->iter;
    return true;
}

static bool create_graph(t_core *core, int isl, t_vertice ***ad_lst) {
    int x;

    if(isl == 1)
        x = mx_check_vertice_presence(*ad_lst, core->isl1, core->prsd_isls);
    else
        x = mx_check_vertice_presence(*ad_lst, core->isl2, core->prsd_isls);
    if(x == -2) {
        mx_error(WRONG_POINTER, "check_vertice_presence()");
        return false;
    }
    else if (x == -1) {
        if(isl == 1)
            *ad_lst[core->prsd_isls] = mx_create_vertice(core->isl1, core->verts);
        else
            *ad_lst[core->prsd_isls] = mx_create_vertice(core->isl2, core->verts);
        x = core->prsd_isls;
        ++core->prsd_isls;
    }
    if(!create_edges(core, *ad_lst[x], isl))
        return false;
    return true;
}

static bool create_edges(t_core *core, t_vertice *island, int isl) {
    int y;
    int temp_edgnum;
    if(isl == 1)
        y = mx_check_edge_presence(island->edges, core->isl1, island->edges_num);
    else
        y = mx_check_edge_presence(island->edges, core->isl2, island->edges_num);
    if(y == -2) {
        mx_error(WRONG_POINTER, "check_edge_presence()");
        return false;
    }
    else if(y == -1) {
        temp_edgnum = island->edges_num;
        if(isl == 1) {
            printf("1\n");
            island->edges[temp_edgnum] = mx_create_edge(core->isl2, core->distance);
        }
        else
            island->edges[temp_edgnum] = mx_create_edge(core->isl1, core->distance);
        ++island->edges_num;
    }
    else {
        mx_error(DUPLICATE_EDGE, NULL);
        return false;
    }
    return true;    
}
