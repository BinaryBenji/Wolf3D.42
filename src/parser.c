#include "wolf3d.h"

/*
**	Store line by line chars in the map.
*/

void 	store_line_to_tab(t_e *e, char *line)
{
	if (!(e->tab[e->i] = (char *)malloc(sizeof(char) * e->east + 1)))
		exiterror();
	ft_strcpy(e->tab[e->i],line);
}

/*
**	Store all infos of the file, into a char map.
*/

void	store_tab(int fd, t_e *e)
{
	char *line;

	line = NULL;
	printf("east : %d\n", e->east);
	printf("south : %d\n", e->south);
	if (!(e->tab = (char **)malloc(sizeof(char *) * e->south)))
		exiterror();
	while ((get_next_line(fd, &line)) == 1)
	{
		store_line_to_tab(e, line);
		e->i++;
	}
	int g = 0;
	while (g <= e->south) 
	{
		printf("%s\n", e->tab[g]);
		g++;
	}
	if (border_check(e) == -1)
		exiterror();
}	

/*
**	Checks if the the quadragle is delimited byb 1's.
**	Returns an error if not.
*/

int		border_check(t_e *e)
{
	int i;

	i = 0;
	while (i <= e->east)
	{
		if (e->tab[0][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i <= (e->south - 1))
	{
		if (e->tab[i][0] != '1')
			return (-1);
		if (e->tab[i][e->east] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i <= e->east)
	{
		if (e->tab[e->south][i] != '1')
			return (-1);
		i++;
	}
	return (1);
}