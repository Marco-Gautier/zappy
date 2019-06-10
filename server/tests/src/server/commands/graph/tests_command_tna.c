/*
** EPITECH PROJECT, 2019
** tests_command_tna.c
** File description:
** tests_command_tna.c
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    static const char * const team_names[] = {
        "Is",
        "mayonnaise",
        "an",
        "instrument",
        NULL
    };

    server->clients[0]->fd = fd;
    server->options.team_names = (char **)team_names;
    return 0;
}

Test(command_tna, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 1;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "tna" };
    char buffer[512] = { 0 };
    char expected_result[] =
        "tna Is\ntna mayonnaise\ntna an\ntna instrument\n";

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_tna(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, expected_result) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
