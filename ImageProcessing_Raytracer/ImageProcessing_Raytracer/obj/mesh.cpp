#include <stdlib.h>
#include "obj.h"

float	cross_product(t_vector *v1, t_vector *v2)
{
  return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

void	calc_point(t_vector *point, t_vector *pos,
		   t_vector *vec, float t)
{
  point->x = pos->x + t * vec->x;
  point->y = pos->y + t * vec->y;
  point->z = pos->z + t * vec->z;
}

int		check_point(t_vector *a, t_vector *b, t_vector *p, t_vector *n)
{
  t_vector	v;

  v.x = (b->y - a->y) * (p->z - a->z) - (b->z - a->z) * (p->y - a->y);
  v.y = (b->z - a->z) * (p->x - a->x) - (b->x - a->x) * (p->z - a->z);
  v.z = (b->x - a->x) * (p->y - a->y) - (b->y - a->y) * (p->x - a->x);
  if (cross_product(&v, n) >= 0.0f)
    return (1);
  return (0);
}

float		face_intersection(t_face *face, t_vector *pos_eye,
				  t_vector *vec_eye, t_vector *vertice)
{
  float		t;
  t_vector	point;

  t = face->normal.x * vec_eye->x + face->normal.y * vec_eye->y
    + face->normal.z * vec_eye->z;
  if (t > -0.000001f && t < 0.000001f)
    return (-1.0f);
  t = -(face->d + face->normal.x * pos_eye->x + face->normal.y * pos_eye->y
	+ face->normal.z * pos_eye->z) / t;
  if (t < 0.00001f)
    return (-1.0f);
  calc_point(&point, pos_eye, vec_eye, t);
  if (check_point(vertice + face->p1, vertice + face->p2, &point,
		  &face->normal)
      && check_point(vertice + face->p2, vertice + face->p3,
		     &point, &face->normal)
      && check_point(vertice + face->p3, vertice + face->p1,
		     &point, &face->normal))
    return (t);
  return (-1.0f);
}

float		intersection_mesh(t_obj *obj, t_vector *pos_eye,
				  t_vector *vec_eye)
{
  t_mesh	*mesh;
  int		i;
  float		k;
  float		tmp;

  mesh = (t_mesh *)obj->elem;
  i = 0;
  k = -1.0f;
  while (i < mesh->count_face)
    {
      tmp = face_intersection(mesh->face + i, pos_eye, vec_eye, mesh->vertice);
      if (k < 0 || (tmp < k && tmp > 0))
	{
	  k = tmp;
	  obj->normal.x = mesh->face[i].normal.x;
	  obj->normal.y = mesh->face[i].normal.y;
	  obj->normal.z = mesh->face[i].normal.z;
	}
      i += 1;
    }
  return (k);
}
