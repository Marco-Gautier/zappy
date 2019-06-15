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
    int client_id = 42;
    int argc = 3;
    static const char * const argv[] = {
        "msz",
        "1",
        "2",
        NULL
    };

    cr_redirect_stdout();
    assert(log_command(NULL, client_id, argc, (char **)argv) == 0);
//    cr_assert_stdout_eq_str("Received command [msz, 1, 2] from client n°42\n");
}
