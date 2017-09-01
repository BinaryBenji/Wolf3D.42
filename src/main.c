#include "wolf3d.h"

/*
**	Initialize basic parameters
*/

void	init_map(t_e *e)
{
	// if (!(e->tab= (char **)malloc(sizeof(char*) * )))
	e->xchecker = 0;
	e->south = 0;
	e->previous = 0;
}

/*
**	A line is "ok" if it contains only digits and only one X for one map.
*/

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

/*
**	Checks if every line have same length : only quadrangle are allowed.
**	Then check content of each line.
*/

int 	check(int fd, t_e *e)
{
	char 			*line;
	
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (is_line_ok(line, e) == 0)
			return (-1);
		if (e->south == 0)
			e->previous = ft_strlen(line);
		else
		{
			if (e->previous != ft_strlen(line))
				return (-1);
			e->previous = ft_strlen(line);
		}
		e->south++;
	}
	e->east = e->previous;
	if (e->xchecker != 1)
		return (-1);
	return (1);
}

/*
**	Return cases for false map
*/

int 	false_map(int fd, t_e *e)
{
	if (check(fd, e) == -1)
		return (-1);
	return (1);
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
	return (0);
}