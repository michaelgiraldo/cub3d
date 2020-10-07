/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:15:13 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 21:15:55 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gcc -Wextra -Werror -Wall
** cub3d*.c libft/ft*.c getline/get*.c ft_printf/ft*.c ft_printf/pf*.c
** -L minilibx-linux -lmlx -lXext -lX11 -lbsd -lm -g
*/

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_param cub3d;

	ft_memset(&cub3d, 0, sizeof(t_param));
	if (argc > 3 || argc == 1)
		c3d_print_error(&cub3d, "INVALID NUMBER OF ARUGMENTS");
	if (!c3d_is_cub_extension(cub3d.map.file = argv[1]))
		c3d_print_error(&cub3d, "GAME FILE NOT CUB EXTENSION");
	if (argc == 3 && c3d_is_save(argv[2]))
		cub3d.bitmap = 1;
	c3d_initiate_game(&cub3d);
	c3d_raycasting(&cub3d);
	c3d_valid_keys();
	mlx_key_hook(cub3d.win, c3d_key_press, &cub3d);
	mlx_hook(cub3d.win, DESTROYNOTIFY, 1L << 17, c3d_x_window_exit, &cub3d);
	mlx_hook(cub3d.win, RESIZEREQUEST, 1L << 18, c3d_window_refresh, &cub3d);
	mlx_loop(cub3d.mlx);
	return (1);
}

int	c3d_is_save(char *arg)
{
	if (ft_strlen(arg) == 6 && !ft_strcmp(arg, "--save"))
		return (1);
	return (0);
}

int	c3d_is_cub_extension(char *line)
{
	char *file_extension;

	file_extension = line + ft_strlen(line) - 4;
	if (!ft_strncmp(file_extension, ".cub", 4))
		return (1);
	return (0);
}
