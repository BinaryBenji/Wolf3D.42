#include "wolf3d.h"


void 	inits(t_e *e)
{
	e->cameraX = 2 * e->x / (double)e->width - 1;
	e->rayPosX = e->posX;
	e->rayPosY = e->posY;
	e->rayDirX = e->dirX + e->planeX * e->cameraX;
	e->rayDirY = e->dirY + e->planeY * e->cameraX;
	e->mapX = (int)e->rayPosX;
	e->mapY = (int)e->rayPosY;
	e->hit = 0;
	e->side = 0; //changes
}


void 	dda_1(t_e *e)
{
	e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
	e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->rayPosX - (double)e->mapX) * e->deltaDistX; // add double each
	}
	else
	{
		e->stepX = 1;
		e->sideDistX = ((double)e->mapX + 1.0 - e->rayPosX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->rayPosY - (double)e->mapY) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = ((double)e->mapY + 1.0 - e->rayPosY) * e->deltaDistY;
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
		
		if ((e->tab[e->mapX][e->mapY] == 49))
			//printf("Map : %c\n = true", e->tab[e->mapX][e->mapY]);
			e->hit = 1;
			// printf("Map : %c\n = false", e->tab[e->mapX][e->mapY]);
	}
}


/*
**	Moves the camera according to the distance between 
**		the wall and the camera.
**	Blocks the camera in front of the wall if too close.
*/

void 	wall(t_e *e)
{
	// dist non redeclare

	if (e->side == 0)
		e->cam_WD = fabs((e->mapX - e->rayPosX + 
			(1 - e->stepX) / 2) / e->rayDirX);
	else
		e->cam_WD = fabs((e->mapY - e->rayPosY + 
			(1 - e->stepY) / 2) / e->rayDirY);
	if (e->cam_WD <= 0.05)
		e->cam_WD = 0.05;   // ADD Or NOt


	// MISS or not

	// e->draw_height = abs(e->height / e->cam_WD);
	// if ((e->drawStart = (-1 * (e->draw_height)) / e->draw_height + e->height) < 0)
	// 	e->drawStart = 0;
	// if ((e->drawEnd = e->draw_height / 2 + e->height / 2) >= e->height)
	// 	e->drawEnd = e->height - 1;



	e->lineHeight = abs((int)(e->height / e->cam_WD));
	e->drawStart = (-1 * (e->lineHeight)) / 2 + e->height / 2;
	if (e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineHeight / 2 + e->height / 2;
	if (e->drawEnd >= e->height)
		e->drawEnd = e->height - 1;
}