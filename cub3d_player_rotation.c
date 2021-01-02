/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:52:14 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 23:08:38 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_player_rotation(t_param *cub3d, int direction)
{
	cub3d->player.angle += (double)M_PI / 36.0 * (double)direction;
	cub3d->window.render = 1;
	c3d_player_normalize_angle(cub3d);
}

void	c3d_player_normalize_angle(t_param *cub3d)
{
	if (cub3d->player.angle < 0)
		cub3d->player.angle = (2 * M_PI) + cub3d->player.angle;
	else if (cub3d->player.angle > (2 * M_PI))
		cub3d->player.angle = cub3d->player.angle - (2 * M_PI);
}
