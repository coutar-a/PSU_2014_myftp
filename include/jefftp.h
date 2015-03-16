/*
** server.h for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:21:11 2015 Ambroise Coutarel
** Last update Mon Mar 16 12:59:26 2015 Ambroise Coutarel
*/

#ifndef JEFFTP_H_

# define JEFFTP_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <sys/dir.h>
# include <sys/sendfile.h>
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
# include <errno.h>
# include <fcntl.h>

/*
** Macros
*/

# define CAST_C		const struct sockaddr *
# define CAST_NC	struct sockaddr *
# define QUEUE		5
# define GREETING	"Welcome to JefFTP ! Your IP address is : "
# define INFO1		"Please enter a command, or type help for a "
# define INFO2		"list of commands"
# define PROMPT		"JefFTP $>"
# define PATHNAME	"\"%s\n\" created."
# define HELP		"Look it up on the internet, nerd."
# define CODE_150	"150 : File status okay; about to open data connection."
# define CODE_200	"200 : Command okay."
# define CODE_230	"230 : User logged in, proceed."
# define CODE_250	"250 : Requested file action okay, completed."
# define CODE_221	"221 : Service closing control connection."
# define CODE_331	"331 : User name okay, need password."
# define CODE_332	"332 : Need account for login."
# define CODE_501	"501 : Syntax error"
# define CODE_502	"502 : Command not implemented."
# define CODE_530	"530 : Not logged in."
# define CODE_550	"550 : Requested action not taken. File unavailable."
# define ROOT_CDUP	"Already at filesystem root."

/*
** Typedefs
*/

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
void	list_dir(char *pathname, t_client *client);
void	list_file(char *pathname, t_client *client);
int	list_args(char **param, t_client *client);
void	write_desc(int fd, char *path, char *desc);
int	sys_to_ftp_cwd(t_server *server);
int	str_cdup(t_server *server);
int	cwd_root(t_server *server);
int	str_cwd(t_server *server, char *pathname);
int	sys_to_ftp_cwd(t_server *server);
int	str_cdup(t_server *server);
char	*my_strcat(char *dest, char *src);
char	*supercat(char *str1, char *str2, char *str3);
int	delete_file(char *file, t_client *client);
int	cd_and_more(char **param, t_client *client, t_server *server);
int	serv_rcv_file(char *file, t_client *client, t_server *server);
int	serv_snd_file(char *file, t_client *client, t_server *server);

/*
** function prototypes for client
*/

char	*get_filename(char *request);
int	client_rcv_file(char *file, char *msg, int socket);
int	client_snd_file(char *file, char *msg, int socket);

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
int	ftp_send_file(char *file, int socket);
int	ftp_rcv_file(char *file, int socket);

extern	t_command	g_commands[16];

#endif /* !JEFFTP_H_ */
