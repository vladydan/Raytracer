/*
** my_str_realloc.c for my_str_realloc in /home/bertra_w/my/lib
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Mon Dec  1 02:31:00 2014 antoine bertrand
** Last update Fri Jun  5 00:50:19 2015 antoine bertrand
*/

#include <stdlib.h>
#include "utils.h"

char		*my_str_realloc(char *dest, char *src)
{
  char		*tmp;
  int		i;
  int		size;

  i = 0;
  (src) ? (size = my_strlen(src)) : (size = 0);
  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      tmp[i] = src[i];
      i += 1;
    }
  tmp[i] = '\0';
  if (dest)
    free(dest);
  return (tmp);
}
