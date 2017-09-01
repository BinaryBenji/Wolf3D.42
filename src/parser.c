#include "wolf3d.h"

/*
**	Store all infos of the file.
*/


void	store_tab(int fd, t_e *e)
{
	

	//printf("line : %s\n", line);
	printf("fd : %d\n", fd);
	printf("east : %d\n", e->east);
	printf("south : %d\n", e->south);
	if (!(e->tab = (char **)malloc(sizeof(char*) * e->south)))
		exiterror();
}