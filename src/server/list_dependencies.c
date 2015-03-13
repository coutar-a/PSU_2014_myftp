/*
** list_dependencies.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Thu Mar 12 19:17:55 2015 Ambroise Coutarel
** Last update Fri Mar 13 16:27:41 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

void			write_desc(int fd, char *path, char *desc)
{
  write_to_fd(fd, path, 0);
  write_to_fd(fd, " : ", 0);
  write_to_fd(fd, desc, 0);
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
      while (i != nbfiles)
	{
	  write_to_fd(client->fd, contents[i]->d_name, 1);
	  free(contents[i]);
	  ++i;
	}
      free(contents);
    }
  else
    write_to_fd(client->fd, "Couldn't open directory.", 0);
}
