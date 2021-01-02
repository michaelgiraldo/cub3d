/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_initialize_display.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:42:38 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 23:42:24 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_initialize_display(t_param *cub3d)
{
	c3d_initialize_display_mlx(cub3d);
	c3d_parse_map_file(cub3d);
	if (!cub3d->bitmap)
		c3d_initialize_display_window(cub3d);
	c3d_initialize_render_image(cub3d);
}

/*
** https://github.com/sguillia/42-fractol/blob/master/fractol/init_t_mlx.c
**
** Useage example of autorepeat
*/

void	c3d_initialize_display_mlx(t_param *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		c3d_print_error_sys(cub3d, "DISPLAY MLX");
	mlx_do_key_autorepeaton(cub3d->mlx);
}

void	c3d_initialize_display_window(t_param *cub3d)
{
	cub3d->win = mlx_new_window(cub3d->mlx,
	cub3d->window.width, cub3d->window.height, "Michael Giraldo - Cub3d");
	if (!cub3d->win)
		c3d_print_error_sys(cub3d, "DISPLAY WINDOW");
}

void	c3d_initialize_render_image(t_param *cub3d)
{
	c3d_create_image(cub3d, &cub3d->render);
}
