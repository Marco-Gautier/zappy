/*
** EPITECH PROJECT, 2019
** command_bct
** File description:
** command_bct
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static const char *format = "bct %d %d %d %d %d %d %d %d %d\n";

static int bct_builtin(cell_t *cell, int fd, int x, int y)
{
    return dprintf(fd, format, x, y, cell->food,
                   cell->stones[0],
                   cell->stones[1],
                   cell->stones[2],
                   cell->stones[3],
                   cell->stones[4],
                   cell->stones[5]);
}

int command_bct(struct server *server, struct client *client,
                int argc, char **argv)
{
    int x;
    int y;

    if (argc != 3)
        return send_client_msg(client, "ko\n"), -1;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (x < 0 || x >= server->options.width ||
        y < 0 || y >= server->options.height)
        return send_client_msg(client, "ko\n"), -1;
    return bct_builtin(&server->world.map[y][x], client->fd, x, y);
}
