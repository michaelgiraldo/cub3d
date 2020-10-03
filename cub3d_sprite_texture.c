/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:31:07 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 14:02:47 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** if(cub3d->sprite.visible[k].type == 2)
*/

void		c3d_sprite_texture(t_param *cub3d, int k, int x, int y)
{
	int			h;
	uint32_t	c;

	h = cub3d->sprite.visible[k].height;
	c = c3d_sprite_texture_pixel_color(&cub3d->texture.sprite, x, y, h);
	cub3d->sprite.visible[k].color = c;
}

uint32_t	c3d_sprite_texture_pixel_color(t_image *img, int x, int y, int h)
{
	double	texture_ratio_y;
	double	texture_ratio_x;
	double	sprite_height;

	sprite_height = h;
	texture_ratio_y = (double)img->height / sprite_height;
	y *= texture_ratio_y;
	texture_ratio_x = (double)img->width / sprite_height;
	x *= texture_ratio_x;
	return (c3d_pixel_get_color(img, x, y));
}
