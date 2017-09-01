#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
// #include "mlx.h"


typedef struct 		s_e
{
	// void 			*mlx;
	// void 			*win;
	// int				width;
	// int 			height;
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
      int   sidelen;
      int   ok;
      int	xchecker;
}			   		t_e;

int   usage(void);
int   exiterror(void);
int   error(void);


#endif