#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *buf = *head;

    while (buf->next) {
        if (buf->next->next)
            buf->next = buf->next->next;
        else {
            free(buf->next);
            buf->next = NULL;
        }
    }
}
