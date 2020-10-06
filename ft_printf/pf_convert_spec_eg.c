/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_spec_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:00:35 by mg                #+#    #+#             */
/*   Updated: 2020/06/21 22:13:05 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	pf_normalize_float(long double dx, t_fmt *flag)
{
	flag->exponent = ft_numlen_float(dx) - 1;
	while (dx > -1 && dx < 1 && !flag->is_zero && --flag->exponent)
	{
		dx = dx * 10;
		if ((dx < 1 && dx >= 0.9999999) || (dx > -1 && dx <= -0.9999999))
			dx = (dx < 0) ? -1 : 1;
	}
	if (dx > 10 || dx < -10)
		dx = dx / ft_pow(flag->base, flag->exponent);
	if (flag->spec == 'e' || flag->spec == 'E')
	{
		if (ft_abs_ld(ft_dtoa_round(dx, flag->precision)) >= 10)
		{
			++flag->exponent;
			dx /= 10;
		}
	}
	else if (flag->spec == 'g' || flag->spec == 'G')
		if (ft_abs_ld(ft_dtoa_round(dx, flag->precision - 1)) >= 10)
		{
			++flag->exponent;
			dx /= 10;
		}
	return (dx);
}

void		pf_convert_spec_e(long double nbr, t_fmt *flag)
{
	long double	dx;

	dx = pf_normalize_float(nbr, flag);
	flag->print = ft_dtoa(dx, flag->precision, flag->base);
}

void		pf_convert_spec_g(long double nbr, t_fmt *flag)
{
	long double				dx;

	dx = pf_normalize_float(nbr, flag);
	if (flag->precision > flag->exponent && flag->exponent >= -4)
	{
		flag->print = ft_dtoa(nbr, flag->precision - (flag->exponent + 1),
																flag->base);
		flag->is_normalized = 0;
	}
	else
		flag->print = ft_dtoa(dx, flag->precision - 1, flag->base);
	pf_check_mantissa(flag);
	pf_format_spec_g(flag);
	flag->precision = -1;
}

void		pf_check_mantissa(t_fmt *flag)
{
	char	*ptr;

	if ((ptr = ft_strchr(flag->print, '.')))
		++ptr;
	else
		return ;
	while (*ptr && flag->null_mantissa)
	{
		if (*ptr > 48 && *ptr <= 57)
			flag->null_mantissa = 0;
		++ptr;
	}
}

void		pf_format_spec_g(t_fmt *flag)
{
	char *ptr;

	if (!flag->alt && (flag->spec == 'g' || flag->spec == 'G'))
	{
		if (flag->null_mantissa)
		{
			if ((ptr = ft_strchr(flag->print, '.')))
				ft_strclr(ptr);
		}
		else
		{
			ptr = flag->print + ft_strlen(flag->print) - 1;
			while (*ptr == 48 && ptr > flag->print)
			{
				*ptr = 0;
				--ptr;
			}
		}
	}
}
