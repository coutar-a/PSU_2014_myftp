/*
** serverFunctions_1.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 12:55:04 2015 Ambroise Coutarel
** Last update Wed Mar 11 15:43:53 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		user(char **param)
{
  printf("user asked for command user !\n");
  (void)param;
  return (0);
}

int		pass(char **param)
{
  printf("user asked for command pass !\n");
  (void)param;
  return (0);
}

int		cwd(char **param)
{
  printf("user asked for command cwd !\n");
  (void)param;
  return (0);
}

int		cdup(char **param)
{
  printf("user asked for command cdup !\n");
  (void)param;
  return (0);
}

int		quit(char **param)
{
  printf("user asked for command quit !\n");
  (void)param;
  return (0);
}
