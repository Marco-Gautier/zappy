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

/* Utils */
enum direction compute_direction(enum direction dir, int offset);

/* API command reserved to graphical clients */
int command_msz(struct server *server, int client, int argc, char **argv);
int command_tna(struct server *server, int client, int argc, char **argv);
int command_sst(struct server *server, int client, int argc, char **argv);
int command_sgt(struct server *server, int client, int argc, char **argv);
int command_plv(struct server *server, int client, int argc, char **argv);
int command_ppo(struct server *server, int client, int argc, char **argv);
int command_bct(struct server *server, int client, int argc, char **argv);
int command_mct(struct server *server, int client, int argc, char **argv);
int command_pin(struct server *server, int client, int argc, char **argv);

/* API command reserved to AI clients */
int command_test(struct server *server, int client, int argc, char **argv);
