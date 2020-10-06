/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_n_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:46:04 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 08:54:07 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_convert_n_count(va_list *ap, t_fmt *flag)
{
	void *nbr;

	(void)nbr;
	nbr = 0;
	if (!flag->length)
		nbr = (int *)va_arg(*ap, void*);
	else if (flag->is_char)
		nbr = (char*)va_arg(*ap, void*);
	else if (flag->length == 'h')
		nbr = (short*)va_arg(*ap, void*);
	else if (flag->is_llong)
		nbr = (long long int*)va_arg(*ap, void*);
	else if (flag->length == 'l')
		nbr = (long int*)va_arg(*ap, void*);
	else if (flag->length == 'j')
		nbr = (intmax_t *)va_arg(*ap, void*);
	else if (flag->length == 'z')
		nbr = (size_t *)va_arg(*ap, void*);
	else if (flag->length == 't')
		nbr = (ptrdiff_t *)va_arg(*ap, void*);
	nbr = &flag->print_len;
	flag->print = ft_strnew(0);
}
