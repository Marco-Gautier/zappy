/*
** EPITECH PROJECT, 2018
** world
** File description:
** world
*/

#pragma once

#include "options.h"
#include "cell.h"

struct world {
        int         x;
        int         y;
        cell_t      **map;
};

int init_world(struct world *world, struct server_opt *options);
