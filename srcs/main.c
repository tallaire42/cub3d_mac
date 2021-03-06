/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:36:10 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/10 15:22:20 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

static	int	game(t_env *env)
{
	free_img(env);
	new_image(env);
	move_player(env);
	raycast(env);
	mlx_put_image_to_window(env->vars.mlx, env->vars.win, env->wall.img, 0,
		0);
	return (1);
}

static	int	start_game(t_env *env)
{
	env->vars.mlx = mlx_init();
	res_max(env);
	if (get_texture_and_sprite(env) < 0)
	{
		free(env->vars.mlx);
		exit_game(env);
		return (-1);
	}
	env->vars.win = mlx_new_window(env->vars.mlx,
		env->vars.res_x, env->vars.res_y, "Cub3d");
	mlx_hook(env->vars.win, 2, 1L << 0, key_pressed, env);
	mlx_hook(env->vars.win, 3, 1L << 1, key_released, env);
	mlx_hook(env->vars.win, 17, 1L << 17, red_cross, env);
	mlx_loop_hook(env->vars.mlx, game, env);
	mlx_loop(env->vars.mlx);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2 || argc > 3)
	{
		aie_error("Wrong number of arguments");
		return (0);
	}
	if (init_env(&env) < 0)
		return (exit_game(&env));
	if (get_file(&env, argv[1]) < 0)
		return (exit_game(&env));
	if (init_vars(&env) < 1)
		return (exit_game(&env));
	if (parsing_file(&env) < 0)
		return (exit_game(&env));
	if (init_raycaster(&env) < 0)
		return (exit_game(&env));
	if (argc == 3)
		if (is_arg_save(argv[2]) > 0)
			return (create_bmp_file(&env));
	start_game(&env);
	return (0);
}
