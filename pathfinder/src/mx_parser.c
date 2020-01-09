#include "pathfinder.h"

static bool init(char *data, int *itr, int *verts, t_vertice **ad_lst);

bool mx_parser(char **data, int *itr, int *verts, t_vertice **ad_lst) {
    if(!init(*data, itr, verts, ad_lst))
        return false;
    return true;
}

static bool init(char *data, int *itr, int *verts, t_vertice **ad_lst) {
    int i = 0;
    *verts = mx_atoi(data);
    if(*verts == 0)
        return false;
    ad_lst = malloc(sizeof(t_vertice*) * *verts);

    while (!mx_isalpha(data[i])) {
        printf("%s!!!\n",&data[i]);
        i++;
    }
    *itr = i;
    return true;
}
