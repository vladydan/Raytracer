#include "include/mlx_uses.h"

static void	fill_load(t_mlx *param, int step, t_color *col)
{
  int		w;
  int		h;


  // TODO Chargement
//  w = step;
//  while (w < step + 1)
//    {
//      h = 0;
//      while (h < param->load.y - 1)
//	{
////	  put_pixel(&param->load, w, h, gere_endian(&param->load, col));
//	  h++;
//	}
//      w++;
//    }
}

void		display_load_bar(t_mlx *param, int cur_nb_pix, int w)
{
  t_color	col;
  char		*display;
  int		step;
  int		h;

  //if ((w % (W_WIDTH / 100)) != 0)
  //  return ;
  //init_color(&col, 255, 255, 255);
  //display = xmalloc(my_strlen(LOADING_MSG) + 1);
  //my_strcpy(display, LOADING_MSG);
  //mlx_string_put(param->mlx_ptr, param->win_ptr, param->width / 3,
		// 3 * (param->height / 4), 0xFFFFFF, display);
  //step = 100 * cur_nb_pix / (param->width * param->height);
  //fill_load(param, step, &col);
  //h = 0;
  //while (h < param->load.y - 1)
  //  {
  //    put_pixel(&param->load, param->load.x - 1, h,
		//gere_endian(&param->load, &col));
  //    h++;
  //  }
  //mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->load.img_ptr,
		//	  param->width / 3 + 150, 3 * (param->height / 4) - 10);
}
