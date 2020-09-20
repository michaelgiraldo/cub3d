/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:39:33 by mg                #+#    #+#             */
/*   Updated: 2020/09/19 16:39:33 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** stderr = standard error = 2
*/

int		c3d_print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (0);
}

void	c3d_print_map_grid(t_param *cub3d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("Map Grid: START\n");
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.colum)
			ft_putnbr(cub3d->map.grid[i][j++]);
		ft_putchar('\n');
		i++;
	}
	ft_printf("Map Grid: END\n");
}
