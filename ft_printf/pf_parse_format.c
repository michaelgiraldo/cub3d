/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:06:44 by mg                #+#    #+#             */
/*   Updated: 2020/06/28 12:43:57 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parse_format(const char *format, va_list *ap, t_fmt *flag)
{
	char *end;

	end = pf_parse_specifier(format, flag);
	if (end)
	{
		pf_parse_flag(format, flag, end);
		pf_parse_width(format, flag, end, ap);
		pf_parse_precision(format, flag, end, ap);
		pf_parse_length(flag, end);
		pf_parse_base(flag);
		if (!(IS_MACOS && *end == '%'))
			if (*end == 'n' || *end == '%')
				pf_reset_format(flag);
	}
	return (end ? (end - format) + 1 : 1);
}

int		pf_islength(char chr)
{
	if (chr == 'h' || chr == 'l' || chr == 'j' ||
		chr == 'z' || chr == 't' || chr == 'L')
		return (1);
	return (0);
}

int		pf_is_valid_specifier(char chr)
{
	if (ft_isalpha(chr))
		if (!(pf_islength(chr)))
			return (0);
	return (1);
}

/*
** https://en.wikipedia.org/wiki/Printf_format_string#Type_field
*/

char	*pf_parse_specifier(const char *format, t_fmt *flag)
{
	char *spec_list;
	char *spec_flag;
	char *tmp;

	spec_list = IS_MACOS ? "%dDiufFeEgGxXoscpaAn" : "%diufFeEgGxXoscpaAn";
	spec_flag = NULL;
	++format;
	while (*spec_list)
	{
		tmp = ft_strchr(format, *spec_list);
		if (tmp)
		{
			if (!spec_flag)
				spec_flag = tmp;
			else if (tmp < spec_flag)
				spec_flag = tmp;
		}
		++spec_list;
	}
	while (spec_flag && format < spec_flag)
		if (!(pf_is_valid_specifier(*format++)))
			spec_flag = NULL;
	if (spec_flag)
		flag->spec = *spec_flag;
	return (spec_flag);
}
