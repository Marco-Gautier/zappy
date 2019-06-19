/*
** EPITECH PROJECT, 2019
** tests_log_command
** File description:
** tests_log_command
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(log_command, mdr)
{
    struct client client = {
        .id = 42,
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options = {
            .width = 42,
            .height = 24
        }
    };
    int argc = 3;
    static const char * const argv[] = {
        "msz",
        "1",
        "2",
        NULL
    };

    cr_redirect_stdout();
    assert(log_command(&server, 0, argc, (char **)argv) == 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("Received command [msz, 1, 2] from client n°42\n");
}
