/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:32:51 by mg                #+#    #+#             */
/*   Updated: 2020/06/23 21:59:28 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	https://www.gnu.org/software/libc/
** 	manual/html_node/Calling-Variadics.html#Calling-Variadics
*/

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_fmt	flag;

	flag.print_len = 0;
	va_start(ap, format);
	pf_internal(format, &ap, &flag);
	va_end(ap);
	return (flag.print_len);
}

void	pf_internal(const char *format, va_list *ap, t_fmt *flag)
{
	while (*format)
	{
		if (*format == '%')
		{
			pf_intialize_format(flag);
			format += pf_parse_format(format, ap, flag);
			pf_print(ap, flag);
		}
		else
		{
			flag->print_len += ft_putchar(*format);
			++format;
		}
	}
}
