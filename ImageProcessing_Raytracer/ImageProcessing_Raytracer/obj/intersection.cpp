#include <math.h>
#include "obj.h"

float		intersection_plan(t_obj *obj, t_vector *pos_eye,
				  t_vector *vec_eye)
{
  float		k;

  pos_eye->z -= obj->pos.z;
  if (pos_eye->z == obj->pos.z || vec_eye->z == 0)
    k = -1;
  else
    k = -pos_eye->z / vec_eye->z;
  pos_eye->z += obj->pos.z;
  return (k);
}

float		intersection(t_obj *obj, t_vector *pos_eye,
			     t_vector *vec_eye)
{
  float		k;
  float		k2;
  t_delta	delta;
  t_vector	pos;

  init_vector(&pos, pos_eye->x, pos_eye->y, pos_eye->z);
  vec_eye = make_trans(obj, vec_eye, &pos);
  obj->calc_delta(&delta, obj, &pos, vec_eye);
  if (delta.delta >= 0)
    {
      k = (-delta.b + sqrt(delta.delta)) / (2.0f * delta.a);
      k2 = (-delta.b - sqrt(delta.delta)) / (2.0f * delta.a);
      if (k < 0)
	k = k2;
      if (k > 0 && k2 > 0)
	k = (k > k2) ? k2 : k;
    }
  else if (delta.delta == 0)
    k = (-delta.b) / (2.0f * delta.a);
  else
    k = -1;
  obj->k = k;
  return (k);
}
