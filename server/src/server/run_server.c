/*
** EPITECH PROJECT, 2019
** run_server
** File description:
** run_server
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

/**
** man 2 select
**
** man 2 select_tut
**
** Compute and return the highest-numbered file descriptor in any of the
** three sets, + 1. Use as select(2) first parameter.
**
*/

static int get_server_process_fd_max(struct server *server)
{
    int fd = server->fd;

    if (!server->clients)
        return fd;
    for (size_t i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->fd > fd)
            fd = server->clients[i]->fd;
    return fd;
}

/**
** man 2 select_tut
**
** 𝙻̲𝚊̲𝚠̲ ̲𝟷̲𝟷̲ :
** Since select() modifies its file descriptor sets, if the call is being used
** in a loop, then the sets must be reinitialized before each call.
*/

static void server_reset_fds(struct server *server)
{
    FD_ZERO(&server->rfds);
    FD_ZERO(&server->wfds);
    FD_SET(server->fd, &server->rfds);
    if (server->clients)
        for (size_t i = 0; server->clients[i] != NULL; i++) {
            if (server->clients[i]->fd != -1) {
                FD_SET(server->clients[i]->fd, &server->rfds);
                FD_SET(server->clients[i]->fd, &server->wfds);
            }
        }
}

/**
** 1) Walk through all used clients with an existing buffer
**
** 2) Check if the buffer contains an entire command
**
** 3) Execute this command
*/

static void exec_clients_command(struct server *server)
{
    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!server->clients[i]->buffer)
            continue;
        if (strchr(server->clients[i]->buffer, '\n') != NULL)
            exec_client_command(server, server->clients[i]);
    }
}

int run_server(struct server *server)
{
    int fdmax;
    struct timeval *time = NULL;

    add_stones_event(server);
    while (!is_game_over(server)) {
        server_reset_fds(server);
        fdmax = get_server_process_fd_max(server);
        if (select(fdmax + 1, &server->rfds, &server->wfds, NULL, time) == -1)
            return -1;
        if (FD_ISSET(server->fd, &server->rfds))
            if (accept_new_client(server) == -1)
                puts("New client rejected.");
        read_clients_fd(server);
        exec_clients_command(server);
        update_events(server);
        kick_dead_client(server);
    }
    return 0;
}
