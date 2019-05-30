/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** my_list_erase
*/

#include "my.h"

/*
** Erase l2 node in l1 list.
** Call destructor function to destroy l2.
*/

void *my_list_erase(void *l1, void *l2, void (*destructor)(void *ptr))
{
    __list_t *list = l1;
    __list_t *to_remove = l2;

    if (!list)
        return NULL;
    if (!l2)
        return list;
    else if (to_remove->next == NULL && to_remove->prev != NULL)
        to_remove->prev->next = NULL;
    if (list == to_remove)
        list = list->next;
    if (to_remove->next != NULL)
        to_remove->next->prev = to_remove->prev;
    if (to_remove->prev != NULL)
        to_remove->prev->next = to_remove->next;
    if (destructor != NULL)
        destructor(l2);
    return list;
}
