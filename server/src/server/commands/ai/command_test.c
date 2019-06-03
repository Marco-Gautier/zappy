/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_test
*/

#include <stdio.h>
#include "event.h"
#include "zappy.h"

int test_callback(struct server *s, struct client *client, int ac, char **av)
{
    (void) ac;
    (void) av;
    (void) s;
    return dprintf(client->fd, "event_test mdr\n");
}

int command_test(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(7, server->options.freq);
    event_t *event = create_event(trigger_time, argc, argv, test_callback);

    if (!event) {
        fprintf(stderr, "error during event creation\n");
        return -1;
    }
    return add_event(server->clients[i], event);
}