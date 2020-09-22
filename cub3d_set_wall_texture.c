/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_wall_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:56:05 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 19:55:48 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void c3d_set_wall_texture(t_param *cub3d)
{
	if (cub3d->wall.facing == 'E')
		cub3d->wall.color = 0xFF00FF; // pink
	else if (cub3d->wall.facing == 'N')
		cub3d->wall.color = 0x087A88; // green
	else if (cub3d->wall.facing == 'W')
		cub3d->wall.color = 0xE0F01B; // yellow
	else if (cub3d->wall.facing == 'S')
		cub3d->wall.color = 0x641173;
}