/*
** EPITECH PROJECT, 2019
** tests_kick_dead_client
** File description:
** tests_kick_dead_client
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

static struct client *create_client(bool hatched)
{
    struct client *client = malloc(sizeof(struct client));

    *client = (struct client) {
        .buffer = NULL,
        .type = CT_AI,
        .event = NULL,
        .hatched = hatched,
        .id = hatched + 1,
        .inventory = {
            .food = -1
        },
        .team_name = strdup("team1"),
    };
    return client;
}

Test(kick_dead_client, mdr)
{
    struct client *client_hatched = create_client(true);
    struct client *client = create_client(false);
    struct client client_graphic = {
        .type = CT_GRAPHIC,
        .id = 0,
        .team_name = "GRAPHIC"
    };
    struct client *clients[] = {
        &client_graphic,
        client,
        client_hatched,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd[2];
    char buffer[512] = {0};

    close(STDOUT_FILENO);
    assert(pipe(pipefd) == 0);
    client->fd = pipefd[1];
    assert(server.clients[0] == &client_graphic);
    assert(server.clients[1] == client);
    assert(server.clients[2] == client_hatched);
    assert(server.clients[3] == NULL);
    kick_dead_client(&server);
    assert(server.clients[0] == &client_graphic);
    assert(server.clients[1] == NULL);
    read(pipefd[0], buffer, sizeof(buffer));
    assert(strcmp(buffer, "dead\n") == 0);
}
