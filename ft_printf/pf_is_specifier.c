/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_is_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:37:51 by mg                #+#    #+#             */
/*   Updated: 2020/06/23 22:35:50 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_is_signed_spec(char specifier, t_fmt *flag)
{
	if (specifier == 'd' || specifier == 'D' ||
		specifier == 'i')
	{
		flag->is_numeric = 1;
		flag->is_signed = 1;
		flag->is_integer = 1;
		return (1);
	}
	return (0);
}

/*
**	If specifier is unsigned flag->is_showsign is ignored
** 	flag->showsign = 0;
*/

int		pf_is_unsigned_spec(char specifier, t_fmt *flag)
{
	if (specifier == 'u' || specifier == 'o' ||
		specifier == 'x' || specifier == 'X')
	{
		if (ft_isupper(specifier))
			flag->is_upper = 1;
		flag->is_numeric = 1;
		flag->is_integer = 1;
		flag->showsign = 0;
		flag->space = 0;
		return (1);
	}
	return (0);
}

int		pf_is_float_spec(char specifier, t_fmt *flag)
{
	if (specifier == 'f' || specifier == 'F' ||
		specifier == 'e' || specifier == 'E' ||
		specifier == 'g' || specifier == 'G' ||
		specifier == 'a' || specifier == 'A')
	{
		if (specifier == 'e' || specifier == 'E' ||
			specifier == 'g' || specifier == 'G')
			flag->is_normalized = 1;
		if (ft_isupper(specifier))
			flag->is_upper = 1;
		flag->is_float = 1;
		flag->is_numeric = 1;
		flag->is_signed = 1;
		return (1);
	}
	return (0);
}

int		pf_is_spec_ax(t_fmt *flag)
{
	if (flag->spec == 'a' || flag->spec == 'A' ||
		flag->spec == 'x' || flag->spec == 'X')
		return (1);
	return (0);
}
