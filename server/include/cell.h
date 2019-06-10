/*
** EPITECH PROJECT, 2018
** cell
** File description:
** cell
*/

#pragma once

#include <stdbool.h>

enum caouilloux {
    C_LINEMATE,
    C_DERAUMERE,
    C_SIBUR,
    C_MENDIANE,
    C_PHIRAS,
    C_THYSTAME,
    C_CAOUILLOUX_SIZE
};

typedef struct cell {
    int food;
    int stones[C_CAOUILLOUX_SIZE];
} cell_t;

void    init_cell(cell_t *cell);
bool    cell_is_empty(cell_t *cell);

extern const char *cayou_names[];
