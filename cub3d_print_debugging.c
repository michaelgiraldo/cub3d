/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print_debugging.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:05:36 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 20:12:56 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_print_map_grid(t_param *cub3d)
{
	int i;
	int j;

	i = 0;
	ft_printf("Map Grid: START\n");
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
			ft_putnbr(cub3d->map.grid[i][j++]);
		ft_putchar('\n');
		i++;
	}
	ft_printf("Map Grid: END\n");
}

void	c3d_print_sprite_grid(t_param *cub3d)
{
	int i;
	int j;

	i = 0;
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
		{
			ft_printf("|%.2lf, %.2lf| ",
				cub3d->sprite.grid[i][j].x,
				cub3d->sprite.grid[i][j].y);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void	c3d_print_strip(t_param *cub3d)
{
	ft_printf("H.wall_hit |%d| H.intersect (x, y) |%lf, %lf| \
	H.wall_hit (x, y) |%lf, %lf| H.step (x, y) |%lf, %lf| \
	H.distance |%lf| h.angle |%lf|\n",
	cub3d->horizontal.wall_hit,
	cub3d->horizontal.xintercept, cub3d->horizontal.yintercept,
	cub3d->horizontal.x, cub3d->horizontal.y,
	cub3d->horizontal.xstep, cub3d->horizontal.ystep,
	cub3d->horizontal.distance, cub3d->ray.angle);
	ft_printf("V.wall_hit |%d| V.intersect (x, y) |%lf, %lf| \
	V.wall_hit (x, y) |%lf, %lf| V.step (x, y) |%lf, %lf| \
	V.distance |%lf| v.angle |%lf|\n",
	cub3d->vertical.wall_hit,
	cub3d->vertical.xintercept, cub3d->vertical.yintercept,
	cub3d->vertical.x, cub3d->vertical.y,
	cub3d->vertical.xstep, cub3d->vertical.ystep,
	cub3d->vertical.distance, cub3d->ray.angle);
}

void	c3d_print_sprite_strip(t_param *cub3d, int k)
{
	double	angle_increment;
	double	start_angle;
	double	delta_angle;

	ft_printf("SPRITE| ******* %d *******|\n", k);
	ft_printf("PLAYER|   x   |%lf|\n", cub3d->player.x);
	ft_printf("PLAYER|   y   |%lf|\n", cub3d->player.y);
	ft_printf("PLAYER| ANGLE |%lf|\n", cub3d->player.angle);
	ft_printf("SPRITE| ANGLE |%lf|\n", cub3d->sprite.visible[k].angle);
	ft_printf("SPRITE|   x   |%lf|\n", cub3d->sprite.visible[k].x);
	ft_printf("SPRITE|   y   |%lf|\n", cub3d->sprite.visible[k].y);
	ft_printf("SPRITE| delta x  |%lf|\n", cub3d->sprite.visible[k].delta_x);
	ft_printf("SPRITE| delta y  |%lf|\n", cub3d->sprite.visible[k].delta_y);
	ft_printf("SPRITE| distance |%lf|\n", cub3d->sprite.visible[k].distance);
	ft_printf("SPRITE| perp.dist|%lf|\n",
	cub3d->sprite.visible[k].perpendicular_distance);
	ft_printf("SPRITE|height  |%lf|\n", cub3d->sprite.visible[k].height);
	angle_increment = (M_PI / 3) / cub3d->window.width;
	start_angle = cub3d->player.angle + M_PI / 6;
	delta_angle = start_angle - cub3d->sprite.visible[k].angle;
	ft_printf("SPRITE|angle increment |%lf| \
	start angle |%lf| delta angle |%lf| center x |%lf|\n", k, angle_increment,
	start_angle, delta_angle, cub3d->sprite.visible[k].center_x);
}

void	c3d_print_texture_trgb(t_image *img)
{
	int			x;
	int			y;
	uint32_t	c;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			c = c3d_pixel_get_color(img, x, y);
			if (x > 0 && !(x % 4))
				ft_printf("\n");
			ft_printf("(%2d, %2d) (%3d, %3d, %3d, %3d) [%X] | ",
			x, y,
			c3d_get_t(c),
			c3d_get_r(c),
			c3d_get_g(c),
			c3d_get_b(c),
			c);
		}
		ft_printf("\n*********************************************************\
		*******************************************************************\
		*******************************************************************\n");
	}
}
