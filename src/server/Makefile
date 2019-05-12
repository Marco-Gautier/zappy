##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

PROJECT_ROOT_DIR = ../../
SRC_DIR		=	src/
INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3		\
			-g

NAME		=	zappy_server

all:		$(NAME)
			@cp $(NAME) $(PROJECT_ROOT_DIR)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(PROJECT_ROOT_DIR)$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
