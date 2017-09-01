#include "wolf3d.h"

// int 	key_pressed(int keycode, t_e *e)
// {
// 	if (keycode == 53) // quit
// 		exit(0);
// 	if (keycode == 123)
// 	{
// 		double oldDirX;
// 		double oldPlaneX;

// 		oldDirX = e->dirX;
// 		e->dirX = e->dirX * cos(-rotSpeed) - e->dirY * sin(-rotSpeed);
// 		e->dirY = oldDirX * sin(-rotSpeed) + e->dirY * cos(-rotSpeed);
// 		oldPlaneX = ->planeX;
// 		e->planeX = e->planeX * cos(-rotSpeed) - e->planeY * sin(-rotSpeed);
// 	    e->planeY = oldPlaneX * sin(-rotSpeed) + e->planeY * cos(-rotSpeed);	
// 	}
// 	if (keycode == 124)
// 	{
// 		double oldDirX;
// 		double oldPlaneX;

// 		oldDirX = e->dirX;
//       	e->dirX = e->dirX * cos(rotSpeed) - e->dirY * sin(rotSpeed);
//       	e->dirY = oldDirX * sin(rotSpeed) + e->dirY * cos(rotSpeed);
//       	oldPlaneX = e->planeX;
//       	e->planeX = e->planeX * cos(rotSpeed) - e->planeY * sin(rotSpeed);
//       	e->planeY = oldPlaneX * sin(rotSpeed) + e->planeY * cos(rotSpeed);
// 	}
// 	if (keycode == 126)
// 	{
// 		if(worldMap[int(e->posX + e->dirX * e->moveSpeed)]
// 			[int(e->posY)] == false) e->posX += e->dirX * e->moveSpeed;
//       	if(worldMap[int(e->posX)][int(e->posY + e->dirY * e->moveSpeed)] 
//       		== false) e->posY += e->dirY * e->moveSpeed;

// 	}
// 	if (keycode == 125)
// 	{
// 		if(worldMap[int(e->posX - e->dirX * e->moveSpeed)]
// 			[int(e->posY)] == false) e->posX -= e->dirX * e->moveSpeed;
//       	if(worldMap[int(e->posX)][int(e->posY - e->dirY * e->moveSpeed)]
//       		== false) e->posY -= e->dirY * e->moveSpeed;
// 	}
// 	draw(e);
// 	return (0);
// }

// void 	draw(t_e *e)
// {
// 	printf("lol");
// }

// void 	ft_map(t_e *e)
// {
// 	e->mlx = mlx_init();
// 	e->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D");
// 	draw(e);
// 	mlx_key_hook(e->win, key_pressed, e);
// 	mlx_loop(e->mlx);
// }

void	init_map(t_e *e)
{
	// e->color = 0;
	// e->width = 1000;
	// e->height = 1000;
	// e->posX = 22;
	// e->posY = 12;  
 //  	e->dirX = -1;
 //  	e->dirY = 0; 
 //  	e->planeX = 0;
 //  	e->planeY = 0.66;
 //  	e->time = 0;
 //  	e->oldTime = 0;
 //  	e->x = 0;
 //  	e->y = 0;
	e->xchecker = 0;
}


int 	is_line_ok(char *line, t_e *e)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((ft_isdigit(line[i]) > 0) || (line[i] == 'X'))
		{
			if (line[i] == 'X')
				e->xchecker++;
			if (e->xchecker > 1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int 	check_and_parse(int fd, t_e *e)
{
	char 			*line;
	unsigned int 	 i;
	unsigned int 	previous;
	
	i = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (is_line_ok(line, e) == 0)
			return (-1);
		if (i == 0)
			previous = ft_strlen(line);
		else
		{
			if (previous != ft_strlen(line))
				return (-1);
			previous = ft_strlen(line);
		}
		i++;
	}
	if (e->xchecker != 1)
		return (-1);
	return (1);
}



int 	false_map(int fd, t_e *e)
{
	if (check_and_parse(fd, e) == -1)
	{
		printf("ko map\n");
		return (-1);
	}
	else
		printf("ok map\n");
	e->ok= 1;
	return (1);
}

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
	// if (!(fd = open(argv[1], O_RDONLY)))
	// 	return (error());
	return (0);
}