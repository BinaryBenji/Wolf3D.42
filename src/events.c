#include "wolf3d.h"

/*
**	Key handler : 
** 	For AZERTY : UP = 122, DOWN = 115, LEFT = 113, RIGHT, 100
** 	For QWERTY : 
*/


/*
**	UP key move
*/

void	key_up(t_e *e) 
{
		if (e->tab[(int)(e->posX + e->dirX * e->moveSpeed)]
			[(int)(e->posY)] != 49)
				e->posX += e->dirX * e->moveSpeed;
			//e->posX = e->posX + 0.01;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY + e->dirY * e->moveSpeed)] != 49)
				e->posY += e->dirY * e->moveSpeed;
		// e->posX = e->posX + 0.01;
		// e->dirX = e->dirX + 0.01;
		// printf("posX = %g", e->posX);
		// printf("posY = %g", e->posY);

}

/*
**	DOWN key move
*/

void		key_down(t_e *e)
{
		if (e->tab[(int)(e->posX - e->dirX * e->moveSpeed)]
			[(int)(e->posY)] != 49)
				e->posX -= e->dirX * e->moveSpeed;
		if (e->tab[(int)(e->posX)]
			[(int)(e->posY - e->dirY * e->moveSpeed)] != 49)
				e->posY -= e->dirY * e->moveSpeed;
		//e->posX = e->posX - 0.01;
		// e->posX = e->posX - 0.01;
		// e->dirX = e->dirX - 0.01;
}

/*
**	LEFT key move
*/

void		key_left(t_e *e) // Left Rotation
{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed)- e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);

		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
		// e->dirY = e->dirY + 0.01;
}

/*
**	RIGHT key move
*/

void		key_right(t_e *e) // Right Rotation
{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed * -1) - e->dirY * sin(e->rotSpeed * -1);
		e->dirY = e->oldDirX * sin(e->rotSpeed * -1) + e->dirY * cos(e->rotSpeed * -1);

		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed * -1) - e->planeY * sin(e->rotSpeed * -1);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed * -1) + e->planeY * cos(e->rotSpeed * -1);
		//e->dirY = e->dirY - 0.01;
	//e->dirX = e->dirX + 0.01;
}




// int		key_pressed(int keycode, t_e *e)
// {
// 	if (keycode == 65307) // Echap
// 		exit(0);
// 	printf("Keycode : %d\n",keycode);
// 	e->ok = 2;
// 	e->ok = 3;
// 	key_up(e);
// 	key_down(keycode, e);
// 	key_left(keycode, e);
// 	key_right(keycode, e);
// 	if (keycode == 104 && e->help == 1)
// 	{
// 		help(e);
// 		e->help = 0;
// 	} 
// 	else if (keycode == 104 && e->help == 0) // H
// 	{
// 		mlx_clear_window(e->mlx, e->win);
// 		draw_map(e);
// 		e->help = 1;
// 	}
// 	return (0);
// }

/*
**	Put the hero back to the 'X' spawn.
*/

void 	key_reinit(t_e *e)
{
	hero_init(e);
	e->planeX = 0;
	e->planeY = -0.9;
}



