/*
** EPITECH PROJECT, 2018
** my_tabdup
** File description:
** my_tabdup
*/

#include "my.h"

char **my_tabdup(char **tab)
{
    return my_tabndup(tab, my_tablen(tab));
}
