/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static void options_dump(struct server_opt *options)
{
    printf("\t-p, --port:          %d\n", options->port);
    printf("\t-f, --frequence:     %d\n", options->freq);
    printf("\t-x, --width:         %d\n", options->width);
    printf("\t-y, --height:        %d\n", options->height);
    printf("\t-c, --clients-nb:    %d\n", options->max_team_nbr);
    printf("\t-n, --team-names:    ");
    for (size_t i = 0; options->team_names[i] != NULL; i++)
        printf("%s ", options->team_names[i]);
    putchar('\n');
}

int main(int argc, char **argv)
{
    struct server server;

    if (parse_options(&server.options, argc, argv) == -1)
        return -1;
    options_dump(&server.options);
    if (init_server(&server) == -1) {
        fprintf(stderr, "%s: Cannot start server.\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (init_world(&server.world, &server.options) == -1)
        return EXIT_FAILURE;
    printf("%s: Listening on port: %d\n", argv[0], server.options.port);
    signal(SIGPIPE, SIG_IGN);
    run_server(&server);
    return 0;
}
