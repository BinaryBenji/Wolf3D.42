/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:01:16 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 14:24:42 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct		s_e
{
	void			*mlx;
	void			*win;
	void			*imgptr;
	char			*imgstr;
	int				endian;
	int				s_l;
	int				bpp;
	int				width;
	int				height;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	double			rot_speed;
	double			move_speed;
	double			draw_height;
	double			cam_wall;
	int				l;
	int				x;
	int				color;
	char			**tab;
	int				east;
	int				k;
	unsigned int	previous;
	int				south;
	int				xchecker;
	int				i;
	int				bou;
	int				tap_sprint;
	int				tap_up;
	int				tap_down;
	int				tap_left;
	int				tap_right;
	int				tap_reinit;
}					t_e;

int					usage(void);
void				ft_map(t_e *e);
int					exiterror(void);
int					error(void);
void				store_tab(int fd, t_e *e);
int					key_pressed(int keycode, t_e *e);
int					exit_cl();
int					false_map(int fd, t_e *e);
void				dda_2(t_e *e);
void				dda_1(t_e *e);
void				help(t_e *e);
void				wall(t_e *e);
void				inits(t_e *e);
void				calc(t_e *e);
int					draw_map(t_e *e);
void				init_map(t_e *e);
int					hero_init(t_e *e);
void				pix_to_img(t_e *e, int color);
int					border_check(t_e *e);
void				win_inits(t_e *e);
void				renew_image(t_e *e);
int					wheel(t_e *e);
int					strike(int keycode, t_e *e);
int					release(int keycode, t_e *e);
void				key_up(t_e *e);
void				key_down(t_e *e);
void				key_left(t_e *e);
void				key_right(t_e *e);
void				key_sprint(t_e *e);
void				key_reinit(t_e *e);

#endif
