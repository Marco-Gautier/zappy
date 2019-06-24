/*
** EPITECH PROJECT, 2019
** command_plv
** File description:
** command_plv
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

int command_plv(struct server *server, struct client *client,
                int argc, char **argv)
{
    int target = atoi(argv[1]);
    int level = server->clients[target]->level;

    (void)argc;
    return send_client_msg(client, "plv %d %d\n", target, level);
}
