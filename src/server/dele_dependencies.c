/*
** dele_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Sat Mar 14 14:53:51 2015 Ambroise Coutarel
** Last update Sat Mar 14 15:06:32 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"


int	delete_file(char *file, t_client *client)
{
  if ((access(file, F_OK | R_OK | W_OK)) == -1)
    {
      printf("ERROR : %s\n", strerror(errno));
      printf("cannot delete %s\n", file);
      write_to_fd(client->fd, CODE_550, 0);
      return (-1);
    }
  else
    {
      printf("user asked to delete file %s\n", file);
      unlink(file);
      write_to_fd(client->fd, CODE_250, 0);
    }
  return (0);
}
