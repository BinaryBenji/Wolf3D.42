#include "wolf3d.h"

int	key_pressed(int keycode, t_e *e)
{
	if (keycode == 65307) // Echap
		exit(0);
	printf("Keycode : %d\n",keycode);
	e->ok = 2;
	return (0);
}


void ft_map(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");
	mlx_key_hook(e->win, key_pressed, e);
	mlx_loop(e->mlx);
}