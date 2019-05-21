/*
** EPITECH PROJECT, 2019
** server
** File description:
** server
*/

#pragma once

#include <sys/select.h>
#include "world.h"

struct server {
    struct server_opt   options;
    int                 fd;
    fd_set              rfds;
    fd_set              wfds;
    struct world        world;
    struct client       **clients;
};

int     init_server(struct server *server);
int     run_server(struct server *server);
int     accept_new_client(struct server *server);
