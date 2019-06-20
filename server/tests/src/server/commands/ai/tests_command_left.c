/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_left
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "zappy.h"

int left_callback(struct server *s, struct client *client, int ac, char **av);

Test(command_left, left_from_north)
{
    int pipefd[2];
    struct client client = {
        .direction = D_NORTH
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = { .clients = clients };
    char buffer[512] = { 0 };

    cr_assert_eq(pipe(pipefd), 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert_neq(left_callback(NULL, &client, 1, NULL), -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert_eq(client.direction, D_WEST);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_left, left_from_west)
{
    int pipefd[2];
    struct client client = {
        .direction = D_WEST
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = { .clients = clients };
    char buffer[512] = { 0 };

    cr_assert_eq(pipe(pipefd), 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert_neq(left_callback(NULL, &client, 1, NULL), -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert_eq(client.direction, D_SOUTH);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_left, left_from_south)
{
    int pipefd[2];
    struct client client = {
        .direction = D_SOUTH
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = { .clients = clients };
    char buffer[512] = { 0 };

    cr_assert_eq(pipe(pipefd), 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert_neq(left_callback(NULL, &client, 1, NULL), -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert_eq(client.direction, D_EAST);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_left, left_from_east)
{
    int pipefd[2];
    struct client client = {
        .direction = D_EAST
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = { .clients = clients };
    char buffer[512] = { 0 };

    cr_assert_eq(pipe(pipefd), 0);
    server.clients[0]->fd = pipefd[1];
    cr_assert_neq(left_callback(NULL, &client, 1, NULL), -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ok\n") == 0);
    cr_assert_eq(client.direction, D_NORTH);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_left, test_left_event_creation)
{
    struct client client = {
        .event = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.freq = 100
    };

    cr_assert(command_left(&server, 0, 1, NULL) == 0);
    cr_assert(server.clients[0]->event != NULL);
    cr_assert(server.clients[0]->event->callback == left_callback);
}
