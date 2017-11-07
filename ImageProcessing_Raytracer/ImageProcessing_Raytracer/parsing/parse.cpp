/*
** parse.c for rtracer in /home/breton_y/rendu/MUL_2014_rtracer
** 
** Made by yanis breton
** Login   <breton_y@epitech.net>
** 
** Started on  Tue May 26 11:41:15 2015 yanis breton
** Last update Sun Jun  7 21:00:40 2015 yanis breton
*/

#include <stdlib.h>
#include "rt.h"
#include "obj.h"
#include "utils.h"

int		is_comment(char *line)
{
  int	i;

  i = 0;
  while (line[i] && line[i] == ' ' && line[i] == '\t' )
    i++;
  if (line[i] == '#')
    return (1);
  else
    return (0);
}

int		valid_float(char *nb)
{
  int		i;
  int		boolVal;

  i = 0;
  boolVal = 0;
  while (nb[i])
    {
      if ((nb[i] < '0' && nb[i] != '.') || nb[i] > '9')
	return (0);
      if (nb[i] == '.')
	{
	  if (boolVal == 1)
	    return (0);
	  else
		  boolVal = 1;
	}
      i++;
    }
  return (1);
}

t_cam		*parse_cam(char **tab)
{
  t_cam     	*new_cam;

  new_cam = (t_cam *)xmalloc(sizeof(t_cam));
  new_cam->pos = (t_vector *)xmalloc(sizeof(t_vector));
  init_rot(&(new_cam->x), atof(tab[2]));
  init_rot(&(new_cam->y), atof(tab[3]));
  init_rot(&(new_cam->z), atof(tab[4]));
  new_cam->pos->x = atof(tab[5]);
  new_cam->pos->y = atof(tab[6]);
  new_cam->pos->z = atof(tab[7]);
  return (new_cam);
}

t_light		*parse_light(char **tab, t_rt *scene)
{
  t_light	*new_light;

  new_light = (t_light *)xmalloc(sizeof(t_light));
  init_color(&(new_light->color), atouc(tab[2]), atouc(tab[3]), atouc(tab[4]));
  init_vector(&(new_light->pos), atof(tab[5]), atof(tab[6]), atof(tab[7]));
  new_light->next = scene->light;
  return (new_light);
}

int		parse_special_obj(char **tab, t_obj *newObj)
{
	newObj->type_obj = MESH;
	newObj->intersection = &intersection_mesh;
  if ((newObj->elem = get_mesh(tab[14])) == NULL)
    return (1);
  return (0);
}
