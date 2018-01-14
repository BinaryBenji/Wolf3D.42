/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:49:32 by bzmuda            #+#    #+#             */
/*   Updated: 2018/01/02 12:42:57 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	A line is "ok" if it contains only digits and only one X for one map.
*/

int		is_line_ok(char *line, t_e *e)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '0') || (line[i] == 'X') || (line[i] == '1'))
		{
			if (line[i] == 'X')
				e->xchecker++;
			if (e->xchecker > 1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	free(line);
	return (1);
}

/*
**	Checks if every line have same length : only quadrangle are allowed.
**	A map with x < 2 or y < 2 are forbidden
**	Then check content of each line.
*/

int		check(int fd, t_e *e)
{
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (is_line_ok(line, e) == 0)
			return (-1);
		if (e->south == 0)
			e->previous = ft_strlen(line);
		else
		{
			if (e->previous != ft_strlen(line))
				return (-1);
			e->previous = ft_strlen(line);
		}
		e->south++;
	}
	free(line);
	e->east = e->previous - 1;
	e->south--;
	if (e->xchecker != 1)
		return (-1);
	if (e->south < 2 || e->east < 2)
		return (-1);
	return (1);
}

/*
**	Return cases for false map
*/

int		false_map(int fd, t_e *e)
{
	if (check(fd, e) == -1)
		return (-1);
	return (1);
}
