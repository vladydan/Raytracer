#include <math.h>
#include "obj.h"

int		inter_ok(t_delta *delta, t_obj *obj,
			 t_vector *vec_eye, t_cone *cone)
{
  float		k;
  float		k2;

  if (delta->delta > 0)
    {
      if (cone->inf)
	return (1);
      k = (-delta->b + sqrt(delta->delta)) / (2.0f * delta->a);
      k2 = (-delta->b - sqrt(delta->delta)) / (2.0f * delta->a);
      if (k < 0)
	k = k2;
      if (k > 0 && k2 > 0)
	k = (k > k2) ? k2 : k;
      if (k * vec_eye->z > obj->pos.z + cone->h_max ||
	  k * vec_eye->z < obj->pos.z + cone->h_min)
	return (0);
      return (1);
    }
  return (0);
}

void		delta_cone(t_delta *delta, t_obj *obj,
			     t_vector *pos_eye, t_vector *vec_eye)
{
  t_cone	*cone;

  cone = (t_cone *)obj->elem;
  delta->a = pow(vec_eye->x, 2.0f) + pow(vec_eye->y, 2.0f)
    - (pow(vec_eye->z, 2.0f) * pow(tan(cone->ray), 2.0f));
  delta->b = 2 * ((pos_eye->x * vec_eye->x) + (pos_eye->y * vec_eye->y)
		  - (pos_eye->z * vec_eye->z * pow(tan(cone->ray), 2.0f)));
  delta->c = pow(pos_eye->x, 2.0f) + pow(pos_eye->y, 2.0f)
    - (pow(pos_eye->z, 2.0f) * pow(tan(cone->ray), 2.0f));
  delta->delta = pow(delta->b, 2) - (4 * delta->a * delta->c);
  if (!inter_ok(delta, obj, vec_eye, cone))
    delta->delta = -1;
}
