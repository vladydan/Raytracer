/*
** my_strlen.c for raytracer in /home/bertra_w/rendu/Sem_2/Igraph/02_Raytracer/MUL_2014_rtracer
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Sat May 30 12:02:28 2015 antoine bertrand
** Last update Sat May 30 12:02:43 2015 antoine bertrand
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i += 1;
  return (i);
}
