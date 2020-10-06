/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:56:06 by mg                #+#    #+#             */
/*   Updated: 2020/09/01 20:43:39 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include "ft_printf_type.h"

/*
** update
** List of edge cases
** https://android.googlesource.com/
** platform/external/clang/+/d147f8f/test/Sema/format-strings.c
** Search for "warning"
*/

int		ft_printf(const char *format, ...);
void	pf_internal(const char *format, va_list *ap, t_fmt *flag);
void	pf_intialize_format(t_fmt *flag);
void	pf_reset_format(t_fmt *flag);
void	pf_print(va_list *ap, t_fmt *flag);
void	pf_print_null(t_fmt *flag);

/*
**	Parse printf parameters
**	[specifier] %, d, i, u, f, F, e, E, g, G, x, X, o, s, c, p, a, A, n
**	[flag]: '-', '+', ' ', '#', '0'
**	[width]: 'number', '*'
**	[.precision]: '.number', '.*'
**	[length]: '(none)', 'hh', 'h', 'l', 'll', 'j', 'z', 't', 'L'
*/

int		pf_parse_format(const char *format, va_list *ap, t_fmt *flag);
char	*pf_parse_specifier(const char *format, t_fmt *flag);
void	pf_parse_flag(const char *format, t_fmt *flag, char *end);
void	pf_parse_width(const char *format, t_fmt *flag, char *end, va_list *ap);
void	pf_parse_precision(const char *format, t_fmt *flag, char *end,
																va_list *ap);
void	pf_parse_length(t_fmt *flag, char *end);
void	pf_parse_base(t_fmt *flag);

void	pf_print_flags_1(t_fmt *flag);
void	pf_print_flags_2(t_fmt *flag);
void	pf_print_flags_3(t_fmt *flag);

void	pf_format_numeric(t_fmt *flag);
void	pf_format_space(t_fmt *flag);
void	pf_format_showsign(t_fmt *flag);
void	pf_format_precision(t_fmt *flag);
void	pf_format_padding_width(t_fmt *flag);
void	pf_format_padding_zero(t_fmt *flag);
void	pf_format_case(t_fmt *flag);
void	pf_format_exponent(t_fmt *flag);
void	pf_format_alternate(t_fmt *flag);
void	pf_format_spec_g(t_fmt *flag);

int		pf_is_signed_spec(char specifier, t_fmt *flag);
int		pf_is_unsigned_spec(char specifier, t_fmt *flag);
int		pf_is_float_spec(char specifier, t_fmt *flag);
int		pf_is_nonzero(int c);
int		pf_is_spec_ax(t_fmt *flag);

/*
** convert number specificers with approiate length
** [specifier] d, i, u, f, F, e, E, g, G, x, X, o, a, A,
** [length]: '(none)', 'hh', 'h', 'l', 'll', 'j', 'z', 't', 'L'
*/

void	pf_convert_specifier(va_list *ap, t_fmt *flag);
void	pf_convert_signed(va_list *ap, t_fmt *flag);
void	pf_convert_unsigned(va_list *ap, t_fmt *flag);
void	pf_convert_float(va_list *ap, t_fmt *flag);
void	pf_convert_float_print(long double nbr, t_fmt *flag);
void	pf_convert_spec_e(long double nbr, t_fmt *flag);
void	pf_convert_spec_g(long double nbr, t_fmt *flag);
void	pf_convert_pointer(va_list *ap, t_fmt *flag);
void	pf_convert_n_count(va_list *ap, t_fmt *flag);
void	pf_convert_zero(t_fmt *flag);
void	pf_check_precision(t_fmt *flag);
void	pf_check_mantissa(t_fmt *flag);

/*
**	Convert aplha sepcificers types char, char *, and character '%'
** [specifier] c, s, %
** [length]: not applicable
*/

void	pf_convert_char(va_list *ap, t_fmt *flag);
void	pf_convert_str(va_list *ap, t_fmt *flag);
void	pf_convert_pct(t_fmt *flag);

/*
** convert number specificers with approiate length
** [specifier] p, n
** [length]: '(none)', 'hh', 'h', 'l', 'll', 'j', 'z', 't', 'L'
*/

void	pf_convert_pointer(va_list *ap, t_fmt *flag);
void	pf_convert_nbr_printed(va_list *ap, t_fmt *flag);

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

#endif
