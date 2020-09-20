/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:36:59 by mg                #+#    #+#             */
/*   Updated: 2020/09/19 16:40:47 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_parse_map_file(t_param *cub3d)
{
	char *line;

	if ((cub3d->map.fd = open(cub3d->map.file, O_RDONLY)) == -1)
		return (c3d_print_error("Error opening Cub3d Map File.\n"));
	while (get_next_line(cub3d->map.fd, &line) > 0)
	{
		if (c3d_map_file_is_resolution(line))
			c3d_parse_map_resolution(line, cub3d);
		else if (c3d_map_file_is_texture(line))
			c3d_parse_map_file_texture(line, cub3d);
		else if (c3d_map_file_is_floor_or_ceiling(line))
			c3d_parse_map_floor_or_ceiling(line, cub3d);
		else if (*line == '\0')
			;
		else
		{
			if ((int)ft_strlen(line) > cub3d->map.colum)
				cub3d->map.colum = ft_strlen(line);
			cub3d->map.row++;
		}
		free(line);
	}
	free(line);
	close(cub3d->map.fd);
	return (1);
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

