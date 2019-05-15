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

SRC		=	$(SRC_DIR)main.c		\
			$(SRC_DIR)parse_options.c	\
			$(SERVER_DIR)init_server.c

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
