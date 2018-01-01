#include "wolf3d.h"

int 	error(void)
{
	ft_putstr_fd("error\n", 1);
	return(-1);
}

int 	exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int 	exit_cl(void)
{
	exit(0);
	return (0);
}


/*
**	Message when invalid parameters
*/

int 	usage(void)
{
	ft_putstr_fd("usage: ./wolf3d [map] \n", 2);
	return (-1);
}

/*
**	Graphical help menu
*/

void 	help(t_e *e)
{
	mlx_string_put(e->mlx, e->win, 1100, 20, 0x0a122a, "Keys :");
	mlx_string_put(e->mlx, e->win, 1100, 40, 0x0a122a, "WASD to move");
	mlx_string_put(e->mlx, e->win, 1100, 60, 0x0a122a, "SHIFT to sprint");	
	mlx_string_put(e->mlx, e->win, 1100, 80, 0x0a122a, "I to respawn");	
	mlx_string_put(e->mlx, e->win, 1100, 100, 0x0a122a, "ECHAP to quit");	
}