/*
** EPITECH PROJECT, 2019
** send_graphical_broadcast
** File description:
** send_graphical_broadcast
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"

void send_graphical_broadcast(struct server *server, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (!server->clients[i]->team_name)
            continue;
        if (server->clients[i]->client_type != CT_GRAPHIC)
            continue;
        vdprintf(server->clients[i]->fd, format, ap);
    }
    va_end(ap);
}
