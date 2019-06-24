/*
** EPITECH PROJECT, 2019
** tests_command_pin
** File description:
** tests_command_pin
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "zappy.h"

Test(command_pin, success)
{
    struct client client = {
        .id = 42,
        .inventory = {
            .food = 1,
            .stones = {2, 3, 4, 5, 6, 7}
        }
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients
    };
    int argc = 2;
    int pipefd[2];
    char *argv[3] = { "pin", "42", NULL };
    cell_t cell = {
        .food = 1,
        .stones = {2, 3, 4, 5, 6, 7}
    };
    char buffer[1024] = { 0 };

    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    client.inventory = cell;
    assert(command_pin(&server, &client, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    assert(strcmp(buffer, "pin 42 1 2 3 4 5 6 7\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
