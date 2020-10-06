/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_floor_ceiling.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 13:29:15 by mg                #+#    #+#             */
/*   Updated: 2020/10/04 00:24:17 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_floor_or_ceiling(char *line, t_param *cub3d)
{
	if (*line == 'F' && *(line + 1) == ' ')
		cub3d->floor.texture.file = ft_strdup(line);
	else if (*line == 'C' && *(line + 1) == ' ')
		cub3d->ceiling.texture.file = ft_strdup(line);
}
