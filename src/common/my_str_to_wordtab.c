/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/coutar_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Tue Oct 29 10:05:09 2013 coutar_a
** Last update Wed Mar 11 12:51:54 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

/*
** Frees the wordtab set as parameter 
*/

void	free_wordtab(char **tab)
{
  int	i;
  
  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

/*
** Displays the wordtab set as parameter
*/

void	view_wordtab(char **tab, char newline)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (newline == 1)
	printf("%s\n", tab[i]);
      else
	printf("%s ", tab[i]);
      i++;
    }
}

/*
** Counts "words" in an array
*/

int	word_count(char *str, char sep)
{
  int	i;
  int	ctr;

  i = 0;
  ctr = 0;
  while (str[i] != '\0')
    {
      if ((i == 0 && str[i] != sep) ||
	  (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0'))
	ctr++;
      i++;
    }
  return (ctr);
}

/*
** Boilerplate code from GetNextLine, should return each "word" ( i.e. chars separated by spaces)
*/

char            *gnl_parser(char *str, int *i, char sep)
{
  int           ctr1;
  int           ctr2;
  char          *result;

  ctr2 = 0;
  while (str[*i] == sep)
    (*i)++;
  ctr1 = (*i);
  while(str[ctr1] != sep && str[ctr1] != '\0')
    ctr1++;
  if ((result = malloc((ctr1 - (*i)) + 1)) == NULL)
    return (NULL);
  while ((*i) != ctr1)
    result[ctr2++] = str[(*i)++];
  result[ctr2] = '\0';
  while (str[*i] == sep)
    (*i)++;
  return (result);
}

/*
** "main" function, calls in gnl_parser for each "word"
*/

char		**my_str_to_wordtab(char *str, char sep)
{
  char		**tab;
  int		wordcount;
  int		i;
  int		s;

  i = 0;
  s = 0;
  wordcount = word_count(str, sep);
  if ((tab = malloc(sizeof(char *) * (wordcount + 1))) == NULL)
    return (NULL);
  tab[wordcount] = '\0';
  while (i != wordcount)
    {
      tab[i] = gnl_parser(str, &s, sep);
      i++;
    }
  return (tab);
}
