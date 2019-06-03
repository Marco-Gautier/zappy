/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** events
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

event_t *create_event(time_t time, int argc, char **argv, callback_t callback)
{
    event_t *new = calloc(1, sizeof(event_t));

    new->trigger_time = time;
    new->argc = argc;
    new->argv = argv;
    new->callback = callback;
    return new;
}

int add_event(struct client *client, event_t *event)
{
    client->event = my_push_back(client->event, event);
    return 0;
}

static int handle_client_events(struct server *server, struct client *client)
{
    for (event_t *event = client->event; event != NULL;) {
        if (event->trigger_time <= time(NULL)) {
            printf("triggered event %p with trigger time: %ld at time %ld\n",
                event, event->trigger_time, time(NULL));
            event->callback(server, client, event->argc, event->argv);
            event_t *tmp = event->next;
            client->event = my_list_erase(client->event, event, free);
            event = tmp;
            break;
        }
        event = event->next;
    }
    return 0;
}

void update_events(struct server *server)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        handle_client_events(server, server->clients[i]);
}
