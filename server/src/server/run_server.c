/*
** EPITECH PROJECT, 2019
** run_server
** File description:
** run_server
*/

#include <stdio.h>
#include "zappy.h"

static int get_server_process_fd_max(struct server *server)
{
    int fd = server->fd;

    if (!server->clients)
        return fd;
    for (size_t i = 0; server->clients[i].fd != -1; i++)
        if (server->clients[i].fd > fd)
            fd = server->clients[i].fd;
    return fd;
}

static void server_reset_fds(struct server *server)
{
    FD_ZERO(&server->rfds);
    FD_ZERO(&server->wfds);
    FD_SET(server->fd, &server->rfds);
    if (!server->clients)
        return;
    for (size_t i = 0; server->clients[i].fd != -1; i++) {
        FD_SET(server->clients[i].fd, &server->rfds);
        FD_SET(server->clients[i].fd, &server->wfds);
    }
}

int run_server(struct server *server)
{
    int fdmax;
    struct timeval time = {0};

    while (1) {
        server_reset_fds(server);
        fdmax = get_server_process_fd_max(server);
        if (select(fdmax + 1, &server->rfds, &server->wfds, NULL, &time) == -1)
            return -1;
        if (FD_ISSET(server->fd, &server->rfds) == 0)
            continue;
        if (accept_new_client(server) == -1)
            puts("New client rejected.");
    }
    return 0;
}
