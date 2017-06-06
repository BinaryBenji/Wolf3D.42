#include "wolf3d.h"

int 	key_pressed(int keycode, t_e *e)
{
	if (keycode == 53) // quit
		exit(0);
	e->color = e->color;
	return (0);
}

void 	ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D");
	mlx_key_hook(e->win, key_pressed, e);
	mlx_loop(e->mlx);
}

t_e		init_map(t_e *e)
{
	e->color = 0;
	e->width = 1000;
	e->height = 1000;
	return (*e);
}

int 	main ()
{
	t_e e;

	Playsound("../music/undercat.mp3",NULL,SND_ASYNC);
	//init_map(&e);
	//ft_map(&e);
	return (0);
}