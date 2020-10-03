/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_create_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:39:19 by mg                #+#    #+#             */
/*   Updated: 2020/09/30 23:27:57 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_create_image(t_param *cub3d, t_image *image, int width, int height)
{
	image->img_ptr = mlx_new_image(cub3d->mlx, width, height);
	image->img_data =
	mlx_get_data_addr(image->img_ptr,
	&image->bits_per_pixel, &image->size_line, &image->endian);
}
