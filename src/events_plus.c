/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:50:12 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:55:40 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	SPRINT (SHIFT) key move
*/

void	key_sprint(t_e *e)
{
	e->rot_speed = 0.06;
	e->move_speed = 0.06;
}

/*
**	Strike : when a key is pushed, status of the key is 1.
**	FOR AZERTY / LINUX : up = 122 / down = 115 / left = 113 / right = 100
**	shift = 65505 / i = 105 / echap = 65307
**	FOR QWERTY / MACOS : up = 13 / down = 1 / left = 0 / right = 2
**	shift = 257 / i = 13 / echap = 53
*/

int		strike(int keycode, t_e *e)
{
	if (keycode == 53)
		exit_cl(e);
	if (keycode == 13)
		e->tap_up = 1;
	if (keycode == 1)
		e->tap_down = 1;
	if (keycode == 0)
		e->tap_left = 1;
	if (keycode == 2)
		e->tap_right = 1;
	if (keycode == 257)
		e->tap_sprint = 1;
	if (keycode == 34)
		e->tap_reinit = 1;
	return (0);
}

/*
**	Release : when a key is released, status of the key is 0.
*/

int		release(int keycode, t_e *e)
{
	if (keycode == 13)
		e->tap_up = 0;
	if (keycode == 1)
		e->tap_down = 0;
	if (keycode == 0)
		e->tap_left = 0;
	if (keycode == 2)
		e->tap_right = 0;
	if (keycode == 257)
		e->tap_sprint = 0;
	if (keycode == 34)
		e->tap_reinit = 0;
	return (0);
}
