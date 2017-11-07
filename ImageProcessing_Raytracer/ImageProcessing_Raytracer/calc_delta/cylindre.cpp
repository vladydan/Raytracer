#include <math.h>
#include "obj.h"

void		delta_cylindre(t_delta *delta, t_obj *obj,
			       t_vector *pos_eye, t_vector *vec_eye)
{
  t_cone	*cylindre;

  cylindre = (t_cone *)obj->elem;
  delta->a = pow(vec_eye->x, 2.0f) + pow(vec_eye->y, 2.0f);
  delta->b = 2 * ((pos_eye->x * vec_eye->x) + (pos_eye->y * vec_eye->y));
  delta->c = pow(pos_eye->x, 2.0f) + pow(pos_eye->y, 2.0f)
    - pow(cylindre->ray, 2);
  delta->delta = pow(delta->b, 2) - (4 * delta->a * delta->c);
  if (!inter_ok(delta, obj, vec_eye, cylindre))
    delta->delta = -1;
}
