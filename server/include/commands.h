/*
** EPITECH PROJECT, 2019
** commands
** File description:
** commands
*/

#pragma once

#include "middleware.h"

struct command {
    const char          *name;
    middleware_t        middleware[MIDDLEWARE_NB];
    int (*callback)(struct server *s, struct client *c, int ac, char **av);
};

int command_unknown(struct server *s, struct client *c, int ac, char **av);

/* Utils */
int compute_new_position(int pos, int offset, int max);
enum direction compute_direction(enum direction dir, int offset);
char *list_case_content(struct server *s, struct world *world, int x, int y);

/* API command reserved to graphical clients */
int command_msz(struct server *s, struct client *c, int ac, char **av);
int command_tna(struct server *s, struct client *c, int ac, char **av);
int command_sst(struct server *s, struct client *c, int ac, char **av);
int command_sgt(struct server *s, struct client *c, int ac, char **av);
int command_plv(struct server *s, struct client *c, int ac, char **av);
int command_ppo(struct server *s, struct client *c, int ac, char **av);
int command_bct(struct server *s, struct client *c, int ac, char **av);
int command_mct(struct server *s, struct client *c, int ac, char **av);
int command_pin(struct server *s, struct client *c, int ac, char **av);

/* API command reserved to AI clients */
int command_test(struct server *s, struct client *c, int ac, char **av);
int command_forward(struct server *s, struct client *c, int ac, char **av);
int command_right(struct server *s, struct client *c, int ac, char **av);
int command_left(struct server *s, struct client *c, int ac, char **av);
int command_inventory(struct server *s, struct client *c, int ac, char **av);
int command_connect_nbr(struct server *s, struct client *c, int ac, char **av);
int command_take(struct server *s, struct client *c, int ac, char **av);
int command_set(struct server *s, struct client *c, int ac, char **av);
int command_look(struct server *s, struct client *c, int ac, char **av);
int command_incantation(struct server *s, struct client *c, int ac, char **av);
int command_fork(struct server *s, struct client *c, int ac, char **av);
int command_broadcast(struct server *s, struct client *c, int ac, char **av);
int command_eject(struct server *s, struct client *c, int ac, char **av);

/* API callback reserved for tests */
int test_callback(struct server *s, struct client *c, int ac, char **av);
int forward_callback(struct server *s, struct client *c, int ac, char **av);
int right_callback(struct server *s, struct client *c, int ac, char **av);
int left_callback(struct server *s, struct client *c, int ac, char **av);
int inventory_callback(struct server *s, struct client *c, int ac, char **av);
int take_callback(struct server *s, struct client *c, int ac, char **av);
int set_callback(struct server *s, struct client *c, int ac, char **av);
int look_callback(struct server *s, struct client *c, int ac, char **av);
int incantation_callback(struct server *s, struct client *c, int ac, char **av);
int fork_callback(struct server *s, struct client *c, int ac, char **av);
int broadcast_callback(struct server *s, struct client *c, int ac, char **av);
int eject_callback(struct server *s, struct client *c, int ac, char **av);
