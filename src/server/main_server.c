/*
** main_server.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:26:04 2015 Ambroise Coutarel
** Last update Tue Mar 10 12:55:12 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int			client_transaction(int s_fd, int c_fd, 
					   struct sockaddr_in *c_sock, 
					   struct sockaddr_in *s_sock) 
{
  char			*client_ip;
  char			*client_request;

  client_ip = inet_ntoa(c_sock->sin_addr);
  printf("IP client : %s\n", client_ip);
  //loginDisplay(c_fd, client_ip);
  while ("Jeff")
    {
      if ((client_request = readFromSocket(c_fd)) != NULL)
	{
	  printf("client request : %s\n", client_request);
	  free(client_request);
	  usleep(300000);
	  writeToFd(c_fd, "message recieved, now go fuck yourself >:(", 1);
	}
    }
  (void)s_fd;
  (void)c_fd;
  (void)s_sock;
  return (0);
}

int			client_handler(int server_fd, 
				       struct sockaddr_in *s_sock)
{
  struct sockaddr_in	c_sock;
  int			client_fd;
  int			pid;
  socklen_t		c_in_size;
  int			nb_clients;

  nb_clients = 0;
  c_in_size = sizeof(c_sock);
  if ((client_fd = accept(server_fd, (sock)&c_sock, &c_in_size)) != -1)
    {
      loginDisplay(client_fd, inet_ntoa(c_sock.sin_addr));
      if ((pid = fork()) == -1)
	return (close_and_fail(client_fd));
      else if (pid == 0 && nb_clients != QUEUE)
	{
	  client_transaction(server_fd, client_fd, &c_sock, s_sock);
	  ++nb_clients;
	}
      else
	return (0);
    }
  else
    close_and_fail(client_fd);
  return (0);
}

int			main(int argc, char **argv)
{
  struct protoent	*prot;
  struct sockaddr_in	sock_in;
  int			server_fd;

  if (argc < 2)
    {
      printf("Usage : ./server <port>\n");
      return (0);
    }
  sock_in.sin_family = AF_INET;
  sock_in.sin_port = htons(atoi(argv[1]));
  sock_in.sin_addr.s_addr = INADDR_ANY;
  if ((prot = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((server_fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (-1);
  if ((bind(server_fd, (constsock)&sock_in, sizeof(sock_in))) == -1)
    return (close_and_fail(server_fd));
  if ((listen(server_fd, QUEUE)) == -1)
    return (close_and_fail(server_fd));
  while ("jeff")
    client_handler(server_fd, &sock_in);
  close(server_fd);
  return (0);
}
