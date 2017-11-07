#include "mlx_uses.h"
#include "obj.h"

void	calc_texture(t_obj *obj, int x, int y)
{
  int   coord_x;
  int   coord_y;
  int	j;

  coord_x = x * obj->texture->x / W_WIDTH;
  coord_y = y * obj->texture->y / W_HEIGHT;
  j = (obj->texture->size_line * coord_y)
    + (coord_x * (obj->texture->bpp / 8));
  obj->color.r = obj->texture->pixels[j];
  obj->color.g = obj->texture->pixels[j + 1];
  obj->color.b = obj->texture->pixels[j + 2];
}
