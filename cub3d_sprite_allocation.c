/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_allocation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 03:13:18 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 13:37:53 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_sprite_malloc_map_grid(t_param *cub3d)
{
	int i;

	i = 0;
	if (!(cub3d->map.row > 0 && cub3d->map.column > 0))
		c3d_print_error(cub3d, "Sprite Map: Invalid Map Height or Width.");
	cub3d->sprite.grid = malloc(cub3d->map.row * sizeof(t_sprite_grid *));
	if (!cub3d->sprite.grid)
		c3d_print_error(cub3d, "SPRITE GRID #1");
	while (i < cub3d->map.row)
	{
		cub3d->sprite.grid[i] =
		malloc(cub3d->map.column * sizeof(t_sprite_grid));
		if (!cub3d->sprite.grid[i] || !(cub3d->free.sprite_row = i + 1))
			c3d_print_error(cub3d, "SPRITE GRID #2");
		++i;
	}
}

void	c3d_sprite_malloc_visible_arrary(t_param *cub3d)
{
	uint size;

	size = MAX_SPRITE * sizeof(t_sprite_info);
	cub3d->sprite.visible = malloc(size);
	if (!(cub3d->sprite.visible))
		c3d_print_error(cub3d, "SPRITE GRID");
}

void	c3d_sprite_map_grid_free(t_param *cub3d)
{
	int i;

	i = -1;
	if (cub3d->free.sprite_row)
		while (++i < cub3d->free.sprite_row)
			free(cub3d->sprite.grid[i]);
	free(cub3d->sprite.grid);
}
