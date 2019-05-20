/*
** EPITECH PROJECT, 2019
** command_plv
** File description:
** command_plv
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

int command_plv(struct server *server, int i, int argc, char **argv)
{
    int target = atoi(argv[1]);
    int level = server->clients[target]->level;

    (void)argc;
    return dprintf(server->clients[i]->fd, "plv %d %d\n", target, level);
}
