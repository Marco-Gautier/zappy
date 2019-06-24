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

Test(command_sst, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .freq = 1
        }
    };
    int pipefd[2];
    int argc = 2;
    char *argv[3] = { "sst", "132", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_sst(&server, &client, argc, argv) != -1);
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
    struct server server = {
        .clients = clients,
        .options = {
            .freq = 1
        }
    };
    int pipefd[2];
    int argc = 1;
    char *argv[2] = { "sst", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_sst(&server, &client, argc, argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "sst 1\n") == 0);
    cr_assert(server.options.freq == 1);
    close(pipefd[0]);
    close(pipefd[1]);
}
