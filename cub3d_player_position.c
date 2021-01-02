/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:17:35 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 00:01:25 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_player_starting_positon(t_param *cub3d)
{
	int	x;
	int	y;
	int	angle;
	int i;

	y = -1;
	i = 0;
	while (++y < cub3d->map.row)
	{
		x = -1;
		while (++x < cub3d->map.column)
		{
			angle = cub3d->map.grid[y][x];
			if (angle == 'N' && ++i)
				c3d_player_coordinate(cub3d, M_PI_2, x, y);
			else if (angle == 'S' && ++i)
				c3d_player_coordinate(cub3d, 3 * M_PI_2, x, y);
			else if (angle == 'E' && ++i)
				c3d_player_coordinate(cub3d, 0.0, x, y);
			else if (angle == 'W' && ++i)
				c3d_player_coordinate(cub3d, M_PI, x, y);
		}
	}
	c3d_player_validation(cub3d, i);
}

void	c3d_player_coordinate(t_param *cub3d, double angle, int x, int y)
{
	cub3d->player.x = x * cub3d->map.tile_size + cub3d->map.tile_size / 2;
	cub3d->player.y = y * cub3d->map.tile_size + cub3d->map.tile_size / 2;
	cub3d->player.angle = angle;
}

void	c3d_player_validation(t_param *cub3d, int i)
{
	if (!i)
		c3d_print_error(cub3d, "Map Player: no starting position");
	else if (i > 1)
		c3d_print_error(cub3d, "Map Player: multiple starting position");
}
