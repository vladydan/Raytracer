/*
** reflection.c for reflection in /home/danilo_d/semestre2/MUL_2014_rtracer
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Fri May 29 14:32:18 2015 danilov dimitri
** Last update Sun Jun  7 19:02:25 2015 danilov dimitri
*/

#include <stdlib.h>
#include <math.h>
#include "rt.h"
#include "light.h"
#include "obj.h"
#include "mlx_uses.h"

t_color		transparence(t_rt *rt, t_obj *obj, t_color tmp_color)
{
  static int	number_loop;
  t_obj		*new_obj;
  t_color	color;

  if (++number_loop == 2)
    {
      number_loop = 0;
      return (tmp_color);
    }
  color.r = 0;
  color.g = 0;
  color.b = 0;
  if ((new_obj = find_nearest_obj(rt->obj, rt->eye, rt->vec, obj)))
    color = calculate_light(rt, new_obj);
  return (color);
}
