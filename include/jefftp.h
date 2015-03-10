/*
** server.h for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:21:11 2015 Ambroise Coutarel
** Last update Tue Mar 10 15:53:03 2015 Ambroise Coutarel
*/

#ifndef JEFFTP_H_

# define JEFFTP_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <netdb.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdarg.h>
# include <ctype.h>

# define CAST_C		const struct sockaddr *
# define CAST_NC	struct sockaddr *
# define QUEUE		5
# define GREETING	"Welcome to JefFTP ! Your IP address is : "
# define LOGIN		"Please enter your login : "
# define PASSWD		"Please enter your password : "
# define INFO1		"Please enter a command, or type help for a "
# define INFO2		"list of commands"
# define PROMPT		"JefFTP $>"

typedef const struct sockaddr* constsock;
typedef struct sockaddr* sock;

typedef struct		s_client
{
  char			*ip;
  char			*name;
  struct sockaddr_in	sock;
  char			isLogged;
  int			fd;
}			t_client;

/*
** function prototypes for serveur
*/

/*
** function prototypes for client
*/

/*
** common function prototypes
*/

int	close_and_fail(int fd);
void	writeToFd(int fd, char *str, char newline);
char*	readFromSocket(int socket);
int	readFromStdin(char buffer[256]);
void	loginDisplay(int c_fd, char *client_ip);
void	strlower(char *str, char stop);

#endif /* !JEFFTP_H_ */
