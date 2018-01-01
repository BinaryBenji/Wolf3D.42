#include "wolf3d.h"

/*
** "Wheel" represents all the hooks managing of the game
**	And also the execution of the display.
*/

int 	wheel(t_e *e)
{
	renew_image(e);
	if (e->tap_up == 1)
		key_up(e);
	if (e->tap_down == 1)
		key_down(e);
	if (e->tap_left == 1)
		key_left(e);
	if (e->tap_right == 1)
		key_right(e);
	if (e->tap_sprint == 1)
		key_sprint(e);
	else
	{
		e->moveSpeed = 0.03;
		e->rotSpeed = 0.03;
	}
	if ((e->tap_sprint_double == 1) && (e->tap_sprint == 1)) 
		key_sprint_double(e);
	if (e->tap_reinit == 1)
		key_reinit(e);
	draw_map(e);
	return (0);
}

/*
**	Gives hero position according to the 'X' position
**	of the given map.
**	Also gives Speeds of the rotations & movement.
*/

int 	hero_init(t_e *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= e->south)
	{
		while (i <= e->east)
		{
			if (e->tab[j][i] == 'X')
			{
				e->posX = j;
				e->posY = i;
				e->dirX = 1;
				e->dirY = 0;
				e->rotSpeed = 0.03;
				e->moveSpeed = 0.03;
				//printf("Your hero is sitting at : %lf - %lf \n", e->posX, e->posY);
				return (0);
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (-1);
}


/*
**	Initialize basic parameters
*/

void	init_map(t_e *e)
{
	e->xchecker = 0;
	e->south = 0;
	e->previous = 0;
	e->i = 0;
	e->width = 1200;
	e->height = 600;
	e->x = 0;
	e->color = 0x512F0D;
	e->posX = 1;
	e->posY = 1;
	e->planeX = 0;
	e->planeY = -0.9; // change
	//ft_putstr("Passed the init of map.\n");
}

/*
**	Inits the window.
*/

void 	win_inits(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");
	e->imgptr = mlx_new_image(e->mlx, e->width, e->height);
	e->imgstr = mlx_get_data_addr(e->imgptr, &(e->bpp), &(e->s_l), &(e->endian));


	// to try
	//e->imgptr_grass = mlx_xpm_file_to_image(e->mlx, "textures/grass.xpm", &(e->width), &(e->height));
	//e->imgstr_grass = mlx_get_data_addr(e->imgptr_grass, &(e->bpp), &(e->s_l), &(e->endian));
}

/*
**	Main : checks validity of the map.
**	Then go to map
*/

int 	main(int argc, char **argv)
{
	t_e e;
	int fd;

	fd = 0;
	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	init_map(&e);
	if (false_map(fd, &e) != 1)
		return (exiterror());
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	store_tab(fd, &e);
	if (hero_init(&e) == -1)
		return (error());
	win_inits(&e);
	mlx_hook(e.win, 2, 1L<<0, strike, &e);
	mlx_hook(e.win, 3, 1L<<1, release, &e);
	mlx_hook(e.win, 17, 0, exit_cl, NULL);
	mlx_loop_hook(e.mlx, wheel, &e);
	mlx_loop(e.mlx);
	return (0);
}