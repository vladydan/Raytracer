#include <stdlib.h>
#include <time.h>
#include "include/rt.h"
#include "include/obj.h"
#include "include/mlx_uses.h"
#include "include/utils.h"

t_obj		*find_nearest_obj(t_obj *obj, t_vector *pos_eye,
	t_vector *vec_eye, t_obj *actual)
{
	t_obj		*buff;
	float		k;
	float		k_buff;

	k = -1;
	buff = NULL;
	while (obj)
	{
		k_buff = obj->intersection(obj, pos_eye, vec_eye);
		if (k_buff > 0 && (k < 0 || k_buff < k) && actual != obj)
		{
			k = k_buff;
			buff = obj;
			buff->k = k;
		}
		obj = obj->next;
	}
	if (k < 0)
		return (NULL);
	return (buff);
}

static void	calc(t_rt *rt, t_mlx *param, int w, int h)
{
	t_obj		*buff;
	t_color	tmp;

	init_vector(rt->vec, 100, (param->width / 2) - w,
		(param->height / 2) - h);
	rotation(AXE_X, rt->cam->x.cos, rt->cam->x.sin, rt->vec);
	rotation(AXE_Y, rt->cam->y.cos, rt->cam->y.sin, rt->vec);
	rotation(AXE_Z, rt->cam->z.cos, rt->cam->z.sin, rt->vec);
	rt->eye = rt->cam->pos;
	buff = find_nearest_obj(rt->obj, rt->cam->pos, rt->vec, NULL);
	if (buff != NULL && rt->obj->texture != NULL)
		calc_texture(rt->obj, w, h);
	if (buff != NULL)
	{
		tmp = calculate_light(rt, buff);
		param->image.setPixel(w, h, sf::Color(tmp.r, tmp.g, tmp.b));
		//  put_pixel(&param->img, w, h, );
	}
	else
		param->image.setPixel(w, h, sf::Color(0, 0, 0));
	//    put_pixel(&param->img, w, h, 0);

}

int		calc_loop(t_rt *rt, t_mlx *param)
{
	int		w;
	int		h;

	w = 0;
	rt->vec = (t_vector *)xmalloc(sizeof(t_vector));
	while (w < param->width)
	{
		h = 0;
		while (h < param->height)
		{
			calc(rt, param, w, h);
			h += 1;
		}
		//display_load_bar(param, h * w, w);
		w += 1;
	}
	return (0);
}
