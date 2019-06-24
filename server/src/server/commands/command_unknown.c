/*
** EPITECH PROJECT, 2019
** command_unknown
** File description:
** command_unknown
*/

#include <stdio.h>
#include "zappy.h"

int command_unknown(struct server *server, struct client *client,
                    int argc, char **argv)
{
    (void)server;
    (void)argc;
    (void)argv;
    return send_client_msg(client, "ko\n");
}
