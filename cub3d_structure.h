/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:51:40 by mg                #+#    #+#             */
/*   Updated: 2020/10/02 20:07:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURE_H
# define CUB3D_STRUCTURE_H

typedef struct		s_image {
	void			*img_ptr;
	char			*img_data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_texture {
	t_image			north;
	t_image			south;
	t_image			west;
	t_image			east;
	t_image			sprite;
}					t_texture;

typedef struct		s_map {
	char			*file;
	int				fd;
	int				colum;
	int				row;
	int				tile_size;
	int				width;
	int				height;
	int				step;
	int				**grid;
}					t_map;

typedef struct		s_window {
	int				width;
	int				height;
	int				render;
	double			distance_plane;
}					t_window;

typedef struct		s_background {
	int				is_texture;
	uint32_t		color;
	t_image			texture;
}					t_background;

typedef struct		s_player {
	double			x;
	double			y;
	double			angle;
}					t_player;

typedef struct		s_raycast {
	double			x;
	double			y;
	double			xintercept;
	double			yintercept;
	double			xstep;
	double			ystep;
	double			distance;
	int				wall_hit;
}					t_raycast;

typedef struct		s_ray {
	double			angle;
}					t_ray;

typedef struct		s_wall {
	int				type;
	int				height;
	uint32_t		color;
	double			angle;
	double			distance;
	double			distance_plane;
	char			facing;
	int				*height_at;
}					t_wall;

/*
** perpendicular distance
*/

typedef struct		s_sprite_grid{
	int				visible;
	double			x;
	double			y;
}					t_sprite_grid;

typedef struct		s_sprite_info{
	double			x;
	double			y;
	double			delta_x;
	double			delta_y;
	double			angle;
	int				height;
	double			center_x;
	double			distance;
	double			perpendicular_distance;
	uint32_t		color;
	int				type;
}					t_sprite_info;

typedef struct		s_sprite {
	t_sprite_grid	**grid;
	t_sprite_info	*visible;
	int				max;
}					t_sprite;

typedef struct		s_param {
	void			*mlx;
	void			*win;
	t_sprite		sprite;
	t_player		player;
	t_player		next;
	t_ray			ray;
	t_raycast		horizontal;
	t_raycast		vertical;
	t_wall			wall;
	t_image			background;
	t_image			minimap;
	t_image			render;
	t_background	ceiling;
	t_background	floor;
	t_texture		texture;
	t_map			map;
	t_window		window;
}					t_param;

#endif
