#include <math.h>
#include "utils.h"

void		init_vector(t_vector *vec, float x, float y, float z)
{
  vec->x = x;
  vec->y = y;
  vec->z = z;
}

void		init_color(t_color *col, unsigned char r,
			   unsigned char g, unsigned char b)
{
  col->r = r;
  col->g = g;
  col->b = b;
}

void		init_rot(t_rot *rot, float angle)
{
  rot->cos = cos(deg_to_rad(angle));
  rot->sin = sin(deg_to_rad(angle));
}
