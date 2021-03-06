/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:55:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/10 13:49:52 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_map(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->map.map && env->map.map[i] != NULL)
	{
		free(env->map.map[i]);
		env->map.map[i] = NULL;
		++i;
	}
	free(env->map.map);
	env->map.map = NULL;
}

char		*strdup_path(char *str)
{
	size_t		i;
	size_t		size;
	char		*new;

	i = 0;
	size = 0;
	while (str && str[size] && str[size] != ' ')
		++size;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str && str[i] && str[i] != ' ')
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}

void		res_max(t_env *env)
{
	int	res_x_max;
	int	res_y_max;

	res_x_max = 0;
	res_y_max = 0;
	mlx_get_screen_size(env->vars.mlx, &res_x_max, &res_y_max);
	if (env->vars.res_x > res_x_max)
		env->vars.res_x = res_x_max;
	if (env->vars.res_y > res_y_max)
		env->vars.res_y = res_y_max;
}
