/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:09:07 by mg                #+#    #+#             */
/*   Updated: 2020/10/03 12:45:50 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_sprite_visible(t_param *cub3d)
{
	int	k;

	k = 0;
	c3d_sprite_visible_check(cub3d);
	while (k < cub3d->sprite.max)
	{
		c3d_sprite_visible_angle(cub3d, k);
		c3d_sprite_visible_distance(cub3d, k);
		c3d_sprite_visible_perpendicular_distance(cub3d, k);
		c3d_sprite_visible_height(cub3d, k);
		c3d_sprite_visible_xcenter(cub3d, k);
		++k;
	}
	if (cub3d->sprite.max > 1)
		c3d_sprite_visible_sort(cub3d);
}

void	c3d_sprite_visible_check(t_param *cub3d)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
		{
			if (cub3d->sprite.grid[i][j].visible == 1)
			{
				cub3d->sprite.visible[k].x = cub3d->sprite.grid[i][j].x;
				cub3d->sprite.visible[k].y = cub3d->sprite.grid[i][j].y;
				cub3d->sprite.visible[k].type = cub3d->map.grid[i][j];
				cub3d->sprite.grid[i][j].visible = 0;
				++k;
			}
			++j;
		}
		++i;
	}
	cub3d->sprite.max = k;
}

void	c3d_sprite_visible_sort(t_param *cub3d)
{
	int k;
	int i;

	i = 0;
	while (i < cub3d->sprite.max - 1)
	{
		i = 0;
		k = 0;
		while (k < cub3d->sprite.max - 1)
		{
			if ((cub3d->sprite.visible[k].distance >
				cub3d->sprite.visible[k + 1].distance))
				c3d_sprite_visible_swap(&cub3d->sprite.visible[k],
										&cub3d->sprite.visible[k + 1]);
			else
				++i;
			++k;
		}
	}
}

void	c3d_sprite_visible_swap(t_sprite_info *a, t_sprite_info *b)
{
	t_sprite_info tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
