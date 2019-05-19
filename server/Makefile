##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/
LIB_DIR		=	lib/
INC_DIR		=	include/
TESTS_DIR	=	tests/

SERVER_DIR	=	$(SRC_DIR)server/
MIDDLEWARE_DIR	=	$(SERVER_DIR)middleware/
COMMANDS_DIR	=	$(SERVER_DIR)commands/
GRAPH_DIR	=	$(COMMANDS_DIR)graph/
AI_DIR		=	$(COMMANDS_DIR)ai/

SRC		=	$(SRC_DIR)main.c				\
			$(SRC_DIR)parse_options.c			\
			$(SERVER_DIR)init_server.c			\
			$(SERVER_DIR)run_server.c			\
			$(SERVER_DIR)accept_new_client.c		\
			$(SERVER_DIR)read_clients_fd.c			\
			$(SERVER_DIR)exec_client_command.c		\
			$(SERVER_DIR)kick_client_from_server.c		\
			$(SERVER_DIR)send_graphical_broadcast.c		\
			$(SERVER_DIR)client_join_team.c			\
			$(SERVER_DIR)get_nb_free_team_slot.c		\
			$(MIDDLEWARE_DIR)log_command.c			\
			$(MIDDLEWARE_DIR)filter_graphic_request.c	\
			$(COMMANDS_DIR)command_unknown.c		\
			$(GRAPH_DIR)command_msz.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

LDFLAGS		=	-L $(LIB_DIR) -lmy

NAME		=	../zappy_server

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory
		@$(RM) $(OBJ)

fclean:		clean
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory
		@$(RM) $(NAME)

tests_run:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

lcov:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

gcov:
		@$(MAKE) $@ -C $(TESTS_DIR) --no-print-directory

re:		fclean all

.PHONY:		all clean fclean tests_run lcov gcov re
