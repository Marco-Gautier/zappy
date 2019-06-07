/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

int inv_callback(struct server *s, struct client *client, int ac, char **av)
{
    char buffer[BUFSIZ];
    char tmp[128];
    int *stones = client->inventory.stones;

    (void)ac;
    (void)av;
    (void)s;
    snprintf(buffer, sizeof(buffer), "[ food %d", client->inventory.food);
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++) {
        snprintf(tmp, sizeof(tmp), ", %s %d", cayou_names[i],stones[i]);
        strcat(buffer, tmp);
    }
    snprintf(tmp, sizeof(tmp), " ]");
    strcat(buffer, tmp);
    if (buffer[0] == '\0')
        return -1;
    return dprintf(client->fd, "%s\n", buffer);
}

int command_inventory(struct server *server, int i, int argc, char **argv)
{
    suseconds_t trigger_time = compute_trigger_time(1, server->options.freq);
    event_t *event;

    if (trigger_time == -1)
        return fprintf(stderr, "error during event time computing\n"), -1;
    event = create_event(trigger_time, argc, argv, &inv_callback);
    if (!event)
        return fprintf(stderr, "error during event creation\n"), -1;
    return add_event(server->clients[i], event);
}
