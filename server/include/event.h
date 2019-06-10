/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** event.h
*/

#pragma once

#include <time.h>
#include "server.h"
#include "client.h"

#define DIGEST_TIME 126

/* https://stackoverflow.com/q/5833094 */
#define GET_TIME_SEC(tv) (1000000 * tv.tv_sec + tv.tv_usec)

struct server;

typedef int (*callback_t)(struct server *s, struct client *client, int ac, char
**av);

typedef struct event {
    struct event *next;
    struct event *prev;
    suseconds_t trigger_time;
    int argc;
    char **argv;
    callback_t callback;
} event_t;

event_t *create_event(time_t time, int argc, char **argv, callback_t callback);
int add_event(struct client *client, event_t *event);
suseconds_t compute_trigger_time(int time, int freq);

int add_food_event(struct server *server, struct client *client);
int add_stones_event(struct server *server);
