/*
** EPITECH PROJECT, 2019
** tests_parse_options
** File description:
** tests_parse_options
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

static void init(void)
{
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

Test(parse_options, _default, .init = init)
{
    struct server_opt options;
    static const char * const argv[] = {
        "./zappy_server",
        NULL
    };
    int argc = ARRAY_SIZE(argv) - 1;
    char **team_names;

    assert(parse_options(&options, argc, (char **)argv) != -1);
    assert(options.port == default_options.port);
    assert(options.freq == default_options.freq);
    assert(options.width == default_options.width);
    assert(options.height == default_options.height);
    assert(options.max_team_nbr == default_options.max_team_nbr);
    assert(options.team_names != NULL);
    team_names = my_str_to_word_array(strdup(default_team_names), " ");
    for (size_t i = 0; options.team_names[i] != NULL; i++)
        assert(!strcmp(team_names[i], options.team_names[i]));
}

Test(parse_options, all, .init = init)
{
    struct server_opt options;
    static const char * const argv[] = {
        "./zappy_server",
        "-p", "8080",
        "--frequence", "42",
        "-x", "21",
        "--height", "84",
        "-c", "150",
        "--team-names", "mdr1", "mdr2",
        NULL
    };
    int argc = ARRAY_SIZE(argv) - 1;

    assert(parse_options(&options, argc, (char **)argv) != -1);
    assert(options.port == 8080);
    assert(options.freq == 42);
    assert(options.width == 21);
    assert(options.height == 84);
    assert(options.max_team_nbr == 150);
    assert(options.team_names != NULL);
    assert(!strcmp(options.team_names[0], "mdr1"));
    assert(!strcmp(options.team_names[1], "mdr2"));
}

Test(parse_options, bad_short_options, .init = init)
{
    struct server_opt options;
    static const char * const argv[] = {
        "./zappy_server",
        "-p", "mdr",
        NULL
    };
    int argc = ARRAY_SIZE(argv) - 1;
    char **team_names;

    assert(parse_options(&options, argc, (char **)argv) == -1);
    assert(options.port == 0);
    assert(options.freq == default_options.freq);
    assert(options.width == default_options.width);
    assert(options.height == default_options.height);
    assert(options.max_team_nbr == default_options.max_team_nbr);
    assert(options.team_names != NULL);
    team_names = my_str_to_word_array(strdup(default_team_names), " ");
    for (size_t i = 0; options.team_names[i] != NULL; i++)
        assert(!strcmp(team_names[i], options.team_names[i]));
}

Test(parse_options, bad_options, .init = init)
{
    struct server_opt options;
    static const char * const argv[] = {
        "./zappy_server",
        "-c", "150",
        "--team-names",
        "-p", "8080",
        NULL
    };
    int argc = ARRAY_SIZE(argv) - 1;
    char **team_names;

    assert(parse_options(&options, argc, (char **)argv) != -1);
    assert(options.port == default_options.port);
    assert(options.freq == default_options.freq);
    assert(options.width == default_options.width);
    assert(options.height == default_options.height);
    assert(options.max_team_nbr == 150);
    assert(options.team_names != NULL);
    team_names = my_str_to_word_array(strdup(default_team_names), " ");
    for (size_t i = 0; options.team_names[i] != NULL; i++)
        assert(!strcmp(team_names[i], options.team_names[i]));
}
