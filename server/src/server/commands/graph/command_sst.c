/*
** EPITECH PROJECT, 2019
** command_sst
** File description:
** command_sst
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

int command_sst(struct server *server, int i, int argc, char **argv)
{
    int tmp;

    if (argc == 2) {
        tmp = atoi(argv[1]);
        if (tmp > 0)
            server->options.freq = tmp;
    }
    return dprintf(server->clients[i]->fd, "sst %d\n", server->options.freq);
}
