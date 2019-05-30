/*
** EPITECH PROJECT, 2018
** my_listlen
** File description:
** my_listlen
*/

#include "my.h"

/*
** Return the list length
*/

size_t my_listlen(void *l1)
{
    size_t i = 0;

    for (__list_t *list = l1; list != NULL; list = list->next)
        i++;
    return i;
}
