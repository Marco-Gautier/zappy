/*
** EPITECH PROJECT, 2019
** commands
** File description:
** commands
*/

#pragma once

#include "server.h"

struct command {
    const char          *name;
    int (*callback)(struct server *server, int client, int argc, char **argv);
};

int command_unknown(struct server *server, int client, int argc, char **argv);

int command_msz(struct server *server, int client, int argc, char **argv);
