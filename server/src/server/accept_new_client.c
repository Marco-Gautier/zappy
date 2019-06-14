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

static struct client *create_new_client(struct server_opt *server_opt,
int fd, int id)
{
    struct client *new = malloc(sizeof(struct client));

    if (!new)
        return NULL;
    *new = (struct client) {
        .fd = fd,
        .id = id,
        .y = rand() % server_opt->height,
        .x = rand() % server_opt->width,
        .level = 1,
        .client_type = CT_AI,
        .direction = D_NORTH,
    };
    new->inventory.food = 10;
    return new;
}

static struct client *add_new_client(struct server *server, int fd)
{
    size_t i = 0;
    void *tmp;

    if (server->clients)
        while (server->clients[i] != NULL)
            i++;
    tmp = realloc(server->clients, sizeof(struct client *) * (i + 2));
    if (!tmp)
        return NULL;
    server->clients = tmp;
    server->clients[i] = create_new_client(&server->options, fd, i);
    if (!server->clients[i])
        return NULL;
    server->clients[i + 1] = NULL;
    return server->clients[i];
}

struct client *add_available_client(struct server *server, int fd)
{
    struct client *client;

    if (!server->clients)
        return NULL;
    for (int i = 0; server->clients[i] != NULL; i++) {
        client = server->clients[i];
        if (client->hatched == true && client->fd == -1) {
            fprintf(stderr, "found available client from hatched egg\n");
            client->fd = fd;
            return client;
        }
    }
    return NULL;
}

const char *mdr = "Can't accept a new client : resources are currently limited";

int accept_new_client(struct server *server)
{
    int fd;
    struct client *new;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    puts("New client request.");
    fd = accept(server->fd, (struct sockaddr *)&addr, &addrlen);
    if (fd == -1)
        return puts("Can't accept a new client."), -1;
    new = add_available_client(server, fd);
    if (!new)
        new = add_new_client(server, fd);
    if (!new) {
        dprintf(fd, "%s", mdr);
        puts(mdr);
        close(fd);
        return -1;
    }
    printf("New client accepted with n°%d\n", new->id);
    dprintf(new->fd, "Welcome!\n");
    return 0;
}
