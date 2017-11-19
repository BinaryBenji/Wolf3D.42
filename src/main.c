#include "wolf3d.h"

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
	while (e->tab[j])
	{
		while (e->tab[j][i])
		{
			if (e->tab[j][i] == 'X')
			{
				e->posX = i;
				e->posY = j;
				e->dirX = -1;
				e->dirY = 0;
				e->rotSpeed = 0.05;
				e->moveSpeed = 0.05;
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
	e->width = 800;
	e->height = 400;
	e->x = 0;

	e->color = 0x512f0d;
	e->posX = 2;
	e->posY = 1;
	e->planeX = 0;
	e->planeY = 0.66;
	e->time = 0;
	e->oldTime = 0;
	e->help = 1;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");

	
	// e->posX = 1.5;
	// e->posY = 1.5;
	// e->dirX = 1;
	// e->dirY = 0;
	// e->planeX = 0;
	// e->planeY = -0.8;
	// e->moveSpeed = 1;
	// e->rotSpeed = 1;
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
	draw_map(&e);
	return (0);
}