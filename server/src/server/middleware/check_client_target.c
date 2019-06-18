/*
** EPITECH PROJECT, 2019
** check_client_target
** File description:
** check_client_target
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static struct client *get_client(struct client **clients, int id)
{
    if (clients)
        for (size_t i = 0; clients[i] != NULL; i++)
            if (clients[i]->id == id)
                return clients[i];
    return NULL;
}

/*
** Middleware use to check if the client target is valid
*/

int check_client_target(struct server *server, int clien, int argc, char **argv)
{
    struct client *client;
    int id;

    (void)clien;
    if (argc != 2)
        return -1;
    id = atoi(argv[1]);
    if (id < 1)
        return -1;
    client = get_client(server->clients, id);
    if (!client)
        return -1;
    if (client->client_type != CT_AI)
        return -1;
    return 0;
}
