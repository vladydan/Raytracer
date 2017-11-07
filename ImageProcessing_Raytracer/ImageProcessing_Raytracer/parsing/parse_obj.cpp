#include <stdlib.h>
#include "rt.h"
#include "obj.h"
#include "parsing.h"
#include "utils.h"

static void    	parse_sphere(char **tab, t_obj *new_sphere)
{
	new_sphere->type_obj = SPHERE;
	new_sphere->elem = xmalloc(sizeof(t_sphere));
	new_sphere->calc_delta = &delta_sphere;
	new_sphere->intersection = &intersection;
  ((t_sphere *)new_sphere->elem)->radius = atof(tab[14]);
}

static void    	parse_plan(t_obj *new_plan)
{
	new_plan->type_obj = PLAN;
	new_plan->calc_delta = NULL;
	new_plan->intersection = &intersection_plan;
	new_plan->elem = NULL;
}

static void    	parse_cylinder(char **tab, t_obj *new_cylinder)
{
	new_cylinder->type_obj = CYLINDRE;
	new_cylinder->elem = (t_cone *)xmalloc(sizeof(t_cone));
	new_cylinder->calc_delta = &delta_cylindre;
	new_cylinder->intersection = &intersection;
  ((t_cone *)new_cylinder->elem)->inf = 1;
  ((t_cone *)new_cylinder->elem)->h_min = -100;
  ((t_cone *)new_cylinder->elem)->h_max = 100;
  ((t_cone *)new_cylinder->elem)->ray = atof(tab[14]);
}

static void   	parse_cone(char **tab, t_obj *new_cone)
{
	new_cone->type_obj = CONE;
	new_cone->elem = (t_cone *)xmalloc(sizeof(t_cone));
	new_cone->calc_delta = &delta_cone;
	new_cone->intersection = &intersection;
  ((t_cone *)new_cone->elem)->inf = 1;
  ((t_cone *)new_cone->elem)->h_min = -100;
  ((t_cone *)new_cone->elem)->h_max = 100;
  ((t_cone *)new_cone->elem)->ray = deg_to_rad(atof(tab[14]));
}

t_obj		*parse_obj(char **tab, t_rt *scene)
{
  t_obj		*new_obj;

  new_obj = (t_obj *) xmalloc(sizeof(t_obj));
  init_color(&(new_obj->color), atouc(tab[2]), atouc(tab[3]), atouc(tab[4]));
  new_obj->shine = atof(tab[5]);
  new_obj->reflection = atof(tab[6]);
  new_obj->transparency = atof(tab[7]);
  init_rot(&(new_obj->rot_x), atof(tab[8]));
  init_rot(&(new_obj->rot_y), atof(tab[9]));
  init_rot(&(new_obj->rot_z), atof(tab[10]));
  init_vector(&(new_obj->pos), atof(tab[11]), atof(tab[12]), atof(tab[13]));
  if (my_strcmp(tab[1], SPHERE_PARSE))
    parse_sphere(tab, new_obj);
  else if (my_strcmp(tab[1], PLAN_PARSE))
    parse_plan(new_obj);
  else if (my_strcmp(tab[1], CYLINDER_PARSE))
    parse_cylinder(tab, new_obj);
  else if  (my_strcmp(tab[1], CONE_PARSE))
    parse_cone(tab, new_obj);
  else if (my_strcmp(tab[1], SPECIAL_OBJ_PARSE))
    if (parse_special_obj(tab, new_obj))
      exit(1);
  new_obj->texture = NULL;
  new_obj->next = scene->obj;
  return (new_obj);
}
