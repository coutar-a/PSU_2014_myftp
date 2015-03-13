/*
** cd_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Fri Mar 13 12:44:49 2015 Ambroise Coutarel
** Last update Fri Mar 13 17:53:28 2015 Ambroise Coutarel
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
  printf("new sys_wd : %s\n", server->sys_cwd);
  sys_to_ftp_cwd(server);
  return (0);
}

int	sys_to_ftp_cwd(t_server *server)
{
  int	i;
  int	j;
  char	*buf;
  char	fart[256];

  i = 0;
  j = 0;
  while (server->root[i] != 0)
    ++i;
  buf = strdup(server->ftp_cwd);
  free(server->ftp_cwd);
  while(server->sys_cwd[i++] != 0)
    fart[j++] = server->sys_cwd[i];
  fart[j] = 0;
  if (!(server->ftp_cwd = malloc(sizeof(char) * (j + strlen(buf) + 1))))
    return (-1);
  printf("fart : %s\n", fart);
  printf("server_root : %s\n server_wd : %s\n length new cwd ftp : %d\n", server->root, server->sys_cwd, (int)(j + strlen(buf)));
  server->ftp_cwd = supercat(buf, "/", fart);
  printf("new ftp_wd : %s\n", server->ftp_cwd);
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
  server->ftp_cwd[j] = 0;
  printf("new sys_cwd after cdup : %s\n", server->sys_cwd);
  printf("new ftp_cwd after cdup : %s\n", server->ftp_cwd);
  //sys_to_ftp_cwd(server);
  return (0);
}
