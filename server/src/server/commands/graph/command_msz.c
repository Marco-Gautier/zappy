/*
** EPITECH PROJECT, 2019
** command_msz
** File description:
** command_msz
*/

#include <stdio.h>
#include "zappy.h"

int command_msz(struct server *server, int client, int argc, char **argv)
{
    int width = server->options.width;
    int height = server->options.height;

    (void)argc;
    (void)argv;
    return dprintf(server->clients[client].fd, "msz %d %d\n", width, height);
}
