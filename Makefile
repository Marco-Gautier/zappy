##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SERVER_DIR	=	server/
AI_DIR		=	ai/

all:		zappy_server zappy_ai

zappy_server:
		@make -C $(SERVER_DIR) --no-print-directory

zappy_ai:
		@make -C $(AI_DIR) --no-print-directory

clean:
		@make -C $(SERVER_DIR) clean --no-print-directory
		@make -C $(AI_DIR) clean --no-print-directory

fclean:
		@make -C $(SERVER_DIR) fclean --no-print-directory
		@make -C $(AI_DIR) fclean --no-print-directory

re:		fclean all

.PHONY:		zappy_server zappy_ai all clean fclean re
