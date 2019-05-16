/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** zappy
*/

#pragma once

#include <sys/select.h>
#include "client.h"
#include "options.h"

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define destructor(dtor)    __attribute__((cleanup(dtor)))

#define MAX_CLIENTS (1024)

struct server {
    struct server_opt   options;
    int                 fd;
    fd_set              rfds;
    fd_set              wfds;
    struct client       *clients;
};

struct command {
    const char          *name;
    int (*callback)(struct server *server, int client, int argc, char **argv);
};

int     init_server(struct server *server);
int     run_server(struct server *server);
int     accept_new_client(struct server *server);
void    read_clients_fd(struct server *server);
int     exec_client_command(struct server *server, int i);
void    kick_client_from_server(struct server *server, int i);
void    send_graphical_broadcast(struct server *server, const char *message);

int command_unknown(struct server *server, int client, int argc, char **argv);

int command_msz(struct server *server, int client, int argc, char **argv);
