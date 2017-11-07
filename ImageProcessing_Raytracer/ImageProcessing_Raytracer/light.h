/*
** light.h for light in /home/danilo_d/semestre2/MUL_2014_rtracer
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Thu May 28 19:24:58 2015 danilov dimitri
** Last update Sun Jun  7 21:48:16 2015 Hugo Bauer
*/

#ifndef LIGHT_H_
# define LIGHT_H_

#include "rt.h"
#include "obj.h"

float		light_up_plan(t_rt *rt, t_obj *obj,
				t_lvector *vec, t_light *light);
float		light_up_sphere(t_rt *rt, t_obj *obj, t_lvector *vec,
				  t_light *light);
double		light_up_cone(t_rt *rt, t_obj *obj,
				t_lvector *vec, t_light *light);
double		light_up_cylindre(t_rt *rt, t_obj *obj,
				    t_lvector *vec, t_light *light);
float		light_up_mesh(t_rt *rt, t_obj *obj,
				    t_lvector *vec, t_light *light);

int		shadow_sphere(t_lvector *vec, t_obj *obj);
int		shadow_cylindre(t_lvector *vec, t_obj *obj);
int		shadow_cone(t_lvector *vec, t_obj *obj);
int		light_list_size(t_light *light);
t_color		transparence(t_rt *rt, t_obj *obj, t_color);
void		normal_plan(t_vector *normal);
void		normal_sphere(t_vector *normal, t_lvector *vec);
void		normal_cylindre(t_vector *normal, t_lvector *vec);
void		normal_cone(t_vector *normal, t_lvector *vec, t_obj *);
void		find_normal(t_vector *normal, t_lvector *vec, t_obj *obj);
int		type_shadow(t_obj *tmp, t_lvector *vec);

#endif /* !LIGHT_H_ */
