/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 13:50:11 by mg                #+#    #+#             */
/*   Updated: 2020/10/05 14:15:53 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** https://harm-smits.github.io/42docs/libs/minilibx/colors.html
*/

uint32_t	c3d_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	c3d_get_t(uint32_t trgb)
{
	return (trgb >>= 24);
}

int	c3d_get_r(uint32_t trgb)
{
	trgb &= 0x00FF0000;
	return (trgb >>= 16);
}

int	c3d_get_g(uint32_t trgb)
{
	trgb &= 0x0000FF00;
	return (trgb >>= 8);
}

int	c3d_get_b(uint32_t trgb)
{
	return (trgb & 0xFF);
}
