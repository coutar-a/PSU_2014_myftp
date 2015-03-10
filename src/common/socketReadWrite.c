/*
** socketReadWrite.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Tue Mar 10 10:13:11 2015 Ambroise Coutarel
** Last update Tue Mar 10 13:40:20 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

/*
** reads appropriate number of bytes from socket and shoves them in a buffer
** returns array containing what was read, NULL on error
*/

char*	readFromSocket(int socket)
{
  int	len;
  char	*buffer;

  ioctl(socket, FIONREAD, &len);
  if (len > 0)
    {
      if((buffer = malloc(len + 1)) == NULL)
	return (NULL);
      len = read(socket, buffer, len);
      buffer[len] = 0;
      return (buffer);
    }
  else
    return (NULL);
}

int	readFromStdin(char buffer[256])
{
  int	len;

  while (1)
    {
      if ((len = read(0, buffer, 255)) > 0)
	{
	  buffer[len - 1] = 0;
	  return (len);
	}
      else
	return (-1);
    }
  return (-1);
}

void	strlower(char *str, char stop)
{
  int	i;

  i = 0;
  while (str[i] != stop && str[i] != 0)
    {
      if (isupper(str[i]))
	  str[i] -= 32;
      i++;
    }
}
