/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:39:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:46:15 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static		void	dda(t_env *env)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (env->ray.side_dist_x < env->ray.side_dist_y)
		{
			env->ray.side_dist_x += env->ray.delta_dist_x;
			env->ray.map_x += env->ray.step_x;
			env->ray.side = 0;
		}
		else
		{
			env->ray.side_dist_y += env->ray.delta_dist_y;
			env->ray.map_y += env->ray.step_y;
			env->ray.side = 1;
		}
		if (env->map.map[(int)(env->ray.map_y)][(int)(env->ray.map_x)] == 1)
			hit = 1;
	}
	side = wich_plan(env);
}

static		void	init_step_and_side_dist(t_env *env)
{
	if (env->ray.ray_dir_x < 0)
	{
		env->ray.step_x = (-1);
		env->ray.side_dist_x = (env->player.pos_x - env->ray.map_x) *
			env->ray.delta_dist_x;
	}
	else
	{
		env->ray.step_x = 1;
		env->ray.side_dist_x = (env->ray.map_x + 1.0 -
		env->player.pos_x) * env->ray.delta_dist_x;
	}
	if (env->ray.ray_dir_y < 0)
	{
		env->ray.step_y = (-1);
		env->ray.side_dist_y = (env->player.pos_y - env->ray.map_y) *
		env->ray.delta_dist_y;
	}
	else
	{
		env->ray.step_y = 1;
		env->ray.side_dist_y = (env->ray.map_y + 1.0 -
		env->player.pos_y) * env->ray.delta_dist_y;
	}
}

static		void	init_data(t_env *env, int x)
{
	env->ray.camera_x = 2.0 * (float)(env->vars.res_x - 1 - x) /
		(float)env->vars.res_x - 1;
	env->ray.ray_dir_x = env->ray.dir_x + env->ray.plane_x *
		env->ray.camera_x;
	env->ray.ray_dir_y = env->ray.dir_y + env->ray.plane_y *
		env->ray.camera_x;
	env->ray.map_x = (int)env->player.pos_x;
	env->ray.map_y = (int)env->player.pos_y;
	env->ray.delta_dist_x = fabs(1 / env->ray.ray_dir_x);
	env->ray.delta_dist_y = fabs(1 / env->ray.ray_dir_y);
}

int					raycast(t_env *env)
{
	int		x;

	x = 0;
	while (x < env->vars.res_x)
	{
		init_data(env, x);
		init_step_and_side_dist(env);
		dda(env);
		wall_size(env);
		print_texture(env, x, env->wall.draw_start, env->wall.draw_end);
		env->sprite.z_buffer[x] = env->ray.perp_wall_dist;
		++x;
	}
	sprite(env);
	return (1);
}
