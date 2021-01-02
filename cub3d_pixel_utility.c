/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pixel_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:34:10 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 13:32:48 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	c3d_pixel_get_color(t_image *img, int x, int y)
{
	uint32_t	*dst;

	dst = (uint32_t *)(img->img_data +
					(y * img->size_line + x * (img->bits_per_pixel / 8)));
	return (*dst);
}

void		c3d_pixel_set_color(t_image *img, int x, int y, uint32_t color)
{
	uint32_t	*dst;

	dst = (uint32_t *)(img->img_data +
					(y * img->size_line + x * (img->bits_per_pixel / 8)));
	*dst = color;
}

uint32_t	c3d_pixel_get_color_pos(t_image *img, int pos)
{
	uint32_t	*dst;

	dst = (uint32_t *)(img->img_data + pos);
	return (*dst);
}

void		c3d_pixel_set_color_pos(t_image *img, int pos, uint32_t color)
{
	uint32_t	*dst;

	dst = (uint32_t *)(img->img_data + pos);
	*dst = color;
}

int			c3d_pixel_position(int x, int y, int bits_per_pixel, int size_line)
{
	return (y * size_line + x * (bits_per_pixel / 8));
}
