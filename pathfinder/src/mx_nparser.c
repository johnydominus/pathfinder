#include "pathfinder.h"

static bool init(t_core *core);
static bool get_names_n_dstnce(t_core *core);
static bool parse_island(char *name, t_core *core);
static bool fill_matrix(t_core *core);

bool mx_nparser(t_core *core) {
    if(!init(core))
        return false;
    while (core->text[core->iter]) {
        if(!get_names_n_dstnce(core)
        || !parse_island(core->isl1, core)
        || !parse_island(core->isl2, core)
        || !fill_matrix(core)) {
            mx_error(INVALID_ISLANDS_NUM, NULL);
            return false;
        }
    }
    return true;
}

static bool init(t_core *core) {
    core->iter = 0;
    core->verts = mx_atoi(core->text);
    if(core->verts == 0)
        return false;
    while (!mx_isalpha(core->text[core->iter]))
        ++core->iter;
    core->names = (char**)malloc(sizeof(char*) * core->verts);
    core->matrix = (int**)malloc(sizeof(int*) * core->verts);
    for(int i = 0; i < core->verts; ++i) {
        core->matrix[i] = (int*)malloc(sizeof(int) * core->verts);
        for(int j = 0; j < core->verts; ++j) 
            core->matrix[i][j] = 0;
    }
    for(int i = 0; i < core->verts; ++i) {
        for(int j = 0; j < core->verts; ++j) {
            printf("%d ", core->matrix[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
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
    core->isl2 = mx_strndup(&core->text[core->iter], core->len);
    core->iter += ++core->len;
    core->distance = mx_atoi(&core->text[core->iter]);
    while(core->text[core->iter] && !mx_isalpha(core->text[core->iter]))
        ++core->iter;
    printf("Got data: %s,%s,%d\n", core->isl1, core->isl2, core->distance);
    return true;
}

static bool parse_island(char *name, t_core *core) {
    for(int i = 0; i < core->verts; ++i) {
        if(core->names[i] == NULL) {
            core->names[i] = mx_strdup(name);
            printf("%d island parsed: %s!\n", i + 1, core->names[i]);
            return true;
        }
        else if(!mx_strcmp(name, core->names[i])) {
            return true;
        }
    }
    return false;
}

static bool fill_matrix(t_core *core) {
    int i;
    int j;

    for(i = 0; i < core->verts; ++i) {
        if(core->names[i] != NULL) {
            if(!mx_strcmp(core->isl1, core->names[i])) {
                for(j = 0; j < core->verts; ++j) {
                    if(core->names[j] != NULL) {
                        if(!mx_strcmp(core->isl2, core->names[j])) {
                            core->matrix[i][j] = core->distance;
                            core->matrix[j][i] = core->distance;
                            printf("Edge parsed: %s-%s,%d\n", core->names[i], core->names[j], core->matrix[i][j]);
                            printf("Edge parsed: %s-%s,%d\n", core->names[j], core->names[i], core->matrix[j][i]);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return true;
}
