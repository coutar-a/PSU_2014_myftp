/*
** serverFunctions_2.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:57:47 2015 Ambroise Coutarel
** Last update Tue Mar 17 12:46:56 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		retr(char **param, t_client *client, t_server *server)
{
  if (client->is_logged && param[1])
    {
      printf("user asked for %s in %s\n", param[1], server->sys_cwd);
      serv_snd_file(param[1], client, server);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		stor(char **param, t_client *client, t_server *server)
{
  /* char		*msg; */

  if (client->is_logged && param[1])
    {
      /* while ((msg = read_from_socket(client->fd)) == NULL) */
      /* 	usleep(300000); */
      /* printf("msg : %s\n", msg); */
      printf("user asked to store %s in %s\n", param[1], server->sys_cwd);
      serv_rcv_file(param[1], client, server);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		dele(char **param, t_client *client, t_server *server)
{
  (void)server;
  if (client->is_logged)
      {
	if(param[1])
	  {
	    delete_file(param[1], client);
	  }
	else
	  write_to_fd(client->fd, CODE_501, 0);
      }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		pwd(char **param, t_client *client, t_server *server)
{
  printf("user asked for command %s\n", param[0]);
  if (client->is_logged)
    write_to_fd(client->fd, server->ftp_cwd, 0);
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		list(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      printf("user asked to list %s\n", param[1] ? param[1] : server->sys_cwd);
      if (param[1])
	list_args(param, client);
      else
	list_dir(server->sys_cwd, client);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}
