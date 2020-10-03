/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_allocation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 03:13:18 by mg                #+#    #+#             */
/*   Updated: 2020/10/01 22:14:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_sprite_malloc_map_grid(t_param *cub3d)
{
	int i;

	i = 0;
	if (!(cub3d->map.row > 0 && cub3d->map.colum > 0))
		c3d_print_error("Sprite Map: Invalid Map Height or Width.\n");
	cub3d->sprite.grid = malloc(cub3d->map.row * sizeof(t_sprite_grid *));
	if (cub3d->sprite.grid == NULL)
		c3d_print_error("Sprite Map: Memory Allocation Failed.\n");
	while (i < cub3d->map.row)
	{
		cub3d->sprite.grid[i] =
		malloc(cub3d->map.colum * sizeof(t_sprite_grid));
		if (cub3d->sprite.grid[i] == NULL)
			c3d_print_error("Sprite Map: Memory Allocation Failed [COLUM].\n");
		++i;
	}
}

void	c3d_sprite_malloc_visible_arrary(t_param *cub3d)
{
	cub3d->sprite.visible = malloc(50 * sizeof(t_sprite_info));
	if (cub3d->sprite.visible == NULL)
		c3d_print_error("Sprite Visible Grid: Memory Allocation Failed.\n");
}
