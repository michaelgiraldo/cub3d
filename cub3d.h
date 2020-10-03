/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:55:21 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 21:55:17 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "getline/get_next_line.h"
# include "ft_printf/ft_printf.h"

# include "cub3d_structure.h"
# include "cub3d_define.h"

/*
** 	Bitmap
*/

int			c3d_bitmap_save(t_param *cub3d);
long		c3d_bitmap_pad(long width);
size_t		c3d_bitmap_size(long width, long height);
int			c3d_bitmap_write_header(int fd, t_param *cub3d);
int			c3d_bitmap_write_data(int fd, t_param *cub3d);
void		c3d_bitmap_write_int_in_char(unsigned char *start, int value);

/*
** 	Color 
*/

uint32_t	c3d_create_trgb(int t, int r, int g, int b);
uint32_t	c3d_get_t(uint32_t trgb);
uint32_t	c3d_get_r(uint32_t trgb);
uint32_t	c3d_get_g(uint32_t trgb);
uint32_t	c3d_get_b(uint32_t trgb);

/*
** 	Pixel 
*/

uint32_t	c3d_pixel_get_color(t_image *img, int x, int y);
void		c3d_pixel_set_color(t_image *img, int x, int y, uint32_t color);
uint32_t	c3d_sprite_texture_pixel_color(t_image *img, int x, int y, int h);
int			c3d_pixel_get_image_color(t_param *cub3d, int x, int y);
int			c3d_pixel_postion(int x, int y, int bits_per_pixel, int size_line);

/*
** MLX create functons 
*/

void		c3d_create_image(t_param *cub3d, t_image *image, int width, int height);
void		c3d_create_texture(t_param *cub3d, t_image *texture, char *path);

/*
** 	User Input
*/

int			c3d_key_press(int keycode, t_param *cub3d);

/*
** 	Player Movement
*/

void		c3d_player_rotation(t_param *cub3d, int direction);
void		c3d_player_normalize_angle(t_param *cub3d);
void		c3d_player_normalize_next_angle(t_param *cub3d);
void		c3d_player_next_postion(t_param *cub3d, int direction);
void		c3d_player_next_postion_wall_check(t_param *cub3d);
int			c3d_wall_collusion(t_param *cub3d, int x, int y);

void		c3d_window_distance_plane(t_param *cub3d);

/*
** 	Set wall varaiblees
*/

void		c3d_wall(t_param *cub3d);
void		c3d_wall_type(t_param *cub3d);
void		c3d_wall_distance(t_param *cub3d);
void		c3d_wall_height(t_param *cub3d);

/*
** 	Determine  north, south, west, east facing wall
*/

void		c3d_wall_facing(t_param *cub3d);
void		c3d_wall_facing_quadrant_1(t_param *cub3d);
void		c3d_wall_facing_quadrant_2(t_param *cub3d);
void		c3d_wall_facing_quadrant_3(t_param *cub3d);
void		c3d_wall_facing_quadrant_4(t_param *cub3d);

/*
** 	Determine determne wall texture color
*/

void		c3d_wall_texture(t_param *cub3d, int y);
void		c3d_wall_texture_color(t_param *cub3d, t_image *img, int x, int y);

/*
** Raycasting
*/

void		c3d_raycasting(t_param *cub3d);
void		c3d_raycasting_normalize_ray_angle(t_param *cub3d);
void		c3d_raycasting_ray_angle_at_x(t_param *cub3d, int x);
void		c3d_window_render(t_param *cub3d);

/*
** Raycasting - Hortizontal
*/

void		c3d_raycasting_horizontal(t_param *cub3d);
void		c3d_raycasting_horizontal_intercept(t_param *cub3d);
void		c3d_raycasting_horizontal_intercept_internal(t_param *cub3d);
void		c3d_raycasting_horizontal_wall_check(t_param *cub3d);
void		c3d_raycasting_horizontal_wall_distance(t_param *cub3d);

/*
** Raycasting - Vertical
*/

void		c3d_raycasting_vertical(t_param *cub3d);
void		c3d_raycasting_vertical_intercept(t_param *cub3d);
void		c3d_raycasting_vertical_intercept_internal(t_param *cub3d);
void		c3d_raycasting_vertical_wall_check(t_param *cub3d);
void		c3d_raycasting_vertical_wall_distance(t_param *cub3d);

/*
** Raycasting - Vertical
*/

void		c3d_draw_background(t_param *cub3d);
void		c3d_draw_minimap(t_param *cub3d);

/*
** Draw Wall
*/

void		c3d_draw_wall_strip(t_param *cub3d, int x);
void		c3d_draw_wall_strip_internal(t_param *cub3d, int x);
void		c3d_draw_wall_pixel(t_param *cub3d, int x, int y);

/*
** Draw Sprite
*/

void		c3d_draw_sprite(t_param *cub3d);
void		c3d_draw_sprite_internal(t_param *cub3d, int k);
int			c3d_draw_sprite_valid(t_param *cub3d, int k, int x, int y);
void		c3d_draw_sprite_pixel(t_param *cub3d, int k, int x, int y);

/*
** Print Info - Debugging
*/

void		c3d_print_struct(t_param *cub3d);
void		c3d_sprite_grid_print(t_param *cub3d);
void		c3d_print_map_grid(t_param *cub3d);
void		c3d_print_strip(t_param *cub3d);
void		c3d_print_sprite_strip(t_param *cub3d, int k);
int			c3d_print_error(char *msg);

/*
** Initialize Game
*/

int			c3d_initiate(t_param *cub3d);
int			c3d_initialize_display(t_param *cub3d);
void		c3d_initialize_map(t_param *cub3d);
void		c3d_initialize_sprite(t_param *cub3d);

/*
** Parse Map File
*/

char		*c3d_parse_map_texture_path(char *line);
int			c3d_parse_map_file(t_param *cub3d);
int			c3d_parse_map_grid(t_param *cub3d);
int			c3d_parse_map_rgb(char *line);
void		c3d_parse_map_resolution(char *line, t_param *cub3d);
void		c3d_parse_map_resolution_validaiton(t_param *cub3d);
void		c3d_parse_map_floor_or_ceiling(char *line, t_param *cub3d);
void		c3d_parse_map_file_texture(char *line, t_param *cub3d);
void		c3d_parse_map_grid_copy(int i, char *line, t_param *cub3d);
void		c3d_parse_map_player(t_param *cub3d);

/*
** Parse Map File
*/

int			c3d_map_grid_allocation(t_param *cub3d);
void		c3d_player_coordinate(t_param *cub3d, double angle, int x, int y);
void		c3d_map_grid_free(t_param *cub3d);

/*
** Parse Map File IS FUNCTIONS
*/

int			c3d_map_file_is_resolution(char *line);
int			c3d_map_file_is_texture(char *line);
int			c3d_map_file_is_floor_or_ceiling(char *line);


/*
**  Sprite map grid and visible array memory allocation
*/

void		c3d_sprite_malloc_map_grid(t_param *cub3d);
void		c3d_sprite_malloc_visible_arrary(t_param *cub3d);
void		c3d_sprite_grid_coordinate(t_param *cub3d);
void		c3d_sprite_grid_default(t_param *cub3d);

/*
**  Sprite calulcation for visible items
*/

void		c3d_sprite_visible(t_param *cub3d);
void		c3d_sprite_visible_check(t_param *cub3d);
void		c3d_sprite_visible_distance(t_param *cub3d, int i);
void		c3d_sprite_visible_angle(t_param *cub3d, int i);
void		c3d_sprite_visible_perpendicular_distance(t_param *cub3d, int i);
void		c3d_sprite_visible_height(t_param *cub3d, int i);
void		c3d_sprite_visible_xcenter(t_param *cub3d, int i);
void		c3d_sprite_visible_sort(t_param *cub3d);
void		c3d_sprite_visible_swap(t_sprite_info *a, t_sprite_info *b);

/*
**  Sprite texture color
*/

void		c3d_sprite_texture(t_param *cub3d, int k, int x, int y);
uint32_t	c3d_sprite_texture_pixel_color(t_image *img, int x, int y, int h);

#endif
