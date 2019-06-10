/*
** EPITECH PROJECT, 2019
** tests_command_sst
** File description:
** tests_command_sst
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    server->clients[0]->fd = fd;
    server->options.freq = 1;
    return 0;
}

Test(command_sst, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 2;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "sst", "132" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_sst(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "sst 132\n") == 0);
    cr_assert(server.options.freq == 132);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_sst, failure)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 1;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "sst" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_sst(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "sst 1\n") == 0);
    cr_assert(server.options.freq == 1);
    close(pipefd[0]);
    close(pipefd[1]);
}
