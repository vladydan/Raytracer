/*
** put_pixel_image.c for put_pixe_image in /home/bauer_a/Igraph/fdf
**
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
**
** Started on  Wed Dec  3 18:33:54 2014 Hugo Bauer
** Last update Sun Jun  7 20:45:55 2015 Hugo Bauer
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "mlx_uses.h"
#include "utils.h"

unsigned int	gere_endian(t_img *img, t_color *color)
{
  unsigned int	int_color;

  int_color = 0;
  if (img->endian == 0)
    {
      int_color = (int_color << 8);
      int_color += color->r;
      int_color = (int_color << 8);
      int_color += color->g;
      int_color = (int_color << 8);
      int_color += color->b;
    }
  else
    {
      int_color = (int_color >> 8);
      int_color += color->b;
      int_color = (int_color >> 8);
      int_color += color->g;
      int_color = (int_color >> 8);
      int_color += color->r;
    }
  return (int_color);
}

int		put_pixel(t_img *img, int x, int y, unsigned int int_color)
{
  unsigned char	*color_octal;
  int		i;

  if (x >= img->x || y >= img->y || x < 0 || y < 0)
    return (1);
  i = ((y * img->size_line) + ((img->bpp / 8) * x));
  int_color = mlx_get_color_value(img->mlx_ptr, int_color);
  color_octal = (void *)&(int_color);
  img->pixels[i] = *(color_octal);
  img->pixels[i + 1] = *(color_octal + 1);
  img->pixels[i + 2] = *(color_octal + 2);
  img->pixels[i + 3] = *(color_octal + 3);
  return (0);
}
