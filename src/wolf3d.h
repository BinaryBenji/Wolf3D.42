#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"


typedef struct 		s_e
{
	void 			*mlx;
	void 			*win;
	void			*imgptr;
	char 			*imgstr;
	int 			endian;
	int 			s_l;
	int 			bpp;

	int				width;
	int 			height;
	double 			posX;
	double 			posY;
  	double 			dirX;
  	double 			dirY; 
  	double 			planeX;
  	double			planeY;
  	double 			time;
  	double 			oldTime;

  	double			cameraX;
  	double 			rayPosX;
  	double			rayPosY;
  	double 			rayDirX;
  	double 			rayDirY;
  	double 			sideDistX;
    double 			sideDistY;
    double 			deltaDistX;
    double 			deltaDistY;
    int 			stepX;
    int 			stepY;
    int 			hit;
    int 			side;
    int 			mapX;
    int				mapY;
    int 			perpWallDist;
    int				lineHeight;
    int 			drawStart;
    int 			drawEnd;
    double 			oldDirX;
    double 			oldPlaneX;
    int 			rotSpeed;
    int 			moveSpeed;

    int x;
    int 			color;
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
int	key_pressed(int keycode, t_e *e);
int 	exit_cl(void);


#endif