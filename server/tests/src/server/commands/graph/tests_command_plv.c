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

Test(command_plv, success)
{
    struct client client = {
        .level = 132
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int pipefd[2];
    int argc = 2;
    char *argv[3] = { "plv", "0", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_plv(&server, &client, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "plv 0 132\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
