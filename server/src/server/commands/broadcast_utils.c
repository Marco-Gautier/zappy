/*
** EPITECH PROJECT, 2019
** broadcast_utils
** File description:
** broadcast_utils
*/

#include "sound.h"
#include "zappy.h"

const struct sound_helper sound_helper[] = {
    {
        .min = 0 - M_PI_8,
        .max = 0 + M_PI_8,
        .direction = SD_EAST
    },
    {
        .min = M_PI_4 - M_PI_8,
        .max = M_PI_4 + M_PI_8,
        .direction = SD_NORTH_EAST
    },
    {
        .min = M_PI_2 - M_PI_8,
        .max = M_PI_2 + M_PI_8,
        .direction = SD_NORTH
    },
    {
        .min = M_PI_4 * 3 - M_PI_8,
        .max = M_PI_4 * 3 + M_PI_8,
        .direction = SD_NORTH_WEST
    },
    {
        .min = -M_PI_4 * 3 - M_PI_8,
        .max = -M_PI_4 * 3 + M_PI_8,
        .direction = SD_SOUTH_WEST
    },
    {
        .min = -M_PI_2 - M_PI_8,
        .max = -M_PI_2 + M_PI_8,
        .direction = SD_SOUTH
    },
    {
        .min = -M_PI_4 - M_PI_8,
        .max = -M_PI_4 + M_PI_8,
        .direction = SD_SOUTH_EAST
    }
};

static double sq(double x)
{
    return pow(x, 2);
}

static void shortest_vector(struct vector *v1, int x, int y)
{
    if (sqrt(sq(v1->x) + sq(v1->y)) > sqrt(sq(x) + sq(y))) {
        *v1 = (struct vector) {
            .x = x,
            .y = y
        };
    }
}

/**
** Don't forgot that the orthonormal frame is circular.
*/

static void vector_op(struct vector *v, int width, int height)
{
    struct vector origin = *v;

    shortest_vector(v, origin.x + width, origin.y + height);
    shortest_vector(v, origin.x + width, origin.y - height);
    shortest_vector(v, origin.x + width, origin.y);
    shortest_vector(v, origin.x - width, origin.y + height);
    shortest_vector(v, origin.x - width, origin.y - height);
    shortest_vector(v, origin.x - width, origin.y);
    shortest_vector(v, origin.x, origin.y + height);
    shortest_vector(v, origin.x, origin.y - height);
}

/**
** SD_NORTH_EAST is the last number representing direction, because
** the transmission of the sound is done in the opposite direction
** of the clockwise.
*/

static int relative_sound(int sound, enum direction dir)
{
    int sound_size = SD_NORTH_EAST;

    switch (dir) {
    case (D_SOUTH):
        return sound;
    case (D_EAST):
        return sound + 2 > sound_size ? (sound + 2) % sound_size : sound + 2;
    case (D_NORTH):
        return sound + 4 > sound_size ? (sound + 4) % sound_size : sound + 4;
    case (D_WEST):
        return sound + 6 > sound_size ? (sound + 6) % sound_size : sound + 6;
    default:
        return SD_NONE;
    }
}

/**
** Compute the broadcast direction according to the position of the sender and
** the target on a repère orthonormé comme on dit chez nous
*/

int broadcast_direction(struct server_opt *options, struct client *sender,
struct client *target)
{
    double angle;
    struct vector v = {
        .x = sender->x - target->x,
        .y = sender->y - target->y
    };

    vector_op(&v, options->width, options->height);
    if (v.x == 0 && v.y == 0)
        return SD_NONE;
    if (v.x == 0)
        return relative_sound(v.y < 0 ? SD_SOUTH : SD_NORTH, target->direction);
    if (v.y == 0)
        return relative_sound(v.x < 0 ? SD_WEST : SD_EAST, target->direction);
    angle = atan2(v.y, v.x);
    for (int i = 0; i < 7; i++) {
        if (angle >= sound_helper[i].min &&
            angle <= sound_helper[i].max)
            return relative_sound(sound_helper[i].direction, target->direction);
    }
    return relative_sound(SD_WEST, target->direction);
}
