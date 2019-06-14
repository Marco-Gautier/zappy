/*
** EPITECH PROJECT, 2019
** tests_events
** File description:
** tests_events
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

static const char * const argv[] = {
    "mdr",
    "lol",
    "singe",
    NULL
};

int foo(struct server *server, struct client *client, int argc, char **argv)
{
    (void)server;
    (void)client;
    (void)argc;
    (void)argv;
    return 0;
}

Test(create_event, mdr)
{
    int time = rand();
    int argc = 3;
    callback_t callback = foo;
    event_t *mdr;

    mdr = create_event(time, argc, (char **)argv, callback);
    assert(mdr != NULL);
    assert(mdr->trigger_time == time);
    assert(mdr->argc == argc);
    assert(mdr->argv == (char **)argv);
    assert(mdr->callback == callback);
}

Test(add_event, add_1)
{
    int time = rand();
    int argc = 3;
    callback_t callback = foo;
    struct client client = {
        .event = NULL
    };
    event_t *event = create_event(time, argc, (char **)argv, callback);

    assert(event != NULL);
    add_event(&client, event);
    assert(event != NULL);
    assert(client.event != NULL);
    assert(client.event == event);
    assert(client.event->trigger_time == time);
    assert(client.event->argc == argc);
    assert(client.event->argv == (char **)argv);
    assert(client.event->callback == callback);
}
