/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_rainbow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:49:06 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 15:01:08 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_rainbow(t_param *cub3d)
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
