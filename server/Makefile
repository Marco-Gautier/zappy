##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/
LIB_DIR		=	lib/
INC_DIR		=	include/
TESTS_DIR	=	tests/
DOC_DIR		=	doc/

SERVER_DIR	=	$(SRC_DIR)server/
GAME_DIR	=	$(SERVER_DIR)game/
MIDDLEWARE_DIR	=	$(SERVER_DIR)middleware/
COMMANDS_DIR	=	$(SERVER_DIR)commands/
GRAPH_DIR	=	$(COMMANDS_DIR)graph/
AI_DIR		=	$(COMMANDS_DIR)ai/

SRC		=	$(SRC_DIR)main.c				\
			$(SRC_DIR)parse_options.c			\
			$(SERVER_DIR)events.c				\
			$(SERVER_DIR)init_server.c			\
			$(SERVER_DIR)run_server.c			\
			$(SERVER_DIR)accept_new_client.c		\
			$(SERVER_DIR)read_clients_fd.c			\
			$(SERVER_DIR)exec_client_command.c		\
			$(SERVER_DIR)kick_client_from_server.c		\
			$(SERVER_DIR)send_client_msg.c			\
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
			$(COMMANDS_DIR)utils.c				\
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
			$(AI_DIR)command_incantation.c			\
			$(AI_DIR)command_fork.c				\
			$(AI_DIR)command_eject.c			\
			$(AI_DIR)command_broadcast.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

LDFLAGS		=	-L $(LIB_DIR) -lmy

NAME		=	../zappy_server

DOXYFILE	=	Doxyfile

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(MAKE) -C $(LIB_DIR) --no-print-directory
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory
		@$(MAKE) $@ -C $(LIB_DIR) --no-print-directory
		@$(RM) $(OBJ)

fclean:		clean
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory
		@$(MAKE) $@ -C $(LIB_DIR) --no-print-directory
		@$(RM) $(NAME)
		@$(RM) -r $(DOC_DIR)

add_debug_flag:
		$(eval CFLAGS := $(CFLAGS) -g)

debug:		add_debug_flag re

tests_run:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

lcov:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

gcov:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

doc:
		@doxygen $(DOXYFILE)


re:		fclean all

.PHONY:		all clean fclean debug tests_run lcov gcov doc re
