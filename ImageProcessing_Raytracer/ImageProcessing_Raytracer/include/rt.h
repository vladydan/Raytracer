/*
** rt.h for rtracer in /home/breton_y/MUL_2014_rtracer/include
**
** Made by yanis breton
** Login   <breton_y@epitech.net>
**
** Started on  Wed Mar 25 12:27:31 2015 yanis breton
** Last update Sun Jun  7 19:59:48 2015 yanis breton
*/

#ifndef RT_H_
# define RT_H_

# include <SFML\Graphics.hpp>
#include "mlx_uses.h"
#include "utils.h"
#include "obj.h"

typedef struct		s_light
{
  t_vector		pos;
  t_color		color;
  struct s_light	*next;
}			t_light;

typedef struct		s_cam
{
  t_vector		*pos;
  t_rot			x;
  t_rot			y;
  t_rot			z;
}			t_cam;

typedef struct		s_rt
{
  t_obj			*obj;
  t_light		*light;
  t_vector		*vec;
  t_vector		*eye;
  t_cam			*cam;
}			t_rt;

float		intersection(t_obj *obj, t_vector *pos_eye,
			     t_vector *vec_eye);
int		calc_loop(t_rt *rt, t_mlx *param);
t_color		calculate_light(t_rt *rt, t_obj *obj);
t_obj		*find_nearest_obj(t_obj *obj, t_vector *pos_eye,
				  t_vector *vec_eye, t_obj *);

#endif /* !RT_H_ */
