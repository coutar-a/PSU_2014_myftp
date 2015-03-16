/*
** files_client.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar 16 10:30:44 2015 Ambroise Coutarel
** Last update Mon Mar 16 16:24:37 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

char	*get_filename(char *request)
{
  char	**tmp;
  char	*ret;

  tmp = my_str_to_wordtab(request, ' ');
  if(!tmp)
    return (NULL);
  ret = strdup(tmp[1]);
  free_wordtab(tmp);
  return (ret);
}

int	client_rcv_file(char *file, char *msg, int socket)
{
  if ((strcmp(msg, CODE_150)) != 0)
    return(-1);
  printf("Now preparing to recieve file\n");
  ftp_rcv_file(file, socket);
  return (0);
}

int	client_snd_file(char *file, char *msg, int socket)
{
  if ((strcmp(msg, CODE_150)) != 0)
    return(-1);
  //printf("server message : %s\n", msg);
  printf("Now preparing to upload file.\n");
  //sleep(1);
  ftp_send_file(file, socket);
  return (0);
}
