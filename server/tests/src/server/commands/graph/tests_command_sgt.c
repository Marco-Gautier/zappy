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

Test(command_sgt, success)
{
    struct client client;
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .options = {
            .freq = 132
        },
        .clients = clients
    };
    int pipefd[2];
    int argc = 1;
    char *argv[2] = { "sgt", NULL };
    char buffer[512] = { 0 };

    cr_assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    cr_assert(command_sgt(&server, &client, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "sgt 132\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
