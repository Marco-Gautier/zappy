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
    struct client client = { .id = 42 };
    struct client *clients[] = {
        &client,
        NULL
    };
    int argc = 2;
    int pipefd[2];
    struct server server = { .clients = clients };
    static const char * const argv[] = { "pin", "42" };
    cell_t cell = {
        .food = 1,
        .stones = {2, 3, 4, 5, 6, 7}
    };
    char buffer[1024] = { 0 };
    char expected_result[] = "pin 42 1 2 3 4 5 6 7\n";

    assert(pipe(pipefd) == 0);
    client.fd = pipefd[1];
    client.inventory = cell;
    assert(command_pin(&server, 0, argc, (char **)argv) != -1);
    read(pipefd[0], buffer, 512);
    assert(strcmp(buffer, expected_result) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}
