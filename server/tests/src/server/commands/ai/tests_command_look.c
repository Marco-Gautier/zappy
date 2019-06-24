/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** tests_command_look
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "zappy.h"

const char *res = "[player food,linemate,,sibur,deraumere,,mendiane,,phiras]\n";

Test(command_look, test_look_north)
{
    int pipefd[2];
    struct client client = {
        .level = 1,
        .x = 4,
        .y = 4,
        .direction = D_NORTH,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[4][4].food = 4;
    server.world.map[3][3].stones[C_LINEMATE] = 1;
    server.world.map[5][3].stones[C_SIBUR] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "[player food,linemate,,sibur]\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_west)
{
    int pipefd[2];
    struct client client = {
        .level = 1,
        .x = 9,
        .y = 4,
        .direction = D_WEST,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[9][4].food = 4;
    server.world.map[8][5].stones[C_LINEMATE] = 1;
    server.world.map[8][3].stones[C_SIBUR] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "[player food,linemate,,sibur]\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_south)
{
    int pipefd[2];
    struct client client = {
        .level = 1,
        .x = 4,
        .y = 0,
        .direction = D_SOUTH,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[4][0].food = 4;
    server.world.map[5][1].stones[C_LINEMATE] = 1;
    server.world.map[3][1].stones[C_SIBUR] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "[player food,linemate,,sibur]\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_east)
{
    int pipefd[2];
    struct client client = {
        .level = 1,
        .x = 0,
        .y = 4,
        .direction = D_EAST,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[0][4].food = 4;
    server.world.map[1][3].stones[C_LINEMATE] = 1;
    server.world.map[1][5].stones[C_SIBUR] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, "[player food,linemate,,sibur]\n") == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_north_depth2)
{
    int pipefd[2];
    struct client client = {
        .level = 2,
        .x = 4,
        .y = 1,
        .direction = D_NORTH,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[4][1].food = 4;
    server.world.map[3][0].stones[C_LINEMATE] = 1;
    server.world.map[5][0].stones[C_SIBUR] = 1;
    server.world.map[2][9].stones[C_DERAUMERE] = 1;
    server.world.map[4][9].stones[C_MENDIANE] = 1;
    server.world.map[6][9].stones[C_PHIRAS] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, res) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_west_depth2)
{
    int pipefd[2];
    struct client client = {
        .level = 2,
        .x = 1,
        .y = 4,
        .direction = D_WEST,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[1][4].food = 4;
    server.world.map[0][5].stones[C_LINEMATE] = 1;
    server.world.map[0][3].stones[C_SIBUR] = 1;
    server.world.map[9][6].stones[C_DERAUMERE] = 1;
    server.world.map[9][4].stones[C_MENDIANE] = 1;
    server.world.map[9][2].stones[C_PHIRAS] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, res) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_south_depth2)
{
    int pipefd[2];
    struct client client = {
        .level = 2,
        .x = 4,
        .y = 8,
        .direction = D_SOUTH,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[4][8].food = 4;
    server.world.map[5][9].stones[C_LINEMATE] = 1;
    server.world.map[3][9].stones[C_SIBUR] = 1;
    server.world.map[6][0].stones[C_DERAUMERE] = 1;
    server.world.map[4][0].stones[C_MENDIANE] = 1;
    server.world.map[2][0].stones[C_PHIRAS] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, res) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_east_depth2)
{
    int pipefd[2];
    struct client client = {
        .level = 2,
        .x = 8,
        .y = 4,
        .direction = D_EAST,
        .inventory.food = 42
    };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .world = {
            .height = 10,
            .width = 10
        },
        .options = {
            .width = 10,
            .height = 10,
            .freq = 100
        }
    };
    char buffer[512] = {0};

    cr_assert(pipe(pipefd) == 0);
    cr_assert(init_world(&server.world, &server.options) == 0);
    server.clients[0]->fd = pipefd[1];
    server.world.map[8][4].food = 4;
    server.world.map[9][3].stones[C_LINEMATE] = 1;
    server.world.map[9][5].stones[C_SIBUR] = 1;
    server.world.map[0][2].stones[C_DERAUMERE] = 1;
    server.world.map[0][4].stones[C_MENDIANE] = 1;
    server.world.map[0][6].stones[C_PHIRAS] = 1;
    cr_assert(look_callback(&server, &client, 1, NULL) != 1);
    read(pipefd[0], buffer, 512);
    cr_assert(strcmp(buffer, res) == 0);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(command_look, test_look_event_creation)
{
    struct client client = { .event = NULL };
    struct client *clients[] = {
        &client,
        NULL
    };
    struct server server = {
        .clients = clients,
        .options.freq = 100
    };

    cr_assert(command_look(&server, &client, 1, NULL) == 0);
    cr_assert(client.event != NULL);
    cr_assert(client.event->callback == look_callback);
}
