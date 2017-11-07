
#ifndef MLX_USES_H_
# define MLX_USES_H_

# include <SFML\Graphics.hpp>
# include "utils.h"

# define W_WIDTH 800
# define W_HEIGHT 800
# define AXE_X ((int)1)
# define AXE_Y ((int)2)
# define AXE_Z ((int)3)
# define LOADING_MSG "CHARGEMENT DE L IMAGE :  "

/* Error Messages */
# define MLX_INIT_ERROR ("error : mlx_init failed !\n")
# define MLX_NW_WIN_ERROR ("error : mlx_new_window failed !\n")
# define MLX_NW_IMG_ERROR ("error : mlx_new_image failed !\n")
# define MLX_GET_DATA_ERROR ("error : mlx_get_data_addr failed !\n")

typedef struct	s_img
{
  void		*mlx_ptr;
  void		*img_ptr;
  int		bpp;
  int		size_line;
  int		endian;
  char		*pixels;
  int		x;
  int		y;
}		t_img;

typedef struct	s_mlx
{
	sf::Image	image;
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}		t_mlx;

unsigned int	gere_endian(t_img *, t_color *);
int		gere_key(int keycode, t_mlx *param);
int		gere_expose(t_mlx *param);
void		display_load_bar(t_mlx *param, int cur_nb_pix, int w);

#endif /* !MLX_USES_H_ */
