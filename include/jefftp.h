/*
** server.h for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:21:11 2015 Ambroise Coutarel
** Last update Mon Mar  9 16:27:33 2015 Ambroise Coutarel
*/

#ifndef JEFFTP_H_

# define JEFFTP_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define CAST_C		const struct sockaddr *
# define CAST_NC	struct sockaddr *
# define QUEUE		5
# define GREETING	"Welcome to JefFTP ! Your IP address is : "
# define LOGIN		"Please enter your login : "
# define PASSWD		"Please enter your password : "

typedef const struct sockaddr* constsock;
typedef struct sockaddr* sock;

/*
** function prototypes for serveur
*/

int	close_and_fail(int fd);
void	writeToFd(int fd, char *str, char newline);

/*
** function prototypes for client
*/

#endif /* !JEFFTP_H_ */
