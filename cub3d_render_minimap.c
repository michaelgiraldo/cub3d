/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:22:50 by mg                #+#    #+#             */
/*   Updated: 2020/09/19 16:39:32 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_minimap(t_param *cub3d)
{
	int	x;
	int	y;
	int		color;
	int		position;
	double	scale_width;
	double	scale_height;
	int		grid_x;
	int		grid_y;

	c3d_create_img(cub3d, &cub3d->minimap,
							cub3d->window.width, cub3d->window.height);
	scale_width = (double)cub3d->map.colum / (double)cub3d->window.width;
	scale_height = (double)cub3d->map.row / (double)cub3d->window.height;
	y = 0;
	while (y < cub3d->window.height)
	{
		x = 0;
		while (x < cub3d->window.width)
		{
			grid_x = (int)((double)x * scale_width);
			grid_y = (int)((double)y * scale_height);
			if (x % (cub3d->window.width / cub3d->map.colum) == 0)
				color = 0x000000;
			else if (y % (cub3d->window.height / cub3d->map.row) == 0)
				color = 0x000000;
			else if (cub3d->map.grid[grid_y][grid_x] == 1)
				color = 0xFFFFFF;
			else if (cub3d->map.grid[grid_y][grid_x] == 'N')
			{
				if (x == cub3d->player.x && y == cub3d->player.y)
					color = 0xFF00FF;
				else
					color = 0x00FF00;
			}
			else
				color = 0x00FF00;
			position = c3d_pixel_postion(x, y,
					cub3d->minimap.bits_per_pixel, cub3d->minimap.size_line);
			*(unsigned int*)(cub3d->minimap.img_data + position) = color;
			++x;
		}
		++y;
	}
}
