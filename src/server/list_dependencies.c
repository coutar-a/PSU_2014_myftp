/*
** list_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Thu Mar 12 19:17:55 2015 Ambroise Coutarel
** Last update Sat Mar 14 14:46:17 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

void			write_desc(int fd, char *path, char *desc)
{
  char			*msg;

  msg = supercat(path, " : ", desc);
  write_to_fd(fd, msg, 1);
  free(msg);
  /* write_to_fd(fd, path, 0); */
  /* write_to_fd(fd, " : ", 0); */
  /* write_to_fd(fd, desc, 0); */
}

void			list_file(char *pathname, t_client *client)
{
  struct stat	buf;

  stat(pathname, &buf);
  if(S_ISREG(buf.st_mode))
    write_desc(client->fd, pathname, "Regular file.");
  else if(S_ISLNK(buf.st_mode))
    write_desc(client->fd, pathname, "Symbolic link.");
  else
    write_desc(client->fd, pathname, "Unknown file type.");
}

void			list_dir(char *pathname, t_client *client)
{
  struct dirent		**contents;
  int			nbfiles;
  int			i;
  
  i = 0;
  nbfiles = scandir(pathname, &contents, NULL, alphasort);
  if (nbfiles > -1)
    {
      write_to_fd(client->fd, my_strcat(pathname, " : "), 1);
      while (i != nbfiles)
	{
	  write_to_fd(client->fd, contents[i]->d_name, 1);
	  free(contents[i]);
	  ++i;
	}
      free(contents);
    }
  else
    write_to_fd(client->fd, CODE_550, 0);
}

int		list_args(char **param, t_client *client)
{
  struct stat	buf;
  int		i;

  i = 1;
  while (param[i])
    {
      printf("file/directory to list : %s\n", param[i]);
      if (access(param[i], F_OK | R_OK | W_OK) == -1)
	{
	  printf("ERROR : %s\n", strerror(errno));
	  write_to_fd(client->fd, CODE_550, 0);
	  return (-1);
	}
      stat(param[i], &buf);
      if(S_ISDIR(buf.st_mode))
	list_dir(param[i], client);
      else
	list_file(param[i], client);
      ++i;
    }
  return (0);
}
