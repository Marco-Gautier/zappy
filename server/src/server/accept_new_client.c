/*
** EPITECH PROJECT, 2019
** accept_new_client
** File description:
** accept_new_client
*/

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "zappy.h"

static void reset_client(struct client *client)
{
    *client = (struct client) {
        .fd = -1,
        .y = 0,
        .x = 0,
        .level = 1,
        .in_use = true,
        .egg_id = 0,
        .buffer = NULL,
        .hatched = false,
        .client_type = CT_AI,
        .team_name = NULL,
        .direction = D_NORTH,
//        .inventory = inventory_create(),
    };
}

static struct client *init_new_client(struct server_opt *server_opt,
struct client *client, int fd)
{
    reset_client(client);
    client->fd = fd;
    client->in_use = true;
    client->buffer = NULL;
    client->direction = D_NORTH;
    client->x = rand() % server_opt->width;
    client->y = rand() % server_opt->height;
    return client;
}

static struct client *add_new_client(struct server *server, int fd)
{
    size_t i = 0;
    void *tmp;

    if (server->clients)
        while (server->clients[i].fd != -1)
            i++;
    if (i >= MAX_CLIENTS)
        return NULL;
    tmp = realloc(server->clients, sizeof(struct client) * (i + 2));
    if (!tmp)
        return NULL;
    server->clients = tmp;
    init_new_client(&server->options, &server->clients[i], fd);
    reset_client(&server->clients[i + 1]);
    return &server->clients[i];
}

static struct client *get_free_client(struct server *server, int fd)
{
    if (!server->clients)
        return add_new_client(server, fd);
    for (size_t i = 0; server->clients[i].fd != -1; i++)
        if (server->clients[i].in_use == false)
            return init_new_client(&server->options, &server->clients[i], fd);
    return add_new_client(server, fd);
}

int accept_new_client(struct server *server)
{
    int fd;
    struct client *new;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    puts("New client request.");
    fd = accept(server->fd, (struct sockaddr *)&addr, &addrlen);
    if (fd == -1)
        return puts("Can't accept new client."), -1;
    new = get_free_client(server, fd);
    if (!new) {
        puts("Maximum number of client reached.");
        close(fd);
        return -1;
    }
    puts("New client accepted.");
    dprintf(new->fd, "Welcome!\n");
    return 0;
}
