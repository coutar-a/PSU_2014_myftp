/*
** display.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 14:55:41 2015 Ambroise Coutarel
** Last update Mon Mar  9 15:10:21 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

void	writeToFd(int fd, char *str, char newline)
{
  write(fd, str, strlen(str));
  if (newline)
    write(fd, "\n", 1);
}
