/*
** EPITECH PROJECT, 2019
** tests_command_msz
** File description:
** tests_command_msz
*/

#include <assert.h>
#include <arpa/inet.h>
#include <criterion/criterion.h>
#include <sys/socket.h>
#include <unistd.h>
#include "zappy.h"

static int setup_success_test(struct server *server, int fd)
{
    server->clients[0]->fd = fd;
    server->options.width = 120;
    server->options.height = 148;
    return 0;
}

Test(cmd_handler_msz, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 1;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "msz" };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    setup_success_test(&server, pipefd[1]);
    cr_assert(command_msz(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "msz 120 148\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}