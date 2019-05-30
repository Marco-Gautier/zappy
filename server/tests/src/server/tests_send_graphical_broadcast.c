/*
** EPITECH PROJECT, 2019
** tests_send_graphical_broadcast
** File description:
** tests_send_graphical_broadcast
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

/*
** Keskon ferait pas pour du coverage
*/

Test(send_graphical_broadcast, one_client)
{
    const char *message = "jeune renoi sauvage\n";
    struct client client = {
        .client_type = CT_GRAPHIC,
        .team_name = "GRAPHIC",
        .buffer = NULL
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd[2];

    cr_assert(pipe(pipefd) != -1);
    server.clients[0]->fd = pipefd[1];
    FD_ZERO(&server.rfds);
    FD_SET(server.clients[0]->fd, &server.rfds);
    __FDS_BITS(&server.rfds)[__FD_ELT(server.clients[0]->fd)] = 0xFFFFFFFFF;
    send_graphical_broadcast(&server, message);
    server.clients[0]->fd = pipefd[0];
    read_clients_fd(&server);
    cr_assert(strcmp(message, server.clients[0]->buffer) == 0);
}

Test(send_graphical_broadcast, one_client_2)
{
    const char *message = "jeune renoi \nsauvage\n";
    struct client client = {
        .client_type = CT_GRAPHIC,
        .team_name = "GRAPHIC",
        .buffer = strdup("")
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd[2];

    cr_assert(pipe(pipefd) != -1);
    server.clients[0]->fd = pipefd[1];
    FD_ZERO(&server.rfds);
    FD_SET(server.clients[0]->fd, &server.rfds);
    __FDS_BITS(&server.rfds)[__FD_ELT(server.clients[0]->fd)] = 0xFFFFFFFFF;
    send_graphical_broadcast(&server, message);
    server.clients[0]->fd = pipefd[0];
    read_clients_fd(&server);
    cr_assert(strcmp(message, server.clients[0]->buffer) == 0);
}
