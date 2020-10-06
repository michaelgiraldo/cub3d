/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_grid_allocation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:22:11 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 15:35:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_map_grid_allocation(t_param *cub3d)
{
	int i;

	i = 0;
	if (!(cub3d->map.row > 0 && cub3d->map.column > 0))
		c3d_print_error(cub3d, "Map Grid: Invalid Map Height or Width.");
	cub3d->map.grid = malloc(cub3d->map.row * sizeof(int *));
	if (!cub3d->map.grid)
		c3d_print_error(cub3d, "MAP GRID #1");
	while (i < cub3d->map.row)
	{
		cub3d->map.grid[i] = malloc(cub3d->map.column * sizeof(int));
		if (!cub3d->map.grid[i] || !(cub3d->free.map_row = i + 1))
			c3d_print_error(cub3d, "MAP GRID #2");
		++i;
	}
}

void	c3d_map_grid_free(t_param *cub3d)
{
	int i;

	i = -1;
	if (cub3d->free.map_row && cub3d->free.map_row)
		while (++i < cub3d->free.map_row)
			free(cub3d->map.grid[i]);
	free(cub3d->map.grid);
}
