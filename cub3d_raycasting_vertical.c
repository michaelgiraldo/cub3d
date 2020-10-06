/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_vertical.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:53:10 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 01:07:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_raycasting_vertical(t_param *cub3d)
{
	c3d_raycasting_vertical_intercept(cub3d);
	c3d_raycasting_vertical_wall_check(cub3d);
	c3d_raycasting_vertical_wall_distance(cub3d);
}

/*
** [Note to self] Must subtract 0.01 instead of 1.0 [LINE 33]
** cub3d->vertical.xintercept =
** floor(cub3d->player.x / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
*/

void	c3d_raycasting_vertical_intercept(t_param *cub3d)
{
	if (cub3d->ray.angle == M_PI_2 || cub3d->ray.angle == (3.0 * M_PI_2))
	{
		cub3d->vertical.yintercept = cub3d->player.y;
		cub3d->vertical.xintercept = cub3d->player.x;
		cub3d->vertical.ystep = 64;
		cub3d->vertical.xstep = 0;
	}
	else
		c3d_raycasting_vertical_intercept_internal(cub3d);
	if (cub3d->vertical.ystep > 0 &&
		cub3d->ray.angle < M_PI && cub3d->ray.angle > 0)
		cub3d->vertical.ystep *= -1;
	else if (cub3d->vertical.ystep < 0 &&
		cub3d->ray.angle > M_PI && cub3d->ray.angle < (2 * M_PI))
		cub3d->vertical.ystep *= -1;
}

void	c3d_raycasting_vertical_intercept_internal(t_param *cub3d)
{
	if (cub3d->ray.angle > M_PI_2 && cub3d->ray.angle < (3.0 * M_PI_2))
	{
		cub3d->vertical.xintercept =
			floor(cub3d->player.x / cub3d->map.tile_size) *
			cub3d->map.tile_size - 0.001;
		cub3d->vertical.xstep = cub3d->map.tile_size * -1;
	}
	else if (cub3d->ray.angle < M_PI_2 || cub3d->ray.angle > (3.0 * M_PI_2))
	{
		cub3d->vertical.xintercept =
			floor(cub3d->player.x / cub3d->map.tile_size) *
			cub3d->map.tile_size + cub3d->map.tile_size;
		cub3d->vertical.xstep = cub3d->map.tile_size;
	}
	cub3d->vertical.yintercept = cub3d->player.y +
		(cub3d->player.x - cub3d->vertical.xintercept) * tan(cub3d->ray.angle);
	cub3d->vertical.ystep = cub3d->map.tile_size * tan(cub3d->ray.angle);
}

void	c3d_raycasting_vertical_wall_check(t_param *cub3d)
{
	int x;
	int y;

	cub3d->vertical.x = cub3d->vertical.xintercept;
	cub3d->vertical.y = cub3d->vertical.yintercept;
	cub3d->vertical.wall_hit = 0;
	while (!cub3d->vertical.wall_hit &&
		cub3d->vertical.x >= 0 && cub3d->vertical.x < cub3d->map.width &&
		cub3d->vertical.y >= 0 && cub3d->vertical.y < cub3d->map.height)
	{
		y = (int)(cub3d->vertical.y / cub3d->map.tile_size);
		x = (int)(cub3d->vertical.x / cub3d->map.tile_size);
		if (cub3d->map.grid[y][x] == 2)
			cub3d->sprite.grid[y][x].visible = 1;
		else if (cub3d->map.grid[y][x] == 1)
			cub3d->vertical.wall_hit = 1;
		if (!cub3d->vertical.wall_hit)
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
		cub3d->ray.angle == M_PI_2 || cub3d->ray.angle == (3.0 * M_PI_2))
	{
		cub3d->vertical.distance = 1.7976931348623157E+308;
		cub3d->vertical.wall_hit = 0;
	}
	else
	{
		x = cub3d->player.x - cub3d->vertical.x;
		y = cub3d->player.y - cub3d->vertical.y;
		cub3d->vertical.distance = hypot(x, y);
	}
}
