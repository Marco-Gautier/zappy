/*
** EPITECH PROJECT, 2019
** kick_client_from_server
** File description:
** kick_client_from_server
*/

#include <stdio.h>
#include "zappy.h"

/*
** 1) Kick client from server, send "dead\n" to this client.
** 2) Broadcast the dead to other.
*/

void kick_client_from_server(struct server *server, int i)
{
    char buff[64];

    if (server->clients[i].hatched == true)
        snprintf(buff, sizeof(buff), "edi %d\n", server->clients[i].egg_id);
    else
        snprintf(buff, sizeof(buff), "pdi %d\n", i);
    send_graphical_broadcast(server, buff);
    dprintf(server->clients[i].fd, "dead\n");
//    client_reset_slot(&server->clients[i]);
    puts("Client left.");
}
