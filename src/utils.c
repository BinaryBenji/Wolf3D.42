/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:51:01 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:52:17 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

int		exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int		exit_cl(void)
{
	exit(0);
	return (0);
}

/*
**	Message when invalid parameters
*/

int		usage(void)
{
	ft_putstr_fd("usage: ./wolf3d [map] \n", 2);
	return (-1);
}

/*
**	Graphical help menu
*/

void	help(t_e *e)
{
	mlx_string_put(e->mlx, e->win, 1025, 10, 0x000000, "Keys :");
	mlx_string_put(e->mlx, e->win, 1025, 30, 0x000000, "WASD to move");
	mlx_string_put(e->mlx, e->win, 1025, 50, 0x000000, "SHIFT to sprint");
	mlx_string_put(e->mlx, e->win, 1025, 70, 0x000000, "I to respawn");
	mlx_string_put(e->mlx, e->win, 1025, 90, 0x000000, "ECHAP to quit");
}
