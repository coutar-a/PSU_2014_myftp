/*
** serverFunctions_1.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:55:04 2015 Ambroise Coutarel
** Last update Thu Mar 12 15:50:40 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		user(char **param, t_client *client, t_server *server)
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
	  write_to_fd(client->fd, "230 : User logged in, proceed.", 0);
	}
      else
	{
	  client->is_logged = 0;
	  write_to_fd(client->fd, "331 : User name okay, need password.", 0);
	  return (0);
	}
    }
  else
    write_to_fd(client->fd, "501 : Syntax error", 0);
  return (0);
}

int		pass(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("User '%s', name : '%s' requests identification\n", 
	 client->ip, param[0]);
  strlower(param[0], 0);
  if (client->name)
    {
      if (strcmp(client->name, "Anonymous") == 0 || client->is_logged == 1)
	write_to_fd(client->fd, "230 : User logged in, proceed.", 0);
      else
	write_to_fd(client->fd, "502 : Command not implemented.", 0);
    }
  else
    write_to_fd(client->fd, "332 : Need account for login.", 0);
  return (0);
}

int		cwd(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command %s\n", param[0]);
  if (client->is_logged)
    {
      write_to_fd(client->fd, "200 : Command okay.", 0);
    }
  else
    write_to_fd(client->fd, " 530 : Not logged in.", 0);
  return (0);
}

int		cdup(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command %s\n", param[0]);
  write_to_fd(client->fd, "200 : Command okay.", 0);
  return (0);
}

int		quit(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command %s\n", param[0]);
  write_to_fd(client->fd, "221 : Service closing control connection.", 0);
  close(client->fd);
  return (0);
}
