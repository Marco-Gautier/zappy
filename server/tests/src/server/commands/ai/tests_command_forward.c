/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_forward
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "zappy.h"

Test(command_forward, forward_north)
{
    int pipefd[2];
    struct client client = {
        .direction = D_NORTH,
        .x = 0,
        .y = 1
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_west)
{
    int pipefd[2];
    struct client client = {
        .direction = D_WEST,
        .x = 1,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_south)
{
    int pipefd[2];
    struct client client = {
        .direction = D_SOUTH,
        .x = 0,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 1);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_east)
{
    int pipefd[2];
    struct client client = {
        .direction = D_EAST,
        .x = 0,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 1);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_wrong_direction)
{
    struct client client = {
        .direction = D_DIRECTION_SIZE,
        .x = 0,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };

    cr_assert(forward_callback(&server, &client, 1, NULL) == -1);
}

Test(command_forward, forward_north_round_map)
{
    int pipefd[2];
    struct client client = {
        .direction = D_NORTH,
        .x = 0,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 9);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_west_round_map)
{
    int pipefd[2];
    struct client client = {
        .direction = D_WEST,
        .x = 0,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 9);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_south_round_map)
{
    int pipefd[2];
    struct client client = {
        .direction = D_SOUTH,
        .x = 0,
        .y = 9
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, forward_east_round_map)
{
    int pipefd[2];
    struct client client = {
        .direction = D_EAST,
        .x = 9,
        .y = 0
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world.height = 10,
        .world.width = 10
    };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert(forward_callback(&server, &client, 1, NULL) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert(client.x == 0);
    cr_assert(client.y == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_forward, test_forward_event_creation)
{
    struct client client = { .event = NULL };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.freq = 100
    };

    cr_assert(command_forward(&server, &client, 1, NULL) == 0);
    cr_assert(server.clients[0]->event != NULL);
    cr_assert(server.clients[0]->event->callback == forward_callback);
}
