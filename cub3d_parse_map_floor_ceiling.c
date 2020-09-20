/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse_map_floor_ceiling.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 13:29:15 by mg                #+#    #+#             */
/*   Updated: 2020/09/15 14:28:24 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_floor_or_ceiling(char *line, t_param *cub3d)
{
	char *path;

	path = c3d_parse_map_texture_path(line);
	if (*line == 'F' && *(line + 1) == ' ')
	{
		if (path && (cub3d->floor.is_texture = 1))
			c3d_create_texture_from_xpm(cub3d, &cub3d->floor.texture, path);
		else
			cub3d->floor.color = c3d_parse_map_rgb(line);
	}
	else if (*line == 'C' && *(line + 1) == ' ')
	{
		if (path && (cub3d->ceiling.is_texture = 1))
			c3d_create_texture_from_xpm(cub3d, &cub3d->ceiling.texture, path);
		else
			cub3d->ceiling.color = c3d_parse_map_rgb(line);
	}
}

int		c3d_parse_map_rgb(char *line)
{
	char *color;
	size_t red;
	size_t green;
	size_t blue;

	color = ft_strnew(0);
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	red = ft_atoi(color);
	*color = '\0';
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	green = ft_atoi(color);
	*color = '\0';
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	blue = ft_atoi(color);
	free(color);
	return (c3d_create_trgb(0, red, green, blue));
}
