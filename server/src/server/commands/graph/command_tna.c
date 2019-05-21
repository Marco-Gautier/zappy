/*
** EPITECH PROJECT, 2019
** command_tna
** File description:
** command_tna
*/

#include <stdio.h>
#include "zappy.h"

static const char *format = "tna %s\n";

int command_tna(struct server *server, int i, int argc, char **argv)
{
    (void)argc;
    (void)argv;
    for (size_t j = 0; server->options.team_names[j] != NULL; j++)
        dprintf(server->clients[i]->fd, format, server->options.team_names[j]);
    return 0;
}
