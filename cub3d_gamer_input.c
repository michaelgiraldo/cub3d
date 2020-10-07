/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_gamer_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:47:07 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 21:20:23 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_x_window_exit(t_param *cub3d)
{
	ft_printf("THANK YOU FOR PLAYING MY GAME\n");
	c3d_free_memory(cub3d);
	return (1);
}

/*
** 	KEY_W = NORTH = FORWARD MOVEMENT
**	KEY_S = SOUTH = BACKWARD MOVEMENT
** 	KEY_A = WEST  = LEFT MOVEMENT
** 	KEY_D = EAST  = RIGHT MOVEMENT
** 	KEY_LEFT = COUNTER CLOCKWISE ROTATION
** 	KEY_RIGHT = CLOCKWISE ROTATION
*/

int		c3d_key_press(int keycode, t_param *cub3d)
{
	cub3d->window.render = 0;
	if (keycode == KEY_W)
		c3d_player_next_position(cub3d, FORWARD);
	else if (keycode == KEY_S)
		c3d_player_next_position(cub3d, BACKWARD);
	else if (keycode == KEY_A)
		c3d_player_next_position(cub3d, LEFT);
	else if (keycode == KEY_D)
		c3d_player_next_position(cub3d, RIGHT);
	else if (keycode == KEY_LEFT)
		c3d_player_rotation(cub3d, COUNTERCLOCKWISE);
	else if (keycode == KEY_RIGHT)
		c3d_player_rotation(cub3d, CLOCKWISE);
	else if (keycode == KEY_ESC)
		c3d_free_memory(cub3d);
	else
		c3d_valid_keys();
	if (cub3d->window.render)
		c3d_raycasting(cub3d);
	return (1);
}

void	c3d_valid_keys(void)
{
	ft_printf("VALID KEYS:");
	ft_printf("MOVEMENT: W (FORWARD) A (LEFT) S (BACKWARD) D (RIGHT) and ");
	ft_printf("ROTATION: LEFT ARROW (COUNTER CLOCKWISE)");
	ft_printf("& RIGHT ARROW (CLOCKWISE)\n");
}
