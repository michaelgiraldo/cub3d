/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_grid_allocation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:22:11 by mg                #+#    #+#             */
/*   Updated: 2020/09/30 23:09:35 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_map_grid_allocation(t_param *cub3d)
{
	int i;

	i = 0;
	if (!(cub3d->map.row > 0 && cub3d->map.colum > 0))
		return (c3d_print_error("Map Grid: Invalid Map Height or Width.\n"));
	cub3d->map.grid = malloc(cub3d->map.row * sizeof(int *));
	if (cub3d->map.grid == NULL)
		return (c3d_print_error("Map Grid: Memory Allocation Failed.\n"));
	while (i < cub3d->map.row)
	{
		cub3d->map.grid[i] = malloc(cub3d->map.colum * sizeof(int));
		if (cub3d->map.grid[i] == NULL)
			return (c3d_print_error("Map Grid: Memory Allocation Failed.\n"));
		++i;
	}
	return (1);
}

void	c3d_map_grid_free(t_param *cub3d)
{
	int i;

	i = 0;
	while (i < cub3d->window.height)
		free(cub3d->map.grid[i]);
	free(cub3d->map.grid);
}
