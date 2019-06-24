/*
** EPITECH PROJECT, 2019
** tests_read_clients_fd
** File description:
** tests_read_clients_fd
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(read_clients_fd, no_client)
{
    struct server server = {
        .clients = NULL
    };

    read_clients_fd(&server);
    assert(server.clients == NULL);
}

static struct client *create_client(int id)
{
    struct client *client = malloc(sizeof(struct client));

    client->type = CT_GRAPHIC;
    client->team_name = strdup("GRAPHIC");
    client->buffer = NULL;
    client->id = id;
    return client;
}

Test(read_clients_fd, 2_clients)
{
    struct client *client1 = create_client(42);
    struct client *client2 = create_client(84);
    struct client *clients[] = {
        client1,
        client2,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd1[2];
    int pipefd2[2];

    close(STDOUT_FILENO);
    cr_assert(pipe(pipefd1) != -1);
    cr_assert(pipe(pipefd2) != -1);
    server.clients[0]->fd = pipefd1[1];
    server.clients[1]->fd = pipefd2[1];
    FD_ZERO(&server.rfds);
    FD_SET(server.clients[0]->fd, &server.rfds);
    FD_SET(server.clients[1]->fd, &server.rfds);
    __FDS_BITS(&server.rfds)[__FD_ELT(server.clients[0]->fd)] = 0;
    __FDS_BITS(&server.rfds)[__FD_ELT(server.clients[1]->fd)] = 0xFFFFFFFFF;
    server.clients[1]->fd = pipefd1[0];
    read_clients_fd(&server);
    read_clients_fd(&server);
    cr_assert(strcmp("pdi 42\ndead\n", server.clients[0]->buffer) == 0);
}

Test(read_clients_fd, too_much_command_kick_client)
{
    struct client *client = create_client(42);
    struct client *clients[] = {
        client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd[2];

    client->buffer = strdup("");
    close(STDOUT_FILENO);
    cr_assert(pipe(pipefd) != -1);
    server.clients[0]->fd = pipefd[0];
    FD_ZERO(&server.rfds);
    FD_SET(server.clients[0]->fd, &server.rfds);
    __FDS_BITS(&server.rfds)[__FD_ELT(server.clients[0]->fd)] = 0xFFFFFFFFF;
    dprintf(pipefd[1], "Q\nQ\nQ\nQ\nQ\nQ\nQ\nQ\nQ\nQ\n");
    cr_assert(server.clients[0] == client);
    cr_assert(server.clients[1] == NULL);
    read_clients_fd(&server);
    cr_assert(server.clients[0] == NULL);
}
