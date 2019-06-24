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

Test(command_unknown, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 120,
            .height = 148,
        }
    };
    int argc = 1;
    int pipefd[2];
    char *argv[2] = { "mdr", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_unknown(&server, &client, argc, argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "ko\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
