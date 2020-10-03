/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:15:13 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 19:27:08 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gcc -Wextra -Werror -Wall
** cub3d*.c libft/ft*.c getline/get*.c ft_printf/ft*.c ft_printf/pf*.c
** -L minilibx-linux -lmlx -lXext -lX11 -lbsd -lm -g
*/

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_param cub3d;

	ft_memset(&cub3d, 0, sizeof(t_param));
	if (argc > 3 || argc == 1)
		return (c3d_print_error("Run Command: Wrong number of arguments\n"));
	cub3d.map.file = argv[1];
	if (argc == 3 && ft_strlen(argv[2]) == 6 &&
										!(ft_strncmp(argv[2], "--save", 6)))
		c3d_bitmap_save(&cub3d);
	c3d_initiate(&cub3d);
	c3d_print_struct(&cub3d);
	c3d_raycasting(&cub3d);
	mlx_key_hook(cub3d.win, c3d_key_press, &cub3d);
	mlx_loop(cub3d.mlx);
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
		c3d_player_next_postion(cub3d, FORWARD);
	else if (keycode == KEY_S)
		c3d_player_next_postion(cub3d, BACKWARD);
	else if (keycode == KEY_A)
		c3d_player_next_postion(cub3d, LEFT);
	else if (keycode == KEY_D)
		c3d_player_next_postion(cub3d, RIGHT);
	else if (keycode == KEY_LEFT)
		c3d_player_rotation(cub3d, COUNTERCLOCKWISE);
	else if (keycode == KEY_RIGHT)
		c3d_player_rotation(cub3d, CLOCKWISE);
	else if (keycode == KEY_ESC)
		ft_printf("Key Press: ESC\n");
	else
		ft_printf("Map file: %s\n", cub3d->map.file);
	ft_printf("\n");
	if (cub3d->window.render)
		c3d_raycasting(cub3d);
	return (1);
}
