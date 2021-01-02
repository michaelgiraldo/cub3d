/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:36:54 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 14:46:36 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_parse_map_grid(t_param *cub3d)
{
	char	*line;
	int		i;

	if ((cub3d->map.fd = open(cub3d->map.file, O_RDONLY)) == -1)
		c3d_print_error(cub3d, cub3d->map.file);
	i = 0;
	while (get_next_line(cub3d->map.fd, &line) > 0)
	{
		if (c3d_map_file_is_resolution(line) ||
			c3d_map_file_is_texture(line) ||
			c3d_map_file_is_floor_or_ceiling(line) ||
			(*line == '\0'))
			;
		else
			c3d_parse_map_grid_copy(i++, line, cub3d);
		free(line);
	}
	free(line);
	close(cub3d->map.fd);
	return (1);
}

void	c3d_parse_map_grid_copy(int i, char *line, t_param *cub3d)
{
	int j;

	j = 0;
	while (*line && j < cub3d->map.column)
	{
		if (*line == 32)
			cub3d->map.grid[i][j] = 0;
		else if (ft_isdigit(*line))
			cub3d->map.grid[i][j] = *line - 48;
		else if (ft_isupper(*line))
			cub3d->map.grid[i][j] = *line;
		else if (ft_islower(*line))
			cub3d->map.grid[i][j] = ft_toupper(*line);
		++line;
		++j;
	}
	while (j < cub3d->map.column)
	{
		cub3d->map.grid[i][j] = 0;
		++j;
	}
}
