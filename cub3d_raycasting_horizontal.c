/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_horizontal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:53:17 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 01:07:40 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_raycasting_horizontal(t_param *cub3d)
{
	c3d_raycasting_horizontal_intercept(cub3d);
	c3d_raycasting_horizontal_wall_check(cub3d);
	c3d_raycasting_horizontal_wall_distance(cub3d);
}

/*
** [Note to self] Must subtract 0.01 instead of 1.0 [LINE 33]
** cub3d->vertical.xintercept =
** floor(cub3d->player.x / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
*/

void	c3d_raycasting_horizontal_intercept(t_param *cub3d)
{
	if (cub3d->ray.angle == 0 || cub3d->ray.angle == M_PI ||
		cub3d->ray.angle == (2.0 * M_PI))
	{
		cub3d->horizontal.yintercept = cub3d->player.y;
		cub3d->horizontal.xintercept = cub3d->player.x;
		cub3d->horizontal.ystep = 0;
		cub3d->horizontal.xstep = 64;
	}
	else
		c3d_raycasting_horizontal_intercept_internal(cub3d);
	if (cub3d->horizontal.xstep > 0 &&
		cub3d->ray.angle > M_PI_2 && cub3d->ray.angle < (3.0 * M_PI_2))
		cub3d->horizontal.xstep *= -1;
	else if (cub3d->horizontal.xstep < 0 &&
		(cub3d->ray.angle < M_PI_2 || cub3d->ray.angle > (3.0 * M_PI_2)))
		cub3d->horizontal.xstep *= -1;
}

void	c3d_raycasting_horizontal_intercept_internal(t_param *cub3d)
{
	if (cub3d->ray.angle < M_PI && cub3d->ray.angle > 0)
	{
		cub3d->horizontal.yintercept =
			floor(cub3d->player.y / cub3d->map.tile_size) *
			cub3d->map.tile_size - 0.001;
		cub3d->horizontal.ystep = cub3d->map.tile_size * -1;
	}
	else if (cub3d->ray.angle > M_PI && cub3d->ray.angle < (2.0 * M_PI))
	{
		cub3d->horizontal.yintercept =
			floor(cub3d->player.y / cub3d->map.tile_size) *
			cub3d->map.tile_size + cub3d->map.tile_size;
		cub3d->horizontal.ystep = cub3d->map.tile_size;
	}
	cub3d->horizontal.xintercept = cub3d->player.x +
	(cub3d->player.y - cub3d->horizontal.yintercept) / tan(cub3d->ray.angle);
	cub3d->horizontal.xstep = cub3d->map.tile_size / tan(cub3d->ray.angle);
}

void	c3d_raycasting_horizontal_wall_check(t_param *cub3d)
{
	int x;
	int y;

	cub3d->horizontal.x = cub3d->horizontal.xintercept;
	cub3d->horizontal.y = cub3d->horizontal.yintercept;
	cub3d->horizontal.wall_hit = 0;
	while (!cub3d->horizontal.wall_hit &&
		cub3d->horizontal.x >= 0 && cub3d->horizontal.x < cub3d->map.width &&
		cub3d->horizontal.y >= 0 && cub3d->horizontal.y < cub3d->map.height)
	{
		y = (int)(cub3d->horizontal.y / cub3d->map.tile_size);
		x = (int)(cub3d->horizontal.x / cub3d->map.tile_size);
		if (cub3d->map.grid[y][x] == 2)
			cub3d->sprite.grid[y][x].visible = 1;
		else if (cub3d->map.grid[y][x] == 1)
			cub3d->horizontal.wall_hit = 1;
		if (!cub3d->horizontal.wall_hit)
		{
			cub3d->horizontal.x += cub3d->horizontal.xstep;
			cub3d->horizontal.y += cub3d->horizontal.ystep;
		}
	}
}

/*
**	Double Max is 1.7976931348623157E+308
*/

void	c3d_raycasting_horizontal_wall_distance(t_param *cub3d)
{
	double x;
	double y;

	if (!cub3d->horizontal.wall_hit || cub3d->ray.angle == 0 ||
		cub3d->ray.angle == M_PI || cub3d->ray.angle == (2.0 * M_PI))
	{
		cub3d->horizontal.distance = 1.7976931348623157E+308;
		cub3d->horizontal.wall_hit = 0;
	}
	else
	{
		x = cub3d->player.x - cub3d->horizontal.x;
		y = cub3d->player.y - cub3d->horizontal.y;
		cub3d->horizontal.distance = hypot(x, y);
	}
}
