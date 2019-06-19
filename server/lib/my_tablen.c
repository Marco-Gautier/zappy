/*
** EPITECH PROJECT, 2019
** my_tablen
** File description:
** my_tablen
*/

#include <stddef.h>

size_t my_tablen(void *tab)
{
    char **tmp = tab;
    size_t i = 0;

    while (tmp[i] != NULL)
        i++;
    return i;
}
