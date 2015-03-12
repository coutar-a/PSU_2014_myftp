/*
** sundries.c for minishell1 in /home/coutar_a/rendu/PSU_2013_minishell1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sun Dec 29 17:10:06 2013 coutar_a
** Last update Thu Mar 12 18:56:44 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

/*
** concats two strings into a malloc'd third
*/

char	*my_strcat(char *dest, char *src)
{
  char	*ret;
  int	l;
  int	i;
  int	j;

  i = 0;
  j = 0;
  l = my_strlen(dest) + my_strlen(src) + 1;
  if ((ret = malloc((l) * sizeof(char))) == NULL)
    return (NULL);
  ret[l - 1] = '\0';
  while (dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      ret[i] = src[j];
      i++;
      j++;
    }
  return (ret);
}

/*
** concats 3 strings
*/

char	*supercat(char *str1, char *str2, char *str3)
{
  char	*swap;
  char	*swap2;

  swap = my_strcat(str1, str2);
  swap2 = my_strcat(swap, str3);
  free(swap);
  return (swap2);
}
