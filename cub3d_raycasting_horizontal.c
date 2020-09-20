/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_horizontal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:53:17 by mg                #+#    #+#             */
/*   Updated: 2020/09/20 13:36:29 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_raycasting_horizontal_intercept(t_param *cub3d)
{
	if (cub3d->horizontal.angle == 0 || cub3d->horizontal.angle == M_PI || cub3d->horizontal.angle == (2.0 * M_PI))
	{
		ft_printf("H.STEP_1 ");	
		cub3d->horizontal.yintercept = cub3d->player.y;
		cub3d->horizontal.xintercept = cub3d->player.x;
		cub3d->horizontal.ystep = 0;
		cub3d->horizontal.xstep = 64;
	}
	else
	{
		if (cub3d->horizontal.angle < M_PI && cub3d->horizontal.angle > 0)
		{
			cub3d->horizontal.yintercept = floor(cub3d->player.y / cub3d->map.tile_size) * cub3d->map.tile_size - 1;
			cub3d->horizontal.ystep = cub3d->map.tile_size * -1;
		}
		else if (cub3d->horizontal.angle > M_PI && cub3d->horizontal.angle < (2.0 * M_PI))
		{
			cub3d->horizontal.yintercept = floor(cub3d->player.y / cub3d->map.tile_size) * cub3d->map.tile_size + cub3d->map.tile_size;
			cub3d->horizontal.ystep = cub3d->map.tile_size;
		}
		cub3d->horizontal.xintercept = cub3d->player.x + (double)(cub3d->player.y - cub3d->horizontal.yintercept) / tan(cub3d->horizontal.angle);
		cub3d->horizontal.xstep = cub3d->map.tile_size / tan(cub3d->horizontal.angle);
	}
	if (cub3d->horizontal.xstep > 0 && cub3d->horizontal.angle > M_PI_2 && cub3d->horizontal.angle < (3.0 * M_PI_2))
		cub3d->horizontal.xstep *= -1;
	else if (cub3d->horizontal.xstep < 0 && (cub3d->horizontal.angle < M_PI_2 || cub3d->horizontal.angle > (3.0 * M_PI_2)))
			cub3d->horizontal.xstep *= -1;
}

void	c3d_raycasting_horizontal_wall_check(t_param *cub3d)
{
	cub3d->horizontal.x = cub3d->horizontal.xintercept;
	cub3d->horizontal.y = cub3d->horizontal.yintercept;

	while (cub3d->horizontal.x >= 0 && cub3d->horizontal.x <= (cub3d->map.tile_size * cub3d->map.colum) &&
		cub3d->horizontal.y >= 0 && cub3d->horizontal.y <= (cub3d->map.tile_size * cub3d->map.row))
	{
		if (cub3d->map.grid[(int)(cub3d->horizontal.y / cub3d->map.tile_size)][(int)(cub3d->horizontal.x / cub3d->map.tile_size)] == 1)
		{
			cub3d->horizontal.wall_hit = 1;
			break ;
		}
		else
		{
			cub3d->horizontal.x += cub3d->horizontal.xstep;
			cub3d->horizontal.y += cub3d->horizontal.ystep;
		}
	}
	cub3d->vertical.wall_hit = 0;
}

/*
**	Double Max in Hexadeciaml Float is 1.7976931348623157E+308
*/

void	c3d_raycasting_horizontal_wall_distance(t_param *cub3d)
{
	double x;
	double y;

	if (!cub3d->horizontal.wall_hit)
		cub3d->horizontal.wall_distance = 1.7976931348623157E+308;
	else 
	{
		x = cub3d->player.x - cub3d->horizontal.x;
		y = cub3d->player.y - cub3d->horizontal.y;
		cub3d->horizontal.wall_distance = hypot(x, y);
	}
}
