/*
** EPITECH PROJECT, 2018
** cell
** File description:
** cell
*/

#pragma once

#include <stdbool.h>

enum caouilloux {
    C_SIBUR,
    C_PHIRAS,
    C_LINEMATE,
    C_MENDIANE,
    C_THYSTAME,
    C_DERAUMERE,
    C_CAOUILLOUX_SIZE
};

typedef struct cell {
    int             food;
    enum caouilloux stones[C_CAOUILLOUX_SIZE];
} cell_t;

void    init_cell(cell_t *cell);
bool    cell_is_empty(cell_t *cell);
