/*
** EPITECH PROJECT, 2019
** command_ppo
** File description:
** command_ppo
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

int command_ppo(struct server *server, int i, int argc, char **argv)
{
    enum direction dir;
    int target = atoi(argv[1]);
    int x = server->clients[target]->x;
    int y = server->clients[target]->y;
    int fd = server->clients[i]->fd;
    uint direction[D_DIRECTION_SIZE] = {
        D_NORTH,
        D_EAST,
        D_SOUTH,
        D_WEST
    };

    (void)argc;
    for (int i = 0; i < D_DIRECTION_SIZE; i++)
        if (server->clients[target]->direction == direction[i])
            dir = i + 1;
    return dprintf(fd, "ppo %d %d %d %d\n", target, x, y, dir);
}
