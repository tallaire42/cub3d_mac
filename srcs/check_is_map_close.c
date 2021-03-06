/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_map_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:41:50 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:42:47 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie que toutes les cases de la premiere et de la derniere colonne
** contiennent un 1.
*/

static		int		check_left_and_right(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		if (map[y][0] != '1')
			return (-1);
		while (map[y] && map[y][x + 1])
			++x;
		if (map[y][x] != '1')
			return (-1);
		++y;
	}
	return (1);
}

/*
** verifie qu une case contennant un 1 existe en dessous de la case verifiee.
*/

static		int		check_down(char **map, size_t y, size_t x)
{
	size_t	size;

	size = y;
	while (map[size + 1] && ft_strlen(map[size + 1]) > x &&
		map[size + 1][x] != ' ')
		++size;
	while (y < size && map[y + 1])
	{
		if (map[y + 1][x] == '1')
			return (1);
		++y;
	}
	return (-1);
}

/*
** verifie qu une case contennant un 1 existe audessu de la case verifiee.
*/

static		int		check_up(char **map, size_t y, size_t x)
{
	while (y >= 0 && ft_strlen(map[y]) >= x)
	{
		if (map[y][x] == '1')
			return (1);
		--y;
	}
	return (-1);
}

/*
** verifie que la map est entouree uniquement de 1.
** Pour cela, la fonction verifie si un 1 existe audessus, en dessous,
** a droite et gauche de toute les cases qui ne sont pas des 1.
*/

int					check_is_map_close(char **map)
{
	size_t		y;
	size_t		x;

	y = 0;
	if (check_left_and_right(map) < 0)
		return (-1);
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1')
			{
				if (check_up(map, y, x) < 0)
					return (-1);
				if (check_down(map, y, x) < 0)
					return (-1);
			}
			++x;
		}
		++y;
	}
	return (1);
}
