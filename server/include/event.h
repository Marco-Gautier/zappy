/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** event.h
*/

#pragma once

#include <time.h>
#include "server.h"
#include "client.h"

typedef int (*callback_t)(struct server *s, struct client *client, int ac, char
**av);

struct client;

typedef struct event {
    struct event *next;
    struct event *prev;
    time_t trigger_time;
    int argc;
    char **argv;
    callback_t callback;
} event_t;

event_t *create_event(time_t time, int argc, char **argv, callback_t callback);
int add_event(struct client *client, event_t *event);