/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:56:05 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 15:50:02 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_wall_texture(t_param *cub3d, int y)
{
	int x;

	if (cub3d->wall.facing == 'E')
	{
		x = (int)cub3d->vertical.y;
		c3d_wall_texture_color(cub3d, &cub3d->texture.east, x, y);
	}
	else if (cub3d->wall.facing == 'N')
	{
		x = (int)cub3d->horizontal.x;
		c3d_wall_texture_color(cub3d, &cub3d->texture.north, x, y);
	}
	else if (cub3d->wall.facing == 'W')
	{
		x = (int)cub3d->vertical.y;
		c3d_wall_texture_color(cub3d, &cub3d->texture.west, x, y);
	}
	else if (cub3d->wall.facing == 'S')
	{
		x = (int)cub3d->horizontal.x;
		c3d_wall_texture_color(cub3d, &cub3d->texture.south, x, y);
	}
}

/*
** West and South x axis is inversed
*/

void	c3d_wall_texture_color(t_param *cub3d, t_image *img, int x, int y)
{
	double texture_ratio_y;
	double texture_ratio_x;

	if (cub3d->map.tile_size == img->width)
		x %= cub3d->map.tile_size;
	else
	{
		x %= cub3d->map.tile_size;
		texture_ratio_x = (double)x / (double)cub3d->map.tile_size;
		x = img->width * texture_ratio_x;
	}
	texture_ratio_y = (double)img->height / (double)cub3d->wall.height;
	y *= texture_ratio_y;
	if (cub3d->wall.facing == 'W' || cub3d->wall.facing == 'S')
		x = img->width - 1 - x;
	cub3d->wall.color = c3d_pixel_get_color(img, x, y);
}
