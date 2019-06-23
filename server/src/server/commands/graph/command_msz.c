/*
** EPITECH PROJECT, 2019
** command_msz
** File description:
** command_msz
*/

#include <stdio.h>
#include "zappy.h"

static const char *format = "msz %d %d\n";

int command_msz(struct server *server, int client, int argc, char **argv)
{
    int width = server->options.width;
    int height = server->options.height;

    (void)argc;
    (void)argv;
    return send_client_msg(server->clients[client], format, width, height);
}
