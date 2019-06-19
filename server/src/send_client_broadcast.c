/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** send_client_broadcast
*/

#include <stdarg.h>
#include <stdio.h>
#include <zappy.h>

int send_client_broadcast(struct client *client, const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = vdprintf(client->fd, format, ap);
    va_end(ap);
    return ret;
}
