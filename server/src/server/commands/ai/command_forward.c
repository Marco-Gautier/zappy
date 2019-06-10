/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** command_forward
*/

#include <stdio.h>
#include "zappy.h"

static int compute_new_position(int pos, int offset, int max)
{
    return (pos + offset + max) % max;
}

int forward_callback(struct server *s, struct client *client, int ac, char **av)
{
    (void)ac;
    (void)av;
    switch (client->direction) {
    case D_NORTH:
        client->y = compute_new_position(client->y, -1, s->world.height);
        break;
    case D_EAST:
        client->x = compute_new_position(client->x, 1, s->world.width);
        break;
    case D_SOUTH:
        client->y = compute_new_position(client->y, 1, s->world.height);
        break;
    case D_WEST:
        client->x = compute_new_position(client->x, -1, s->world.width);
        break;
    default:
        return -1;
    }
    return 0;
}

int command_forward(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return fprintf(stderr, "error during event time computing\n"), -1;
    event = create_event(trigger_time, argc, argv, &forward_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    if (dprintf(server->clients[i]->fd, "ok\n") < 0)
        return -1;
    return add_event(server->clients[i], event);
}
