#include "pathfinder.h"

int mx_check_islands(t_list **list, char *island) {
    if(list == NULL || *list == NULL) 
        return 0;

    else {
        t_list *buf = *list;

        while (buf->next) {
            if(mx_strcmp(buf->data->name, island)
                return 1;
            buf = buf->next;
        }

        return 0;
    }
}