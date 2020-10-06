/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:06:22 by mg                #+#    #+#             */
/*   Updated: 2020/06/28 00:20:19 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_reset_format_p(t_fmt *flag)
{
	flag->group = 0;
	flag->showsign = 0;
	flag->space = 0;
	flag->alt = 0;
}

static void	pf_convert_pointer_internal(void *ptr, t_fmt *flag)
{
	ssize_t len;

	if (!flag->is_null)
	{
		flag->print = ft_itoa_base((unsigned long long int)ptr, flag->base);
		flag->is_numeric = 1;
	}
	else if (IS_MACOS)
	{
		if (flag->precision == 0)
			flag->print = ft_strdup("0x");
		else
			flag->print = ft_strdup("0x0");
		if (!(len = 0) && flag->precision != -1)
			while (++len < flag->precision)
				ft_strappend_xo(&flag->print, "0");
		if ((len = 2) && flag->precision == -1 && !flag->left && flag->pad)
			while (++len < (ssize_t)flag->width)
				ft_strappend_xo(&flag->print, "0");
	}
	else
	{
		flag->print = ft_strdup("(nil)");
		flag->precision = -1;
	}
}

void		pf_convert_pointer(va_list *ap, t_fmt *flag)
{
	void *ptr;

	ptr = va_arg(*ap, void *);
	flag->is_null = (ptr == NULL) ? 1 : 0;
	pf_convert_pointer_internal(ptr, flag);
	if (IS_MACOS)
		pf_reset_format_p(flag);
	if (!(flag->precision == -1))
		flag->pad = 0;
}
