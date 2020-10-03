/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pixel_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:34:10 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 19:08:12 by mg               ###   ########.fr       */
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

int			c3d_pixel_postion(int x, int y, int bits_per_pixel, int size_line)
{
	return (y * size_line + x * (bits_per_pixel / 8));
}

int		c3d_pixel_get_image_color(t_param *cub3d, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(cub3d->render.img_data
		+ (4 * (int)cub3d->window.width * ((int)cub3d->window.height - 1 - y))
		+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}
