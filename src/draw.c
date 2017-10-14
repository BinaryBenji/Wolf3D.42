#include "wolf3d.h"

void 	draw_map(t_e *e)
{
	while (e->x < e->width)
	{
		e->cameraX = 2;
		e->rayPosX = e->posX;
		e->rayPosY = e->posY;
		e->rayDirX = e->dirX + e->planeX * e->cameraX;
		e->rayDirY = e->dirY + e->planeY * e->cameraX;

		e->mapX = (int)e->rayPosX;
		e->mapY = (int)e->rayPosY;

		e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
		e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));

		e->hit = 0;
		if (e->rayDirX < 0)
		{
			e->stepX = -1;
			e->sideDistX = (e->rayPosX - e->mapX) * e->deltaDistX;
		}
		else
		{
			e->stepX = -1;
			e->sideDistX = (e->mapX + 1.0 - e->rayPosX) * e->deltaDistX;
		}
		if (e->rayDirY < 0)
		{
			e->stepY = -1;
			e->sideDistY = (e->rayPosY - e->mapY) * e->deltaDistY;
		}
		else
		{
			e->stepY = 1;
			e->sideDistY = (e->mapY + 1.0 - e->rayPosY) * e->deltaDistY;
		}

		while (e->hit == 0)
		{
			if (e->sideDistX < e->sideDistY)
			{
				e->sideDistX += e->deltaDistX;
				e->mapX += e->stepX;
				e->side = 0;
			}
			else
			{
				e->sideDistY += e->deltaDistY;
				e->mapY += e->stepY;
				e->side = 1;
			}
			if (e->tab[e->mapX][e->mapY] > 0)
				e->hit = 1;
		}
		e->x++;
	}
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
}


void 	ray(t_e *e)
{
	e->imgstr = mlx_new_image(e->mlx, e->width, e->height);
	e->imgptr = mlx_get_data_addr(e->imgstr, &(e->bpp), &(e->s_l), &(e->endian));

}

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");
	//draw_map(e);
	ray(e);
	mlx_hook(e->win, 17, 0, exit_cl, NULL);
	mlx_key_hook(e->win, key_pressed, e);
	mlx_loop(e->mlx);
}