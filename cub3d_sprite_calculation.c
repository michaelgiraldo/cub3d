/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_calculation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 04:20:13 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 12:34:52 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 	Calculates the angle of sprite
**	dx = sprite.x - player.y
**	dy = player.y - sprite.y  <<< NOTE DIFFERENCE >>>
**
**	player is substracted from sprite for dy
**
**  INSTEAD OF
**
** 	sprite is substracted from player for dx
**
**	https://github.com/id-Software/wolf3d/blob/master/WOLFSRC/WL_GAME.C
** 	See line 1126
*/

void	c3d_sprite_visible_angle(t_param *cub3d, int k)
{
	double s;
	double p;
	double dx;
	double dy;

	dx = cub3d->sprite.visible[k].x - cub3d->player.x;
	dy = cub3d->player.y - cub3d->sprite.visible[k].y;
	p = cub3d->player.angle;
	s = atan2(dy, dx);
	if (s < 0)
		s += M_PI * 2;
	if (s >= 3 * M_PI_2 && p < M_PI_2)
		s -= M_PI * 2;
	if (p >= 3 * M_PI_2 && s < M_PI_2)
		s += M_PI * 2;
	cub3d->sprite.visible[k].angle = s;
	cub3d->sprite.visible[k].delta_x = dx;
	cub3d->sprite.visible[k].delta_y = dy;
}

/*
** 	Calculates the hypotenuse of sprite
*/

void	c3d_sprite_visible_distance(t_param *cub3d, int k)
{
	double dx;
	double dy;

	dx = cub3d->sprite.visible[k].delta_x;
	dy = cub3d->sprite.visible[k].delta_y;
	cub3d->sprite.visible[k].distance = hypot(dx, dy);
}

/*
** 	Calculates the perpendicular distance of sprite
*/

void	c3d_sprite_visible_perpendicular_distance(t_param *cub3d, int k)
{
	cub3d->sprite.visible[k].perpendicular_distance =
		cub3d->sprite.visible[k].distance *
		cos(cub3d->player.angle - cub3d->sprite.visible[k].angle);
}

/*
** 	Calculates the height of sprite
*/

void	c3d_sprite_visible_height(t_param *cub3d, int k)
{
	if (cub3d->sprite.visible[k].perpendicular_distance > cub3d->map.step)
		cub3d->sprite.visible[k].height =
		cub3d->map.tile_size /
		cub3d->sprite.visible[k].perpendicular_distance *
		cub3d->window.distance_plane;
	else
		cub3d->sprite.visible[k].height =
	cub3d->map.tile_size / cub3d->map.step * cub3d->window.distance_plane;
}

/*
** 	Calculates the x center on screen of sprite
*/

void	c3d_sprite_visible_xcenter(t_param *cub3d, int k)
{
	double	angle_increment;
	double	start_angle;
	double	delta_angle;

	angle_increment = (M_PI / 3) / cub3d->window.width;
	start_angle = cub3d->player.angle + M_PI / 6;
	delta_angle = start_angle - cub3d->sprite.visible[k].angle;
	cub3d->sprite.visible[k].center_x = delta_angle / angle_increment;
}
