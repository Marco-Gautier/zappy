/*
** EPITECH PROJECT, 2019
** command_bct
** File description:
** command_bct
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

// TODO : add more explicit error message

static const char *format = "bct %d %d %d %d %d %d %d %d %d\n";

/*
** C'est la pire fonction
*/

static int bct_builtin(cell_t *cell, int fd, int x, int y)
{
    int mdr = cell->food;
    enum caouilloux g[C_CAOUILLOUX_SIZE];

    for (size_t i = 0; i < ARRAY_SIZE(g); i++)
        g[i] = cell->stones[i];
    return dprintf(fd, format, x, y, mdr, g[0], g[1], g[2], g[3], g[4], g[5]);
}

int command_bct(struct server *server, int i, int argc, char **argv)
{
    struct server_opt *options = &server->options;
    int x;
    int y;

    if (argc != 3)
        return dprintf(server->clients[i]->fd, "ko\n");
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (x < 0 || x >= options->width || y < 0 || y >= options->height)
        return dprintf(server->clients[i]->fd, "ko\n");
    return bct_builtin(&server->world.map[x][y], server->clients[i]->fd, x, y);
}
