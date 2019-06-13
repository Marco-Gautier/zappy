##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR			=	../src/
LIB_DIR			=	../lib/
INC_DIR			=	../include
TESTS_DIR		=	src/

SERVER_DIR		=	$(SRC_DIR)server/
GAME_DIR		=	$(SERVER_DIR)game/
MIDDLEWARE_DIR		=	$(SERVER_DIR)middleware/
COMMANDS_DIR		=	$(SERVER_DIR)commands/
GRAPH_DIR		=	$(COMMANDS_DIR)graph/
AI_DIR			=	$(COMMANDS_DIR)ai/

TESTS_LIB_DIR		=	lib/tests_
TESTS_SRC_DIR		=	src/tests_
TESTS_SERVER_DIR	=	src/server/tests_
TESTS_COMMANDS_DIR	=	src/server/commands/tests_
TESTS_GRAPH_DIR		=	src/server/commands/graph/tests_
TESTS_AI_DIR		=	src/server/commands/ai/tests_

LIB		=	$(LIB_DIR)my_tabdup.c			\
			$(LIB_DIR)my_tabndup.c			\
			$(LIB_DIR)my_tablen.c			\
			$(LIB_DIR)my_str_to_word_array.c	\
			$(LIB_DIR)my_push_back.c		\
			$(LIB_DIR)my_listlen.c			\
			$(LIB_DIR)my_list_erase.c		\
			$(LIB_DIR)my_list_clear.c		\

SRC		=	$(SRC_DIR)parse_options.c			\
			$(SERVER_DIR)events.c				\
			$(SERVER_DIR)init_server.c			\
			$(SERVER_DIR)run_server.c			\
			$(SERVER_DIR)accept_new_client.c		\
			$(SERVER_DIR)read_clients_fd.c			\
			$(SERVER_DIR)exec_client_command.c		\
			$(SERVER_DIR)kick_client_from_server.c		\
			$(SERVER_DIR)send_graphical_broadcast.c		\
			$(SERVER_DIR)client_join_team.c			\
			$(SERVER_DIR)get_nb_free_team_slot.c		\
			$(SERVER_DIR)is_game_over.c			\
			$(SERVER_DIR)kick_dead_client.c			\
			$(GAME_DIR)init_world.c				\
			$(GAME_DIR)cell_utils.c				\
			$(GAME_DIR)inventory_utils.c			\
			$(GAME_DIR)food_events.c			\
			$(GAME_DIR)stones_events.c			\
			$(MIDDLEWARE_DIR)log_command.c			\
			$(MIDDLEWARE_DIR)filter_graphic_request.c	\
			$(MIDDLEWARE_DIR)filter_ai_request.c		\
			$(MIDDLEWARE_DIR)check_client_target.c		\
			$(COMMANDS_DIR)utils.c                          \
			$(COMMANDS_DIR)command_unknown.c		\
			$(GRAPH_DIR)command_msz.c			\
			$(GRAPH_DIR)command_tna.c			\
			$(GRAPH_DIR)command_sst.c			\
			$(GRAPH_DIR)command_sgt.c			\
			$(GRAPH_DIR)command_plv.c			\
			$(GRAPH_DIR)command_ppo.c			\
			$(GRAPH_DIR)command_bct.c			\
			$(GRAPH_DIR)command_mct.c			\
			$(GRAPH_DIR)command_pin.c			\
			$(AI_DIR)command_test.c				\
			$(AI_DIR)command_forward.c			\
			$(AI_DIR)command_right.c			\
			$(AI_DIR)command_left.c				\
			$(AI_DIR)command_inventory.c			\
			$(AI_DIR)command_connect_nbr.c			\
			$(AI_DIR)command_take.c				\
			$(AI_DIR)command_set.c				\
			$(AI_DIR)command_look.c				\
			$(AI_DIR)command_incantation.c
SRC		+=	$(LIB)

TESTS_LIB	=	$(TESTS_LIB_DIR)my_tabdup.c			\
			$(TESTS_LIB_DIR)my_tabndup.c			\
			$(TESTS_LIB_DIR)my_tablen.c			\
			$(TESTS_LIB_DIR)my_str_to_word_array.c		\
			$(TESTS_LIB_DIR)my_push_back.c			\
			$(TESTS_LIB_DIR)my_listlen.c			\
			$(TESTS_LIB_DIR)my_list_erase.c			\
			$(TESTS_LIB_DIR)my_list_clear.c			\

TESTS		=	$(TESTS_SRC_DIR)parse_options.c			\
			$(TESTS_SERVER_DIR)init_server.c		\
			$(TESTS_SERVER_DIR)send_graphical_broadcast.c	\
			$(TESTS_SERVER_DIR)read_clients_fd.c		\
			$(TESTS_COMMANDS_DIR)command_unknown.c		\
			$(TESTS_GRAPH_DIR)command_msz.c			\
			$(TESTS_GRAPH_DIR)command_tna.c			\
			$(TESTS_GRAPH_DIR)command_sst.c			\
			$(TESTS_GRAPH_DIR)command_sgt.c			\
			$(TESTS_GRAPH_DIR)command_plv.c			\
			$(TESTS_GRAPH_DIR)command_ppo.c			\
			$(TESTS_GRAPH_DIR)command_bct.c			\
			$(TESTS_GRAPH_DIR)command_mct.c			\
			$(TESTS_GRAPH_DIR)command_pin.c
TESTS		+=	$(TESTS_LIB)
TESTS		+=	$(SRC)

CFLAGS		=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-fprofile-arcs	\
			-ftest-coverage

LDFLAGS		=	-lcriterion --coverage

OBJ		=	$(TESTS:.c=.o)
GCDA		=	$(TESTS:.c=.gcda)
GCNO		=	$(TESTS:.c=.gcno)

NAME		=	zappy_server_tests

CGCOV		=	./*.c.gcov
LCOV_DIR	=	../
RAPPORT_DIR	=	../rapport
RAPPORT_NAME	=	../rapport.info
RAPPORT_TITLE	=	"Zappy Server TU coverage"
RAPPORT_IDX	=	../rapport/index.html
BROWSER		=	google-chrome

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

gcov:		tests_run
		gcov -n $(SRC)

lcov:		gcov
		@lcov -q --directory $(LCOV_DIR) -c -o $(RAPPORT_NAME)
		@genhtml -q -o $(RAPPORT_DIR) -t $(RAPPORT_TITLE) $(RAPPORT_NAME)
		@$(BROWSER) $(RAPPORT_IDX)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(GCDA)
		@$(RM) $(GCNO)
		@$(RM) $(CGCOV)
		@$(RM) $(RAPPORT_NAME)
		@$(RM) -r $(RAPPORT_DIR)

fclean:		clean
		@$(RM) $(NAME)

tests_run:	re
		./$(NAME)

re:		fclean all

.PHONY:		all gcov lcov clean fclean tests_run re
