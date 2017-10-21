#include "wolf3d.h"

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

	e->color = 0xddFF00;
	e->rotSpeed = 0.05;
	e->moveSpeed = 0.05;
	e->posX = 22;
	e->posY = 12;
	e->dirX = -1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = 0.66;
	e->time = 0;
	e->oldTime = 0;
	e->help = 1;
}


/*
**	Main
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
	ft_map(&e);
	return (0);
}