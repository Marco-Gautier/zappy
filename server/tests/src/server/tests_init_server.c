/*
** EPITECH PROJECT, 2019
** tests_init_server
** File description:
** tests_init_server
*/

#include <assert.h>
#include <arpa/inet.h>
#include <criterion/criterion.h>
#include <sys/socket.h>
#include <unistd.h>
#include "zappy.h"

static void init(void)
{
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

Test(init_server, defaut, .init = init)
{
    struct server server = {
        .options = default_options
    };

    assert(init_server(&server) == 0);
    assert(server.fd != -1);
}

Test(init_server, port_8080, .init = init)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    struct server server = {
        .options = {
            .port = 8080
        }
    };

    assert(init_server(&server) == 0);
    assert(server.fd != -1);
    assert(getsockname(server.fd, (struct sockaddr *)&sin, &len) != -1);
    assert(ntohs(sin.sin_port) == 8080);
}
