/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:11:52 by mg                #+#    #+#             */
/*   Updated: 2020/06/23 22:06:14 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse_flag(const char *format, t_fmt *flag, char *end)
{
	while (format < end && *format != '.')
	{
		if (*format == '\'')
			flag->group = 1;
		if (*format == '-')
			flag->left = 1;
		if (*format == '+')
			flag->showsign = 1;
		if (*format == ' ')
			flag->space = 1;
		if (*format == '#')
			flag->alt = 1;
		++format;
	}
}

/*
**	pf_parse_width
**	function parse the width and zero padding from the format string
*/

void	pf_parse_width(const char *format, t_fmt *flag, char *end, va_list *ap)
{
	char	*nbr;
	char	*ptr;
	int		nbrx;

	nbr = ft_strnew(0);
	while (format < end && *format != '.')
	{
		if (*format == '*' && (*(format + 1) == '.' || (format + 1) == end))
		{
			nbrx = va_arg(*ap, int);
			nbrx < 0 ? flag->left = 1 : 0;
			ptr = ft_itoa(ft_abs(nbrx));
			ft_strappend_xx(&nbr, &ptr);
		}
		else if (ft_isdigit(*format))
			ft_strappend_xo_chr(&nbr, *format);
		++format;
	}
	if (nbr)
		flag->width = atoi(nbr);
	if (*nbr == 48)
		flag->pad = 1;
	ft_strdel(&nbr);
}

void	pf_parse_precision(const char *format, t_fmt *flag, char *end,
																va_list *ap)
{
	int		nbrx;

	while (format < end)
	{
		if (*format == '.')
		{
			if (*(format + 1) == '*')
			{
				nbrx = va_arg(*ap, int);
				if (nbrx < 0 && pf_is_float_spec(flag->spec, flag))
					flag->precision = 6;
				else if (nbrx < 0)
					flag->precision = -1;
				else
					flag->precision = ft_abs(nbrx);
			}
			else if ((format + 1) != end)
				flag->precision = ft_atoi(format + 1);
			else
				flag->precision = 0;
		}
		++format;
	}
}

void	pf_parse_length(t_fmt *flag, char *end)
{
	char *length_flag;

	length_flag = end - 1;
	if (*length_flag == 'h')
	{
		flag->length = 'h';
		if (*(length_flag - 1) == 'h')
			flag->is_char = 1;
	}
	else if (*length_flag == 'l')
	{
		flag->length = 'l';
		if (*(length_flag - 1) == 'l')
			flag->is_llong = 1;
	}
	else if (*length_flag == 'j')
		flag->length = 'j';
	else if (*length_flag == 'z')
		flag->length = 'z';
	else if (*length_flag == 't')
		flag->length = 't';
	else if (*length_flag == 'L')
		flag->length = 'L';
}

void	pf_parse_base(t_fmt *flag)
{
	if (flag->spec == 'o')
		flag->base = 8;
	else if (flag->spec == 'x' || flag->spec == 'X')
		flag->base = 16;
	else if (flag->spec == 'a' || flag->spec == 'A')
		flag->base = 16;
	else if (flag->spec == 'p')
		flag->base = 16;
	else
		flag->base = 10;
}
