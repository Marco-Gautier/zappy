/*
** EPITECH PROJECT, 2019
** kick_client_from_server
** File description:
** kick_client_from_server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
#include "zappy.h"

void remove_client(struct server *server, int i)
{
    size_t last = 0;

    close(server->clients[i]->fd);
    free(server->clients[i]->buffer);
    if (server->clients[i]->client_type == CT_AI)
        free(server->clients[i]->team_name);
    my_list_clear(&server->clients[i]->event, free);
    while (server->clients[last] != NULL)
        last++;
    free(server->clients[i]);
    server->clients[i] = server->clients[last - 1];
    server->clients[last - 1] = NULL;
}

/**
** 1) Kick client from server, send "dead\n" to this client.
**
** 2) Broadcast the dead to other.
*/

void kick_client_from_server(struct server *server, int i)
{
    struct client *client = server->clients[i];

    if (server->clients[i]->hatched == true)
        send_graphical_broadcast(server, "edi %d\n", client->egg_id);
    else
        send_graphical_broadcast(server, "pdi %d\n", client->id);
    dprintf(client->fd, "dead\n");
    printf("Client n°%d left.\n", client->id);
    remove_client(server, i);
}
