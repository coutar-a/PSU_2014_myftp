/*
** main_server.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:26:04 2015 Ambroise Coutarel
** Last update Tue Mar 10 16:26:18 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int			client_transaction(int s_fd, struct sockaddr_in *s_sock, 
					   t_client *client) 
{
  char			*client_request;

  printf("IP client : %s\n", client->ip);
  while ("Jeff")
    {
      if ((client_request = readFromSocket(client->fd)) != NULL)
	{
	  printf("client request : %s\n", client_request);
	  if ((strcmp(client_request, "quit")) == 0)
	    {
	      close(client->fd);
	      return(0);
	    }
	  free(client_request);
	  writeToFd(client->fd, "you requested a thing", 0);
	}
    }
  (void)s_fd;
  (void)s_sock;
  return (0);
}

int			client_handler(int server_fd, 
				       struct sockaddr_in *s_sock)
{
  t_client		client;
  /* struct sockaddr_in	c_sock; */
  /* int			client_fd; */
  int			pid;
  socklen_t		c_in_size;


  c_in_size = sizeof(client.sock);
  if ((client.fd = accept(server_fd, (sock)&(client.sock), &c_in_size)) != -1)
    {
      client.ip = inet_ntoa(client.sock.sin_addr);
      loginDisplay(client.fd, client.ip);
      if ((pid = fork()) == -1)
	return (close_and_fail(client.fd));
      else if (pid == 0)
	client_transaction(server_fd, s_sock, &client);
      else
	return (0);
    }
  /* c_in_size = sizeof(c_sock); */
  /* if ((client_fd = accept(server_fd, (sock)&c_sock, &c_in_size)) != -1) */
  /*   { */
  /*     loginDisplay(client_fd, inet_ntoa(c_sock.sin_addr)); */
  /*     if ((pid = fork()) == -1) */
  /* 	return (close_and_fail(client_fd)); */
  /*     else if (pid == 0) */
  /* 	client_transaction(server_fd, client_fd, &c_sock, s_sock); */
  /*     else */
  /* 	return (0); */
  /*   } */
  else
    close_and_fail(client.fd);
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
