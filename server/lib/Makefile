##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

INC_DIR		=	../include/

SRC		=	my_tablen.c		\
			my_tabndup.c		\
			my_tabdup.c		\
			my_str_to_word_array.c	\
			my_push_back.c		\
			my_listlen.c		\
			my_list_erase.c		\
			my_list_clear.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

NAME		=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) rc -o $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
