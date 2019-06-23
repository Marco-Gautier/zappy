/*
** EPITECH PROJECT, 2019
** tests_events
** File description:
** tests_events
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
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

static int foo(struct server *server, struct client *client, int ac, char **av)
{
    (void)server;
    (void)client;
    (void)ac;
    (void)av;
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
    assert(client.event->callback(NULL, NULL, 0, NULL) == 0);
}

static int func(struct server *server, struct client *client, int ac, char **av)
{
    (void)server;
    (void)client;
    for (int i = 0; i < ac; i++)
        puts(av[i]);
    return 0;
}

Test(update_events, mdr)
{
    struct client client = {
        .id = 42,
        .client_type = CT_AI,
        .team_name = "team1"
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .events = NULL
    };
    int time = 5;
    int argc = 3;
    event_t *event[2];
    callback_t callback = func;
    char **argvv = malloc(sizeof(char *) * 3);

    argvv[0] = "mdr";
    argvv[1] = "lol";
    argvv[2] = "singe";
    cr_redirect_stdout();
    event[0] = create_event(time, argc, argvv, callback);
    event[1] = create_event(compute_trigger_time(100, 100), argc, argvv, callback);
    add_event(&client, event[0]);
    add_event(&client, event[1]);
    cr_assert(client.event == event[0]);
    cr_assert(client.event->next == event[1]);
    cr_assert(client.event->next->next == NULL);
    update_events(&server);
    fflush(stdout);
    cr_assert(client.event == event[1]);
    cr_assert(client.event->next == NULL);
    cr_assert_stdout_eq_str("mdr\nlol\nsinge\n");
}
