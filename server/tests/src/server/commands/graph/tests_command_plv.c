/*
** EPITECH PROJECT, 2019
** tests_command_plv
** File description:
** tests_command_plv
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    server->clients[0]->level = 132;
    server->clients[0]->fd = fd;
    return 0;
}

Test(command_plv, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 2;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "plv", "0" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_plv(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "plv 0 132\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
