/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** events
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "zappy.h"
#include "my.h"

suseconds_t compute_trigger_time(int time, int freq)
{
    struct timeval timeval;

    if (gettimeofday(&timeval, NULL) == -1)
        return -1;
    return GET_TIME_SEC(timeval) + (time / freq) * 1000000;
}

event_t *create_event(time_t time, int argc, char **argv, callback_t callback)
{
    event_t *new = malloc(sizeof(event_t));

    if (!new)
        return NULL;
    *new = (event_t) {
        .trigger_time = time,
        .argc = argc,
        .argv = argv,
        .callback = callback
    };
    return new;
}

int add_event(struct client *client, event_t *event)
{
    client->event = my_push_back(client->event, event);
    return 0;
}

static int handle_client_events(struct server *server, struct client *client)
{
    struct timeval timeval;
    event_t *tmp;

    if (gettimeofday(&timeval, NULL) == -1)
        return -1;
    for (event_t *event = client->event; event != NULL; ) {
        if (event->trigger_time <= GET_TIME_SEC(timeval)) {
            fprintf(stderr, "triggered event %p with trigger time: %ld at time\
 %ld\n", event, event->trigger_time, GET_TIME_SEC(timeval));
            event->callback(server, client, event->argc, event->argv);
            tmp = event->next;
            client->event = my_list_erase(client->event, event, free);
            event = tmp;
        } else
            event = event->next;
    }
    return 0;
}

void update_events(struct server *server)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        handle_client_events(server, server->clients[i]);
}
