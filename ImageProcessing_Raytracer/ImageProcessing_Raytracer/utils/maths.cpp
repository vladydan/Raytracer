#include <math.h>
#include "utils.h"

float	deg_to_rad(float deg)
{
  return ((deg * M_PI) / 180.0f);
}

void	        normalize(t_vector *vec)
{
  float		norme;

  norme = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
  vec->x /= norme;
  vec->y /= norme;
  vec->z /= norme;
}
