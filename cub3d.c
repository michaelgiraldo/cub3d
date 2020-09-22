/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:15:13 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 20:09:16 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wextra -Werror -Wall cub3d*.c libft/ft*.c getline/get*.c ft_printf/ft*.c ft_printf/pf*.c -L minilibx-linux -lmlx -lXext -lX11 -lbsd -lm -g

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_param cub3d;

	ft_memset(&cub3d, 0, sizeof(t_param));
	if (argc > 3 || argc == 1)
		return (c3d_print_error("Run Command: Wrong number of arguments\n"));

	cub3d.map.file = argv[1];

 	c3d_initiate_display(&cub3d);
	if (!(c3d_map_grid_allocation(&cub3d)))
		return (0);
	cub3d_initialize_struct(&cub3d);
	c3d_parse_map_grid(&cub3d);
	c3d_parse_map_player(&cub3d);
	c3d_draw_background(&cub3d);
//	c3d_draw_minimap(&cub3d);
//	c3d_create_img(&cub3d, &cub3d.wall, cub3d.window.width, cub3d.window.height);

	c3d_print_struct(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.background.img_ptr, 0, 0);
//	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.wall.img_ptr, 0, 0);
//	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.minimap.img_ptr, 0, 0);
	c3d_raycasting(&cub3d);
	if (argc == 3 && ft_strlen(argv[2]) == 6 && !(ft_strncmp(argv[2], "--save", 6)))
			c3d_bitmap_save(&cub3d);
	mlx_key_hook(cub3d.win, c3d_key_press, &cub3d);
	mlx_loop(cub3d.mlx);
	return (1);
}

void	c3d_print_strip(t_param *cub3d)
{
	ft_printf("H.wall_hit |%d| H.intersect (x, y) |%lf, %lf| H.wall_hit (x, y) |%lf, %lf| H.step (x, y) |%lf, %lf| H.distance |%lf| h.angle |%lf|\n", 
	cub3d->horizontal.wall_hit,
	cub3d->horizontal.xintercept, cub3d->horizontal.yintercept,
	cub3d->horizontal.x, cub3d->horizontal.y,
	cub3d->horizontal.xstep, cub3d->horizontal.ystep,
	cub3d->horizontal.wall_distance, cub3d->wall.angle);
	ft_printf("V.wall_hit |%d| V.intersect (x, y) |%lf, %lf| V.wall_hit (x, y) |%lf, %lf| V.step (x, y) |%lf, %lf| V.distance |%lf| v.angle |%lf|\n", 
	cub3d->vertical.wall_hit,
	cub3d->vertical.xintercept, cub3d->vertical.yintercept,
	cub3d->vertical.x, cub3d->vertical.y,
	cub3d->vertical.xstep, cub3d->vertical.ystep, 
	cub3d->vertical.wall_distance, cub3d->wall.angle);
}

void c3d_raycasting_normalize_angle(t_param *cub3d)
{
	if (cub3d->wall.angle < 0)
		cub3d->wall.angle = 2 * M_PI + cub3d->wall.angle;
}

/*
**	
** 	start_angle = cub3d->player.angle + (M_PI / 6);
** 	end_angle = cub3d->player.angle - (M_PI / 6);
**
*/

void c3d_raycasting(t_param *cub3d)
{
	double end_angle;
	double ray_angle;
	int x;

	end_angle = cub3d->player.angle - (M_PI / 6);
	ray_angle  = end_angle;
	x = cub3d->window.width;
	while(x--)
	{
		cub3d->wall.angle = ray_angle;
		c3d_raycasting_normalize_angle(cub3d);
		c3d_raycasting_horizontal_intercept(cub3d);
		c3d_raycasting_horizontal_wall_check(cub3d);
		c3d_raycasting_horizontal_wall_distance(cub3d);
		c3d_raycasting_vertical_intercept(cub3d);
		c3d_raycasting_vertical_wall_check(cub3d);
		c3d_raycasting_vertical_wall_distance(cub3d);
		c3d_set_wall(cub3d);
		c3d_set_wall_facing(cub3d);
		c3d_set_wall_texture(cub3d);
	//	c3d_print_strip(cub3d);
		c3d_draw_strip(x, cub3d);
		ray_angle = cub3d->player.angle + atan((double)((double)cub3d->window.width / 2.0 - x) / ((double)(cub3d->window.width / 2.0) / tan(M_PI / 6.0)));
	}
}

void	c3d_draw_strip(int x, t_param *cub3d)
{
	int y;
//	int position;
//	int color;
//	double draw_raito;

//	draw_raito = (cub3d->map.colum * cub3d->map.tile_size) / cub3d->window.width;
	y = (cub3d->window.height - cub3d->wall.height) / 2;
//	ft_printf("[Draw Strip] (x, y) |(%04d, %04d)| distance |%lf| wall height |%d| facing |%c|\n\n", x, y, cub3d->wall.distance, cub3d->wall.height, cub3d->wall.facing);
	while(cub3d->wall.height)
	{	
	//	position = c3d_pixel_postion(x, y, cub3d->wall.bits_per_pixel, cub3d->wall.size_line);
	//	*(unsigned int*)(cub3d->wall.img_data + position) = 0xFF00FF;
		mlx_pixel_put(cub3d->mlx, cub3d->win, x, y, cub3d->wall.color);

		++y;
		cub3d->wall.height--;
	}
}

int c3d_initiate_display(t_param *cub3d)
{
	if (!(cub3d->mlx = mlx_init()))
		return (c3d_print_error("Initiate Display: MLX Initiation Failed.\n"));
	if (!(c3d_parse_map_file(cub3d)))
		return (c3d_print_error("Map File: issue with map file.\n"));
	if (!(cub3d->win = mlx_new_window(cub3d->mlx, cub3d->window.width, cub3d->window.height, "Michael Giraldo - Cub3d - GAME")))
		return (c3d_print_error("Initiate Display: Window Initiation Failed.\n"));
//	if (!(cub3d->img = mlx_new_image(cub3d->mlx, cub3d->window.width, cub3d->window.height)))
//		return (c3d_print_error("Initiate Display: Image Initiation Failed.\n"));
	return (1);
}

int c3d_key_press(int keycode, t_param *cub3d)
{
	if (keycode == KEY_W)                
		ft_printf("Key Press: W\n");
	else if (keycode == KEY_S)
		ft_printf("Key Press: S\n");
	else if (keycode == KEY_A)
		ft_printf("Key Press: A\n");
	else if (keycode == KEY_D)
		ft_printf("Key Press: D\n");
	else if (keycode == KEY_LEFT)
		ft_printf("Key Press: LEFT\n");
	else if (keycode == KEY_RIGHT)
		ft_printf("Key Press: RIGHT\n");
	else if (keycode == KEY_ESC)
		ft_printf("Key Press: ESC\n");
	else
		ft_printf("Map file: %s\n", cub3d->map.file);
	return (1);
}
