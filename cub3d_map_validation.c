/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:37:21 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 15:35:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_flood_fill(t_param *cub3d, int row, int column, int i)
{
	if (row < 0 || row >= cub3d->map.row ||
		column < 0 || column >= cub3d->map.column)
		return (i);
	else if (cub3d->map.grid[row][column] == 1)
		return (0);
	cub3d->map.grid[row][column] = 1;
	return (c3d_flood_fill(cub3d, row - 1, column - 1, 0) +
			c3d_flood_fill(cub3d, row - 1, column + 1, 0) +
			c3d_flood_fill(cub3d, row + 1, column - 1, 0) +
			c3d_flood_fill(cub3d, row + 1, column + 1, 0) +
			c3d_flood_fill(cub3d, row - 1, column, 1) +
			c3d_flood_fill(cub3d, row + 1, column, 1) +
			c3d_flood_fill(cub3d, row, column - 1, 1) +
			c3d_flood_fill(cub3d, row, column + 1, 1));
}

void	c3d_map_validation(t_param *cub3d)
{
	int **tmp;
	int broken_walls;
	int i;
	int row;
	int column;

	tmp = cub3d->map.grid;
	i = -1;
	row = cub3d->player.y / cub3d->map.tile_size;
	column = cub3d->player.x / cub3d->map.tile_size;
	c3d_map_grid_allocation(cub3d);
	while (++i < cub3d->map.row)
		ft_memcpy(cub3d->map.grid[i], tmp[i], cub3d->map.column * sizeof(int));
	broken_walls = 0;
	broken_walls = c3d_flood_fill(cub3d, row, column, 0);
	c3d_map_grid_free(cub3d);
	cub3d->map.grid = tmp;
	if (broken_walls)
		c3d_print_error(cub3d, "Map Grid: broken walls");
}
