/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_create_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:39:19 by mg                #+#    #+#             */
/*   Updated: 2020/10/03 23:59:14 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_create_image(t_param *cub3d, t_image *img, int w, int h)
{
	img->img_ptr = mlx_new_image(cub3d->mlx, w, h);
	if (!img->img_ptr)
		c3d_print_error(cub3d, "MLX NEW IMAGE MALLOC");
	img->img_data = mlx_get_data_addr(img->img_ptr,
	&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!img->img_data)
		c3d_print_error(cub3d, "MLX NEW IMAGE DATA");
}
