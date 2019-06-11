/*
** EPITECH PROJECT, 2019
** command_ppo
** File description:
** command_ppo
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static const char *format = "ppo %d %d %d %d\n";

/*
** ppo -> player position
**
** Command:  "ppo #n" from client, where #n is the player number
** Response: "ppo n X Y O" to client, where :
**          n -> player number
**          X -> horizontal position
**          Y -> vertical position
**          O -> orientation: 1(N), 2(E), 3(S), 4(W)
*/

int command_ppo(struct server *server, int i, int argc, char **argv)
{
    int target = atoi(argv[1]);
    int fd = server->clients[i]->fd;
    struct client *client;

    (void)argc;
    for (size_t j = 0; server->clients[j] != NULL; j++)
        if (server->clients[j]->id == target)
            client = server->clients[j];
    return dprintf(fd, format, target, client->x, client->y, client->direction);
}
