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
#include "zappy.h"

void remove_client(struct server *server, int i)
{
    size_t last = 0;

    close(server->clients[i]->fd);
    free(server->clients[i]->buffer);
    while (server->clients[last] != NULL)
        last++;
    free(server->clients[i]);
    server->clients[i] = server->clients[last - 1];
    server->clients[last - 1] = NULL;
}

/*
** 1) Kick client from server, send "dead\n" to this client.
** 2) Broadcast the dead to other.
*/

void kick_client_from_server(struct server *server, int i)
{
    char buff[64];

    if (server->clients[i]->hatched == true)
        snprintf(buff, sizeof(buff), "edi %d\n", server->clients[i]->egg_id);
    else
        snprintf(buff, sizeof(buff), "pdi %d\n", server->clients[i]->id);
    send_graphical_broadcast(server, buff);
    dprintf(server->clients[i]->fd, "dead\n");
    remove_client(server, i);
    printf("Client n°%d left.\n", i);
}
