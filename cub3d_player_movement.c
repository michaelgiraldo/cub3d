/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:40:25 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 16:14:05 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	As grid array x, y coordinate are stored inversed
** 	lower left (x.min, y.max) the following changes are made accordingly
*/

void	c3d_player_next_position(t_param *cub3d, int direction)
{
	cub3d->next.angle = cub3d->player.angle;
	if (direction == FORWARD)
		cub3d->next.angle -= 0;
	else if (direction == BACKWARD)
		cub3d->next.angle += M_PI;
	else if (direction == LEFT)
		cub3d->next.angle += M_PI_2;
	else if (direction == RIGHT)
		cub3d->next.angle -= M_PI_2;
	c3d_player_normalize_next_angle(cub3d);
	cub3d->next.x = cub3d->player.x +
							(cub3d->map.step) * cos(cub3d->next.angle);
	cub3d->next.y = cub3d->player.y -
							(cub3d->map.step) * sin(cub3d->next.angle);
	c3d_player_next_position_wall_check(cub3d);
	c3d_player_position_sprite_check(cub3d);
}

void	c3d_player_normalize_next_angle(t_param *cub3d)
{
	if (cub3d->next.angle < 0)
		cub3d->next.angle = (2 * M_PI) + cub3d->next.angle;
	else if (cub3d->next.angle > (2 * M_PI))
		cub3d->next.angle = cub3d->next.angle - (2 * M_PI);
}

void	c3d_player_next_position_wall_check(t_param *cub3d)
{
	if (cub3d->next.x >= 0 && cub3d->next.x < cub3d->map.width &&
		cub3d->next.y >= 0 && cub3d->next.y < cub3d->map.height &&
		!c3d_player_wall_collusion(cub3d, cub3d->next.x, cub3d->next.y))
	{
		if (!c3d_player_wall_collusion(cub3d,
			cub3d->next.x + cub3d->map.step * cos(cub3d->next.angle),
			cub3d->next.y + cub3d->map.step * sin(cub3d->next.angle)))
		{
			cub3d->player.x = cub3d->next.x;
			cub3d->player.y = cub3d->next.y;
			cub3d->window.render = 1;
		}
	}
}

void	c3d_player_position_sprite_check(t_param *cub3d)
{
	if (c3d_player_sprite_collusion(cub3d, cub3d->player.x, cub3d->player.y))
	{
		cub3d->map.grid
		[(int)(cub3d->player.y / cub3d->map.tile_size)]
		[(int)(cub3d->player.x / cub3d->map.tile_size)] = 0;
		cub3d->window.render = 1;
	}
}
