/*
** obj.h for rtracer in /home/bauer_a/rendu/MUL_2014_rtracer
**
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
**
** Started on  Thu May  7 14:18:08 2015 Hugo Bauer
** Last update Sun Jun  7 20:34:35 2015 yanis breton
*/

#ifndef OBJ_H_
# define OBJ_H_

# include "utils.h"
# include "mlx_uses.h"

# define SPHERE		0
# define PLAN		1
# define CYLINDRE	2
# define CONE		3
# define MESH		4

typedef struct		s_delta t_delta;
typedef struct		s_obj t_obj;
typedef struct		s_sphere t_sphere;
typedef struct		s_cone t_cone;

struct			s_delta
{
  float			a;
  float			b;
  float			c;
  float			delta;
};

struct			s_obj
{
  void			*elem;
  void			(*calc_delta)(t_delta *, t_obj *,
				      t_vector *, t_vector *);
  float			(*intersection)(t_obj *, t_vector *,
					t_vector *);
  float			k;
  char			type_obj;
  t_vector		pos;
  t_vector	        normal;
  t_rot			rot_x;
  t_rot			rot_y;
  t_rot			rot_z;
  t_color		color;
  float			reflection;
  float			shine;
  float			transparency;
  t_img			*texture;
  t_obj			*next;
};

struct			s_sphere
{
  float			radius;
  float			r_max;
};

struct			s_cone
{
  int			inf;
  float			h_min;
  float			h_max;
  float			ray;
};

typedef struct		s_face
{
  int			p1;
  int			p2;
  int			p3;
  float			d;
  t_vector		normal;
}			t_face;

typedef struct		s_mesh
{
  t_vector		*vertice;
  t_vector		*normal;
  t_face		*face;
  int			count_vert;
  int			count_normal;
  int			count_face;
}			t_mesh;

void			delta_sphere(t_delta *delta, t_obj *obj,
				     t_vector *pos_eye, t_vector *vec_eye);
void			delta_cone(t_delta *delta, t_obj *obj,
				   t_vector *pos_eye, t_vector *vec_eye);
void			delta_cylindre(t_delta *delta, t_obj *obj,
				       t_vector *pos_eye, t_vector *vec_eye);
float			intersection_plan(t_obj *obj, t_vector *pos_eye,
					  t_vector *vec_eye);
float			intersection(t_obj *obj, t_vector *, t_vector *);
t_vector		*make_trans(t_obj *obj, t_vector *vec, t_vector *pos);
void			calc_texture(t_obj *obj, int x, int y);
int			inter_ok(t_delta *delta, t_obj *obj,
				 t_vector *vec_eye, t_cone *cone);
float			intersection_mesh(t_obj *obj, t_vector *pos_eye,
					  t_vector *vec_eye);
t_mesh			*get_mesh(char *file);
void			free_tab(char **tab);
int			count_obj(int fd, int *vert, int *face, int *normal);
int			get_vertice(t_mesh *mesh, char *line, int i);
int			get_normal(t_mesh *mesh, char *line, int i);
int			to_normal(char *str);

#endif /* !OBJ_H_ */
