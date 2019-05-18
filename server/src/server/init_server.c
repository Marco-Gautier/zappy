/*
** EPITECH PROJECT, 2019
** init_server
** File description:
** init_server
*/

#include <netdb.h>
#include <stdio.h>
#include "zappy.h"

static int get_socket_fd(const char *protocol)
{
    struct protoent *pro = getprotobyname(protocol);

    if (!pro)
        return -1;
    return socket(AF_INET, SOCK_STREAM, pro->p_proto);
}

static int server_bind_socket(int fd, int port)
{
    struct sockaddr_in sockaddr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };

    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (int[]){1}, sizeof(int)) == -1)
        return -1;
    if (bind(fd, (const struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
        return -1;
    if (listen(fd, MAX_CLIENTS) == -1)
        return -1;
    return 0;
}

int init_server(struct server *server)
{
    server->fd = get_socket_fd("TCP");
    if (server->fd == -1)
        return -1;
    if (server_bind_socket(server->fd, server->options.port) == -1)
        return -1;
    server->clients = NULL;
    return 0;
}
