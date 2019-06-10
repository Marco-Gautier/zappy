/*
** EPITECH PROJECT, 2019
** my_tabndup
** File description:
** my_tabndup
*/

#include <stdlib.h>
#include <string.h>

char **my_tabndup(char **tab, size_t n)
{
    size_t i;
    char **new;

    if (n == 0)
        return NULL;
    new = malloc(sizeof(char *) * (n + 1));
    if (!new)
        return NULL;
    for (i = 0; i < n; i++) {
        new[i] = strdup(tab[i]);
        if (!new[i])
            return NULL;
    }
    new[i] = NULL;
    return new;
}
