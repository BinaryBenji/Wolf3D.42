#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"


typedef struct 		s_e
{
	void 			*mlx;
	void 			*win;
	int				width;
	int 			height;
	// int				color;
	// double 			posX;
	// double 			posY;  
 //  	double 			dirX;
 //  	double 			dirY; 
 //  	double 			planeX;
 //  	double			planeY;
 //  	double 			time;
 //  	double 			oldTime;
 //  	double 			sideDistX;
 //    double 			sideDistY;
 //    int 			stepX;
 //    int 			stepY;
      char  **tab;
      int   east;
      int   ok;
      unsigned int	previous;
      int 	south;
      int	xchecker;
      int	i;
}			   		t_e;

int   usage(void);
void ft_map(t_e *e);
int   exiterror(void);
int   error(void);
void	store_tab(int fd, t_e *e);


#endif