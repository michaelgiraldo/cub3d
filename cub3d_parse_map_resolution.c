/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_map_resolution.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:05:38 by mg                #+#    #+#             */
/*   Updated: 2020/09/20 15:50:59 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_parse_map_resolution(char *line, t_param *cub3d)
{
	char *resolution;

	resolution = ft_strnew(0);
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&resolution, *line++);
	cub3d->window.width = ft_atoi(resolution);
	*resolution = '\0';
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&resolution, *line++);
	cub3d->window.height = ft_atoi(resolution);
	free(resolution);
}
