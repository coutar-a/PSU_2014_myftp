/*
** serverFunctions_3.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 13:01:11 2015 Ambroise Coutarel
** Last update Mon Mar 16 10:59:11 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		help(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command help !\n");
  (void)param;
  write_to_fd(client->fd, HELP, 0);
  return (0);
}

int		noop(char **param, t_client *client, t_server *server)
{
  if (client->is_logged)
    {
      (void)server;
      printf("user asked for command noop !\n");
      (void)param;
      write_to_fd(client->fd, CODE_200, 0);
    }
  else
    write_to_fd(client->fd, CODE_530, 0);
  return (0);
}
