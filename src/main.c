#include "wolf3d.h"

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53) // quit
		exit(0);
	if (keycode == 123)
	{
		double oldDirX;
		double oldPlaneX;

		oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-rotSpeed) - e->dirY * sin(-rotSpeed);
		e->dirY = oldDirX * sin(-rotSpeed) + e->dirY * cos(-rotSpeed);
		oldPlaneX = ->planeX;
		e->planeX = e->planeX * cos(-rotSpeed) - e->planeY * sin(-rotSpeed);
	    e->planeY = oldPlaneX * sin(-rotSpeed) + e->planeY * cos(-rotSpeed);	
	}
	if (keycode == 124)
	{
		double oldDirX;
		double oldPlaneX;

		oldDirX = e->dirX;
      	e->dirX = e->dirX * cos(rotSpeed) - e->dirY * sin(rotSpeed);
      	e->dirY = oldDirX * sin(rotSpeed) + e->dirY * cos(rotSpeed);
      	oldPlaneX = e->planeX;
      	e->planeX = e->planeX * cos(rotSpeed) - e->planeY * sin(rotSpeed);
      	e->planeY = oldPlaneX * sin(rotSpeed) + e->planeY * cos(rotSpeed);
	}
	return (0);
}

void 	draw(t_e *e)
{
	printf("lol");
}

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D");
	draw(e);
	mlx_key_hook(e->win, key_pressed, e);
	mlx_loop(e->mlx);
}

t_e		init_map(t_e *e)
{
	e->color = 0;
	e->width = 1000;
	e->height = 1000;
	e->posX = 22;
	e->posY = 12;  
  	e->dirX = -1;
  	e->dirY = 0; 
  	e->planeX = 0;
  	e->planeY = 0.66;
  	e->time = 0;
  	e->oldTime = 0;
  	e->x = 0;
  	e->y = 0;
	return (*e);
}

int 	main()
{
	t_e e;

	init_map(&e);
	ft_map(&e);
	return (0);
}