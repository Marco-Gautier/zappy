/*
** EPITECH PROJECT, 2019
** tests_filter_ai_request
** File description:
** tests_filter_ai_request
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"

Test(filter_ai_request, true)
{
    struct client client = {
        .client_type = CT_GRAPHIC
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 3;
    static const char * const argv[] = { "bct", "2", "3" };

    close(STDOUT_FILENO);
    assert(filter_ai_request(&server, 0, argc, (char **)argv) == -1);
}

Test(filter_ai_request, false)
{
    struct client client = {
        .client_type = CT_AI
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
    };
    int argc = 3;
    static const char * const argv[] = { "bct", "2", "3" };

    close(STDOUT_FILENO);
    assert(filter_ai_request(&server, 0, argc, (char **)argv) == 0);
}
