#include <stdlib.h>
#include "rt.h"
#include "light.h"
#include "obj.h"
#include "mlx_uses.h"
#include "utils.h"

int		apply_shadow(t_lvector *vec, t_obj *obj, t_rt *rt,
			     t_light *light)
{
  t_obj		*tmp;
  t_vector	v;
  int		ret;

  tmp = rt->obj;
  while (tmp)
    {
      v.x = rt->vec->x - tmp->pos.x;
      v.y = rt->vec->y - tmp->pos.y;
      v.z = rt->vec->z - tmp->pos.z;
      vec->px = rt->eye->x + obj->k * v.x;
      vec->py = rt->eye->y + obj->k * v.y;
      vec->pz = rt->eye->z + obj->k * v.z;
      vec->lx = light->pos.x - vec->px;
      vec->ly = light->pos.y - vec->py;
      vec->lz = light->pos.z - vec->pz;
      if ((ret = type_shadow(tmp, vec)) != -1)
	return (ret);
      tmp = tmp->next;
    }
  return (0);
}

float		calcule_cosa(t_rt *rt, t_obj *obj, t_light *light,
			     t_lvector *vector)
{
  float		cosa;

  cosa = 0;
  if (obj->type_obj == SPHERE)
    cosa = light_up_sphere(rt, obj, vector, light);
  else if (obj->type_obj == PLAN)
    cosa = light_up_plan(rt, obj, vector, light);
  else if (obj->type_obj == CONE)
    cosa = light_up_cone(rt, obj, vector, light);
  else if (obj->type_obj == CYLINDRE)
    cosa = light_up_cylindre(rt, obj, vector, light);
  else if (obj->type_obj == MESH)
    cosa = light_up_mesh(rt, obj, vector, light);
  if (cosa < 0.00001f)
    return (0);
  else if (apply_shadow(vector, obj, rt, light) == 1)
    return (0);
  return (cosa);
}

t_color		find_average_color(float *arr, int size, t_obj *obj,
				   t_light *light)
{
  int		i;
  int		tmp_color[3];
  t_color	new_color;

  tmp_color[0] = 0;
  tmp_color[1] = 0;
  tmp_color[2] = 0;
  i = -1;
  while (++i != size)
    {
      tmp_color[0] += arr[i] * obj->color.r;
      tmp_color[0] += obj->shine * light->color.r * arr[i];
      tmp_color[1] += arr[i] * obj->color.g;
      tmp_color[1] += obj->shine * light->color.g * arr[i];
      tmp_color[2] += arr[i] * obj->color.b;
      tmp_color[2] += obj->shine * light->color.b * arr[i];
      light = light->next;
    }
  new_color.r = tmp_color[0] / size;
  new_color.g = tmp_color[1] / size;
  new_color.b = tmp_color[2] / size;
  color_overflow(&new_color, tmp_color, size);
  return (new_color);
}

t_color		combine_color(t_color reflechi, t_color object, float mult)
{
  t_color	new_color;

  new_color.r = reflechi.r * mult + object.r * (1 - mult);
  new_color.g = reflechi.g * mult + object.g * (1 - mult);
  new_color.b = reflechi.b * mult + object.b * (1 - mult);
  return (new_color);
}

t_color		calculate_light(t_rt *rt, t_obj *obj)
{
  float		*array_cosa;
  t_light	*tmp;
  int		i;
  t_color	tmp_color;
  t_lvector	vector;

  tmp = rt->light;
  i = 0;
  array_cosa = (float *)xmalloc(sizeof(float) * light_list_size(rt->light));
  while (tmp != NULL)
    {
      array_cosa[i] = calcule_cosa(rt, obj, tmp, &vector);
      tmp = tmp->next;
      i++;
    }
  tmp_color.r = 0;
  tmp_color.g = 0;
  tmp_color.b = 0;
  if (i == 0)
    return (tmp_color);
  tmp_color = find_average_color(array_cosa, i, obj, rt->light);
  if (obj->type_obj != PLAN)
    tmp_color = combine_color(transparence(rt, obj, tmp_color),
			      tmp_color, obj->transparency);
  return (tmp_color);
}
