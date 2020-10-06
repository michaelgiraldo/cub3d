/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:35:54 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 00:14:57 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_print_struct(t_param *cub3d)
{
	ft_printf("Map file: %s\n", cub3d->map.file);
	ft_printf("File Descriptor: %d\n", cub3d->map.fd);
	ft_printf("Map columnn count: %d\n", cub3d->map.column);
	ft_printf("Map row count: %d\n", cub3d->map.row);
	ft_printf("Window width: %d\n", cub3d->window.width);
	ft_printf("Window height: %d\n", cub3d->window.height);
	ft_printf("floor is texure %d\n", cub3d->floor.is_texture);
	ft_printf("floor color %#X\n", cub3d->floor.color);
	ft_printf("ceiling is texure %d\n", cub3d->ceiling.is_texture);
	ft_printf("ceiling color %#X\n", cub3d->ceiling.color);
	ft_printf("player X: %lf\n", cub3d->player.x);
	ft_printf("player Y: %lf\n", cub3d->player.y);
	ft_printf("player angle: %lf\n", cub3d->player.angle);
}
