/*
** EPITECH PROJECT, 2019
** read_clients_fd
** File description:
** read_clients_fd
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "zappy.h"

/*
** Reject client if the buffer contains :
** > 10 commands
** > 5120 caracters
*/

static int check_client_buffer(const char *buffer)
{
    if (!buffer)
        return -1;
    for (size_t i = 0, line = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            line++;
        if (line >= 10 || i >= 5120)
            return -1;
    }
    return 0;
}

/*
** 1) Read string from the client socket
** 2) Append string in client->buffer
** 3) Check if the buffer is valid
*/

int read_client_fd_to_buffer(struct client *client)
{
    size_t size;
    char buff[512];

    memset(buff, 0, sizeof(buff));
    if (read(client->fd, buff, sizeof(buff)) < 1)
        return -1;
    if (!client->buffer) {
        client->buffer = strdup(buff);
        if (!client->buffer)
            return -1;
        return 0;
    }
    size = sizeof(char) * (strlen(buff) + strlen(client->buffer) + 2);
    client->buffer = realloc(client->buffer, size);
    if (!client->buffer)
        return -1;
    strcat(client->buffer, buff);
    if (check_client_buffer(client->buffer) == -1)
        return -1;
    return 0;
}

/*
** 1) Walk through all used clients on which data is available for reading,
** 2) Read data from socket
** 3) If data exist, bufferize it or kick the client from server.
*/

void read_clients_fd(struct server *server)
{
    if (!server->clients)
        return;
    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (FD_ISSET(server->clients[i]->fd, &server->rfds) != true)
            continue;
        if (read_client_fd_to_buffer(server->clients[i]) == -1)
            kick_client_from_server(server, i);
    }
}
