#include "wolf3d.h"


/*
**	Fill pixels to the img : 
**	For each pixels on the vertical 
**	We give attribute a color
*/

void 	fill_img(t_e *e)
{
	e->l = 0;
	while (e->l < e->height)
	{
		if (e->l < e->drawStart)
			pix_to_img(e, RED);
		else if (e->l > e->drawEnd)
			pix_to_img(e, BLUE);
		else
		{
			if (e->hit == 1)
				pix_to_img(e, GREEN);
		}
		e->l++;
	}
}


void 	draw_map(t_e *e)
{
	e->x = 0;
	// e->x = 0;
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
	mlx_key_hook(e->win, key_pressed, e);
	mlx_hook(e->win, 17, 0, exit_cl, NULL);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
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


void 	pix_to_img(t_e *e, int color)
{
	int i;
	unsigned int p;

	i = 0;
	p = e->x * (e->bpp / 8) + e->l * (e->s_l);
	
	while (i < (e->bpp / 8))
	{
		e->imgstr[p + i] = color;
		color >>= 8;
		i++;
	}
}






