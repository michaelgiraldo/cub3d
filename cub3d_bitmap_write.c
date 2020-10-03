/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bitmap_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:47:30 by mg                #+#    #+#             */
/*   Updated: 2020/10/01 22:28:36 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_bitmap_write_header(int fd, t_param *cub3d)
{
	int				y;
	int				tmp;
	unsigned char	bmpfileheader[54];
	unsigned long	filesize;

	y = 0;
	filesize = c3d_bitmap_size(cub3d->window.width, cub3d->window.height);
	ft_printf("Bitmap File Size: %u", filesize);
	while (y < 54)
		bmpfileheader[y++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	c3d_bitmap_write_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = cub3d->window.width;
	c3d_bitmap_write_int_in_char(bmpfileheader + 18, tmp);
	tmp = cub3d->window.height;
	c3d_bitmap_write_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

int		c3d_bitmap_write_data(int fd, t_param *cub3d)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < (int)cub3d->window.height)
	{
		x = 0;
		while (x < (int)cub3d->window.width)
		{
			color = c3d_pixel_get_image_color(cub3d, x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
			++x;
		}
		++y;
	}
	return (1);
}
