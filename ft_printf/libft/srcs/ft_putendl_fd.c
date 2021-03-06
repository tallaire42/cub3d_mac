/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:47:15 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/09 14:29:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (*(s + i))
		{
			ft_putchar_fd(*(s + i), fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
