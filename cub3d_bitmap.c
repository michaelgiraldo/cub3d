/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bitmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:58:47 by mg                #+#    #+#             */
/*   Updated: 2020/09/20 15:49:11 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** https://github.com/skeeto/bmp
*/

long			c3d_bmp_pad(long width)
{
	long pad;

	pad = ((width % 4) * -3UL) & 3;
	return (pad);
}

unsigned long	c3d_bmp_size(long width, long height)
{
	long pad;

	pad = c3d_bmp_pad(width);
	if (width < 1 || height < 1)
		return (0);
	else if (width > ((0x7fffffffL - 14 - 40) / height - pad) / 3)
		return (0);
	else
		return (height * (width * 3 + pad) + 14 + 40);
}

/*
** https://github.com/Glagan/42-cub3d/blob/master/bmp.c
*/

void			c3d_set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value >> 0);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int				c3d_get_image_color(t_param *cub3d, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(cub3d->background.img_data
		+ (4 * (int)cub3d->window.width * ((int)cub3d->window.height - 1 - y))
		+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int				c3d_bitmap_save(t_param *cub3d)
{
	int	fd;

	if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!c3d_write_bmp_header(fd, cub3d))
		return (0);
	if (!c3d_write_bmp_data(fd, cub3d))
		return (0);
	close(fd);
	return (1);
}
