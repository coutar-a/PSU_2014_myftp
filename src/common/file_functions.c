/*
** file_functions.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar 16 09:57:59 2015 Ambroise Coutarel
** Last update Tue Mar 17 13:11:29 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int	ftp_send_file(char *file, int socket)
{
  char	*msg;
  int	len;
  int	file_fd;

  len = 0;
  if((file_fd = open(file, O_RDONLY)) == -1)
    {
      write_to_fd(socket, CODE_550, 0);
      return (-1);
    }
  printf("file is open.\n");
  write_to_fd(socket, CODE_150, 0);
  while ((msg = read_from_socket(socket)) == NULL)
    usleep(300000);
  printf("starting transfer.\n");
  free(msg);
  ioctl(file_fd, FIONREAD, &len);
  sendfile(socket, file_fd, 0, len);
  printf("Transfer over. Closing file.\n");
  close(file_fd);
  return(0);
}

int	ftp_rcv_file(char *file, int socket)
{
  char	*buff;
  int	file_fd;

  if((file_fd = open(file, O_RDWR | O_CREAT, 0666)) == -1)
    {
      write_to_fd(socket, CODE_550, 0);
      return (-1);
    }
  printf("ready to recieve.\n");
  write_to_fd(socket, CODE_150, 0);
  while (!(buff = read_from_socket(socket)))
    usleep(300000);
  if(!(strcmp(CODE_550, buff)))
    {
      close(file_fd);
      return (-1);
    }
  write_to_fd(file_fd, buff, 0);
  close(file_fd);
  return(0);
}

int	clt_snd_file(char *file, int socket)
{
  char	*buff;
  int	len;
  int	file_fd;

  len = 0;
  if((file_fd = open(file, O_RDONLY)) == -1)
    {
      write_to_fd(socket, CODE_550, 0);
      return (-1);
    }
  printf("file is open.\n");
  while (!(buff = read_from_socket(socket)))
    {
      write_to_fd(socket, CODE_150, 0);
      usleep(300000);
    }
  printf("%s\n", buff);
  free(buff);
  ioctl(file_fd, FIONREAD, &len);
  sendfile(socket, file_fd, 0, len);
  printf("Transfer over. Closing file.\n");
  close(file_fd);
  return(0);
}

int	srv_file(char *file, int socket)
{
  char	*buff;
  int	file_fd;

  if((file_fd = open(file, O_RDWR | O_CREAT, 0666)) == -1)
    {
      write_to_fd(socket, CODE_550, 0);
      return (-1);
    }
  printf("ready to recieve.\n");
  while (!(buff = read_from_socket(socket)))
    {
      write_to_fd(socket, CODE_150, 0);
      usleep(300000);
    }
  free(buff);
  write_to_fd(socket, CODE_150, 0);
  while (!(buff = read_from_socket(socket)))
    usleep(300000);
  write_to_fd(file_fd, buff, 0);
  free(buff);
  close(file_fd);
  return(0);
}
