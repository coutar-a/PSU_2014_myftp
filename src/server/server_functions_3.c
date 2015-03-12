/*
** serverFunctions_3.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 13:01:11 2015 Ambroise Coutarel
** Last update Thu Mar 12 18:46:38 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		help(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command help !\n");
  (void)param;
  write_to_fd(client->fd, "214 : HELP MESSAGE", 0);
  return (0);
}

int		noop(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      (void)server;
      printf("user asked for command noop !\n");
      (void)param;
      write_to_fd(client->fd, "200 : Command okay.", 0);
    }
  else
    write_to_fd(client->fd, "530 : Not logged in", 0);
  return (0);
}
