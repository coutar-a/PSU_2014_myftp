/*
** main_server.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp/src/client
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  9 12:26:04 2015 Ambroise Coutarel
** Last update Thu Mar 12 15:56:20 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"


t_command g_commands[16];

int	query_parsing(char *query, t_client *client, t_server *server)
{
  char	**queryTab;
  int	i;

  i = 0;
  queryTab = my_str_to_wordtab(query, ' ');
  strlower(queryTab[0], 0);
  while (i != 16)
    {
      if (strcmp(queryTab[0], g_commands[i].ftp_command) == 0)
	{
	  g_commands[i].func(queryTab, client, server);
	  free_wordtab(queryTab);
	  return (0);
	}
      ++i;
    }
  printf("user asked for an unknown command.\n");
  write_to_fd(client->fd, "502 : Command not implemented.", 0);
  free_wordtab(queryTab);
  return(0);
}


int	client_transaction(t_client *client, t_server *server)
{
  char	*client_request;

  printf("server root folder : %s\n", server->root);
  init_commands(g_commands);
  printf("IP client : %s\n", client->ip);
  while ("Jeff")
    {
      while ((client_request = read_from_socket(client->fd)) == NULL)
	usleep(300000);
      query_parsing(client_request, client, server);
      free(client_request);
    }
  return (0);
}

int			client_handler(t_server *server)
{
  t_client		client;
  int			pid;
  socklen_t		c_in_size;


  client.name = NULL;
  client.is_logged = 0;
  c_in_size = sizeof(client.sock);
  if ((client.fd = accept(server->fd, (sock)&(client.sock), &c_in_size)) != -1)
    {
      client.ip = inet_ntoa(client.sock.sin_addr);
      login_display(client.fd, client.ip);
      if ((pid = fork()) == -1)
	return (close_and_fail(client.fd));
      else if (pid == 0)
	client_transaction(&client, server);
      else
	return (0);
    }
  else
    close_and_fail(client.fd);
  return (0);
}

int			main(int argc, char **argv)
{
  t_server		server;
  struct protoent	*prot;

  if (argc < 2)
    {
      printf("Usage : ./server <port>\n");
      return (0);
    }
  server.sock.sin_family = AF_INET;
  server.sock.sin_port = htons(atoi(argv[1]));
  server.sock.sin_addr.s_addr = INADDR_ANY;
  init_server(&server);
  if ((prot = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((server.fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (-1);
  if ((bind(server.fd, (constsock)&(server.sock), sizeof(server.sock))) == -1)
    return (close_and_fail(server.fd));
  if ((listen(server.fd, QUEUE)) == -1)
    return (close_and_fail(server.fd));
  while ("jeff")
    client_handler(&server);
  close(server.fd);
  return (0);
}
