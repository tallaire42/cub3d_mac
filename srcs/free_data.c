/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:57:57 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:58:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_img(t_env *env)
{
	if (env->wall.img != NULL)
		mlx_destroy_image(env->vars.mlx, env->wall.img);
}
