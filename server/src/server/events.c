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
    return GET_TIME_SEC(timeval) + (1000000 / freq) * time;
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

static int update_event_list(struct server *server, struct client *client,
event_t **event_list)
{
    struct timeval timeval;
    event_t *tmp;

    if (gettimeofday(&timeval, NULL) == -1)
        return -1;
    for (event_t *event = *event_list; event != NULL; ) {
        if (event->trigger_time <= GET_TIME_SEC(timeval)) {
            event->callback(server, client, event->argc, event->argv);
            tmp = event->next;
            *event_list = my_list_erase(*event_list, event, free);
            event = tmp;
        } else
            event = event->next;
    }
    return 0;
}

void update_events(struct server *serv)
{
    for (size_t i = 0; serv->clients[i] != NULL; i++)
        update_event_list(serv, serv->clients[i], &serv->clients[i]->event);
    update_event_list(serv, NULL, &serv->events);
}
