/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:15:04 by mg                #+#    #+#             */
/*   Updated: 2020/06/28 00:40:46 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_convert_char(va_list *ap, t_fmt *flag)
{
	char chr;

	if (flag->spec == 'c')
	{
		flag->print = ft_strnew(1);
		chr = (char)va_arg(*ap, int);
		if (chr == 0)
		{
			flag->is_null = 1;
			if (flag->width > 0)
				--flag->width;
		}
		else
			*flag->print = chr;
	}
}

void	pf_convert_str(va_list *ap, t_fmt *flag)
{
	char *ptr;

	if (flag->spec == 's')
	{
		flag->print = ft_strnew(0);
		ptr = va_arg(*ap, char *);
		if (!ptr)
		{
			ft_strappend_xo(&flag->print, "(null)");
			if (!IS_MACOS && flag->precision != -1)
				flag->precision = flag->precision > 5 ? flag->precision : 0;
		}
		else
			ft_strappend_xo(&flag->print, ptr);
	}
}

void	pf_convert_pct(t_fmt *flag)
{
	if (flag->spec == '%')
	{
		flag->print = ft_strnew(0);
		ft_strappend_xo_chr(&flag->print, '%');
		if (IS_MACOS)
			flag->is_numeric = 1;
	}
}
