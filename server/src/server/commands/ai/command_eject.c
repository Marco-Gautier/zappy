/*
** EPITECH PROJECT, 2019
** command_eject
** File description:
** command_eject
*/

#include <stdio.h>
#include "zappy.h"

static void forward_client(struct client *client, int width, int height)
{
    switch (client->direction) {
    case D_NORTH:
        client->y = compute_new_position(client->y, -1, height);
        break;
    case D_EAST:
        client->x = compute_new_position(client->x, 1, width);
        break;
    case D_SOUTH:
        client->y = compute_new_position(client->y, 1, height);
        break;
    case D_WEST:
        client->x = compute_new_position(client->x, -1, width);
        break;
    default:
        return;
    }
}

int eject_callback(struct server *s, struct client *client, int ac, char **av)
{
    const enum direction new_dir = compute_direction(client->direction, 1);

    (void)ac;
    (void)av;
    for (size_t i = 0; s->clients[i] != NULL; i++) {
        if (s->clients[i]->id == client->id)
            continue;
        if (s->clients[i]->client_type == CT_GRAPHIC)
            continue;
        if (s->clients[i]->x == client->x &&
            s->clients[i]->y == client->y) {
            forward_client(s->clients[i], s->options.width, s->options.height);
            send_client_msg(s->clients[i], "eject: %d\n", new_dir);
        }
    }
    send_graphical_broadcast(s, "pex %d\n", client->id);
    return send_client_msg(client, "ok\n");
}

int command_eject(struct server *server, struct client *client,
                  int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return -1;
    event = create_event(trigger_time, argc, argv, &eject_callback);
    if (!event)
        return -1;
    return add_event(client, event);
}
