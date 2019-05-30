/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_test
*/

#include <stdio.h>
#include "event.h"
#include "zappy.h"

int test_callback(struct client *client, int argc, char **argv)
{
    (void) argc;
    (void) argv;
    return dprintf(client->fd, "event_test mdr\n");
}

int command_test(struct server *server, int i, int argc, char **argv)
{
    time_t trigger_time = time(NULL) + 7 / server->options.freq;
    event_t *event = create_event(trigger_time, argc, argv, test_callback);
    return (add_event(server->clients[i], event));
}