/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 07:40:55 by mg                #+#    #+#             */
/*   Updated: 2020/06/23 20:11:40 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_format_padding_width(t_fmt *flag)
{
	size_t len;

	len = ft_strlen(flag->print);
	if (len < flag->width)
	{
		if (flag->left)
		{
			while (len++ < flag->width)
				ft_strappend_xo(&flag->print, " ");
		}
		else
		{
			while (len++ < flag->width)
				ft_strappend_ox(" ", &flag->print);
		}
	}
}
