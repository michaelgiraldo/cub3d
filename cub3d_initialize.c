/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:33:17 by mg                #+#    #+#             */
/*   Updated: 2020/10/01 22:19:54 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_initiate(t_param *cub3d)
{
	c3d_initialize_display(cub3d);
	c3d_initialize_map(cub3d);
	c3d_initialize_sprite(cub3d);
	c3d_window_distance_plane(cub3d);
	return (1);
}

int		c3d_initialize_display(t_param *cub3d)
{
	if (!(cub3d->mlx = mlx_init()))
		return (c3d_print_error("Display: MLX Initiation Failed.\n"));
	if (!(c3d_parse_map_file(cub3d)))
		return (c3d_print_error("Map File: issue with map file.\n"));
	if (!(cub3d->win =
	mlx_new_window(cub3d->mlx, cub3d->window.width, cub3d->window.height,
											"Michael Giraldo - Cub3d - GAME")))
		return (c3d_print_error("Display: Window Initiation Failed.\n"));
	c3d_create_image(cub3d,
					&cub3d->render, cub3d->window.width, cub3d->window.height);
	return (1);
}

void	c3d_initialize_map(t_param *cub3d)
{
	cub3d->map.tile_size = 64;
	c3d_map_grid_allocation(cub3d);
	c3d_parse_map_grid(cub3d);
	c3d_parse_map_player(cub3d);
	cub3d->map.step = cub3d->map.tile_size / 2;
	cub3d->map.width = cub3d->map.tile_size * cub3d->map.colum;
	cub3d->map.height = cub3d->map.tile_size * cub3d->map.row;
}

void	c3d_initialize_sprite(t_param *cub3d)
{
	c3d_sprite_malloc_map_grid(cub3d);
	c3d_sprite_malloc_visible_arrary(cub3d);
	c3d_sprite_grid_default(cub3d);
	c3d_sprite_grid_coordinate(cub3d);
	cub3d->wall.height_at = ft_memalloc(cub3d->window.width * sizeof(int));
	if (cub3d->wall.height_at == NULL)
		c3d_print_error("Sprite: Wall Height At Memory Allocation Failed.\n");
}
