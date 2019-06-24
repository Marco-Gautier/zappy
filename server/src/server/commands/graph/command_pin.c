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

static int pin_builtin(struct client *client, int target_id,
                       inventory_t *inventory)
{
    return send_client_msg(client, format, target_id, inventory->food,
                           inventory->stones[0],
                           inventory->stones[1],
                           inventory->stones[2],
                           inventory->stones[3],
                           inventory->stones[4],
                           inventory->stones[5]);
}

int command_pin(struct server *server, struct client *client,
                int argc, char **argv)
{
    int target_id = atoi(argv[1]);
    inventory_t *inventory = NULL;

    (void)argc;
    for (size_t j = 0; server->clients[j] != NULL; j++)
        if (server->clients[j]->id == target_id)
            inventory = &server->clients[j]->inventory;
    if (!inventory)
        return -1;
    return pin_builtin(client, target_id, inventory);
}
