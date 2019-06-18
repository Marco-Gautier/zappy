/*
** EPITECH PROJECT, 2019
** tests_utils
** File description:
** tests_utils
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(compute_direction, mdr)
{
    assert(compute_direction(D_NORTH, 1) == D_EAST);
    assert(compute_direction(D_NORTH, 2) == D_SOUTH);
    assert(compute_direction(D_NORTH, 3) == D_WEST);
    assert(compute_direction(D_NORTH, 4) == D_NORTH);
    assert(compute_direction(D_EAST, 1) == D_SOUTH);
    assert(compute_direction(D_EAST, 2) == D_WEST);
    assert(compute_direction(D_EAST, 3) == D_NORTH);
    assert(compute_direction(D_EAST, 4) == D_EAST);
    assert(compute_direction(D_SOUTH, 1) == D_WEST);
    assert(compute_direction(D_SOUTH, 2) == D_NORTH);
    assert(compute_direction(D_SOUTH, 3) == D_EAST);
    assert(compute_direction(D_SOUTH, 4) == D_SOUTH);
    assert(compute_direction(D_WEST, 1) == D_NORTH);
    assert(compute_direction(D_WEST, 2) == D_EAST);
    assert(compute_direction(D_WEST, 3) == D_SOUTH);
    assert(compute_direction(D_WEST, 4) == D_WEST);

    assert(compute_direction(D_NORTH, -1) == D_WEST);
    assert(compute_direction(D_NORTH, -2) == D_SOUTH);
    assert(compute_direction(D_NORTH, -3) == D_EAST);
    assert(compute_direction(D_NORTH, -4) == D_NORTH);
    assert(compute_direction(D_EAST, -1) == D_NORTH);
    assert(compute_direction(D_EAST, -2) == D_WEST);
    assert(compute_direction(D_EAST, -3) == D_SOUTH);
    assert(compute_direction(D_EAST, -4) == D_EAST);
    assert(compute_direction(D_SOUTH, -1) == D_EAST);
    assert(compute_direction(D_SOUTH, -2) == D_NORTH);
    assert(compute_direction(D_SOUTH, -3) == D_WEST);
    assert(compute_direction(D_SOUTH, -4) == D_SOUTH);
    assert(compute_direction(D_WEST, -1) == D_SOUTH);
    assert(compute_direction(D_WEST, -2) == D_EAST);
    assert(compute_direction(D_WEST, -3) == D_NORTH);
    assert(compute_direction(D_WEST, -4) == D_WEST);
}

Test(compute_new_position, mdr)
{
    assert(compute_new_position(42, -4, 100) == 38);
    assert(compute_new_position(42, 4, 100) == 46);
    assert(compute_new_position(42, 0, 100) == 42);
    assert(compute_new_position(42, 0, 43) == 42);
    assert(compute_new_position(8, 4, 10) == 2);
    assert(compute_new_position(2, -4, 10) == 8);
}

Test(list_case_content, mdr)
{
    struct client client = {
        .x = 4,
        .y = 4,
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
    char *tmp;

    cr_assert(init_world(&server.world, &server.options) == 0);
    server.world.map[4][4].food = 4;
    server.world.map[4][4].stones[C_LINEMATE] = 1;
    server.world.map[4][4].stones[C_SIBUR] = 1;
    tmp = list_case_content(&server, &server.world, 4, 4);
    assert(tmp != NULL);
    assert(strcmp(tmp, "player food linemate sibur") == 0);
}
