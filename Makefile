##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/
SERVER_DIR  = 	$(SRC_DIR)server/
AI_DIR		=	$(SRC_DIR)ai/

all:		zappy_server zappy_ai

zappy_server:
			make -C $(SERVER_DIR) -s

zappy_ai:
			make -C $(AI_DIR) -s

clean:
		make -C $(SERVER_DIR) clean -s
		make -C $(AI_DIR) clean -s

fclean:
		make -C $(SERVER_DIR) fclean -s
		make -C $(AI_DIR) fclean -s

re:		fclean all

.PHONY:		zappy_server zappy_ai all clean fclean re
