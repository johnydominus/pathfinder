#include "libmx.h"

t_list *mx_create_node(void *data);

void mx_push_back(t_list **list, void *data) {
    if(list == NULL) 
        return;

    if(*list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    else {
        t_list *buf = *list;

        while (buf->next)
            buf = buf->next;

        buf->next = mx_create_node(data);
    }
}
