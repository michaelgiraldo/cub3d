/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:20:25 by mg                #+#    #+#             */
/*   Updated: 2020/06/09 15:33:13 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_flags_1(t_fmt *flag)
{
	ft_putstr("\n********FLAGS*******\n");
	ft_putchar(flag->length);
	ft_putstr(" | length\n");
	ft_putchar(flag->spec);
	ft_putstr(" | specificer\n");
	ft_putnbr(flag->width);
	ft_putstr(" | width\n");
	ft_putnbr(flag->precision);
	ft_putstr(" | precision\n");
	ft_putnbr(flag->group);
	ft_putstr(" | group\n");
	ft_putnbr(flag->left);
	ft_putstr(" | left\n");
	ft_putnbr(flag->showsign);
	ft_putstr(" | show sign\n");
	ft_putnbr(flag->space);
	ft_putstr(" | space\n");
	ft_putnbr(flag->alt);
	ft_putstr(" | alt\n");
	ft_putnbr(flag->pad);
	ft_putstr(" | zero padding\n");
	pf_print_flags_2(flag);
	pf_print_flags_3(flag);
}

void	pf_print_flags_2(t_fmt *flag)
{
	ft_putnbr(flag->print_len);
	ft_putstr(" | print length\n");
	ft_putnbr(flag->base);
	ft_putstr(" | base\n");
	ft_putnbr(flag->exponent);
	ft_putstr(" | exponent\n");
	ft_putnbr(flag->null_mantissa);
	ft_putstr(" | null mantissa\n");
}

void	pf_print_flags_3(t_fmt *flag)
{
	ft_putnbr(flag->is_char);
	ft_putstr(" | is char\n");
	ft_putnbr(flag->is_llong);
	ft_putstr(" | is llong\n");
	ft_putnbr(flag->is_numeric);
	ft_putstr(" | is numeric\n");
	ft_putnbr(flag->is_signed);
	ft_putstr(" | is signed\n");
	ft_putnbr(flag->is_negative);
	ft_putstr(" | is negative\n");
	ft_putnbr(flag->is_normalized);
	ft_putstr(" | is normalized\n");
	ft_putnbr(flag->is_zero);
	ft_putstr(" | is zero\n");
	ft_putnbr(flag->is_integer);
	ft_putstr(" | is integer\n");
	ft_putnbr(flag->is_float);
	ft_putstr(" | is float\n");
}
