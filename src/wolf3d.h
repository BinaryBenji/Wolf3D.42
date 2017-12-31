#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"

# define RED 0xAF1822
# define GREEN 0x64AD6A
# define BLUE 0x3BBDED

typedef struct 		s_e
{
	void 			*mlx;
	void 			*win;
	void			*imgptr;
	char 			*imgstr;
	int 			endian;
	int 			s_l;
	int 			bpp;


  void  *imgptr_grass;
  char  *imgstr_grass;

	int				width;
	int 			height;
	double 			posX;
	double 			posY;
  	double 			dirX;
  	double 			dirY; 
  	double 			planeX;
  	double			planeY;

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
    double 			rotSpeed;
    double 			moveSpeed;
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


      int lol;

      int tap_sprint;
      int tap_up;
      int tap_down;
      int tap_left;
      int tap_right;
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
int 	draw_map(t_e *e);
int   hero_init(t_e *e);
void  pix_to_img(t_e *e, int color);
int   border_check(t_e *e);
void  win_inits(t_e *e);
void  renew_image(t_e *e);
int   wheel(t_e *e);
int   strike(int keycode, t_e *e);
int   release(int keycode, t_e *e);

void  key_up(t_e *e);
void  key_down(t_e *e) ;
void  key_left(t_e *e) ;
void  key_right(t_e *e) ;
void  key_sprint(t_e *e);


#endif