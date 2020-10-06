/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_iniatalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:31:46 by mg                #+#    #+#             */
/*   Updated: 2020/06/27 22:17:01 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	pf_intialize_format_2(t_fmt *flag)
{
	flag->is_char = 0;
	flag->is_upper = 0;
	flag->is_llong = 0;
	flag->is_numeric = 0;
	flag->is_signed = 0;
	flag->is_negative = 0;
	flag->is_normalized = 0;
	flag->is_zero = 0;
	flag->is_null = 0;
	flag->is_nan = 0;
	flag->is_inf = 0;
	flag->is_integer = 0;
	flag->is_float = 0;
}

void				pf_intialize_format(t_fmt *flag)
{
	flag->length = 0;
	flag->spec = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->group = 0;
	flag->left = 0;
	flag->showsign = 0;
	flag->space = 0;
	flag->alt = 0;
	flag->pad = 0;
	pf_intialize_format_2(flag);
	flag->base = 0;
	flag->exponent = 0;
	flag->null_mantissa = 1;
}

void				pf_reset_format(t_fmt *flag)
{
	flag->length = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->group = 0;
	flag->left = 0;
	flag->showsign = 0;
	flag->space = 0;
	flag->alt = 0;
	flag->pad = 0;
}
