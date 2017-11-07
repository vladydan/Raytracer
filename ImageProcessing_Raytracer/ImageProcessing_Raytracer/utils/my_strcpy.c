/*
** my_strcpy.c for raytracer in /home/bertra_w/rendu/Sem_2/Igraph/02_Raytracer/MUL_2014_rtracer
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Sun Jun  7 00:19:44 2015 antoine bertrand
** Last update Sun Jun  7 00:22:22 2015 antoine bertrand
*/

void		my_strcpy(char *dest, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
}
