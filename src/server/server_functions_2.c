/*
** serverFunctions_2.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:57:47 2015 Ambroise Coutarel
** Last update Fri Mar 13 11:42:44 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		retr(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      (void)server;
      printf("user asked for command retr !\n");
      (void)param;
      write_to_fd(client->fd, "JEFF !!", 0);
      (void)client;
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		stor(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      (void)server;
      printf("user asked for command stor !\n");
      (void)param;
      write_to_fd(client->fd, "JEFF !!", 0);
      (void)client;
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int		dele(char **param, t_client *client, t_server *server)
{
  int		file;

  if (client->is_logged)
      {
	if(param[1])
	  {
	    if ((file = access(param[1], F_OK | R_OK | W_OK)) == -1)
	      write_to_fd(client->fd, CODE_505, 0);
	    else
	      {
		printf("user asked to delete file %s\n", param[1]);
		unlink(param[1]);
		(void)server;
		write_to_fd(client->fd, CODE_250, 0);
	      }
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
  if(client->is_logged)
    {
      if (param[1])
	{
	  printf("user asked to list %s\n", param[1]);
	  list_dir(param[1], client);
	}
      else
	{
	  printf("user asked to list %s\n", server->sys_cwd);
	  list_dir(server->sys_cwd, client);
	}
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}
