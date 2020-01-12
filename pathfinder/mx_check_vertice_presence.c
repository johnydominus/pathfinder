#include "pathfinder.h"

int mx_check_vertice_presence(t_vertice **ad_list, char *content, int verts) {
    int i = 0;
    if(!ad_list)
        return -2;
    else {
        for(i = 0; i <= verts; ++i) {
            if(i == verts)
                return -1;
            else if(mx_compare_vert_names(ad_list[i], content)) {
                return i;
            }
        }
    }
    return i;
}
