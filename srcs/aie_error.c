/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aie_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:10:53 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/02 17:36:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		aie_error(const char *str)
{
	ft_printf("Error\n%s\n", str);
	return (-1);
}
