/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_forward
*/

#include <stdio.h>
#include "zappy.h"

int forward_callback(struct server *s, struct client *client, int ac, char **av)
{
    (void)ac;
    (void)av;

    switch (client->direction) {
        case D_NORTH:
            client->y = (client->y - 1 >= 0) ? client->y - 1 : s->world.height;
        case D_EAST:
            client->x = (client->x + 1) % s->world.width;
        case D_SOUTH:
            client->y = (client->y + 1) % s->world.height;
        case D_WEST:
            client->x = (client->x - 1 >= 0) ? client->x - 1 : s->world.width;
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