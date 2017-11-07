#include <math.h>
#include "rt.h"
#include "mlx_uses.h"

float		light_up_plan(t_rt *rt, t_obj *obj,
			      t_lvector *vec, t_light *light)
{
  float		scalaire;
  float		normal;
  float		normal_lum;
  float		cosa;

  rt->eye->x -= obj->pos.x;
  rt->eye->y -= obj->pos.y;
  rt->eye->z -= obj->pos.z;
  vec->px = (rt->eye->x) + obj->k * rt->vec->x;
  vec->py = (rt->eye->y) + obj->k * rt->vec->y;
  vec->pz = (rt->eye->z) + obj->k * rt->vec->z;
  vec->lx = light->pos.x - vec->px;
  vec->ly = light->pos.y - vec->py;
  vec->lz = light->pos.z - vec->pz;
  scalaire = (vec->lz * 100);
  normal = sqrt(pow(100, 2));
  normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  cosa = scalaire / (normal * normal_lum);
  rt->eye->x += obj->pos.x;
  rt->eye->y += obj->pos.y;
  rt->eye->z += obj->pos.z;
  return (cosa);
}

float		light_up_sphere(t_rt *rt, t_obj *obj,
				t_lvector *vec, t_light *light)
{
  double	scalaire;
  double	normal;
  double	normal_lum;
  float		cosa;

  rt->vec->x -= obj->pos.x;
  rt->vec->y -= obj->pos.y;
  rt->vec->z -= obj->pos.z;
  vec->px = (rt->eye->x) + obj->k * rt->vec->x;
  vec->py = (rt->eye->y) + obj->k * rt->vec->y;
  vec->pz = (rt->eye->z) + obj->k * rt->vec->z;
  vec->lx = light->pos.x - vec->px;
  vec->ly = light->pos.y - vec->py;
  vec->lz = light->pos.z - vec->pz;
  scalaire = (vec->px * vec->lx) + (vec->py * vec->ly) + (vec->pz * vec->lz);
  normal = sqrt(pow(vec->px, 2) + pow(vec->py, 2) + pow(vec->pz, 2));
  normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  cosa = scalaire / (normal * normal_lum);
  rt->vec->x += obj->pos.x;
  rt->vec->y += obj->pos.y;
  rt->vec->z += obj->pos.z;
  return (cosa);
}

double		light_up_cone(t_rt *rt, t_obj *obj,
			      t_lvector *vec, t_light *light)
{
  double	scalaire;
  double	normal;
  double	normal_lum;
  double	cosa;
  t_cone	*cone;
  t_vector	v;

  cone = (t_cone *)obj->elem;
  v.x = rt->vec->x - obj->pos.x;
  v.y = rt->vec->y - obj->pos.y;
  v.z = rt->vec->z - obj->pos.z;
  vec->px = rt->eye->x + obj->k * v.x;
  vec->py = rt->eye->y + obj->k * v.y;
  vec->pz = rt->eye->z + obj->k * v.z;
  vec->lx = light->pos.x - vec->px;
  vec->ly = light->pos.y - vec->py;
  vec->lz = light->pos.z - vec->pz;
  scalaire = (vec->px * vec->lx) + (vec->py * vec->ly)
    + ((vec->pz * -tan(cone->ray)) * vec->lz);
  normal = sqrt(pow(vec->px, 2) + pow(vec->py, 2)
		+ pow((vec->pz * -tan(cone->ray)), 2));
  normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  cosa = scalaire / (normal * normal_lum);
  return (cosa);
}

double		light_up_cylindre(t_rt *rt, t_obj *obj,
				  t_lvector *vec, t_light *light)
{
  double	scalaire;
  double	normal;
  double	normal_lum;
  double	cosa;

  rt->vec->x -= obj->pos.x;
  rt->vec->y -= obj->pos.y;
  rt->vec->z -= obj->pos.z;
  vec->px = rt->eye->x + obj->k * rt->vec->x;
  vec->py = rt->eye->y + obj->k * rt->vec->y;
  vec->pz = rt->eye->z + obj->k * rt->vec->z;
  vec->lx = light->pos.x - vec->px;
  vec->ly = light->pos.y - vec->py;
  vec->lz = light->pos.z - vec->pz;
  scalaire = (vec->px * vec->lx) + (vec->py * vec->ly);
  normal = sqrt(pow(vec->px, 2) + pow(vec->py, 2));
  normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  cosa = scalaire / (normal * normal_lum);
  rt->vec->x += obj->pos.x;
  rt->vec->y += obj->pos.y;
  rt->vec->z += obj->pos.z;
  return (cosa);
}

float		light_up_mesh(t_rt *rt, t_obj *obj,
			      t_lvector *vec, t_light *light)
{
  float		scalaire;
  float		normal;
  float		normal_lum;
  float		cosa;

  vec->px = rt->eye->x + obj->k * rt->vec->x;
  vec->py = rt->eye->y + obj->k * rt->vec->y;
  vec->pz = rt->eye->z + obj->k * rt->vec->z;
  vec->lx = light->pos.x - vec->px;
  vec->ly = light->pos.y - vec->py;
  vec->lz = light->pos.z - vec->pz;
  scalaire = (obj->normal.x * vec->lx) + (obj->normal.y * vec->ly)
    + (obj->normal.z * vec->lz);
  normal = sqrt(pow(obj->normal.x, 2) + pow(obj->normal.y, 2)
		+ pow(obj->normal.z, 2));
  normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  cosa = scalaire / (normal * normal_lum);
  return (cosa);
}
