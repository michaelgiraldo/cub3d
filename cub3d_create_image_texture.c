/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_create_image_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:52:15 by mg                #+#    #+#             */
/*   Updated: 2020/09/30 23:32:21 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_create_texture(t_param *cub3d, t_image *texture, char *path)
{
	if (open(path, O_RDONLY) == -1)
		exit(c3d_print_error("Texture: Error opening texture file.\n"));
	texture->img_ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
										&texture->width, &texture->height);
	texture->img_data = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
}
