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

/**
** ppo -> player position
**
** Command:  "ppo #n" from client, where #n is the player number
** Response: "ppo n X Y O" to client, where :
**          n -> player number
**          X -> horizontal position
**          Y -> vertical position
**          O -> orientation: 1(N), 2(E), 3(S), 4(W)
*/

static int ppo_builtin(struct client *client, struct client *target)
{
    return send_client_msg(client, format,
                           target->id,
                           target->x,
                           target->y,
                           target->direction);
}

int command_ppo(struct server *server, struct client *client,
                int argc, char **argv)
{
    int target_id = atoi(argv[1]);
    struct client *target = NULL;

    (void)argc;
    for (size_t j = 0; server->clients[j] != NULL; j++)
        if (server->clients[j]->id == target_id)
            target = server->clients[j];
    if (!target)
        return -1;
    return ppo_builtin(client, target);
}
