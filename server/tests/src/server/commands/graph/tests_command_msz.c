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

Test(cmd_handler_msz, success)
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
    int pipefd[2];
    int argc = 1;
    char *argv[2] = { "msz", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_msz(&server, &client, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "msz 120 148\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
