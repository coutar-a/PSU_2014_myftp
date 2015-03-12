/*
** main_client.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:19:05 2015 Ambroise Coutarel
** Last update Thu Mar 12 13:48:53 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	command_line(int socket)
{
  char			*server_msg;
  char			user_request[256];

  server_msg = read_from_socket(socket);
  write_to_fd(1, server_msg, 1);
  free(server_msg);
  while("jeff")
    {
      write_to_fd(1, PROMPT, 0);
      read_from_stdin(user_request);
      write_to_fd(socket, user_request, 0);
      strlower(user_request, 0);
      while ((server_msg = read_from_socket(socket)) == NULL)
	usleep(300000);
      write_to_fd(1, server_msg, 1);
      free(server_msg);
      if ((strcmp(user_request, "quit")) == 0)
	{
	  close(socket);
	  exit(0);
	}
    }
  return (0);
}

int	main(int argc, char **argv)
{
  struct protoent	*prot;
  struct sockaddr_in	sock_in;
  int			s_fd;
  
  if (argc < 3)
    {
      printf("Usage : ./client <IP> <port>\n");
      return (0);
    }
  sock_in.sin_family = AF_INET;
  sock_in.sin_port = htons(atoi(argv[2]));
  sock_in.sin_addr.s_addr = inet_addr(argv[1]);
  if ((prot = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((s_fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (-1);
  if ((connect(s_fd, (sock)&sock_in, sizeof(sock_in))) == -1)
    close_and_fail(s_fd);
  sleep(2);
  command_line(s_fd);
  return (0);
}
