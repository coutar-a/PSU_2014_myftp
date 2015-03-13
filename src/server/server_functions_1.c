/*
** serverFunctions_1.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:55:04 2015 Ambroise Coutarel
** Last update Fri Mar 13 11:37:47 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	user(char **param, t_client *client, t_server *server)
{
  (void)server;
  if (param[1] != NULL)
    {
      printf("User '%s' logging in as '%s'\n", client->ip, param[1]);
      if (client->name)
	free(client->name);
      client->name = strdup(param[1]);
      if (strcmp(client->name, "Anonymous") == 0)
	{
	  client->is_logged = 1;
	  write_to_fd(client->fd, CODE_230, 0);
	}
      else
	{
	  client->is_logged = 0;
	  write_to_fd(client->fd, CODE_331, 0);
	  return (0);
	}
    }
  else
    write_to_fd(client->fd, CODE_501, 0);
  return (0);
}

int	pass(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("User '%s', name : '%s' requests identification\n", 
	 client->ip, param[0]);
  strlower(param[0], 0);
  if (client->name)
    {
      if (strcmp(client->name, "Anonymous") == 0 || client->is_logged == 1)
	write_to_fd(client->fd, CODE_230, 0);
      else
	write_to_fd(client->fd, CODE_502, 0);
    }
  else
    write_to_fd(client->fd, CODE_332, 0);
  return (0);
}

int	cwd(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command %s\n", param[0]);
  if (client->is_logged)
    {
      write_to_fd(client->fd, CODE_200, 0);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int	cdup(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      (void)server;
      printf("user asked for command %s\n", param[0]);
      write_to_fd(client->fd, CODE_200, 0);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}

int	quit(char **param, t_client *client, t_server *server)
{
  (void)server;
  (void)param;
  printf("user %s IP %s is logging out\n", client->name, client->ip);
  write_to_fd(client->fd, CODE_221, 0);
  close(client->fd);
  return (0);
}
