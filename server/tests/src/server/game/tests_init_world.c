/*
** EPITECH PROJECT, 2019
** tests_init_world
** File description:
** tests_init_world
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(world, init)
{
    struct server_opt options = {
        .width = 11,
        .height = 12
    };
    struct world world;

    init_world(&world, &options);
    assert(world.map != NULL);
    assert(world.width == 11);
    assert(world.height == 12);
    for (int i = 0; i < world.height; i++)
        for (int j = 0; j < world.width; j++)
            assert(cell_is_empty(&world.map[i][j]) == true);
}
