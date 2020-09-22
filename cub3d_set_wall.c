/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:37:12 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 17:37:28 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	c3d_set_wall(t_param *cub3d)
{
	c3d_set_wall_type(cub3d);
	c3d_set_wall_distance(cub3d);
	c3d_set_wall_height(cub3d);
}

void 	c3d_set_wall_type(t_param *cub3d)
{
	if (cub3d->vertical.wall_hit == 1 || cub3d->horizontal.wall_hit == 1)
	{
		if (cub3d->vertical.wall_distance < cub3d->horizontal.wall_distance)
			cub3d->wall.type = VERTICAL;
		else
			cub3d->wall.type = HORIZONTAL;
	}
}

void 	c3d_set_wall_distance(t_param *cub3d)
{
	if (cub3d->vertical.wall_hit == 1 || cub3d->horizontal.wall_hit == 1)
	{
		cub3d->wall.distance = 
		fmin(cub3d->vertical.wall_distance, cub3d->horizontal.wall_distance)
		* cos(cub3d->player.angle - cub3d->wall.angle);
	}
	else
		c3d_print_error("Wall: No Wall Hit\n");
}


void 	c3d_set_wall_height(t_param *cub3d)
{
	cub3d->wall.height = 
	cub3d->map.tile_size / cub3d->wall.distance * cub3d->wall.distance_plane;
}

/*
**	Wall Distance Plane is called by cub3d_initialize_struct()
*/

void 	c3d_set_wall_distance_plane(t_param *cub3d)
{
	cub3d->wall.distance_plane = 
	((double)(cub3d->window.width / 2.0) / tan(M_PI / 6.0));
}
