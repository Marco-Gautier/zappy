/*
** EPITECH PROJECT, 2019
** world
** File description:
** world
*/

#pragma once

#include "options.h"
#include "cell.h"

struct world {
        int         width;
        int         height;
        cell_t      **map;
};

int init_world(struct world *world, struct server_opt *options);
