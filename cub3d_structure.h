/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:51:40 by mg                #+#    #+#             */
/*   Updated: 2020/09/20 13:31:15 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

#endif

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
	int	 			tile_size;
	int 			**grid;
}					t_map;

typedef struct		s_window {
	int				width;
	int				height;
}					t_window;


typedef struct		s_background{
	size_t			is_texture;
	size_t			color;
	t_image			texture;
}					t_background;

typedef struct		s_coordinate {
	size_t			x;
	size_t			y;
}					t_coordinate;

typedef struct		s_player {
	int 			x;
	int				y;
	double			angle;
}					t_player;

typedef struct		s_ray {
	double 			x;
	double			y;
	double			xintercept;
	double			yintercept;
	double			xstep;
	double			ystep;
	double			wall_distance;
	double			angle;
	int				wall_hit;

}					t_ray;

typedef struct		s_param {
	void			*mlx;
	void			*win;
	t_player		player;
	t_ray			horizontal;
	t_ray			vertical;
	t_image			background;
	t_image			minimap;
	t_image			wall;
	t_background	ceiling;
	t_background	floor;
	t_texture		texture;
	t_map			map;
	t_window		window;
}					t_param;
