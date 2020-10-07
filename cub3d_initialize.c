/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:33:17 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 15:48:34 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_initiate_game(t_param *cub3d)
{
	c3d_initialize_display(cub3d);
	c3d_initialize_map(cub3d);
	c3d_initialize_sprite(cub3d);
	c3d_initialize_background(cub3d);
	c3d_initialize_texture(cub3d);
	c3d_window_distance_plane(cub3d);
}

void	c3d_initialize_background(t_param *cub3d)
{
	c3d_background(cub3d, &cub3d->ceiling);
	c3d_background(cub3d, &cub3d->floor);
}

void	c3d_initialize_texture(t_param *cub3d)
{
	c3d_texture_xpm_to_image(cub3d, &cub3d->texture.north);
	c3d_texture_xpm_to_image(cub3d, &cub3d->texture.south);
	c3d_texture_xpm_to_image(cub3d, &cub3d->texture.west);
	c3d_texture_xpm_to_image(cub3d, &cub3d->texture.east);
	c3d_texture_xpm_to_image(cub3d, &cub3d->texture.sprite);
}

void	c3d_initialize_map(t_param *cub3d)
{
	cub3d->map.tile_size = TILE_SIZE;
	c3d_map_grid_allocation(cub3d);
	c3d_parse_map_grid(cub3d);
	c3d_player_starting_positon(cub3d);
	c3d_map_validation(cub3d);
	cub3d->map.step = cub3d->map.tile_size / 2;
	cub3d->map.width = cub3d->map.tile_size * cub3d->map.column;
	cub3d->map.height = cub3d->map.tile_size * cub3d->map.row;
}

void	c3d_initialize_sprite(t_param *cub3d)
{
	c3d_sprite_malloc_map_grid(cub3d);
	c3d_sprite_malloc_visible_arrary(cub3d);
	c3d_sprite_grid_default(cub3d);
	c3d_sprite_grid_coordinate(cub3d);
	cub3d->wall.height_at = ft_memalloc(cub3d->window.width * sizeof(int));
	if (!cub3d->wall.height_at)
		c3d_print_error(cub3d, "SPRITE HEIGHT AT ARRAY");
}
