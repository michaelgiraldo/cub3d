/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:56:54 by mg                #+#    #+#             */
/*   Updated: 2020/09/15 23:38:01 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_file_texture(char *line, t_param *cub3d)
{
	char	*path;

	if (!(path = c3d_parse_map_texture_path(line)))
		exit(c3d_print_error("Texture File: Invalid file\n"));
	else if (*line == 'N' && *(line + 1) == 'O')
		c3d_create_texture_from_xpm(cub3d, &cub3d->texture.north, path);
	else if (*line == 'S' && *(line + 1) == 'O')
		c3d_create_texture_from_xpm(cub3d, &cub3d->texture.south, path);
	else if (*line == 'W' && *(line + 1) == 'E')
		c3d_create_texture_from_xpm(cub3d, &cub3d->texture.west, path);
	else if (*line == 'E' && *(line + 1) == 'A')
		c3d_create_texture_from_xpm(cub3d, &cub3d->texture.east, path);
	else if (*line == 'S' && *(line + 1) == ' ')
		c3d_create_texture_from_xpm(cub3d, &cub3d->texture.sprite, path);
}
