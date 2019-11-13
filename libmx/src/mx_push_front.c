#include <stdlib.h>
#include "list.h"

t_list *mx_create_node(void *data);

void mx_push_front(t_list **list, void *data){
    t_list *n_head_node = mx_create_node(data);
    if(*list == NULL)
        *list = n_head_node;
    else{
        n_head_node->next = *list;
        *list = n_head_node;
    }
}
