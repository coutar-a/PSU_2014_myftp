/*
** serverFunctions_2.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:57:47 2015 Ambroise Coutarel
** Last update Thu Mar 12 19:14:36 2015 Ambroise Coutarel
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
    write_to_fd(client->fd, "530 : Not logged in", 0);
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
    write_to_fd(client->fd, "530 : Not logged in", 0);
  return (0);
}

int		dele(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
      {
	(void)server;
	printf("user asked for command dele !\n");
	(void)param;
	write_to_fd(client->fd, "JEFF !!", 0);
	(void)client;
      }
  else
    write_to_fd(client->fd, "530 : Not logged in", 0);
  return (0);
}

int		pwd(char **param, t_client *client, t_server *server)
{
  printf("user asked for command %s\n", param[0]);
  if (client->is_logged)
    write_to_fd(client->fd, server->ftp_cwd, 0);
  else
    write_to_fd(client->fd, "530 : Not logged in", 0);
  return (0);
}

int		list(char **param, t_client *client, t_server *server)
{
  DIR		*dir;
  struct dirent	*dirbuff;

  (void)server;
  if(client->is_logged)
    {
      printf("user asked to list %s\n", param[1]);
      if (param[1])
	;//list directory
      else
	{
	  dir = opendir(server->sys_cwd);
	  if (dir)
	    {
	      while ((dirbuff = readdir(dir)))
		write_to_fd(client->fd, dirbuff->d_name, 1);
	      closedir(dir);
	    }
	  else
	    write_to_fd(client->fd, "Couldn' open direcotry.", 0);
	}//list cwd
    }
  else
    write_to_fd(client->fd, "530 : Not logged in", 0);
  return (0);
}
