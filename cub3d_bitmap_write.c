/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bitmap_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:47:30 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 14:55:03 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_bitmap_write_header(int fd, t_image *img)
{
	int				y;
	int				tmp;
	unsigned char	bmpfileheader[54];
	unsigned long	filesize;

	y = 0;
	filesize = c3d_bitmap_size(img->width, img->height);
	ft_printf("Bitmap File Size: %u\n", filesize);
	while (y < 54)
		bmpfileheader[y++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	c3d_bitmap_write_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = img->width;
	c3d_bitmap_write_int_in_char(bmpfileheader + 18, tmp);
	tmp = img->height;
	c3d_bitmap_write_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

int		c3d_bitmap_write_data(int fd, t_image *img)
{
	int			y;
	int			x;
	uint32_t	color;

	y = img->height;
	while (y--)
	{
		x = -1;
		while (++x < img->width)
		{
			color = c3d_pixel_get_color(img, x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
		}
	}
	return (1);
}
