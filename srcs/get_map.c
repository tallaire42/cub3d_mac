/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:00:59 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:12:18 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		**alloc_map(char **map)
{
	int		**new_map;
	size_t	y;
	size_t	x;
	size_t	size;

	y = 0;
	x = 0;
	size = 0;
	while (map && map[size])
		++size;
	if (!(new_map = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	while (map && map[y])
	{
		size = ft_strlen(map[y]);
		if (!(new_map[y] = (int *)malloc(sizeof(int) * (size + 1))))
			return (NULL);
		++y;
	}
	new_map[y] = NULL;
	return (new_map);
}

static	int		get_map(char **file, t_env *env, size_t y, size_t x)
{
	if (!(env->map.map = alloc_map(file)))
		return (aie_error("map alloc memory failed"));
	while (file && file[y])
	{
		x = 0;
		while (file[y][x])
		{
			if (file[y][x] == '2')
			{
				env->sprite.num += 1;
				env->map.map[y][x] = 2;
			}
			else if (file[y][x] == ' ' || file[y][x] == '1')
				env->map.map[y][x] = 1;
			else
				env->map.map[y][x] = 0;
			++x;
		}
		env->map.map[y][x] = (-1);
		++y;
	}
	env->map.map[y] = NULL;
	env->map.size = (int)y;
	return (1);
}

static	int		get_map_and_sprite_pos(char **map, t_env *env)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (get_map(map, env, y, x) < 0)
		return (-1);
	if (sprite_pos(env) < 0)
		return (aie_error("sprite alloc memory failed"));
	return (1);
}

static	void	get_dir_player(t_env *env, char pos)
{
	if (pos == 'S')
		env->player.dir = 0;
	else if (pos == 'N')
		env->player.dir = M_PI;
	else if (pos == 'W')
		env->player.dir = (3 * M_PI) / 2;
	else if (pos == 'E')
		env->player.dir = M_PI / 2;
}

int				get_pos_player(char **map, t_env *env)
{
	int	x;
	int	y;

	y = 0;
	if (check_map(map) < 0)
		return (aie_error("invalid map in data.cub\n"));
	while (map && map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				env->player.pos_y = (float)y + 0.5;
				env->player.pos_x = (float)x + 0.5;
				get_dir_player(env, map[y][x]);
			}
			++x;
		}
		++y;
	}
	if (get_map_and_sprite_pos(map, env) < 0)
		return (-1);
	return (1);
}
