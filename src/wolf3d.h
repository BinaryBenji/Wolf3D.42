#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"

typedef struct 		s_env
{
	void 			*mlx;
	void 			*win;
	double			x1;
	double 			x2;
	double			y1;
	double			y2; 
	double			itmax; 
	double			zoom; 
	double			img_x;
	double			img_y;
	double			c_i;
	double			c_r;
	double			z_r;
	double			z_i;
	double			i;
}			   		t_env;

void 	draw(t_env env);
#endif