##
## Makefile for  in /home/ganesha/projets/PSU_2014_myftp
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Mon Mar  9 12:10:29 2015 Ambroise Coutarel
## Last update Mon Mar  9 15:46:02 2015 Ambroise Coutarel
##

SRC_SERVER	=	./src/server/main_server.c	

SRC_CLIENT	=	./src/client/main_client.c

SRC_COMMON	=	./src/common/errors.c		\
			./src/common/display.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_COMMON	=	$(SRC_COMMON:.c=.o)

CC		=	gcc

RM		=	rm -f

NAME_SERVER	=	serveur

NAME_CLIENT	=	client

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

all:	common $(NAME_SERVER) $(NAME_CLIENT)

common:		$(OBJ_COMMON)

$(NAME_SERVER):	$(OBJ_SERVER)
		$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(OBJ_COMMON) $(CFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(OBJ_COMMON) $(CFLAGS)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_COMMON)

fclean:	clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re:	fclean all
