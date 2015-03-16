/*
** cd_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Fri Mar 13 12:44:49 2015 Ambroise Coutarel
** Last update Mon Mar 16 10:01:43 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	cwd_root(t_server *server)
{
  free(server->sys_cwd);
  server->sys_cwd = strdup(server->root);
  free(server->ftp_cwd);
  server->ftp_cwd = strdup("/root");
  return (0);
}

int	str_cwd(t_server *server, char *pathname)
{
  char	*new_wd;
  
  if (strcmp(pathname, "..") == 0 || strcmp(pathname, ".") == 0)
    return (-1);
  new_wd = supercat(server->sys_cwd, "/", pathname);
  free(server->sys_cwd);
  server->sys_cwd = strdup(new_wd);
  free(new_wd);
  sys_to_ftp_cwd(server);
  return (0);
}

int	sys_to_ftp_cwd(t_server *server)
{
  int	i;
  int	j;
  char	fart[256];

  i = 0;
  j = 0;
  while (server->root[i] != 0)
    ++i;
  free(server->ftp_cwd);
  while(server->sys_cwd[i++] != 0)
    fart[j++] = server->sys_cwd[i];
  fart[j] = 0;
  if (!(server->ftp_cwd = malloc(sizeof(char) * (j + strlen("/root") + 1))))
    return (-1);
  server->ftp_cwd = supercat("/root", "/", fart);
  return (0);
}

int	str_cdup(t_server *server)
{
  int	i;
  int	j;

  i = strlen(server->sys_cwd);
  j = strlen(server->ftp_cwd);
  while (server->sys_cwd[i] != '/')
    --i;
  if (i == 0)
    ++i;
  while (server->ftp_cwd[j] != '/')
    --j;
  server->sys_cwd[i] = 0;
  server->ftp_cwd[j] = 0;
  return (0);
}

int	cd_and_more(char **param, t_client *client, t_server *server)
{
  if (param[1])
    {
      if (access(param[1], F_OK | R_OK | W_OK) == -1)
	{
	  printf("ERROR : %s\n", strerror(errno));
	  write_to_fd(client->fd, CODE_550, 0);
	}
      else if(strcmp("..", param[1]) == 0)
	{
	  cdup(param, client, server);
	  return (0);
	}
      else
	str_cwd(server, param[1]);
    }
  else
    cwd_root(server);
  write_to_fd(client->fd, CODE_200, 0);
  return (0);
}
