/*
** EPITECH PROJECT, 2019
** command_unknown
** File description:
** command_unknown
*/

#include <stdio.h>
#include "zappy.h"

int command_unknown(struct server *server, int client, int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return dprintf(server->clients[client].fd, "ko\n");
}
