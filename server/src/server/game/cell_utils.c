/*
** EPITECH PROJECT, 2018
** cell_utils
** File description:
** cell_utils
*/

#include <string.h>
#include "cell.h"

const char *cayou_names[] = {
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

void init_cell(cell_t *cell)
{
    memset(cell, 0, sizeof(cell_t));
}

bool cell_is_empty(cell_t *cell)
{
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++)
        if (cell->stones[i])
            return false;
    if (cell->food)
        return false;
    return true;
}
