/*
** parsing.h for raytracer in /home/bertra_w/rendu/Sem_2/Igraph/02_Raytracer/MUL_2014_rtracer
** 
** Made by antoine bertrand
** Login   <bertra_w@epitech.net>
** 
** Started on  Tue Jun  2 18:06:05 2015 antoine bertrand
** Last update Sun Jun  7 20:22:49 2015 Hugo Bauer
*/

#ifndef PARSING_H_
# define PARSING_H_

# include "rt.h"
# include "obj.h"

/*
** Error Messages
*/
# define USAGE ("Usage: ./rt [file]\n")
# define OPEN_FAILED ("error: open failed!\n")
# define NB_ERROR ("error: rgb colors have to be numbers between 0 and 255\n")
# define STR_WORDTAB_FAILED ("error: str_to_wordtab failed\n")

/*
** Objects
*/
# define SPHERE_PARSE ("SPHERE")
# define PLAN_PARSE ("PLAN")
# define CYLINDER_PARSE ("CYLINDER")
# define CONE_PARSE ("CONE")
# define EYE_PARSE ("EYE")
# define LIGHT_PARSE ("LIGHT")
# define SPECIAL_OBJ_PARSE ("OBJECT")

int		is_comment(char *line);
int		valid_float(char *nb);
t_obj		*parse_obj(char **tab, t_rt *scene);
t_light		*parse_light(char **tab, t_rt *scene);
t_cam		*parse_cam(char **tab);
int		parse_special_obj(char **tab, t_obj *);
void		describe_obj(t_obj *obj);
void		describe_scene(t_rt *scene);
int		check_line(char **);

#endif /* !PARSING_H_ */
