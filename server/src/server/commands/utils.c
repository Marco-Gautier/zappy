/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** description
*/

#include "zappy.h"

enum direction compute_direction(enum direction dir, int offset)
{
    return (dir + offset + D_DIRECTION_SIZE) % D_DIRECTION_SIZE;
}