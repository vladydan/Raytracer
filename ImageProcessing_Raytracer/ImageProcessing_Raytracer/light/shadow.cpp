#include	<math.h>
#include	"rt.h"
#include	"obj.h"
#include	"light.h"
#include	"utils.h"

int		type_shadow(t_obj *tmp, t_lvector *vec)
{
  if (tmp->type_obj == SPHERE && shadow_sphere(vec, tmp) == 1)
    return (1);
  if (tmp->type_obj == CONE && shadow_cone(vec, tmp) == 1)
    return (1);
  if (tmp->type_obj == CYLINDRE && shadow_cylindre(vec, tmp) == 1)
    return (1);
  if (tmp->type_obj == MESH)
    return (0);
  return (-1);
}

int		calc_delta(float delta, float a, float b)
{
  float		k;
  float		k2;

  if (delta >= 0)
    {
      k = (-b - sqrt(delta)) / (2 * a);
      k2 = (-b - sqrt(delta)) / (2.0f * a);
      if (k < 0)
	k = k2;
      if (k > 0 && k2 > 0)
	k = (k > k2) ? k2 : k;
      if (k > 0.0001 && k < 1.001)
	return (1);
    }
  return (0);
}

int		shadow_sphere(t_lvector *vec, t_obj *obj)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  t_sphere	*sphere;

  sphere = (t_sphere *)obj->elem;
  a = pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2);
  b = 2 * ((vec->px * vec->lx) + (vec->py * vec->ly) + (vec->pz * vec->lz));
  c = pow(vec->px, 2) + pow(vec->py, 2) + pow(vec->pz, 2)
    - pow(sphere->radius, 2);
  delta = pow(b, 2) - 4 * a * c;
  if (calc_delta(delta, a, b) == 1)
    return (1);
  return (0);
}

int		shadow_cylindre(t_lvector *vec, t_obj *obj)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  t_cone	*cyl;

  cyl =(t_cone *) obj->elem;
  a = pow(vec->lx, 2) + pow(vec->ly, 2);
  b = (2 * vec->px * vec->lx) + (2 * vec->py * vec->ly);
  c = pow(vec->px, 2) + pow(vec->py, 2) - pow(cyl->ray, 2);
  delta = pow(b, 2) - 4 * a * c;
  if (calc_delta(delta, a, b) == 1)
    return (1);
  return (0);
}

int		shadow_cone(t_lvector *vec, t_obj *obj)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  t_cone	*cone;

  cone = (t_cone *)obj->elem;
  a = pow(vec->lx, 2.0f) + pow(vec->ly, 2.0f)
    - (pow(vec->lz, 2.0f) * pow(tan(cone->ray), 2.0f));
  b = 2 * ((vec->px * vec->lx) + (vec->py * vec->ly)
		  - (vec->pz * vec->lz * pow(tan(cone->ray), 2.0f)));
  c = pow(vec->px, 2.0f) + pow(vec->py, 2.0f)
    - (pow(vec->pz, 2.0f) * pow(tan(cone->ray), 2.0f));
  delta = pow(b, 2) - 4 * a * c;
  if (calc_delta(delta, a, b) == 1)
    return (1);
  return (0);
}
