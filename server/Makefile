##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/
INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

NAME		=	../zappy_server

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
