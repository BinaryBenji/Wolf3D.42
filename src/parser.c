#include "wolf3d.h"

/*
**	Store only one line to the tab.
*/

void 	store_line_to_tab(t_e *e, char *line)
{
	if (!(e->tab[e->i] = (char *)malloc(sizeof(char) * e->east)))
		exiterror();
	ft_strcpy(e->tab[e->i],line);
}

/*
**	Store all infos of the file.
*/

void	store_tab(int fd, t_e *e)
{
	char *line;

	line = NULL;
	printf("fd : %d\n", fd);
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
	while(g < e->south) 
	{
		printf("line : %s\n", e->tab[g]);
		g++;
	}
}	