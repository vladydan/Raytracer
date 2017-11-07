#include <math.h>
#include "rt.h"
#include "obj.h"
#include "light.h"

void	find_normal(t_vector *normal, t_lvector *vec, t_obj *obj)
{
  if (obj->type_obj == PLAN)
    normal_plan(normal);
  else if (obj->type_obj == SPHERE)
    normal_sphere(normal, vec);
  else if (obj->type_obj == CONE)
    normal_cone(normal, vec, obj);
  else if (obj->type_obj == CYLINDRE)
    normal_cylindre(normal, vec);
}

void	normal_plan(t_vector *normal)
{
  normal->x = 0;
  normal->y = 0;
  normal->z = 100;
}

void	normal_sphere(t_vector *normal, t_lvector *vec)
{
  normal->x = vec->px;
  normal->y = vec->py;
  normal->z = vec->pz;
}

void	normal_cylindre(t_vector *normal, t_lvector *vec)
{
  normal->x = vec->px;
  normal->y = vec->py;
  normal->z = 0;
}

void		normal_cone(t_vector *normal, t_lvector *vec, t_obj *obj)
{
  t_cone	*cone;

  cone = (t_cone *)obj->elem;
  normal->x = vec->px;
  normal->y = vec->py;
  normal->z = vec->pz * -tan(cone->ray);
}
