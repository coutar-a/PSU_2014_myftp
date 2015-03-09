/*
** errors.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:49:40 2015 Ambroise Coutarel
** Last update Mon Mar  9 12:56:03 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	close_and_fail(int fd)
{
  printf("ERROR : %s\n", strerror(errno));
  if ((close(fd)) == -1)
    printf("ERROR : %s\n", strerror(errno));
  return (-1);
}
