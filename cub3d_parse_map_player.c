/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:17:35 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 21:53:43 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_player(t_param *cub3d)
{
	int	x;
	int	y;
	int	angle;

	y = 0;
	while (y < cub3d->map.row)
	{
		x = 0;
		while (x < cub3d->map.colum)
		{
			angle = cub3d->map.grid[y][x];
			if (angle == 'N')
				c3d_player_coordinate(cub3d, M_PI_2, x, y);
			else if (angle == 'S')
				c3d_player_coordinate(cub3d, 3 * M_PI_2, x, y);
			else if (angle == 'E')
				c3d_player_coordinate(cub3d, 0.0, x, y);
			else if (angle == 'W')
				c3d_player_coordinate(cub3d, M_PI, x, y);
			++x;
		}
		++y;
	}
}

void	c3d_player_coordinate(t_param *cub3d, double angle, int x, int y)
{
	cub3d->player.x = x * cub3d->map.tile_size + cub3d->map.tile_size / 2;
	cub3d->player.y = y * cub3d->map.tile_size + cub3d->map.tile_size / 2;
	cub3d->player.angle = angle;
}
