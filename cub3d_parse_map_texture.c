/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:56:54 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 00:25:14 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_file_texture(char *line, t_param *cub3d)
{
	if (*line == 'N' && *(line + 1) == 'O')
		cub3d->texture.north.file = ft_strdup(line);
	else if (*line == 'S' && *(line + 1) == 'O')
		cub3d->texture.south.file = ft_strdup(line);
	else if (*line == 'W' && *(line + 1) == 'E')
		cub3d->texture.west.file = ft_strdup(line);
	else if (*line == 'E' && *(line + 1) == 'A')
		cub3d->texture.east.file = ft_strdup(line);
	else if (*line == 'S' && *(line + 1) == ' ')
		cub3d->texture.sprite.file = ft_strdup(line);
}
