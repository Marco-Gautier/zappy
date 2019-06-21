/*
** EPITECH PROJECT, 2019
** command_broadcast
** File description:
** command_broadcast
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy.h"

static const char *format = "message %d, %s";

static void send_broadcast(struct server *server, struct client *client,
const char *message)
{
    struct client *target;
    int direction;

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i] == client)
            continue;
        if (server->clients[i]->client_type != CT_AI)
            continue;
        target = server->clients[i];
        direction = broadcast_direction(&server->options, client, target);
        send_client_msg(server->clients[i], format, direction, message);
    }
}

int broadcast_callback(struct server *s, struct client *client,
int ac, char **av)
{
    size_t size;
    char *tmp = strdup("");

    if (!tmp)
        return -1;
    for (int i = 1; i < ac; i++) {
        size = sizeof(char) * (strlen(tmp) + strlen(av[i]) + 5);
        tmp = realloc(tmp, size);
        if (!tmp)
            return -1;
        strcat(tmp, av[i]);
        strcat(tmp, " ");
    }
    strcat(tmp, "\n");
    send_broadcast(s, client, tmp);
    send_graphical_broadcast(s, "pbc %d %s", client->id, tmp);
    free(tmp);
    return send_client_msg(client, "ok\n");
}

int command_broadcast(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return -1;
    event = create_event(trigger_time, argc, argv, &broadcast_callback);
    if (!event)
        return -1;
    return add_event(server->clients[i], event);
}
