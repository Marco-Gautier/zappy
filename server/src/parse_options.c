/*
** EPITECH PROJECT, 2019
** parse_options
** File description:
** parse_options
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"
#include "my.h"

const struct server_opt_helper server_opt_helper[] = {
    {"-p", "--port",       offsetof(struct server_opt, port),          atoi},
    {"-f", "--frequence",  offsetof(struct server_opt, freq),          atoi},
    {"-x", "--width",      offsetof(struct server_opt, width),         atoi},
    {"-y", "--height",     offsetof(struct server_opt, height),        atoi},
    {"-c", "--clients-nb", offsetof(struct server_opt, max_team_nbr),  atoi},
    {NULL,  NULL,          0,                                          NULL}
};

const char *statement[] = {
    "port needs to be strictly positive",
    "freq needs to be strictly positive",
    "width needs to be at least 10",
    "height needs to be at least 10",
    "max team nbr needs to be strictly positive",
    "There should be at least 1 team names specified",
    NULL
};

const char *default_team_names = "team1 team2 team3 team4";

const struct server_opt default_options = {
    .port = DEFAULT_PORT,
    .freq = DEFAULT_FREQ,
    .width = DEFAULT_WIDTH,
    .height = DEFAULT_HEIGHT,
    .max_team_nbr = DEFAULT_TEAM_NUMBER,
    .team_names = NULL
};

static int option_get_value(struct server_opt *options, int option_index,
                            const char *arg_key, const char *arg_value)
{
    void *tmp = (void *)options + server_opt_helper[option_index].offset;
    int *flag_ptr = tmp;

    for (size_t i = 0; arg_value[i] != '\0'; i++)
        if (!IS_DIGIT(arg_value[i])) {
            printf("Warning: %s at \"%s\" for \"%s\".\n",
                   "non numerical argument", arg_value, arg_key);
            break;
        }
    *flag_ptr = server_opt_helper[option_index].callback(arg_value);
    return 0;
}

static int option_get_team_names(struct server_opt *options, int i,
                                 int argc, char **argv)
{
    char *tmp = strdup("");

    if (!tmp)
        return -1;
    for (; i < argc; i++) {
        for (int j = 0; server_opt_helper[j].callback != NULL; j++) {
            bool m = !strcmp(server_opt_helper[j].short_opt, argv[i]);
            if (m || !strcmp(server_opt_helper[j].long_opt, argv[i]))
                goto end_of_loop_mdr_le_goto;
        }
        tmp = realloc(tmp, sizeof(char) * (strlen(tmp) + strlen(argv[i]) + 3));
        if (!tmp)
            return -1;
        strcat(tmp, argv[i]);
        strcat(tmp, " ");
    }
end_of_loop_mdr_le_goto: free(options->team_names);
    options->team_names = my_str_to_word_array(tmp, " ");
    return 0;
}

static int options_checker(struct server_opt *options)
{
    bool assertion[] = {
        options->port > 0,
        options->freq > 0,
        options->width >= 10,
        options->height >= 10,
        options->max_team_nbr > 0,
        options->team_names != NULL
    };

    for (int i = 0; statement[i] != NULL; i++)
        if (assertion[i] == false) {
            fprintf(stderr, "Error: %s.\n", statement[i]);
            return -1;
        }
    return 0;
}

int options_value_parser(struct server_opt *options, int ac, char **av, int i)
{
    const char *short_opt;
    const char *long_opt;
    bool opt_match;

    for (int j = 0; server_opt_helper[j].callback != NULL; j++) {
        short_opt = server_opt_helper[j].short_opt;
        long_opt = server_opt_helper[j].long_opt;
        opt_match = !strcmp(short_opt, av[i]) || !strcmp(long_opt, av[i]);
        if (i + 1 < ac && opt_match) {
            option_get_value(options, j, av[i], av[i + 1]);
            i++;
        }
    }
    return 0;
}

int parse_options(struct server_opt *options, int argc, char **argv)
{
    *options = default_options;
    options->team_names = my_str_to_word_array(strdup(default_team_names), " ");
    for (int i = 0; i < argc; i++) {
        if (options_value_parser(options, argc, argv, i) == -1)
            return -1;
        if (!strcmp("-n", argv[i]) || !strcmp("--team-names", argv[i])) {
            i++;
            if (option_get_team_names(options, i, argc, argv) == -1)
                return -1;
        }
    }
    return options_checker(options);
}
