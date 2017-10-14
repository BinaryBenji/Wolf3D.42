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
}


int 	usage(void)
{
	ft_putstr_fd("usage: ./wolf3d [map] \n", 2);
	return (-1);
}