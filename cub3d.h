/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:36:02 by mg                #+#    #+#             */
/*   Updated: 2020/09/21 18:32:36 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "getline/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <fcntl.h>
# include "cub3d_structure.h"

/*
** Linux key code
*/
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307
# define HORIZONTAL		1
# define VERTICAL		0

int		c3d_bitmap_save(t_param *cub3d);
int		c3d_write_bmp_header(int fd, t_param *cub3d);
int		c3d_write_bmp_data(int fd, t_param *cub3d);
int		c3d_pixel_postion(int x, int y, int bits_per_pixel, int size_line);
void		c3d_set_int_in_char(unsigned char *start, int value);
long			c3d_bmp_pad(long width);
unsigned long	c3d_bmp_size(long width, long height);
int		c3d_get_image_color(t_param *cub3d, int x, int y);

void	cub3d_initialize_struct(t_param *cub3d);


/*
** 	Set wall varaiblees
*/
void 	c3d_set_wall(t_param *cub3d);
void 	c3d_set_wall_type(t_param *cub3d);
void 	c3d_set_wall_distance(t_param *cub3d);
void 	c3d_set_wall_distance_plane(t_param *cub3d);
void 	c3d_set_wall_height(t_param *cub3d);

/*
** 	Determine  north, south, west, east facing wall
*/

void	c3d_set_wall_facing(t_param *cub3d);
void	c3d_set_wall_facing_quadrant_1(t_param *cub3d);
void	c3d_set_wall_facing_quadrant_2(t_param *cub3d);
void	c3d_set_wall_facing_quadrant_3(t_param *cub3d);
void	c3d_set_wall_facing_quadrant_4(t_param *cub3d);


void c3d_set_wall_texture(t_param *cub3d);


/*
** Raycasting
*/

void	c3d_raycasting(t_param *cub3d);

/*
** Raycasting - Hortizontal
*/

void	c3d_raycasting_horizontal_intercept(t_param *cub3d);
void	c3d_raycasting_horizontal_wall_check(t_param *cub3d);
void	c3d_raycasting_horizontal_wall_distance(t_param *cub3d);

/*
** Raycasting - Vertical
*/

void	c3d_raycasting_vertical_intercept(t_param *cub3d);
void	c3d_raycasting_vertical_wall_check(t_param *cub3d);
void	c3d_raycasting_vertical_wall_distance(t_param *cub3d);

void	c3d_draw_background(t_param *cub3d);
void	c3d_draw_minimap(t_param *cub3d);
void	c3d_draw_strip(int x, t_param *cub3d);


void	c3d_print_struct(t_param *cub3d);
void	c3d_print_map_grid(t_param *cub3d);
int		c3d_key_press(int keycode, t_param *cub3d);

int		c3d_print_error(char *msg);
int		c3d_initiate_display(t_param *cub3d);

int		c3d_parse_map_file(t_param *cub3d);
int		c3d_parse_map_grid(t_param *cub3d);
int		c3d_parse_map_rgb(char *line);
void	c3d_parse_map_resolution(char *line, t_param *cub3d);
void	c3d_parse_map_floor_or_ceiling(char *line, t_param *cub3d);
void	c3d_parse_map_file_texture(char *line, t_param *cub3d);
void	c3d_parse_map_player(t_param *cub3d);
char	*c3d_parse_map_texture_path(char *line);

void	c3d_parse_map_grid_copy(int i, char *line, t_param *cub3d);
void	cub3d_map_player_initialize(t_param *cub3d, double angle, int x, int y);

int		c3d_map_grid_allocation(t_param *cub3d);
void	c3d_map_grid_free(t_param *cub3d);

int		c3d_map_file_is_resolution(char *line);
int		c3d_map_file_is_texture(char *line);
int		c3d_map_file_is_floor_or_ceiling(char *line);

int		c3d_create_trgb(int t, int r, int g, int b);
void	c3d_create_img(t_param *cub3d, t_image *image, int width, int height);
void	c3d_create_texture_from_xpm(t_param *cub3d, t_image *texture, char *path);

#endif
