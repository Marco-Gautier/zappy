/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** description
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

static void add_elem_to_str(char *buffer, const char *elem)
{
    char tmp[128];

    if (buffer && strlen(buffer) > 0) {
        snprintf(tmp, sizeof(tmp), " ");
        strcat(buffer, tmp);
    }
    snprintf(tmp, sizeof(tmp), "%s", elem);
    strcat(buffer, tmp);
}

char *list_case_content(struct server *s, struct world *world, int x, int y)
{
    char buffer[BUFSIZ] = {0};

    for (int i = 0; s->clients[i] != NULL; i++)
        if (s->clients[i]->x == x && s->clients[i]->y == y)
            add_elem_to_str(buffer, "player");
    if (world->map[x][y].food > 0)
        add_elem_to_str(buffer, "food");
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++) {
        if (world->map[x][y].stones[i] > 0) {
            add_elem_to_str(buffer, cayou_names[i]);
        }
    }
    return strdup(buffer);
}

enum direction compute_direction(enum direction dir, int offset)
{
    dir -= 1;
    return (dir + offset + (D_DIRECTION_SIZE - 1)) % (D_DIRECTION_SIZE - 1) + 1;
}
