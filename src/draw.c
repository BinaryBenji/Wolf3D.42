/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:49:13 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:50:29 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Fill pixels to the img :
**	For each pixels on the vertical (height)
**	We give attribute a color to a pixel.
*/

void	fill_img_vertical(t_e *e)
{
	e->l = 0;
	while (e->l < e->height)
	{
		if (e->l < e->draw_start)
			pix_to_img(e, 0xd4cbe5);
		else if (e->l >= e->draw_start && e->l <= e->draw_end)
			pix_to_img(e, e->color);
		else
		{
			if (e->hit == 1)
				pix_to_img(e, 0x317b22);
		}
		e->l++;
	}
}

/*
**	Destroys the previous image and create another one.
*/

void	renew_image(t_e *e)
{
	mlx_destroy_image(e->mlx, e->imgptr);
	e->imgptr = mlx_new_image(e->mlx, e->width, e->height);
}

/*
**	Gives to a wall a color, according to the orientation.
*/

void	color_wall(t_e *e)
{
	if (e->side == 0)
	{
		if (e->step_x < 0)
			e->color = 0x78bc61;
		else
			e->color = 0xdce2c8;
	}
	else
	{
		if (e->step_y > 0)
			e->color = 0x4f6d7a;
		else
			e->color = 0xe9806e;
	}
}

/*
**	Executes DDA algorithm, then builds the image
** 	Then finally put it into the screen.
*/

int		draw_map(t_e *e)
{
	e->x = 0;
	while (e->x < e->width)
	{
		inits(e);
		dda_1(e);
		dda_2(e);
		wall(e);
		color_wall(e);
		fill_img_vertical(e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->imgptr, 0, 0);
	help(e);
	return (0);
}

/*
**	Attributes a color to a given pixel.
*/

void	pix_to_img(t_e *e, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = e->x * (e->bpp / 8) + e->l * (e->s_l);
	while (i < (e->bpp / 8))
	{
		e->imgstr[p + i] = color;
		color >>= 8;
		i++;
	}
}
