/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bitmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:58:47 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 00:19:05 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_bitmap_save(t_param *cub3d)
{
	int	fd;
	int error;

	if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
		error = 1;
	if (!c3d_bitmap_write_header(fd, cub3d))
		error = 2;
	if (!c3d_bitmap_write_data(fd, cub3d))
		error = 3;
	close(fd);
	if (error == 1)
		c3d_print_error(cub3d, "ISSUE SAVING BITMAP - OPENING FILE");
	else if (error == 2)
		c3d_print_error(cub3d, "ISSUE SAVING BITMAP - WRITING HEADER");
	else if (error == 3)
		c3d_print_error(cub3d, "ISSUE SAVING BITMAP - WRITING DATA");
	cub3d->bitmap = 0;
}

/*
** https://github.com/skeeto/bmp
*/

long	c3d_bitmap_pad(long width)
{
	long pad;

	pad = ((width % 4) * -3UL) & 3;
	return (pad);
}

size_t	c3d_bitmap_size(long width, long height)
{
	long pad;

	pad = c3d_bitmap_pad(width);
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

void	c3d_bitmap_write_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value >> 0);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}
