#include "obj.h"
#include "mlx_uses.h"

t_vector	*make_trans(t_obj *obj, t_vector *vec, t_vector *pos)
{
  t_vector	v;

  vec = calc_vector(vec, '-', &(obj->pos));
  init_vector(&v, pos->x - obj->pos.x, pos->y - obj->pos.y,
	      pos->z - obj->pos.z);
  rotation(AXE_X, obj->rot_x.cos, obj->rot_x.sin, vec);
  rotation(AXE_Y, obj->rot_y.cos, obj->rot_y.sin, vec);
  rotation(AXE_Z, obj->rot_z.cos, obj->rot_z.sin, vec);
  rotation(AXE_X, obj->rot_x.cos, -(obj->rot_x.sin), &v);
  rotation(AXE_Y, obj->rot_y.cos, -(obj->rot_y.sin), &v);
  rotation(AXE_Z, obj->rot_z.cos, -(obj->rot_z.sin), &v);
  init_vector(pos, v.x + obj->pos.x, v.y + obj->pos.y,
	      v.z + obj->pos.z);
  return (vec);
}
