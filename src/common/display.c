/*
** display.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 14:55:41 2015 Ambroise Coutarel
** Last update Thu Mar 12 13:24:16 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

/*
** Writes str to fd, would you like a newline with that y/n
*/

void	write_to_fd(int fd, char *str, char newline)
{
  write(fd, str, strlen(str));
  if (newline)
    write(fd, "\n", 1);
}

void	login_display(int c_fd, char *client_ip)
{
  write_to_fd(c_fd, GREETING, 0);
  write_to_fd(c_fd, client_ip, 1);
  write_to_fd(c_fd, INFO1, 0);
  write_to_fd(c_fd, INFO2, 1);
}
