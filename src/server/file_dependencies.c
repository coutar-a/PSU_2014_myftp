/*
** file_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar 16 11:29:25 2015 Ambroise Coutarel
** Last update Tue Mar 17 12:52:11 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	serv_rcv_file(char *file, t_client *client, t_server *server)
{
  //char	*msg;
  char	*actual_file;

  /* while ((msg = read_from_socket(client->fd)) == NULL) */
  /*   usleep(300000); */
  /* printf("server msg : %s\n", msg); */
  actual_file = supercat(server->sys_cwd, "/", file);
  printf("filename on server : %s\n", actual_file);
  sleep(1);
  srv_file(actual_file, client->fd);
  return (0);
}

int	serv_snd_file(char *file, t_client *client, t_server *server)
{
  char	*actual_file;

  actual_file = supercat(server->sys_cwd, "/", file);
  printf("filename on server : %s\n", actual_file);
  ftp_send_file(actual_file, client->fd);
  return (0);
}
