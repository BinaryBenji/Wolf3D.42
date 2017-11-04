#include "wolf3d.h"


void 	inits(t_e *e)
{
	e->cameraX = 2;
	e->rayPosX = e->posX;
	e->rayPosY = e->posY;
	e->rayDirX = e->dirX + e->planeX * e->cameraX;
	e->rayDirY = e->dirY + e->planeY * e->cameraX;
	e->mapX = (int)e->rayPosX;
	e->mapY = (int)e->rayPosY;
	e->hit = 0;
}


void 	dda_1(t_e *e)
{
	e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
	e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->rayPosX - e->mapX) * e->deltaDistX;
	}
	else
	{
		e->stepX = -1;
		e->sideDistX = (e->mapX + 1 - e->rayPosX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->rayPosY - e->mapY) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = (e->mapY + 1 - e->rayPosY) * e->deltaDistY;
	}
}

void 	dda_2(t_e *e)
{
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
}