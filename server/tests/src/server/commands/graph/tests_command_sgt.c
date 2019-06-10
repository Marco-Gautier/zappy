/*
** EPITECH PROJECT, 2019
** tests_command_sgt
** File description:
** tests_command_sgt
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    server->options.freq = 132;
    server->clients[0]->fd = fd;
    return 0;
}

Test(command_sgt, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 1;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "sgt" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_sgt(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "sgt 132\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
