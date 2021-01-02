/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:31:19 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 13:04:25 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_draw_sprite(t_param *cub3d)
{
	int k;

	k = cub3d->sprite.max;
	while (k)
		c3d_draw_sprite_internal(cub3d, --k);
}

void	c3d_draw_sprite_internal(t_param *cub3d, int k)
{
	int y;
	int x;
	int y_top;
	int x_offset;
	int y_offset;

	x = cub3d->sprite.visible[k].center_x - cub3d->sprite.visible[k].height / 2;
	y_top = (cub3d->window.height - cub3d->sprite.visible[k].height) / 2;
	x_offset = -1;
	while (++x_offset < cub3d->sprite.visible[k].height)
	{
		y_offset = -1;
		y = y_top;
		while (++y_offset < cub3d->sprite.visible[k].height)
		{
			if (c3d_draw_sprite_valid(cub3d, k, x, y))
			{
				c3d_sprite_texture(cub3d, k, x_offset, y_offset);
				c3d_draw_sprite_pixel(cub3d, k, x, y);
			}
			++y;
		}
		++x;
	}
}

int		c3d_draw_sprite_valid(t_param *cub3d, int k, int x, int y)
{
	if (y >= 0 && y < cub3d->window.height &&
		x >= 0 && x < cub3d->window.width &&
		cub3d->sprite.visible[k].height > cub3d->wall.height_at[x])
		return (1);
	return (0);
}

void	c3d_draw_sprite_pixel(t_param *cub3d, int k, int x, int y)
{
	if (!(c3d_get_t(cub3d->sprite.visible[k].color) == 0xFF))
		c3d_pixel_set_color(&cub3d->render, x, y,
												cub3d->sprite.visible[k].color);
}
