/*
** EPITECH PROJECT, 2019
** my_tablen
** File description:
** my_tablen
*/

#include <stddef.h>

size_t my_tablen(char **tab)
{
    size_t i = 0;

    while (tab[i] != NULL)
        i++;
    return i;
}
