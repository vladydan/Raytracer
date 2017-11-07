/*
** strlcpy.c for 3dwolf in /home/breton_y/IGraph/3DWolf
** 
** Made by yanis breton
** Login   <breton_y@epitech.net>
** 
** Started on  Thu Dec 18 14:50:03 2014 yanis breton
** Last update Sat Jun  6 20:12:20 2015 antoine bertrand
*/

#include <stddef.h>
#include "utils.h"

int		strlcpy(char *dst, char *src, int size)
{
  int		i;

  i = 0;
  while (src[i] && i < size)
    {
      dst[i] = src[i];
      i += 1;
    }
  return (1);
}
