/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_image_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:39:19 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 22:32:34 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** img->img_size = (img->width + 32) * img->height * 4
** comes from mlx_new_image.c line 112
*/

void	c3d_create_image(t_param *cub3d, t_image *img)
{
	img->width = cub3d->window.width;
	img->height = cub3d->window.height;
	if (img->img_ptr)
		c3d_print_error(cub3d, "MLX EXISITING IMAGE");
	img->img_ptr =
		mlx_new_image(cub3d->mlx, img->width, img->height);
	if (!img->img_ptr)
		c3d_print_error_sys(cub3d, "MLX NEW IMAGE MALLOC");
	img->img_data =
		mlx_get_data_addr(img->img_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!img->img_data)
		c3d_print_error_sys(cub3d, "MLX NEW IMAGE DATA");
	img->img_size = (img->width + 32) * img->height * 4;
}

void	c3d_memcpy_image(t_image *a, t_image *b)
{
	if (a->img_size == b->img_size)
		ft_memmove(a->img_data, b->img_data, b->img_size);
}
