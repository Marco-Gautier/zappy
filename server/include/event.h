/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** event.h
*/

#pragma once

#include <time.h>
#include "client.h"

struct client;

typedef struct event {
    struct event *next;
    struct event *prev;
    time_t trigger_time;
    int argc;
    char **argv;
    int (*callback)(struct client *client, int argc, char **argv);
} event_t;

event_t *create_event(time_t time, int argc, char **argv,
int (*callback)(struct client *client, int argc, char **argv));
int add_event(struct client *client, event_t *event);