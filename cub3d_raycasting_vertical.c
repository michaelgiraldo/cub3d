/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_vertical.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:53:10 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 20:07:19 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** [Note to self] Must subtract 0.01 instead of 1.0 [LINE 33]
** cub3d->vertical.xintercept = floor(cub3d->player.x / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
*/

void	c3d_raycasting_vertical_intercept(t_param *cub3d)
{
	if (cub3d->wall.angle == M_PI_2 || cub3d->wall.angle == (3.0 * M_PI_2))
	{
		cub3d->vertical.yintercept = cub3d->player.y;
		cub3d->vertical.xintercept = cub3d->player.x;
		cub3d->vertical.ystep = 64;
		cub3d->vertical.xstep = 0;
	}
	else
	{
		if (cub3d->wall.angle > M_PI_2 && cub3d->wall.angle < (3.0 * M_PI_2))
		{
			cub3d->vertical.xintercept = floor(cub3d->player.x / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
			cub3d->vertical.xstep = cub3d->map.tile_size * -1;
		}
		else if (cub3d->wall.angle < M_PI_2 || cub3d->wall.angle > (3.0 * M_PI_2))
		{
			cub3d->vertical.xintercept = floor(cub3d->player.x / cub3d->map.tile_size) * cub3d->map.tile_size + cub3d->map.tile_size;
			cub3d->vertical.xstep = cub3d->map.tile_size;
		}
		cub3d->vertical.yintercept = cub3d->player.y + (double)(cub3d->player.x - cub3d->vertical.xintercept) * tan(cub3d->wall.angle);
		cub3d->vertical.ystep = cub3d->map.tile_size * tan(cub3d->wall.angle);
	}
	 if (cub3d->vertical.ystep > 0 && cub3d->wall.angle < M_PI && cub3d->wall.angle >  0)
		cub3d->vertical.ystep *= -1;
	else if (cub3d->vertical.ystep < 0 && cub3d->wall.angle > M_PI && cub3d->wall.angle < (2 * M_PI))
		cub3d->vertical.ystep *= -1;
}

void	c3d_raycasting_vertical_wall_check(t_param *cub3d)
{
	cub3d->vertical.x = cub3d->vertical.xintercept;
	cub3d->vertical.y = cub3d->vertical.yintercept;
	cub3d->vertical.wall_hit = 0;
	while (!cub3d->vertical.wall_hit &&
		cub3d->vertical.x >= 0 && cub3d->vertical.x <= (cub3d->map.tile_size * cub3d->map.colum) &&
		cub3d->vertical.y >= 0 && cub3d->vertical.y <= (cub3d->map.tile_size * cub3d->map.row))
	{
		if (cub3d->map.grid[(int)(cub3d->vertical.y / cub3d->map.tile_size)][(int)(cub3d->vertical.x / cub3d->map.tile_size)] == 1)
			cub3d->vertical.wall_hit = 1;
		else
		{
			cub3d->vertical.x += cub3d->vertical.xstep;
			cub3d->vertical.y += cub3d->vertical.ystep;
		}
	}
}

/*
**	Double Max in Hexadeciaml Float is 1.7976931348623157E+308
*/

void	c3d_raycasting_vertical_wall_distance(t_param *cub3d)
{
	double x;
	double y;
	
	if (!cub3d->vertical.wall_hit ||
		cub3d->wall.angle == M_PI_2 || cub3d->wall.angle == (3.0 * M_PI_2))
	{
		cub3d->vertical.wall_distance = 1.7976931348623157E+308;
		cub3d->vertical.wall_hit = 0;
	}
	else
	{
		x = cub3d->player.x - cub3d->vertical.x;
		y = cub3d->player.y - cub3d->vertical.y;
		cub3d->vertical.wall_distance = hypot(x, y);
	}
}
