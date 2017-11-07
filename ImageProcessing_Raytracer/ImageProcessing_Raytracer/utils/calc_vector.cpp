#include "mlx_uses.h"
#include "utils.h"

t_vector	*calc_vector(t_vector *v1, char op, t_vector *v2)
{
  t_vector	*new_vec;

  new_vec = (t_vector *)xmalloc(sizeof(t_vector));
  if (op == '+')
    {
	  new_vec->x = v1->x + v2->x;
	  new_vec->y = v1->y + v2->y;
	  new_vec->z = v1->z + v2->z;
    }
  else if (op == '-')
    {
	  new_vec->x = v1->x - v2->x;
	  new_vec->y = v1->y - v2->y;
	  new_vec->z = v1->z - v2->z;
    }
  return (new_vec);
}
