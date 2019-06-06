/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** description
*/

/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** description
*/

#include <stdio.h>
#include "zappy.h"

int left_callback(struct server *s, struct client *client, int ac, char **av)
{
    (void)ac;
    (void)av;
    (void)s;

    client->direction = compute_direction(client->direction, -1);
    return 0;
}

int command_left(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return fprintf(stderr, "error during event creation\n"), -1;
    event = create_event(trigger_time, argc, argv, &left_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    if (dprintf(server->clients[i]->fd, "ok\n") < 0)
        return -1;
    return add_event(server->clients[i], event);
}