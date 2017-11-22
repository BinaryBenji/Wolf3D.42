#include "wolf3d.h"


void 	fill_img(t_e *e)
{
	e->l = 0;

	while (e->l < e->height)
	{
		pix_to_img(e);
		e->l++;
	}
}


void 	draw_map(t_e *e)
{
	e->imgptr = mlx_new_image(e->mlx, e->width, e->height);
	e->imgstr = mlx_get_data_addr(e->imgptr, &(e->bpp), &(e->s_l), &(e->endian));
	e->x = 0;
	while (e->x < e->width)
	{
		inits(e);
		dda_1(e);
		dda_2(e);
		calc(e);
		wall(e);
		e->draw_height = fabs(e->height / e->cam_WD);
		if ((e->drawStart = -(e->draw_height) / e->draw_height + e->height) < 0)
			e->drawStart = 0;
		if ((e->drawEnd = e->draw_height / 2 + e->height / 2) >= e->height)
			e->drawEnd = e->height - 1;
		fill_img(e);

		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
	mlx_hook(e->win, 17, 0, exit_cl, NULL);
	mlx_key_hook(e->win, key_pressed, e);
	mlx_loop(e->mlx);
}


void 	calc(t_e *e)
{
	if (e->side == 0)
		e->perpWallDist = (e->mapX - e->rayPosX + (1 + e->stepX) / 2) / e->rayDirX;
	else
		e->perpWallDist = (e->mapY - e->rayPosY + (1 + e->stepY) / 2) / e->rayDirY;
	e->lineHeight = (int)(e->height / e->perpWallDist);
	e->drawStart = -(e->lineHeight) / 2 + e->height / 2;
	if (e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineHeight / 2 + e->height / 2;
	if (e->drawEnd >= e->height)
		e->drawEnd = e->height - 1;
	if (e->side == 1)
		e->color = e->color / 2;
}


void 	pix_to_img(t_e *e)
{
	int i;
	int p;

	i = 0;
	p = e->x * (e->bpp / 8) + e->l * (e->s_l);
	while (i < (e->bpp / 8))
	{
		e->imgstr[p + i] = e->color;
		e->color >>=8;
		i++;
	}
}






