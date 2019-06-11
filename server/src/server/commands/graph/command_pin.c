/*
** EPITECH PROJECT, 2019
** command_pin
** File description:
** command_pin
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static const char *format = "pin %d %d %d %d %d %d %d %d\n";

/*
** C'est la pire fonction 2
*/

int command_pin(struct server *server, int i, int argc, char **argv)
{
    int fd = server->clients[i]->fd;
    int target = atoi(argv[1]);
    inventory_t *inventory;
    int g[C_CAOUILLOUX_SIZE];
    int mdr;

    (void)argc;
    for (size_t j = 0; server->clients[j] != NULL; j++)
        if (server->clients[j]->id == target)
            inventory = &server->clients[j]->inventory;
    for (size_t i = 0; i < C_CAOUILLOUX_SIZE; i++)
        g[i] = inventory->stones[i];
    mdr = inventory->food;
    return dprintf(fd, format, target, mdr, g[0], g[1], g[2], g[3], g[4], g[5]);
}
