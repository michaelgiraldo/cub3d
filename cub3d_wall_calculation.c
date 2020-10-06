/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:37:12 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 12:51:10 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_wall(t_param *cub3d)
{
	c3d_wall_type(cub3d);
	c3d_wall_distance(cub3d);
	c3d_wall_height(cub3d);
	c3d_wall_facing(cub3d);
}

void	c3d_wall_type(t_param *cub3d)
{
	if (cub3d->vertical.wall_hit == 1 || cub3d->horizontal.wall_hit == 1)
	{
		if (cub3d->vertical.distance < cub3d->horizontal.distance)
			cub3d->wall.type = VERTICAL;
		else if (cub3d->vertical.distance > cub3d->horizontal.distance)
			cub3d->wall.type = HORIZONTAL;
	}
}

void	c3d_wall_distance(t_param *cub3d)
{
	if (cub3d->vertical.wall_hit == 1 || cub3d->horizontal.wall_hit == 1)
	{
		cub3d->wall.distance =
		fmin(cub3d->vertical.distance, cub3d->horizontal.distance)
		* cos(cub3d->player.angle - cub3d->ray.angle);
	}
	else
		c3d_print_error(cub3d, "Wall: No Wall Hit");
}

void	c3d_wall_height(t_param *cub3d)
{
	if (cub3d->wall.distance > cub3d->map.step)
		cub3d->wall.height =
	cub3d->map.tile_size / cub3d->wall.distance * cub3d->window.distance_plane;
	else
		cub3d->wall.height =
	cub3d->map.tile_size / cub3d->map.step * cub3d->window.distance_plane;
}
