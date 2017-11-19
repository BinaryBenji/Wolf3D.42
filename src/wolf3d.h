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
    double    draw_height;
    double    cam_WD;
    int   l;
    char 			rem;

    int 			help;
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

int   	usage(void);
void 	ft_map(t_e *e);
int  	exiterror(void);
int   	error(void);
void	store_tab(int fd, t_e *e);
int		key_pressed(int keycode, t_e *e);
int 	exit_cl(void);
int 	false_map(int fd, t_e *e);
void 	dda_2(t_e *e);
void 	dda_1(t_e *e);
void 	help(t_e *e);
void 	wall(t_e *e);
void 	inits(t_e *e);
void 	calc(t_e *e);
void 	draw_map(t_e *e);
int   hero_init(t_e *e);
void  pix_to_img(t_e *e);

#endif