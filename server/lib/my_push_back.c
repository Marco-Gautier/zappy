/*
** EPITECH PROJECT, 2018
** my_push_back
** File description:
** my_push_back
*/

#include "my.h"

/*
** Push l2 node at the end of l1 list.
** If l1 list doesn't exist, return l2 node as a list.
*/

void *my_push_back(void *l1, void *l2)
{
    __list_t *list = l1;
    __list_t *new = l2;

    if (!list)
        return l2;
    if (!new)
        return l1;
    while (list != NULL && list->next != NULL)
        list = list->next;
    list->next = new;
    new->prev = list;
    return l1;
}
