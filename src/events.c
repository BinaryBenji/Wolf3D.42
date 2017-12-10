#include "wolf3d.h"

/*
**	Key handler : 
** 	For AZERTY : UP = 122, DOWN = 115, LEFT = 113, RIGHT, 100
** 	For QWERTY : 
*/

int		key_up(int keycode, t_e *e) 
{
	if (keycode == 122)
	{
		if (e->tab[(int)(e->posX + e->dirX * e->moveSpeed)]
			[(int)(e->posY)] != '1')
				e->posX += e->dirX * e->moveSpeed;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY + e->dirY * e->moveSpeed)] != '1')
				e->posY += e->dirY * e->moveSpeed;
	}
	return (0);
}

int		key_down(int keycode, t_e *e)
{
	if (keycode == 115)
	{
		if (e->tab[(int)(e->posX - e->dirX * e->moveSpeed)]
			[(int)(e->posY)] != '1')
				e->posX -= e->dirX * e->moveSpeed;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY - e->dirY * e->moveSpeed)] != '1')
				e->posY -= e->dirY * e->moveSpeed;
	}
	return (0);
}

int		key_left(int keycode, t_e *e) // Left Rotation
{
	if (keycode == 113)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-(e->rotSpeed)) - e->dirY * sin(-(e->rotSpeed));
		e->dirY = e->oldDirX * sin(-(e->rotSpeed)) + e->dirY * cos(-(e->rotSpeed));
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-(e->rotSpeed)) - e->planeY * sin(-(e->rotSpeed));
		e->planeY = e->oldPlaneX * sin(-(e->rotSpeed)) + e->planeY * cos(-(e->rotSpeed));
	}
	return (0);
}

int		key_right(int keycode, t_e *e) // Right Rotation
{
	if (keycode == 100)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed) - e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
	}
	return (0);
}


int		key_pressed(int keycode, t_e *e)
{
	if (keycode == 65307) // Echap
		exit(0);
	printf("Keycode : %d\n",keycode);
	// e->ok = 2;
	key_up(keycode, e);
	key_down(keycode, e);
	key_left(keycode, e);
	key_right(keycode, e);
	// if (keycode == 104 && e->help == 1)
	// {
	// 	help(e);
	// 	e->help = 0;
	// } 
	// else if (keycode == 104 && e->help == 0) // H
	// {
	// 	mlx_clear_window(e->mlx, e->win);
	// 	draw_map(e);
	// 	e->help = 1;
	// }
	return (0);
}