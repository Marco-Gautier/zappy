/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** command_test
*/

#include <stdio.h>
#include "zappy.h"

int test_callback(struct server *s, struct client *client, int ac, char **av)
{
    (void)ac;
    (void)av;
    (void)s;
    return dprintf(client->fd, "event_test mdr\n");
}

int command_test(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return fprintf(stderr, "error during event creation\n"), -1;
    event = create_event(trigger_time, argc, argv, &test_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    return add_event(server->clients[i], event);
}
