/*
** EPITECH PROJECT, 2019
** tests_stones_events
** File description:
** tests_stones_events
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(stones_events, callback)
{
    srand(time(NULL));
    struct server server = {
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        },
        .events = NULL
    };
    int empty_counter = 0;

    assert(init_world(&server.world, &server.options) == 0);
    for (int i = 0; i < server.options.height; i++)
        for (int j = 0; j < server.options.width; j++)
            assert(cell_is_empty(&server.world.map[i][j]) == true);
    assert(server.events == NULL);
    assert(stones_callback(&server, NULL, 0, NULL) == 0);
    for (int i = 0; i < server.options.height; i++)
        for (int j = 0; j < server.options.width; j++)
            empty_counter += !cell_is_empty(&server.world.map[i][j]);
    assert(server.events != NULL);
    assert(server.events->callback == stones_callback);
    assert(empty_counter != 0);
}
