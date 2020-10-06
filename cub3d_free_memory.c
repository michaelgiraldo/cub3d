/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:38:48 by mg                #+#    #+#             */
/*   Updated: 2020/10/05 15:19:36 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3d_free_memory(t_param *cub3d)
{
	c3d_free_memory_str(cub3d);
	c3d_free_memory_array(cub3d);
	c3d_free_memory_mlx_img(cub3d);
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->mlx)
		mlx_destroy_display(cub3d->mlx);
	if (cub3d->mlx)
		free(cub3d->mlx);
	exit(1);
}

void	c3d_free_memory_mlx_img(t_param *cub3d)
{
	if (cub3d->texture.north.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->texture.north.img_ptr);
	if (cub3d->texture.south.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->texture.south.img_ptr);
	if (cub3d->texture.west.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->texture.west.img_ptr);
	if (cub3d->texture.east.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->texture.east.img_ptr);
	if (cub3d->texture.sprite.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->texture.sprite.img_ptr);
	if (cub3d->render.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->render.img_ptr);
	if (cub3d->floor.texture.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->floor.texture.img_ptr);
	if (cub3d->ceiling.texture.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->ceiling.texture.img_ptr);
}

void	c3d_free_memory_str(t_param *cub3d)
{
	if (cub3d->texture.north.file)
		free(cub3d->texture.north.file);
	if (cub3d->texture.south.file)
		free(cub3d->texture.south.file);
	if (cub3d->texture.west.file)
		free(cub3d->texture.west.file);
	if (cub3d->texture.east.file)
		free(cub3d->texture.east.file);
	if (cub3d->texture.sprite.file)
		free(cub3d->texture.sprite.file);
	if (cub3d->ceiling.texture.file)
		free(cub3d->ceiling.texture.file);
	if (cub3d->floor.texture.file)
		free(cub3d->floor.texture.file);
}

void	c3d_free_memory_array(t_param *cub3d)
{
	if (cub3d->sprite.visible)
		free(cub3d->sprite.visible);
	if (cub3d->wall.height_at)
		free(cub3d->wall.height_at);
	if (cub3d->map.grid)
		c3d_map_grid_free(cub3d);
	if (cub3d->sprite.grid)
		c3d_sprite_map_grid_free(cub3d);
}
