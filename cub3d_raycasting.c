/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:31:30 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 20:16:36 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 	start_angle = cub3d->player.angle + (M_PI / 6);
** 	end_angle = cub3d->player.angle - (M_PI / 6);
*/

void	c3d_raycasting(t_param *cub3d)
{
	int x;

	x = cub3d->window.width;
	c3d_draw_background(cub3d);
	while (x--)
	{
		c3d_raycasting_ray_angle_at_x(cub3d, x);
		c3d_raycasting_normalize_ray_angle(cub3d);
		c3d_raycasting_horizontal(cub3d);
		c3d_raycasting_vertical(cub3d);
		c3d_draw_wall_strip(cub3d, x);
	}
	c3d_sprite_visible(cub3d);
	if (cub3d->sprite.max > 0)
		c3d_draw_sprite(cub3d);
	if (cub3d->bitmap)
		c3d_bitmap_save(cub3d);
	c3d_window_render(cub3d);
}

void	c3d_raycasting_normalize_ray_angle(t_param *cub3d)
{
	if (cub3d->ray.angle < 0)
		cub3d->ray.angle = (2 * M_PI) + cub3d->ray.angle;
	else if (cub3d->ray.angle > (2 * M_PI))
		cub3d->ray.angle = cub3d->ray.angle - (2 * M_PI);
}

void	c3d_raycasting_ray_angle_at_x(t_param *cub3d, int x)
{
	cub3d->ray.angle = cub3d->player.angle +
	atan((double)((double)((cub3d->window.width - 1) / 2.0) - x) /
				((double)((cub3d->window.width - 1) / 2.0) / tan(M_PI / 6.0)));
}

/*
** BELOW code is used to prove the use (cub3d->window.width - 1) / 2
**
** WINDOW WIDTH - 1
**
** Instead of (cub3d->window.width / 2.0)
**
** This will correctly
** align WINDOW WIDTH MAX with end_angle = player_angle - M_PI / 6;
** align WINDOW WIDTH MIN (ZERO) with start_angle = player_angle + M_PI / 6;
**
** For Example
** WINDOW WIDTH = 1024 (MAX)
**
** DISPLAY X range 0 to 1023
** WINDOW WIDTH MAX - 1 = 1023
** WINDOW WIDTH MIN = 0
*/

/*
** #include <stdio.h>
** #include <math.h>
**
**
** int main () {
** 	int x;
** 	double ray_angle;
** 	double player_angle;
** 	double end_angle;
** 	double start_angle;
** 	double increment_angle;
** 	double test_angle;
**
** 	x = 1023;
** 	player_angle = M_PI;
** 	end_angle = player_angle - M_PI / 6;
** 	start_angle = player_angle + M_PI / 6;
** 	increment_angle = (M_PI / 3) / 1023;
**
** 	while (x >= 0)
** 	{
** 		ray_angle = player_angle;
** 		test_angle = end_angle;
**    		ray_angle += atan((double)((double)(1023.0 / 2.0) - x) /
**		((double)(1023.0 / 2.0) / tan(M_PI / 6.0)));
** 		test_angle += ((1023 - x) * increment_angle);
**
** 		// change p_r_i_n_t_f  remove underscores
** 		p_r_i_n_t_f("|%04d|ANGLE|%10.10f| >>> TEST ANGLE >>> |%10.10lf|
** 		MATCH |%d| >>> END ANGLE >>> |%10.10lf| MATCH |%d|
**		>>> START ANGLE >>> |%10.10lf| MATCH |%d|\n",
** 		x,
** 		ray_angle,
** 		test_angle, (test_angle == ray_angle),
** 		end_angle, (end_angle == ray_angle),
** 		start_angle, (start_angle == ray_angle));
** 		--x;
** 	}
**
**    return(0);
** }
*/
