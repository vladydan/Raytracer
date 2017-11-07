#include "mlx_uses.h"

void	init_axe_x(t_vector mat[3], float cosa, float sina)
{
  init_vector(mat, 1, 0, 0);
  init_vector(mat + 1, 0, cosa, -sina);
  init_vector(mat + 2, 0, sina, cosa);
}

void	init_axe_y(t_vector mat[3], float cosa, float sina)
{
  init_vector(mat, cosa, 0, sina);
  init_vector(mat + 1, 0, 1, 0);
  init_vector(mat + 2, sina, 0, cosa);
}

void	init_axe_z(t_vector mat[3], float cosa, float sina)
{
  init_vector(mat, cosa, -sina, 0);
  init_vector(mat + 1, sina, cosa, 0);
  init_vector(mat + 2, 0, 0, 1);
}

void		mult_with_mat(t_vector mat[3], t_vector *vec)
{
  t_vector	newvec;

  newvec.x = mat[0].x * vec->x + mat[0].y * vec->y + mat[0].z * vec->z;
  newvec.y = mat[1].x * vec->x + mat[1].y * vec->y + mat[1].z * vec->z;
  newvec.z = mat[2].x * vec->x + mat[2].y * vec->y + mat[2].z * vec->z;
  init_vector(vec, newvec.x, newvec.y, newvec.z);
}

void	rotation(int axe, float cosa, float sina, t_vector *vec)
{
  t_vector	mat[3];

  if (axe == AXE_X)
    init_axe_x(mat, cosa, sina);
  else if (axe == AXE_Y)
    init_axe_y(mat, cosa, sina);
  else if (axe == AXE_Z)
    init_axe_z(mat, cosa, sina);
  mult_with_mat(mat, vec);
}
