#include "libmx.h"

t_list *mx_create_node(void *data);

void mx_push_back(t_list **list, void *data) {
    t_list *buf = *list;

    while (buf->next)
        buf->next = buf->next->next;

    buf->next = mx_create_node(data);
}
