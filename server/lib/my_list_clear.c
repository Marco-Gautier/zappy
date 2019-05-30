/*
** EPITECH PROJECT, 2019
** my_list_clear
** File description:
** my_list_clear
*/

#include "my.h"

static void my_list_clear_builtin(__list_t *list, void (*destructor)(void *ptr))
{
    if (list != NULL) {
        my_list_clear_builtin(list->next, destructor);
        destructor(list);
    }
}

/*
** Erase all elements of l1 list, call destructor on each node during erasing.
*/

void my_list_clear(void **l1, void (*destructor)(void *ptr))
{
    __list_t **list = (__list_t **)l1;

    my_list_clear_builtin(*list, destructor);
    *list = NULL;
}
