/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse_map_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:36:54 by mg                #+#    #+#             */
/*   Updated: 2020/09/15 13:07:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_parse_map_grid(t_param *cub3d)
{
	char	*line;
	int		i;

	if ((cub3d->map.fd = open(cub3d->map.file, O_RDONLY)) == -1)
		return (c3d_print_error("Error opening Cub3d Map File.\n"));
	i = 0;
	while (get_next_line(cub3d->map.fd, &line) > 0)
	{
		if (c3d_map_file_is_resolution(line) ||
			c3d_map_file_is_texture(line) ||
			c3d_map_file_is_floor_or_ceiling(line) ||
			(*line == '\0'))
			;
		else
		{
			if ((int)ft_strlen(line) > cub3d->map.colum)
				return (c3d_print_error("Map Grid: with grid colum size.\n"));
			else
				c3d_parse_map_grid_copy(i++, line, cub3d);
		}
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
	while (*line && (j < cub3d->map.colum))
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
	while (j < cub3d->map.colum)
	{
		cub3d->map.grid[i][j] = 0;
		++j;
	}
}

int		c3d_map_grid_allocation(t_param *cub3d)
{
	int i;

	i = 0;
	if (!(cub3d->window.height > 0 && cub3d->window.width > 0))
		return (c3d_print_error("Map Grid: Invalid Map Height or Width.\n"));
	cub3d->map.grid = malloc(cub3d->window.height * sizeof(int *));
	if (cub3d->map.grid == NULL)
		return (c3d_print_error("Map Grid: Memory Allocation Failed.\n"));
	while (i < cub3d->window.width)
	{
		cub3d->map.grid[i] = malloc(cub3d->window.width * sizeof(int));
		if (cub3d->map.grid[i] == NULL)
			return (c3d_print_error("Map Grid: Memory Allocation Failed.\n"));
		++i;
	}
	return (1);
}

void	c3d_map_grid_free(t_param *cub3d)
{
	int i;

	i = 0;
	while (i < cub3d->window.height)
		free(cub3d->map.grid[i]);
	free(cub3d->map.grid);
}
