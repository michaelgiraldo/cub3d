/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_initialize_display.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:42:38 by mg                #+#    #+#             */
/*   Updated: 2020/10/03 23:56:25 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_initialize_display(t_param *cub3d)
{
	c3d_initialize_display_mlx(cub3d);
	c3d_parse_map_file(cub3d);
	c3d_initialize_display_window(cub3d);
	c3d_create_image(cub3d, &cub3d->render,
						cub3d->window.width, cub3d->window.height);
}

void	c3d_initialize_display_mlx(t_param *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		c3d_print_error(cub3d, "DISPLAY MLX");
}

void	c3d_initialize_display_window(t_param *cub3d)
{
	cub3d->win = mlx_new_window(cub3d->mlx,
	cub3d->window.width, cub3d->window.height, "Michael Giraldo - Cub3d");
	if (!cub3d->win)
		c3d_print_error(cub3d, "DISPLAY WINDOW");
}
