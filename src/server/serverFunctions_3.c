/*
** serverFunctions_3.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar 11 13:01:11 2015 Ambroise Coutarel
** Last update Wed Mar 11 15:45:04 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

int		help(char **param)
{
  printf("user asked for command help !\n");
  (void)param;
  return (0);
}

int		noop(char **param)
{
  printf("user asked for command coop !\n");
  (void)param;
  return (0);
}
