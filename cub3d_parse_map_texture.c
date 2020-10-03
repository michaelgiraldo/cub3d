/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:56:54 by mg                #+#    #+#             */
/*   Updated: 2020/09/30 23:30:06 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_file_texture(char *line, t_param *cub3d)
{
	char	*path;

	if (!(path = c3d_parse_map_texture_path(line)))
		exit(c3d_print_error("Texture File: Invalid file\n"));
	else if (*line == 'N' && *(line + 1) == 'O')
		c3d_create_texture(cub3d, &cub3d->texture.north, path);
	else if (*line == 'S' && *(line + 1) == 'O')
		c3d_create_texture(cub3d, &cub3d->texture.south, path);
	else if (*line == 'W' && *(line + 1) == 'E')
		c3d_create_texture(cub3d, &cub3d->texture.west, path);
	else if (*line == 'E' && *(line + 1) == 'A')
		c3d_create_texture(cub3d, &cub3d->texture.east, path);
	else if (*line == 'S' && *(line + 1) == ' ')
		c3d_create_texture(cub3d, &cub3d->texture.sprite, path);
}

/*
** Parse Texture Path used by Map Texture, Floor, and Ceiling Functions
*/

char	*c3d_parse_map_texture_path(char *line)
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
