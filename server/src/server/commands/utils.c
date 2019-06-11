/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** description
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

char *list_case_content(struct world world, int x, int y)
{
    char buffer[BUFSIZ] = {0};
    char tmp[128];

    if (world.map[x][y].food > 0)
        snprintf(buffer, sizeof(buffer), "food");
    for (int i = 0; i < C_CAOUILLOUX_SIZE; i++) {
        if (world.map[x][y].stones[i] > 0) {
            if (strlen(buffer) > 0) {
                snprintf(tmp, sizeof(tmp), " ");
                strcat(buffer, tmp);
            }
            snprintf(tmp, sizeof(tmp), "%s", cayou_names[i]);
            strcat(buffer, tmp);
        }
    }
    return strdup(buffer);
}

enum direction compute_direction(enum direction dir, int offset)
{
    dir -= 1;
    return (dir + offset + (D_DIRECTION_SIZE - 1)) % (D_DIRECTION_SIZE - 1) + 1;
}
