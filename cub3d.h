/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:55:21 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 23:01:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** 	stdio.h included for perror function
*/

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

# include "cub3d_structure.h"
# include "cub3d_define.h"
# include "cub3d_mlx_event.h"

/*
** 	ARGV validation
*/

int			c3d_is_save(char *arg);
int			c3d_is_cub_extension(char *line);

/*
** 	Bitmap
*/

void		c3d_bitmap_save(t_param *cub3d);
long		c3d_bitmap_pad(long width);
size_t		c3d_bitmap_size(long width, long height);
int			c3d_bitmap_write_header(int fd, t_image *img);
int			c3d_bitmap_write_data(int fd, t_image *img);
void		c3d_bitmap_write_int_in_char(unsigned char *start, int value);

/*
** 	Color
*/

uint32_t	c3d_create_trgb(int t, int r, int g, int b);
int			c3d_get_t(uint32_t trgb);
int			c3d_get_r(uint32_t trgb);
int			c3d_get_g(uint32_t trgb);
int			c3d_get_b(uint32_t trgb);

/*
** 	Pixel
*/

uint32_t	c3d_pixel_get_color(t_image *img, int x, int y);
void		c3d_pixel_set_color(t_image *img, int x, int y, uint32_t color);
uint32_t	c3d_pixel_get_color_pos(t_image *img, int pos);
void		c3d_pixel_set_color_pos(t_image *img, int pos, uint32_t color);
uint32_t	c3d_sprite_texture_pixel_color(t_image *img, int x, int y, int h);
int			c3d_pixel_get_image_color(t_param *cub3d, int x, int y);
int			c3d_pixel_position(int x, int y, int bits_per_pixel, int size_line);

/*
** Image Utility
*/

void		c3d_create_image(t_param *cub3d, t_image *img);
void		c3d_memcpy_image(t_image *a, t_image *b);
void		c3d_memcpy_at_pixel(t_image *a, t_image *b, int x, int y);
/*
** Warper functions for MLX mlx_xpm_file_to_image() and  mlx_get_data_addr()
*/

void		c3d_texture_xpm_to_image(t_param *cub3d, t_image *texture);
void		c3d_texture_xpm_to_image_internal(t_param *cub3d, t_image *texture);
char		*c3d_texture_is_xpm_extension(char *path);

/*
** 	User Input
*/

int			c3d_key_press(int keycode, t_param *cub3d);
int			c3d_game_exit(t_param *cub3d);
void		c3d_valid_keys(void);
/*
** 	Window Information
*/

void		c3d_window_distance_plane(t_param *cub3d);
void		c3d_window_render(t_param *cub3d);
int			c3d_window_refresh(t_param *cub3d);

/*
** 	Set wall varaibles
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
** Draw Rainbow
*/

void		c3d_draw_rainbow(t_param *cub3d);

/*
** Draw Floor and Ceiling
*/

void		c3d_initialize_background(t_param *cub3d);
void		c3d_draw_background(t_param *cub3d);
void		c3d_draw_background_rgb(t_param *cub3d, t_image *background);

/*
** Draw Minimap
*/

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
**	Print Error
*/

void		c3d_print_error(t_param *cub3d, char *msg);
void		c3d_print_error_sys(t_param *cub3d, char *msg);

/*
**	Free Memory
*/

int			c3d_free_memory(t_param *cub3d);
void		c3d_free_memory_mlx_img(t_param *cub3d);
void		c3d_free_memory_img_ptr(t_param *cub3d);
void		c3d_free_memory_str(t_param *cub3d);
void		c3d_free_memory_array(t_param *cub3d);

/*
** Print Info - Debugging
*/

void		c3d_print_struct(t_param *cub3d);
void		c3d_print_sprite_grid(t_param *cub3d);
void		c3d_print_map_grid(t_param *cub3d);
void		c3d_print_strip(t_param *cub3d);
void		c3d_print_sprite_strip(t_param *cub3d, int k);
void		c3d_print_texture_trgb(t_image *img);

/*
** Initialize Game
*/

void		c3d_initiate_game(t_param *cub3d);
void		c3d_initialize_display(t_param *cub3d);
void		c3d_initialize_display_mlx(t_param *cub3d);
void		c3d_initialize_display_window(t_param *cub3d);
void		c3d_initialize_map(t_param *cub3d);
void		c3d_initialize_sprite(t_param *cub3d);
void		c3d_initialize_background(t_param *cub3d);
void		c3d_initialize_texture(t_param *cub3d);
void		c3d_initialize_render_image(t_param *cub3d);

/*
** 	Background floor and ceiling
*/

void		c3d_parse_background(t_param *cub3d, t_background *bg);
int			c3d_parse_rgb_valid_pattern(char *line);
int			c3d_parse_rgb(char *line);

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

/*
** Intialize player start position and angle
*/

void		c3d_player_starting_positon(t_param *cub3d);
void		c3d_player_coordinate(t_param *cub3d, double angle, int x, int y);
void		c3d_player_validation(t_param *cub3d, int i);

/*
** 	Player Movement
*/

void		c3d_player_rotation(t_param *cub3d, int direction);
void		c3d_player_normalize_angle(t_param *cub3d);
void		c3d_player_normalize_next_angle(t_param *cub3d);
void		c3d_player_next_position(t_param *cub3d, int direction);
void		c3d_player_next_position_wall_check(t_param *cub3d);
void		c3d_player_position_sprite_check(t_param *cub3d);
int			c3d_player_wall_collusion(t_param *cub3d, int x, int y);
int			c3d_player_sprite_collusion(t_param *cub3d, int x, int y);

/*
** Map File Grid Allocation & Memory Management
*/

void		c3d_map_grid_allocation(t_param *cub3d);
void		c3d_map_grid_free(t_param *cub3d);

/*
** Parse Map File IS FUNCTIONS
*/

int			c3d_map_file_is_resolution(char *line);
int			c3d_map_file_is_texture(char *line);
int			c3d_map_file_is_floor_or_ceiling(char *line);

/*
** Valid map check
*/

void		c3d_map_validation(t_param *cub3d);
int			c3d_flood_fill(t_param *cub3d, int row, int column, int i);

/*
**  Sprite map grid and visible array memory allocation
*/

void		c3d_sprite_malloc_map_grid(t_param *cub3d);
void		c3d_sprite_malloc_visible_arrary(t_param *cub3d);
void		c3d_sprite_grid_coordinate(t_param *cub3d);
void		c3d_sprite_grid_default(t_param *cub3d);
void		c3d_sprite_map_grid_free(t_param *cub3d);

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
