/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:32:51 by mg                #+#    #+#             */
/*   Updated: 2020/06/21 12:44:01 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print(va_list *ap, t_fmt *flag)
{
	if (flag->spec)
	{
		pf_convert_specifier(ap, flag);
		pf_format_precision(flag);
		pf_format_numeric(flag);
		pf_format_case(flag);
		pf_format_padding_width(flag);
		if (flag->spec == 'c' && flag->is_null)
			pf_print_null(flag);
		else
			flag->print_len += ft_putstr(flag->print);
		free(flag->print);
		if (0)
			pf_print_flags_1(flag);
	}
	else
		flag->print_len += ft_putchar('%');
}

void	pf_print_null(t_fmt *flag)
{
	if (flag->spec == 'c' && flag->is_null)
	{
		if (flag->left)
		{
			flag->print_len += ft_putchar(0);
			flag->print_len += ft_putstr(flag->print);
		}
		else
		{
			flag->print_len += ft_putstr(flag->print);
			flag->print_len += ft_putchar(0);
		}
	}
}

void	pf_convert_specifier(va_list *ap, t_fmt *flag)
{
	if (flag->spec == '%')
		pf_convert_pct(flag);
	else if (pf_is_signed_spec(flag->spec, flag))
		pf_convert_signed(ap, flag);
	else if (pf_is_unsigned_spec(flag->spec, flag))
		pf_convert_unsigned(ap, flag);
	else if (pf_is_float_spec(flag->spec, flag))
		pf_convert_float(ap, flag);
	else if (flag->spec == 'c')
		pf_convert_char(ap, flag);
	else if (flag->spec == 's')
		pf_convert_str(ap, flag);
	else if (flag->spec == 'p')
		pf_convert_pointer(ap, flag);
	else if (flag->spec == 'n')
		pf_convert_n_count(ap, flag);
}

void	pf_format_numeric(t_fmt *flag)
{
	if (flag->is_numeric)
	{
		pf_format_alternate(flag);
		pf_format_exponent(flag);
		pf_format_padding_zero(flag);
		pf_format_space(flag);
		pf_format_showsign(flag);
	}
}
