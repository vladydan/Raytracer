/*
** my_mod_strdup.c for my_mod_strdup in /home/bertra_w/my/lib
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Mon Dec  1 02:20:40 2014 antoine bertrand
** Last update Fri Jun  5 00:41:43 2015 antoine bertrand
*/

#include <stdlib.h>
#include "utils.h"

char		*my_mod_strdup(char *dest, char *src)
{
  char		*result;
  int		size_last_dest;
  int		size;
  int		i;

  (dest) ? (size_last_dest = my_strlen(dest)) : (size_last_dest = 0);
  (src) ? (size = my_strlen(src) + size_last_dest) : (size = size_last_dest);
  if ((result = malloc(size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i < size_last_dest)
    {
      result[i] = dest[i];
      i += 1;
    }
  if (dest)
    free(dest);
  while (i < size)
    {
      result[i] = src[i - size_last_dest];
      i += 1;
    }
  result[i] = '\0';
  return (result);
}
