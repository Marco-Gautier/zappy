#
# EPITECH PROJECT 2018
#
# File description : singe
#
#

SRC_DIR		=	../src/
LIB_DIR		=	../lib/
INC_DIR		=	../include
TESTS_DIR	=	src/

TESTS_LIB_DIR	=	lib/tests_
TESTS_SRC_DIR	=	src/tests_

SRC		=	$(LIB_DIR)my_tabdup.c			\
			$(LIB_DIR)my_tabndup.c			\
			$(LIB_DIR)my_tablen.c			\
			$(LIB_DIR)my_str_to_word_array.c

TESTS		=	$(TESTS_LIB_DIR)my_tabdup.c		\
			$(TESTS_LIB_DIR)my_tabndup.c		\
			$(TESTS_LIB_DIR)my_tablen.c		\
			$(TESTS_LIB_DIR)my_str_to_word_array.c
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
