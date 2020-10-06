/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:40:06 by mg                #+#    #+#             */
/*   Updated: 2020/06/25 16:28:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** convert signed specifiers
** converts specifiers d, i
*/

void	pf_convert_signed(va_list *ap, t_fmt *flag)
{
	long long int nbr;

	nbr = 0;
	if (!flag->length)
		nbr = va_arg(*ap, int);
	else if (flag->is_char)
		nbr = (char)va_arg(*ap, int);
	else if (flag->length == 'h')
		nbr = (short)va_arg(*ap, int);
	else if (flag->is_llong)
		nbr = va_arg(*ap, long long);
	else if (flag->length == 'l')
		nbr = va_arg(*ap, long);
	else if (flag->length == 'j')
		nbr = va_arg(*ap, intmax_t);
	else if (flag->length == 'z')
		nbr = va_arg(*ap, size_t);
	else if (flag->length == 't')
		nbr = va_arg(*ap, ptrdiff_t);
	flag->is_negative = (nbr < 0) ? 1 : 0;
	if (nbr == 0)
		pf_convert_zero(flag);
	else
		flag->print = ft_itoa_base(nbr, flag->base);
}

void	pf_convert_unsigned(va_list *ap, t_fmt *flag)
{
	size_t nbr;

	nbr = 0;
	if (!flag->length)
		nbr = va_arg(*ap, unsigned int);
	else if (flag->is_char)
		nbr = (unsigned char)va_arg(*ap, int);
	else if (flag->length == 'h')
		nbr = (unsigned short)va_arg(*ap, int);
	else if (flag->is_llong)
		nbr = va_arg(*ap, unsigned long long);
	else if (flag->length == 'l')
		nbr = va_arg(*ap, unsigned long);
	else if (flag->length == 'j')
		nbr = va_arg(*ap, uintmax_t);
	else if (flag->length == 'z')
		nbr = va_arg(*ap, size_t);
	else if (flag->length == 't')
		nbr = va_arg(*ap, ptrdiff_t);
	if (nbr == 0 && (flag->is_zero = 1))
		flag->showsign = 0;
	if (nbr == 0)
		pf_convert_zero(flag);
	else
		flag->print = ft_itoa_base_unsigned(nbr, flag->base);
}

void	pf_convert_zero(t_fmt *flag)
{
	flag->is_zero = 1;
	if (flag->is_zero)
	{
		if (flag->precision == 0 && flag->showsign && flag->precision == -1)
			flag->print = ft_strdup("+0");
		else if (flag->precision == 0 && flag->showsign)
			flag->print = ft_strdup("+");
		else if (flag->precision == -1)
			flag->print = ft_strdup("0");
		else
			flag->print = ft_strnew(0);
	}
}
