/*
** my_get_next_line.c for my_get_next_line in /home/bertra_w/rendu/Sem1/C_ProgElem/02_GetNextLine/my_get_next_line_test
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Fri Nov 21 13:06:02 2014 antoine bertrand
** Last update Fri Jun  5 00:38:33 2015 antoine bertrand
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

static int	mod_strln(char *str, int bool)
{
  int		i;

  i = 0;
  if (bool == 0)
    {
      while (str && str[i])
	i += 1;
      return (i);
    }
  else
    {
      while (str && str[i] != '\0')
	{
	  if (str[i] == '\n')
	    return (1);
	  i += 1;
	}
      return (0);
    }
}

static char	*my_strcpy_line(char *str, int *i)
{
  char		*result;

  *i = 0;
  while (str[*i] && str[*i] != '\n')
    *i += 1;
  if ((result = malloc(*i + 1)) == NULL)
    return (NULL);
  *i = 0;
  while (str[*i] && str[*i] != '\n')
    {
      result[*i] = str[*i];
      *i += 1;
    }
  result[*i] = '\0';
  return (result);
}

char		*get_next_line(const int fd)
{
  static char	*txt = NULL;
  char		*result;
  char		buffer[BUFF_SIZE + 1];
  int		i;
  int		a;

  result = NULL;
  while (!mod_strln(txt, 1) && (a = read(fd, buffer, BUFF_SIZE)) > 0)
    {
      buffer[a] = '\0';
      txt = my_mod_strdup(txt, buffer);
    }
  if (txt && *txt)
    {
      result = my_strcpy_line(txt, &i);
      if (txt[i] != '\0')
	txt = my_str_realloc(txt, txt + i + 1);
      else
	txt = my_str_realloc(txt, txt + i);
    }
  return (result);
}
