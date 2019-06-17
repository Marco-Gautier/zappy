/*
** EPITECH PROJECT, 2019
** tests_food_events
** File description:
** tests_food_events
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(food_events, callback)
{
    struct client client = {
        .inventory = {
            .food = 42
        }
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .events = NULL,
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    int empty_counter = 0;

    cr_assert(init_world(&server.world, &server.options) == 0);
    for (int i = 0; i < server.options.height; i++)
        for (int j = 0; j < server.options.width; j++)
            assert(cell_is_empty(&server.world.map[i][j]) == true);
    cr_assert(food_callback(&server, &client, 0, NULL) == 0);
    cr_assert(client.inventory.food == 41);
    for (int i = 0; i < server.options.height; i++)
        for (int j = 0; j < server.options.width; j++)
            empty_counter += !cell_is_empty(&server.world.map[i][j]);
    cr_assert(empty_counter != 0);
}
