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
    cell_t *inv = &server->clients[target]->inventory;
    enum caouilloux g[C_CAOUILLOUX_SIZE];
    int f = inv->food;

    (void)argc;
    for (size_t i = 0; i < ARRAY_SIZE(g); i++)
        g[i] = inv->stones[i];
    return dprintf(fd, format, target, f, g[0], g[1], g[2], g[3], g[4], g[5]);
}
