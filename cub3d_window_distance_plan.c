/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window_distance_plan.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:47:22 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 00:41:40 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_window_render(t_param *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
												cub3d->render.img_ptr, 0, 0);
}

/*
**	Wall Distance Plane is called by cub3d_initialize_struct()
*/

void	c3d_window_distance_plane(t_param *cub3d)
{
	cub3d->window.distance_plane =
	((double)(cub3d->window.width / 2.0) / tan(M_PI / 6.0));
}
