#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *buf = *head;
    *head = (*head)->next;

    free(buf);
}
