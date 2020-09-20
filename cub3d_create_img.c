/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_create_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:39:19 by mg                #+#    #+#             */
/*   Updated: 2020/09/15 18:42:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_create_texture_from_xpm(t_param *cub3d, t_image *texture,
																char *path)
{
	if (open(path, O_RDONLY) == -1)
		exit (c3d_print_error("Texture: Error opening texture file.\n"));
	texture->img_ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
										&texture->width, &texture->height);
	texture->img_data = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
}

void	c3d_create_img(t_param *cub3d, t_image *image, int width, int height)
{
	image->img_ptr = mlx_new_image(cub3d->mlx, width, height);
	image->img_data = mlx_get_data_addr(image->img_ptr,
			&image->bits_per_pixel, &image->size_line, &image->endian);
}
