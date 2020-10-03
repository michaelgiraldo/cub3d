/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:22:08 by mg                #+#    #+#             */
/*   Updated: 2020/06/27 22:12:07 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_format_alternate(t_fmt *flag)
{
	if (!flag->is_null && flag->spec == 'p')
	{
		if (!flag->left && flag->pad)
			pf_format_padding_zero(flag);
		ft_strappend_ox("0X", &flag->print);
	}
	if (flag->alt && flag->is_float)
		if (!ft_strchr(flag->print, '.'))
			ft_strappend_xo_chr(&flag->print, '.');
	if (flag->alt)
		if (flag->spec == 'o' && *flag->print != '0')
			ft_strappend_ox("0", &flag->print);
	if (flag->alt && !flag->is_zero)
	{
		if (flag->spec == 'x' || flag->spec == 'X')
		{
			if (!flag->left && flag->pad)
				pf_format_padding_zero(flag);
			ft_strappend_ox("0X", &flag->print);
		}
		else if (flag->spec == 'a' || flag->spec == 'A')
			ft_strappend_ox("0X", &flag->print);
	}
}

void	pf_format_exponent(t_fmt *flag)
{
	char *ptr;

	if (!(flag->exponent == 0 && (flag->spec == 'g' || flag->spec == 'G'))
		&& !flag->is_nan && !flag->is_inf)
	{
		if (flag->is_normalized)
		{
			if (flag->exponent >= 0)
				ft_strappend_xo(&flag->print, "E+");
			else
				ft_strappend_xo(&flag->print, "E-");
			if (flag->exponent > -10 && flag->exponent < 10)
			{
				ft_strappend_xo(&flag->print, "0");
				ptr = ft_itoa(ft_abs(flag->exponent));
				ft_strappend_xx(&flag->print, &ptr);
			}
			else
			{
				ptr = ft_itoa(ft_abs(flag->exponent));
				ft_strappend_xx(&flag->print, &ptr);
			}
		}
	}
}

/*
** For pf_format_padding_zero
**
** printf("%0-f", 1.23);
** expected-warning{{flag '0' is ignored when flag '-' is present}}
**
** printf("%-0f", 1.23);
** expected-warning{{flag '0' is ignored when flag '-' is present}}
**
** https://android.googlesource.com/
** platform/external/clang/+/d147f8f/test/Sema/format-strings.c
** https://bit.ly/3dwCJjI
**
** If the '0' and '-' flags both appear, the '0' flag is ignored.
**
** For d, i, o, u, x, and X conversion specifiers,
** if a precision is specified, the '0' flag shall be ignored
** https://pubs.opengroup.org/onlinepubs/9699919799/functions/fprintf.html
**
** if (!flag->left && flag->pad &&	!(!flag->is_float && flag->pad))
*/

void	pf_format_padding_zero(t_fmt *flag)
{
	size_t neg_flag;
	size_t len;

	if (flag->is_integer && flag->precision != -1)
		return ;
	else if (!flag->left && flag->pad)
	{
		neg_flag = 0;
		len = ft_strlen(flag->print);
		if (len < flag->width)
		{
			if (flag->spec == 'p' ||
				(flag->alt && !flag->is_zero && pf_is_spec_ax(flag)))
				len += 2;
			if (*flag->print == '-' && ++len && (neg_flag = 1))
				*flag->print = '0';
			else
				len += (flag->showsign || flag->space);
			while (len++ < flag->width)
				ft_strappend_ox("0", &flag->print);
			if (neg_flag)
				ft_strappend_ox("-", &flag->print);
		}
	}
}

/*
** For pf_format_space
**
** printf("% +f", 1.23);
** expected-warning{{flag ' ' is ignored when flag '+' is present}}
**
** printf("%+ f", 1.23);
** expected-warning{{flag ' ' is ignored when flag '+' is present}}
**
** https://android.googlesource.com/
** platform/external/clang/+/d147f8f/test/Sema/format-strings.c
** https://bit.ly/3dwCJjI
*/

void	pf_format_space(t_fmt *flag)
{
	if (!flag->showsign && flag->space && ft_isdigit(*flag->print))
	{
		if (flag->is_signed || flag->spec == 'p')
			ft_strappend_ox(" ", &flag->print);
	}
	else if (!flag->showsign && flag->space)
	{
		if (*flag->print == 'n' || *flag->print == 'i')
			if (flag->is_signed)
				ft_strappend_ox(" ", &flag->print);
	}
}

void	pf_format_showsign(t_fmt *flag)
{
	if (flag->showsign && ft_isdigit(*flag->print))
	{
		if (flag->is_signed || flag->spec == 'p')
			ft_strappend_ox("+", &flag->print);
	}
	else if (flag->showsign && (*flag->print == 'n' || *flag->print == 'i'))
	{
		if (flag->is_signed)
			ft_strappend_ox("+", &flag->print);
	}
}
