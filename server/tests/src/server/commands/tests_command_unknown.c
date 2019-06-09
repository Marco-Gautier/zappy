/*
** EPITECH PROJECT, 2019
** tests_command_unknown
** File description:
** tests_command_unknown
*/

#include <assert.h>
#include <arpa/inet.h>
#include <criterion/criterion.h>
#include <sys/socket.h>
#include <unistd.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    struct client client = {
        .fd = fd
    };
    struct client *clients[] = {
        &client,
        NULL
    };

    server->clients = clients;
    server->options.width = 120;
    server->options.height = 148;
    return 0;
}

Test(command_unknown, success)
{
    int argc = 1;
    int pipefd[2];
    struct server server;
    char *argv[] = { "mdr" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_unknown(&server, 0, argc, argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ko\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
