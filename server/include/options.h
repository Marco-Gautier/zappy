/*
** EPITECH PROJECT, 2019
** options
** File description:
** options
*/

#pragma once

#define DEFAULT_PORT        (4242)
#define DEFAULT_FREQ        (100)
#define DEFAULT_WIDTH       (10)
#define DEFAULT_HEIGHT      (10)
#define DEFAULT_TEAM_NUMBER (10)

struct server_opt {
    int         port;
    int         freq;
    int         width;
    int         height;
    int         max_team_nbr;
    char        **team_names;
};

struct server_opt_helper {
    const char  *short_opt;
    const char  *long_opt;
    int         offset;
    int         (*callback)(const char *nptr);
};

int parse_options(struct server_opt *options, int argc, char **argv);

extern const char *default_team_names;
extern const struct server_opt default_options;
