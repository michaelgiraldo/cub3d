/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:16:51 by mg                #+#    #+#             */
/*   Updated: 2020/06/23 20:13:34 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPE_H
# define FT_PRINTF_TYPE_H

/*
** https://pubs.opengroup.org/onlinepubs/9699919799/functions/fprintf.html
** https://en.wikipedia.org/wiki/Printf_format_string
*/

typedef struct	s_printf_format
{
	char		length;
	char		spec;
	size_t		width;
	ssize_t		precision;
	size_t		group;
	size_t		left;
	size_t		showsign;
	size_t		space;
	size_t		alt;
	size_t		pad;
	size_t		print_len;
	size_t		is_char;
	size_t		is_llong;
	size_t		is_upper;
	size_t		is_numeric;
	size_t		is_signed;
	size_t		is_negative;
	size_t		is_normalized;
	size_t		is_zero;
	size_t		is_null;
	size_t		is_nan;
	size_t		is_inf;
	size_t		is_integer;
	size_t		is_float;
	size_t		base;
	int			exponent;
	size_t		null_mantissa;
	char		*print;
}				t_fmt;

#endif
