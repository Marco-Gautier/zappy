/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** my_node_destroy
*/

#include <stdlib.h>
#include "my.h"

/*
** I didn't find a better name
** Remove a node in doubly linked list
** returns the head of the list
*/
void *my_node_destroy(void *l1, void *l2)
{
    __list_t *list = (__list_t *) l1;
    __list_t *old = (__list_t *) l2;

    if (!l1 || !l2)
        return NULL;
    if (list == old)
        list = old->next;
    if (old->next)
        old->next->prev = old->prev;
    if (old->prev)
        old->prev->next = old->next;
    free(l2);
    return list;
}