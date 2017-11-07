/*
** my_strcat.c for raytracer in /home/bertra_w/rendu/Sem_2/Igraph/02_Raytracer/MUL_2014_rtracer
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Sun Jun  7 00:25:08 2015 antoine bertrand
** Last update Sun Jun  7 00:28:56 2015 antoine bertrand
*/

#include "utils.h"

void		my_strcat(char *dest, char *str)
{
  int		i;
  int		size;

  i = 0;
  size = my_strlen(dest);
  while (str[i])
    {
      dest[size + i] = str[i];
      i++;
    }
  dest[size + i] = '\0';
}
