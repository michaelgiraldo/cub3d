/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture_xpm_to_image.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:52:15 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 15:39:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 		texture->file = xpm;
*/

void	c3d_texture_xpm_to_image(t_param *cub3d, t_image *texture)
{
	int		fd;
	char	*xpm;

	if (!texture->file)
		c3d_print_error(cub3d, "MISSING TEXTURE FILE");
	else if (!(xpm = c3d_texture_is_xpm_extension(texture->file)))
		c3d_print_error(cub3d, texture->file);
	else
		ft_strcpy(texture->file, xpm);
	if ((fd = open(texture->file, O_RDONLY)) == -1)
		c3d_print_error(cub3d, texture->file);
	close(fd);
	c3d_texture_xpm_to_image_internal(cub3d, texture);
}

void	c3d_texture_xpm_to_image_internal(t_param *cub3d, t_image *texture)
{
	texture->img_ptr = mlx_xpm_file_to_image(cub3d->mlx, texture->file,
										&texture->width, &texture->height);
	if (!texture->img_ptr)
		c3d_print_error(cub3d, "MLX XPM IMAGE MALLOC");
	texture->img_data = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
	if (!texture->img_data)
		c3d_print_error(cub3d, "MLX XPM IMAGE DATA");
}

char	*c3d_texture_is_xpm_extension(char *line)
{
	char *file_extension;
	char *path;

	path = NULL;
	file_extension = line + ft_strlen(line) - 4;
	if (!ft_strncmp(file_extension, ".xpm", 4))
	{
		while (!ft_isblank(*(--file_extension)))
			;
		path = ++file_extension;
	}
	return (path);
}
