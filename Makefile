##
## Makefile for  in /home/ganesha/projets/PSU_2014_myftp
##
## Made by Ambroise Coutarel
## Login   <ganesha@epitech.net>
##
## Started on  Mon Mar  9 12:10:29 2015 Ambroise Coutarel
## Last update Mon Mar  9 15:11:07 2015 Ambroise Coutarel
##

SRC_SERVER	=	./src/server/main_server.c	\
			./src/server/errors.c		\
			./src/server/display.c

SRC_CLIENT	=	./src/client/main_client.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

CC		=	gcc

RM		=	rm -f

NAME_SERVER	=	serveur

NAME_CLIENT	=	client

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
		$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:	clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re:	fclean all
