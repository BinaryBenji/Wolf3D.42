/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:49:47 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:46:39 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Inits a ray, starting to the player's position to a wall of the map.
*/

void	inits(t_e *e)
{
	e->camera = 2 * e->x / (double)e->width - 1;
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + e->plane_x * e->camera;
	e->ray_dir_y = e->dir_y + e->plane_y * e->camera;
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->hit = 0;
	e->side = 0;
	e->delta_dist_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) /
		(e->ray_dir_x * e->ray_dir_x));
	e->delta_dist_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) /
		(e->ray_dir_y * e->ray_dir_y));
}

/*
**	Gives direction of a ray according to the move.
*/

void	dda_1(t_e *e)
{
	if (e->ray_dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray_pos_x - (double)e->map_x) * e->delta_dist_x;
	}
	else
	{
		e->step_x = 1;
		e->side_dist_x = ((double)e->map_x + 1.0
			- e->ray_pos_x) * e->delta_dist_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray_pos_y - (double)e->map_y) * e->delta_dist_y;
	}
	else
	{
		e->step_y = 1;
		e->side_dist_y = ((double)e->map_y + 1.0
			- e->ray_pos_y) * e->delta_dist_y;
	}
}

/*
**	Detects if the ray should go further :
**	if a wall has been detected : then the ray should stop progressing.
**	While there are no wall, make the ray progress.
*/

void	dda_2(t_e *e)
{
	while (e->hit == 0)
	{
		if (e->side_dist_x < e->side_dist_y)
		{
			e->side_dist_x += e->delta_dist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->side_dist_y += e->delta_dist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->tab[e->map_x][e->map_y] == 49)
			e->hit = 1;
	}
}

/*
**	Moves the camera according to the distance between
**	the wall and the camera.
**	Blocks the camera in front of the wall if too close.
*/

void	wall(t_e *e)
{
	if (e->side == 0)
		e->cam_wall = fabs((e->map_x - e->ray_pos_x +
			(1 - e->step_x) / 2) / e->ray_dir_x);
	else
		e->cam_wall = fabs((e->map_y - e->ray_pos_y +
			(1 - e->step_y) / 2) / e->ray_dir_y);
	if (e->cam_wall <= 0.05)
		e->cam_wall = 0.05;
	e->line_height = abs((int)(e->height / e->cam_wall));
	e->draw_start = (-1 * (e->line_height)) / 2 + e->height / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->line_height / 2 + e->height / 2;
	if (e->draw_end >= e->height)
		e->draw_end = e->height - 1;
}
