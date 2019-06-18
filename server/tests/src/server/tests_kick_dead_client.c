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

static struct client *create_client(void)
{
    struct client *client = malloc(sizeof(struct client));

    *client = (struct client) {
        .buffer = NULL,
        .client_type = CT_AI,
        .event = NULL,
        .team_name = strdup("team1"),
        .inventory = {
            .food = -1
        }
    };
    return client;
}

Test(kick_dead_client, no_client)
{
    struct client *client = create_client();
    struct client client_graphic = {
        .client_type = CT_GRAPHIC,
        .team_name = "GRAPHIC"
    };
    struct client *clients[] = {
        &client_graphic,
        client,
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
    assert(server.clients[2] == NULL);
    kick_dead_client(&server);
    assert(server.clients[0] == &client_graphic);
    assert(server.clients[1] == NULL);
    read(pipefd[0], buffer, sizeof(buffer));
    assert(strcmp(buffer, "dead\n") == 0);
}
