/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:30:43 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 00:22:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_background(t_param *cub3d, t_background *bg)
{
	char *xpm;

	xpm = c3d_texture_is_xpm_extension(bg->texture.file);
	if (xpm)
	{
		bg->texture.file = xpm;
		bg->is_texture = 1;
		c3d_texture_xpm_to_image(cub3d, &bg->texture);
	}
	else if (c3d_parse_rgb_valid_pattern((bg->texture.file)))
	{
		bg->is_texture = 0;
		bg->color = c3d_parse_rgb(bg->texture.file);
		*bg->texture.file = 0;
	}
	else
		c3d_print_error(cub3d, "NOT VALID FLOOR OR CEILING");
}

int		c3d_parse_rgb_valid_pattern(char *line)
{
	int digit;
	int count;

	digit = 0;
	count = 0;
	while (!ft_isdigit(*line))
		++line;
	while (*line)
	{
		if (ft_isdigit(*line))
			++digit;
		if (*line == 44 || !*(line + 1))
		{
			if (digit > 0 && digit < 4)
				++count;
			digit = 0;
		}
		++line;
	}
	if (count == 3)
		return (1);
	return (0);
}

/*
**	if (!(a >= 0 && t <=255) || !(r >= 0 && r <=255) ||
**		!(g >= 0 && g <=255) ||	!(b >= 0 && b <=255))
**		("INVALID COLOR RANGE");
*/

int		c3d_parse_rgb(char *line)
{
	char	*color;
	size_t	red;
	size_t	green;
	size_t	blue;

	color = ft_strnew(0);
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	red = ft_atoi(color);
	*color = '\0';
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	green = ft_atoi(color);
	*color = '\0';
	while (!ft_isdigit(*line))
		++line;
	while (ft_isdigit(*line))
		ft_strappend_xo_chr(&color, *line++);
	blue = ft_atoi(color);
	free(color);
	return (c3d_create_trgb(0xFF, red, green, blue));
}
