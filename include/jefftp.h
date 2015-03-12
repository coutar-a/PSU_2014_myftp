/*
** server.h for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:21:11 2015 Ambroise Coutarel
** Last update Thu Mar 12 19:06:28 2015 Ambroise Coutarel
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
# include <dirent.h>

# define CAST_C		const struct sockaddr *
# define CAST_NC	struct sockaddr *
# define QUEUE		5
# define GREETING	"Welcome to JefFTP ! Your IP address is : "
# define INFO1		"Please enter a command, or type help for a "
# define INFO2		"list of commands"
# define PROMPT		"JefFTP $>"
# define PATHNAME	"\"%s\n\" created."

typedef const struct sockaddr* constsock;
typedef struct sockaddr* sock;


typedef struct		s_client
{
  char			*ip;
  char			*name;
  struct sockaddr_in	sock;
  char			is_logged;
  int			fd;
}			t_client;

typedef struct		s_server
{
  struct sockaddr_in	sock;
  char			*root;
  char			*sys_cwd;
  char			*ftp_cwd;
  int			fd;
}			t_server;

typedef struct		s_command
{
  char			*ftp_command;
  int			(*func)(char **param, t_client *client, 
				t_server *server);
}			t_command;

typedef struct		s_helpmsg
{
  char			*command;
  char			*verbose;
}			t_helpmsg;

typedef struct		s_user
{
  char			*username;
  char			*pass;
}			t_user;

/*
** function prototypes for serveur
*/

void	init_commands(t_command commands[16]);
void	init_server(t_server *server);
void	subinit(t_command *command, char *name, 
		int (*func)(char **, t_client *, t_server *));
int	user(char **param, t_client *client, t_server *server);
int	pass(char **param, t_client *client, t_server *server);
int	cwd(char **param, t_client *client, t_server *server);
int	cdup(char **param, t_client *client, t_server *server);
int	quit(char **param, t_client *client, t_server *server);
int	retr(char **param, t_client *client, t_server *server);
int	stor(char **param, t_client *client, t_server *server);
int	dele(char **param, t_client *client, t_server *server);
int	pwd(char **param, t_client *client, t_server *server);
int	list(char **param, t_client *client, t_server *server);
int	help(char **param, t_client *client, t_server *server);
int	noop(char **param, t_client *client, t_server *server);

/*
** function prototypes for client
*/

/*
** common function prototypes
*/

int	close_and_fail(int fd);
void	write_to_fd(int fd, char *str, char newline);
char*	read_from_socket(int socket);
int	read_from_stdin(char buffer[256]);
void	login_display(int c_fd, char *client_ip);
void	strlower(char *str, char stop);
char**	my_str_to_wordtab(char *str, char sep);
void	free_wordtab(char **tab);
void	view_wordtab(char **tab, char newline);

extern	t_command	g_commands[16];

#endif /* !JEFFTP_H_ */
