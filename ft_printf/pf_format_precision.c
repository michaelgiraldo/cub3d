/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:49:46 by mg                #+#    #+#             */
/*   Updated: 2020/06/28 12:44:09 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_format_precision(t_fmt *flag)
{
	ssize_t len;

	if (flag->is_numeric)
		len = ft_strlen(flag->print) - (*flag->print == '-');
	else
		len = ft_strlen(flag->print);
	if (flag->is_numeric && flag->precision > len)
	{
		if (flag->is_negative && ++len)
			*flag->print = '0';
		while (!flag->is_float && len++ < flag->precision)
			ft_strappend_ox("0", &flag->print);
		if (flag->is_negative)
			ft_strappend_ox("-", &flag->print);
	}
	else if (!flag->is_numeric && flag->precision < len)
	{
		if (IS_MACOS && flag->is_null && flag->spec == 'p')
			;
		else if (!(flag->precision == -1) && flag->spec != 'c')
			ft_strclr(flag->print + flag->precision);
	}
}
