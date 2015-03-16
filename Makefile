##
## Makefile for  in /home/ganesha/projets/PSU_2014_myftp
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Mon Mar  9 12:10:29 2015 Ambroise Coutarel
## Last update Mon Mar 16 12:47:25 2015 Ambroise Coutarel
##

SRC_SERVER	=	./src/server/main_server.c		\
			./src/server/client_handling.c		\
			./src/server/server_functions_1.c	\
			./src/server/server_functions_2.c	\
			./src/server/server_functions_3.c	\
			./src/server/list_dependencies.c	\
			./src/server/cd_dependencies.c		\
			./src/server/dele_dependencies.c	\
			./src/server/file_dependencies.c

SRC_CLIENT	=	./src/client/main_client.c		\
			./src/client/files_client.c

SRC_COMMON	=	./src/common/errors.c			\
			./src/common/display.c			\
			./src/common/socket_read_write.c	\
			./src/common/my_str_to_wordtab.c	\
			./src/common/sundries.c			\
			./src/common/file_functions.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_COMMON	=	$(SRC_COMMON:.c=.o)

CC		=	gcc

RM		=	rm -f

NAME_SERVER	=	serveur

NAME_CLIENT	=	client

CFLAGS		+=	-W -Wall -Wextra -Werror

## flag pour valgrind, à virer avant rendu

GFLAGS		+=	-g3

## fin partie à retirer

all:	common $(NAME_SERVER) $(NAME_CLIENT)

common:		$(OBJ_COMMON)

$(NAME_SERVER):	$(OBJ_SERVER)
		$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(OBJ_COMMON) $(CFLAGS) $(GFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(OBJ_COMMON) $(CFLAGS) $(GFLAGS)
		cp $(NAME_CLIENT) ~/jefftest/

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_COMMON)

fclean:	clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re:	fclean all
