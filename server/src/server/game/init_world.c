/*
** EPITECH PROJECT, 2018
** init_world
** File description:
** init_world
*/

#include <stdlib.h>
#include "world.h"

int init_world(struct world *world, struct server_opt *options)
{
    world->x = options->width;
    world->y = options->height;
    world->map = malloc(sizeof(cell_t *) * options->height);
    if (!world->map)
        return -1;
    for (int i = 0; i < options->height; i++) {
        world->map[i] = malloc(sizeof(cell_t) * options->width);
        if (!world->map[i])
            return -1;
        for (int j = 0; j < options->width; j++)
            init_cell(&world->map[i][j]);
    }
    return 0;
}
