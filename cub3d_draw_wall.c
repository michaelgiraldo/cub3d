/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:26:38 by mg                #+#    #+#             */
/*   Updated: 2020/10/01 22:28:35 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_wall_strip(t_param *cub3d, int x)
{
	cub3d->wall.height_at[x] = cub3d->wall.height;
	c3d_wall(cub3d);
	c3d_draw_wall_strip_internal(cub3d, x);
}

void	c3d_draw_wall_strip_internal(t_param *cub3d, int x)
{
	int i;
	int y;
	int y_offset;

	y = (cub3d->window.height - cub3d->wall.height) / 2;
	y_offset = 0;
	i = cub3d->wall.height;
	while (i)
	{
		if (y >= 0 && y < cub3d->window.height)
		{
			c3d_wall_texture(cub3d, y_offset);
			c3d_draw_wall_pixel(cub3d, x, y);
		}
		++y_offset;
		++y;
		--i;
	}
}

void	c3d_draw_wall_pixel(t_param *cub3d, int x, int y)
{
	int position;

	position = c3d_pixel_postion(x, y,
						cub3d->render.bits_per_pixel, cub3d->render.size_line);
	*(unsigned int*)(cub3d->render.img_data + position) = cub3d->wall.color;
}
