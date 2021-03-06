/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:04:16 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:05:29 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		sprite_copy(t_env *env)
{
	int		end;
	int		i;

	end = 0;
	i = 0;
	if (!(env->sprite.img = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_sprite, &env->sprite.width, &env->sprite.height)))
		return (aie_error("Sprite doesn't download"));
	env->sprite.addr = (unsigned int *)mlx_get_data_addr(env->sprite.img,
	&env->sprite.bpp, &env->sprite.line_length, &env->sprite.endian);
	if (!(env->sprite.sprite = ft_calloc(env->sprite.width *
	env->sprite.width, sizeof(unsigned int))))
		return (aie_error("Sprite alloc memory failed"));
	end = env->sprite.width * env->sprite.height;
	while (i < end)
	{
		env->sprite.sprite[i] = env->sprite.addr[i];
		++i;
	}
	return (1);
}

static	int		texture_copy(t_env *env)
{
	int		end;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		if (!(env->tex.img[i] = mlx_xpm_file_to_image(env->vars.mlx,
		env->vars.path_tex[i], &env->tex.width[i], &env->tex.height[i])))
			return (aie_error("Texture doesn't download"));
		env->tex.addr[i] = (unsigned int *)mlx_get_data_addr(env->tex.img[i],
		&env->tex.bpp, &env->tex.line_length, &env->tex.endian);
		if (!(env->tex.tex[i] = ft_calloc(env->tex.width[i] *
		env->tex.height[i], sizeof(unsigned int))))
			return (aie_error("Texture alloc memory failed"));
		j = 0;
		end = env->tex.width[i] * env->tex.height[i];
		while (j < end)
		{
			env->tex.tex[i][j] = env->tex.addr[i][j];
			++j;
		}
		++i;
	}
	return (1);
}

int				get_texture_and_sprite(t_env *env)
{
	if (texture_copy(env) < 0)
		return (-1);
	if (sprite_copy(env) < 0)
		return (-1);
	return (1);
}
