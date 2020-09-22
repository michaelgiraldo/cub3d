/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_horizontal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:53:17 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 20:07:08 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** [Note to self] Must subtract 0.01 instead of 1.0 [LINE 33]
** cub3d->horizontal.yintercept = floor(cub3d->player.y / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
*/

void	c3d_raycasting_horizontal_intercept(t_param *cub3d)
{
	if (cub3d->wall.angle == 0 || cub3d->wall.angle == M_PI || cub3d->wall.angle == (2.0 * M_PI))
	{
		cub3d->horizontal.yintercept = cub3d->player.y;
		cub3d->horizontal.xintercept = cub3d->player.x;
		cub3d->horizontal.ystep = 0;
		cub3d->horizontal.xstep = 64;
	}
	else
	{
		if (cub3d->wall.angle < M_PI && cub3d->wall.angle > 0)
		{
			cub3d->horizontal.yintercept = floor(cub3d->player.y / cub3d->map.tile_size) * cub3d->map.tile_size - 0.01;
			cub3d->horizontal.ystep = cub3d->map.tile_size * -1;
		}
		else if (cub3d->wall.angle > M_PI && cub3d->wall.angle < (2.0 * M_PI))
		{
			cub3d->horizontal.yintercept = floor(cub3d->player.y / cub3d->map.tile_size) * cub3d->map.tile_size + cub3d->map.tile_size;
			cub3d->horizontal.ystep = cub3d->map.tile_size;
		}
		cub3d->horizontal.xintercept = cub3d->player.x + (double)(cub3d->player.y - cub3d->horizontal.yintercept) / tan(cub3d->wall.angle);
		cub3d->horizontal.xstep = cub3d->map.tile_size / tan(cub3d->wall.angle);
	}
	if (cub3d->horizontal.xstep > 0 && cub3d->wall.angle > M_PI_2 && cub3d->wall.angle < (3.0 * M_PI_2))
		cub3d->horizontal.xstep *= -1;
	else if (cub3d->horizontal.xstep < 0 && (cub3d->wall.angle < M_PI_2 || cub3d->wall.angle > (3.0 * M_PI_2)))
		cub3d->horizontal.xstep *= -1;
}

void	c3d_raycasting_horizontal_wall_check(t_param *cub3d)
{
	cub3d->horizontal.x = cub3d->horizontal.xintercept;
	cub3d->horizontal.y = cub3d->horizontal.yintercept;
	cub3d->horizontal.wall_hit = 0;
	while (!cub3d->horizontal.wall_hit &&
		cub3d->horizontal.x >= 0 && cub3d->horizontal.x <= (cub3d->map.tile_size * cub3d->map.colum) &&
		cub3d->horizontal.y >= 0 && cub3d->horizontal.y <= (cub3d->map.tile_size * cub3d->map.row))
	{
		if (cub3d->map.grid[(int)(cub3d->horizontal.y / cub3d->map.tile_size)][(int)(cub3d->horizontal.x / cub3d->map.tile_size)] == 1)
			cub3d->horizontal.wall_hit = 1;
		else
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

	if (!cub3d->horizontal.wall_hit || cub3d->wall.angle == 0 ||
		cub3d->wall.angle == M_PI || cub3d->wall.angle == (2.0 * M_PI))
	{
		cub3d->horizontal.wall_distance = 1.7976931348623157E+308;
		cub3d->horizontal.wall_hit = 0;
	}
	else 
	{
		x = round(cub3d->player.x - cub3d->horizontal.x);
		y = round(cub3d->player.y - cub3d->horizontal.y);
		cub3d->horizontal.wall_distance = hypot(x, y);
	}
}
