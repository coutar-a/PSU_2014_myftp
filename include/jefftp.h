/*
** server.h for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:21:11 2015 Ambroise Coutarel
** Last update Wed Mar 11 13:59:33 2015 Ambroise Coutarel
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
# define PATHNAME	"\"%s\n\" created."

typedef const struct sockaddr* constsock;
typedef struct sockaddr* sock;

typedef struct		s_command
{
  char			*ftp_command;
  int			(*func)(char **param);
}			t_command;

typedef struct		s_reply
{
  char			*code;
  char			*verbose;
}			t_reply;

typedef struct		s_user
{
  char			*username;
  char			*pass;
}			t_user;

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

void	init_commands(t_command commands[16]);
void	subinit(t_command *command, char *name, int (*func)(char **));
int	user(char **param);
int	pass(char **param);
int	cwd(char **param);
int	cdup(char **param);
int	quit(char **param);
int	retr(char **param);
int	stor(char **param);
int	dele(char **param);
int	pwd(char **param);
int	list(char **param);
int	help(char **param);
int	noop(char **param);

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
char**	my_str_to_wordtab(char *str, char sep);
void	free_wordtab(char **tab);
void	view_wordtab(char **tab, char newline);

extern	t_command	g_commands[16];
extern	t_reply		g_replies[14];

#endif /* !JEFFTP_H_ */
