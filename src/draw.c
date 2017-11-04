#include "wolf3d.h"

void 	draw_map(t_e *e)
{
	e->imgptr = mlx_new_image(e->mlx, e->width, e->height);
	e->imgstr = mlx_get_data_addr(e->imgptr, &(e->bpp), &(e->s_l), &(e->endian));
	while (e->x < e->width)
	{
		inits(e);
		dda_1(e);
		dda_2(e);
		calc(e);
		wall(e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
	//mlx_destroy_image(e->mlx, e->imgstr);
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

	void *lol;

	lol = &e->color;
	//if (e->mapX < e->width && e->mapY < e->height)
		ft_memmove(e->imgstr + 4 * e->width * e->mapY + 
			e->mapX * 4, &lol, sizeof(int));
}


void 	wall(t_e *e)
{
	ft_putnbr(e->drawStart);
	ft_putchar('-');
	ft_putnbr(e->drawEnd);
	ft_putchar('\n');
	while (e->drawStart <= e->drawEnd)
	{
		pix_to_img(e);
		e->drawStart++;
	}
}



