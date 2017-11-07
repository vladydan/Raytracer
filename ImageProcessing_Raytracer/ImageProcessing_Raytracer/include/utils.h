/*
** utils.h for raytracer in /home/breton_y/MUL_2014_rtracer/include
**
** Made by yanis breton
** Login   <breton_y@epitech.net>
**
** Started on  Wed Mar 25 12:59:47 2015 yanis breton
** Last update Sun Jun  7 19:56:55 2015 yanis breton
*/

#ifndef UTILS_H_
# define UTILS_H_

# define ESCAPE 65307
# define BUFF_SIZE 4096
# define NB_ERROR ("error: rgb colors have to be numbers between 0 and 255\n")
# define M_PI 3.14159265358979323846264338327

typedef struct		s_rot
{
  float			sin;
  float		        cos;
}			t_rot;

typedef	struct	s_vector
{
  float		x;
  float		y;
  float		z;
}		t_vector;

typedef union	s_rgb
{
  int		color;
  unsigned char	rgbtab[4];
}		t_rgb;

typedef struct	s_lvector
{
  float		px;
  float		py;
  float		pz;
  float		lx;
  float		ly;
  float		lz;
}		t_lvector;

typedef	struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
}		t_color;

unsigned char	atouc(char *str);
t_vector	*calc_vector(t_vector *, char op, t_vector *);
void		color_overflow(t_color *new_color, int tmp_color[3], int size);
char		*get_next_line(const int fd);
void		init_vector(t_vector *vec, float x, float y, float z);
void		init_color(t_color *col, unsigned char r,
			   unsigned char g, unsigned char b);
void		init_rot(t_rot *rot, float angle);
float		deg_to_rad(float deg);
int		my_fputs(int fd, char *msg, int value);
char		*my_mod_strdup(char *dest, char *src);
void		my_strcat(char *dest, char *str);
int		my_strcmp(char *str_1, char *str_2);
void		my_strcpy(char *dest, char *str);
int		my_strlen(char *str);
char		*my_strndup(char *str, int len);
char		*my_str_realloc(char *dest, char *src);
int		strlcpy(char *dst, char *src, int size);
char		**str_to_wordtab(char *str);
void		rotation(int axe, float cosa, float sina, t_vector *vec);
void		*xmalloc(int nbr);
void	        normalize(t_vector *vec);

#endif /* !UTILS_H_ */
