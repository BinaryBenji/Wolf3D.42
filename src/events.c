/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:50:00 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:58:53 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	UP key move
*/

void	key_up(t_e *e)
{
	if (e->tab[(int)(e->pos_x + e->dir_x * e->move_speed)]
		[(int)(e->pos_y)] != 49)
		e->pos_x += e->dir_x * e->move_speed;
	if (e->tab[(int)(e->pos_x)]
		[(int)(e->pos_y + e->dir_y * e->move_speed)] != 49)
		e->pos_y += e->dir_y * e->move_speed;
}

/*
**	DOWN key move
*/

void	key_down(t_e *e)
{
	if (e->tab[(int)(e->pos_x - e->dir_x * e->move_speed)]
		[(int)(e->pos_y)] != 49)
		e->pos_x -= e->dir_x * e->move_speed;
	if (e->tab[(int)(e->pos_x)]
		[(int)(e->pos_y - e->dir_y * e->move_speed)] != 49)
		e->pos_y -= e->dir_y * e->move_speed;
}

/*
**	LEFT key move
*/

void	key_left(t_e *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->rot_speed) - e->dir_y * sin(e->rot_speed);
	e->dir_y = e->old_dir_x * sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(e->rot_speed)
		- e->plane_y * sin(e->rot_speed);
	e->plane_y = e->old_plane_x * sin(e->rot_speed)
		+ e->plane_y * cos(e->rot_speed);
}

/*
**	RIGHT key move
*/

void	key_right(t_e *e)
{
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->rot_speed * -1)
		- e->dir_y * sin(e->rot_speed * -1);
	e->dir_y = e->old_dir_x * sin(e->rot_speed * -1)
		+ e->dir_y * cos(e->rot_speed * -1);
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(e->rot_speed * -1)
		- e->plane_y * sin(e->rot_speed * -1);
	e->plane_y = e->old_plane_x * sin(e->rot_speed * -1)
		+ e->plane_y * cos(e->rot_speed * -1);
}

/*
**	Put the hero back to the 'X' spawn.
*/

void	key_reinit(t_e *e)
{
	hero_init(e);
	e->plane_x = 0;
	e->plane_y = -0.9;
}
