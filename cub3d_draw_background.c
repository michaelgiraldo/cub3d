/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:16:54 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 16:10:38 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_background_rainbow(t_param *cub3d)
{
	int	x;
	int	y;
	int	color;
	int w;
	int h;

	x = cub3d->window.width;
	w = x;
	while (x--)
	{
		y = cub3d->window.height;
		h = y;
		while (y--)
		{
			color = (x * 255) / w +
					((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
			mlx_pixel_put(cub3d->mlx, cub3d->win, x, y, color);
		}
	}
}

void	c3d_draw_background(t_param *cub3d)
{
	int	x;
	int	y;
	int	position;

	y = 0;
	while (y < cub3d->window.height)
	{
		x = 0;
		while (x < cub3d->window.width)
		{
			position = c3d_pixel_position(x, y,
				cub3d->render.bits_per_pixel, cub3d->render.size_line);
			if (y < cub3d->window.height / 2)
				*(unsigned int*)(cub3d->render.img_data + position) =
							cub3d->ceiling.color;
			else
				*(unsigned int*)(cub3d->render.img_data + position) =
							cub3d->floor.color;
			++x;
		}
		++y;
	}
}
