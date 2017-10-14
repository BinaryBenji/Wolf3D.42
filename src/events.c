#include "wolf3d.h"



int	key_up(int keycode, t_e *e) // 
{
	if (keycode == 122)
	{
		if (e->tab[(int)(e->posX + e->dirX * e->moveSpeed)]
			[(int)(e->posY)] == 0)
				e->posX += e->dirX * e->moveSpeed;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY + e->dirY * e->moveSpeed)] == 0)
				e->posY += e->dirY * e->moveSpeed;
	}
	return (0);
}

int	key_down(int keycode, t_e *e)
{
	if (keycode == 115)
	{
		if (e->tab[(int)(e->posX - e->dirX * e->moveSpeed)]
			[(int)(e->posY)] == 0)
				e->posX -= e->dirX * e->moveSpeed;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY - e->dirY * e->moveSpeed)] == 0)
				e->posY -= e->dirY * e->moveSpeed;
	}
	return (0);
}

int	key_left(int keycode, t_e *e)
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

int	key_right(int keycode, t_e *e)
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



int	key_pressed(int keycode, t_e *e)
{
	if (keycode == 65307) // Echap
		exit(0);
	printf("Keycode : %d\n",keycode);
	e->ok = 2;
	key_up(keycode, e);
	key_down(keycode, e);
	key_left(keycode, e);
	key_right(keycode, e);

	return (0);
}