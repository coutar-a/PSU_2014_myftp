/*
** display.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 14:55:41 2015 Ambroise Coutarel
** Last update Tue Mar 10 12:42:59 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

/*
** Writes str to fd, would you like a newline with that y/n
*/

void	writeToFd(int fd, char *str, char newline)
{
  write(fd, str, strlen(str));
  if (newline)
    write(fd, "\n", 1);
}

void	loginDisplay(int c_fd, char *client_ip)
{
  writeToFd(c_fd, GREETING, 0);
  writeToFd(c_fd, client_ip, 1);
  writeToFd(c_fd, INFO1, 0);
  writeToFd(c_fd, INFO2, 1);
}
