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
	int				color;
}			   		t_e;


#endif