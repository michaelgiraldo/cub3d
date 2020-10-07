/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:16:54 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 15:01:09 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_background(t_param *cub3d)
{
	if (!cub3d->background.img_ptr)
		c3d_create_image(cub3d, &cub3d->background);
	c3d_draw_background_rgb(cub3d, &cub3d->background);
}

void	c3d_draw_background_rgb(t_param *cub3d, t_image *background)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub3d->window.height)
	{
		x = -1;
		while (++x < cub3d->window.width)
		{
			if (y < cub3d->window.height / 2)
				c3d_pixel_set_color(background, x, y, cub3d->ceiling.color);
			else
				c3d_pixel_set_color(background, x, y, cub3d->floor.color);
		}
	}
}
