/*
** EPITECH PROJECT, 2019
** command_sst
** File description:
** command_sst
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static const char *format = "sst %d\n";

int command_sst(struct server *server, struct client *client,
                int argc, char **argv)
{
    int tmp;

    if (argc == 2) {
        tmp = atoi(argv[1]);
        if (tmp > 0)
            server->options.freq = tmp;
    }
    return send_client_msg(client, format, server->options.freq);
}
