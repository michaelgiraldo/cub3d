/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_collusion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:50:56 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 16:11:21 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_player_wall_collusion(t_param *cub3d, int x, int y)
{
	if (cub3d->map.grid
	[(int)(y / cub3d->map.tile_size)]
	[(int)(x / cub3d->map.tile_size)] == 1)
		return (1);
	return (0);
}

int	c3d_player_sprite_collusion(t_param *cub3d, int x, int y)
{
	if (cub3d->map.grid
	[(int)(y / cub3d->map.tile_size)]
	[(int)(x / cub3d->map.tile_size)] == 2)
		return (1);
	return (0);
}
