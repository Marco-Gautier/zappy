/*
** EPITECH PROJECT, 2019
** commands
** File description:
** commands
*/

#pragma once

#include "middleware.h"

struct command {
    const char          *name;
    middleware_t        middleware[MIDDLEWARE_NB];
    int (*callback)(struct server *server, int client, int argc, char **argv);
};

int command_unknown(struct server *server, int client, int argc, char **argv);

int command_msz(struct server *server, int client, int argc, char **argv);
int command_tna(struct server *server, int client, int argc, char **argv);
int command_sst(struct server *server, int client, int argc, char **argv);
int command_sgt(struct server *server, int client, int argc, char **argv);
