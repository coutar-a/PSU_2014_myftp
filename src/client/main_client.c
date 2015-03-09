/*
** main_client.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:19:05 2015 Ambroise Coutarel
** Last update Mon Mar  9 16:02:10 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	main(int argc, char **argv)
{
  struct protoent	*prot;
  struct sockaddr_in	sock_in;
  int			s_fd;
  
  if (argc < 3)
    {
      printf("Usage : ./server <IP> <port>\n");
      return (0);
    }
  sock_in.sin_family = AF_INET;
  sock_in.sin_port = htons(atoi(argv[2]));
  sock_in.sin_addr.s_addr = inet_addr(argv[1]);
  if ((prot = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((s_fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (-1);
  if ((connect(s_fd, (CAST_NC)&sock_in, sizeof(sock_in))) == -1)
    close_and_fail(s_fd);
  writeToFd(s_fd, "FOR FUCK SAKE", 1);
  return (0);
}
