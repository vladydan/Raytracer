#include "utils.h"

void	color_overflow(t_color *new_color, int tmp_color[3], int size)
{
  (void)size;
  if (tmp_color[0] / size > 255)
    new_color->r = 255;
  if (tmp_color[1] / size > 255)
    new_color->g = 255;
  if (tmp_color[2] / size > 255)
    new_color->b = 255;
}
