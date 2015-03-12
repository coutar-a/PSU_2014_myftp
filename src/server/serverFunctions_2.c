/*
** serverFunctions_2.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:57:47 2015 Ambroise Coutarel
** Last update Thu Mar 12 15:51:22 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		retr(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command retr !\n");
  (void)param;
  write_to_fd(client->fd, "JEFF !!", 0);
  (void)client;
  return (0);
}

int		stor(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command stor !\n");
  (void)param;
  write_to_fd(client->fd, "JEFF !!", 0);
  (void)client;
  return (0);
}

int		dele(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command dele !\n");
  (void)param;
  write_to_fd(client->fd, "JEFF !!", 0);
  (void)client;
  return (0);
}

int		pwd(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command pwd !\n");
  (void)param;
  write_to_fd(client->fd, "JEFF !!", 0);
  (void)client;
  return (0);
}

int		list(char **param, t_client *client, t_server *server)
{
  (void)server;
  printf("user asked for command list !\n");
  (void)param;
  write_to_fd(client->fd, "JEFF !!", 0);
  (void)client;
  return (0);
}
