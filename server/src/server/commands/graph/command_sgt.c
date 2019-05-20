/*
** EPITECH PROJECT, 2019
** command_sgt
** File description:
** command_sgt
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

int command_sgt(struct server *server, int i, int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return dprintf(server->clients[i]->fd, "sgt %d\n", server->options.freq);
}
