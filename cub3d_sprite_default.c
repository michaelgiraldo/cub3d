/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:37:30 by mg                #+#    #+#             */
/*   Updated: 2020/10/03 12:45:50 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_sprite_visible_default(t_param *cub3d)
{
	ft_memset(&cub3d->sprite.visible, 0, 50 * sizeof(t_sprite_info));
}

void	c3d_sprite_grid_default(t_param *cub3d)
{
	int i;
	int j;

	i = 0;
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
		{
			cub3d->sprite.grid[i][j].visible = 0;
			++j;
		}
		++i;
	}
}

void	c3d_sprite_grid_coordinate(t_param *cub3d)
{
	int i;
	int j;

	i = 0;
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
		{
			cub3d->sprite.grid[i][j].y =
					i * cub3d->map.tile_size + cub3d->map.tile_size / 2;
			cub3d->sprite.grid[i][j].x =
					j * cub3d->map.tile_size + cub3d->map.tile_size / 2;
			++j;
		}
		++i;
	}
}
